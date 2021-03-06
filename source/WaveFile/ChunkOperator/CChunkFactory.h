/**
 * @file	CChunkFactory.h
 * @brief	WAVEファイルのChunkクラス.
 */

#ifndef __CCHUNKFACTORY_H__
#define __CCHUNKFACTORY_H__

#include <fstream>
#include <cstring>
using namespace std;

#ifndef __CWAVEFILE_H__
#include "../../CWaveFile.h"
#endif

#ifndef __CWAVEFILEUTILITY_H__
#include "../Utility/CWaveFileUtility.h"
#endif

#ifndef __BCHUNKOPERATOR_H__
#include "BChunkOperator.h"
#endif

#ifndef __CDATACHUNKOPERATOR_H__
#include "CDataChunkOperator.h"
#endif

#ifndef __CFMTCHUNKOPERATOR_H__
#include "CFmtChunkOperator.h"
#endif

#ifndef __COTHERCHUNKOPERATOR_H__
#include "COtherChunkOperator.h"
#endif

#ifndef __CRIFFCHUNKOPERATOR_H__
#include "CRIFFChunkOperator.h"
#endif

/**
 * @brief	WAVEファイルのChunk.
 */
class CChunkFactory
{
public:
	/**
	 * @brief	コンストラクタ.
	 */
	CChunkFactory();
	
	/**
	 * @brief	デストラクタ.
	 */
	virtual ~CChunkFactory(){ }

	/**
	 * @brief	WAVEファイルのchunk種を生成.
	 * @return	WAVEファイルのchunk種.
	 */
	BChunkOperator* create(const char* i_szID);

	/**
	 * @brief	チャンクを探す.
	 * @param	ofstream& i_cFileStream
	 * @return	WAVEファイルのchunk種.
	 */
	BChunkOperator* search(ifstream& i_cFileStream);

private:
	//map<char*, BChunkOperator&>	m_mapChunk;

	CRIFFChunkOperator			m_cRIFFChunkOperator;
	CFmtChunkOperator			m_cFmtChunkOperator;
	CDataChunkOperator			m_cDataChunkOperator;
	COtherChunkOperator			m_cOtherChunkOperator;
};

#endif	//__CCHUNKFACTORY_H__

