/**
 * @file	CWAVEChunkOperator.h
 * @brief	WAVEファイルのChunkクラス.
 */

#ifndef __CWAVECHUNKOPERATOR_H__
#define __CWAVECHUNKOPERATOR_H__

#include <fstream>
using namespace std;

#ifndef __BCHUNKOPERATOR_H__
#include "./BChunkOperator.h"
#endif

/**
 * @brief	WAVEファイルのChunk.
 */
class CWAVEChunkOperator : public BChunkOperator
{
public:
	/**
	 * @brief	コンストラクタ.
	 */
	CWAVEChunkOperator();
	
	/**
	 * @brief	デストラクタ.
	 */
	virtual ~CWAVEChunkOperator(){ }

	/**
	 * @brief	WAVEファイルのChunkを読み込む.
	 * @param	T_CHUNK& i_stChunk
	 * @param	CWaveFile& pcWaveFile
	 * @param	ifstream& i_cFileStream.
	 * @return	成功 / 失敗.
	 */
	bool read(ifstream& i_cFileStream, CWaveFile& i_pcWaveFile, T_CHUNK& i_stChunk);
	
	/**
	 * @brief	WAVEファイルのChunkを書き込む.
	 * @param	T_CHUNK& i_stChunk
	 * @param	CWaveFile& pcWaveFile
	 * @param	ifstream& i_cFileStream.
	 * @return	成功 / 失敗.
	 */
	bool write(ofstream& i_cFileStream, CWaveFile& i_pcWaveFile);
	
};

#endif	//__CWAVECHUNKOPERATOR_H__
