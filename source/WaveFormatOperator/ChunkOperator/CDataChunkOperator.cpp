/**
 * @file	CDataChunkOperator.cpp
 * @brief	WAVEファイルのChunkクラス.
 */

#include <cstring>
using namespace std;

#ifndef __CDATACHUNKOPERATOR_H__
#include "CDataChunkOperator.h"
#endif

#ifndef __CFACTORYSAMPLEOPERATOR_H__
#include "../SampleOperator/CFactorySampleOperator.h"
#endif

#ifndef __IREADSAMPLEOPERATOR_H__
#include "../SampleOperator/ISampleOperator.h"
#endif

/**
 * コンストラクタ.
 */
CDataChunkOperator::CDataChunkOperator()
{
	strncpy(m_szID, "data", 4);
	m_lSize = 0;
}

/**
 * data chunkをファイルから読み込み.
 */
bool  CDataChunkOperator::read(ifstream& i_cFileStream, CWaveFormatOperator& i_pcWaveFormatOperator, T_CHUNK& i_stChunk)
{
	long lDataSize = CWaveFormatOperatorUtility::convert4ByteDataToLong(i_stChunk.m_szSize);
	i_pcWaveFormatOperator.setSamplesPerChannel(lDataSize/i_pcWaveFormatOperator.getBlockAlign());

	// 量子化ビットを取得.
	short a_BitsPerSample = i_pcWaveFormatOperator.getBitsPerSample();
	
	// サンプル値の読み込む方法を生成. (1サンプル 8bit, 16bit...のどれで読み込むかを決定).
	CFactorySampleOperator a_CFactorySampleOperator;
	ISampleOperator* a_piSampleOperator;
	a_piSampleOperator = a_CFactorySampleOperator.create(a_BitsPerSample);
	
	// read sample.
	for(long index=0;index<i_pcWaveFormatOperator.getSamplesPerChannel();index++)
	{
		for(short channel=0;channel<i_pcWaveFormatOperator.getNumChannels();channel++)
		{
			double a_dSample = a_piSampleOperator->read(i_cFileStream);
			i_pcWaveFormatOperator.setSample(a_dSample, index, channel);
		}
	}
	
	if(m_bIsDEBUG) printChunk((char*)"Read Chunk", i_stChunk);
	return true;
}

/**
 * data chunkをファイルへ書き込み.
 */
bool CDataChunkOperator::write(ofstream& i_cFileStream, CWaveFormatOperator& i_pcWaveFormatOperator)
{
	T_CHUNK a_stChunk;
	memset((char*)&a_stChunk, 0x00, sizeof(a_stChunk));

	// "data"をコピー.
	strncpy(a_stChunk.m_szID, this->m_szID, sizeof(a_stChunk.m_szID));
	
	// "data"のサイズを計算.
	long lDataSize = i_pcWaveFormatOperator.getSamplesPerChannel() * i_pcWaveFormatOperator.getBlockAlign();
	CWaveFormatOperatorUtility::convertLongTo4ByteData(lDataSize, a_stChunk.m_szSize);
	
	// chunkをファイルへ書き込み.
	i_cFileStream.write((char*)&a_stChunk, sizeof(a_stChunk));
    
	// 量子化ビットを取得.
	short a_BitsPerSample = i_pcWaveFormatOperator.getBitsPerSample();
	
	// サンプル値の読み込む方法を生成. (1サンプル 8bit, 16bit...のどれで読み込むかを決定).
	CFactorySampleOperator a_CFactorySampleOperator;
	ISampleOperator* a_piSampleOperator;
	a_piSampleOperator = a_CFactorySampleOperator.create(a_BitsPerSample);
	
	// write sample.
	bool a_bIsWriteSuccess = true;
	for(long index=0;index<i_pcWaveFormatOperator.getSamplesPerChannel();index++)
	{
		for(short channel=0;channel<i_pcWaveFormatOperator.getNumChannels();channel++)
		{
			double a_Sample = i_pcWaveFormatOperator.getSample(index,channel);
			a_bIsWriteSuccess = a_piSampleOperator->write(a_Sample, i_cFileStream);
			if(a_bIsWriteSuccess) break;
			
		}
	}

	if(m_bIsDEBUG) printChunk((char*)"Write Sample Chunk", a_stChunk);
	return true;
}

