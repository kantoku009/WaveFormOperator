/**
 * @file	CWaveFormatOperatorUtility.h
 * @brief	CWaveFormatOperatorのユーティリティクラス.
 */

#include <cstring>		//memcpyを使用したい.
using namespace std;

#include "CWaveFormatOperatorUtility.h"

/**************************************************
 * bit shiftをする.
 **************************************************/
long CWaveFormatOperatorUtility::bitShift(short i_shBitShift)
{
	long a_lRet=1;
    
	a_lRet <<= i_shBitShift;
    
	return a_lRet;
}


/**************************************************
 * Big-endianか否かを調べる.
 **************************************************/
bool CWaveFormatOperatorUtility::isBigEndian()
{
	short	a_shCheck = 1;
	bool	a_bIsBigEndian = false;
    
	if(*((char*)&a_shCheck))
	{
		a_bIsBigEndian = false;
	}
	else
	{
		a_bIsBigEndian = true;
	}

	return a_bIsBigEndian;
}

/**************************************************
 * long型 Little-endian -> Big-endian を変換する.
 **************************************************/
long CWaveFormatOperatorUtility::swapLong(char* i_pbyData)
{
	return (*i_pbyData<<24) | (*(i_pbyData+1)<<16) | (*(i_pbyData+2)<<8) | *(i_pbyData+3);
}

/**************************************************
 * short型 Little-endian -> Big-endian を変換する.
 **************************************************/
short CWaveFormatOperatorUtility::swapShort(char* i_pbyData)
{
	return (*i_pbyData<<8) | *(i_pbyData+1);
}


/**************************************************
 * int型 Little-endian -> Big-endian を変換する.
 **************************************************/
int CWaveFormatOperatorUtility::swapInt(char* i_pbyData)
{
	switch (sizeof(int))
	{
		case 2:
		return (int)swapShort(i_pbyData);
        
		case 4:
		return (int)swapLong(i_pbyData);
	}
    
	return 0;
}

/*********************************
 * 2ByteDataをshort型に変換する.
 *********************************/
short CWaveFormatOperatorUtility::convert2ByteDataToShort(char* i_pbyData)
{
	short a_shSize = 0;

	memcpy((char*)&a_shSize, i_pbyData, 2);
	if(isBigEndian()) a_shSize = swapShort((char*)&a_shSize);
	return a_shSize;
}

/*********************************
 * short型を2ByteDataに変換する.
 *********************************/
void CWaveFormatOperatorUtility::convertShortTo2ByteData(short i_shInteger, char* i_pbyData)
{
	bool a_bIsBigEndian = isBigEndian();
	if(a_bIsBigEndian) i_shInteger = swapShort((char*)&i_shInteger);

	memcpy(i_pbyData, (char*)&i_shInteger, 2);
}

/*********************************
 * 4ByteDataをlong型に変換する.
 *********************************/
long CWaveFormatOperatorUtility::convert4ByteDataToLong(char* i_pbyData)
{
	long a_lSize = 0;

	memcpy((char*)&a_lSize, i_pbyData, 4);
	if(isBigEndian()) a_lSize = swapLong((char*)&a_lSize);
	return a_lSize;
}

/**********************************
 * long型を4ByteDataに変換する.
 **********************************/
void CWaveFormatOperatorUtility::convertLongTo4ByteData(long i_lInteger, char* i_pbyData)
{
	bool a_bIsBigEndian = isBigEndian();
	if(a_bIsBigEndian) i_lInteger = swapLong((char*)&i_lInteger);

	memcpy(i_pbyData, (char*)&i_lInteger, 4);
}
