/**
 * @file	BWaveForm.h
 * @brief	音声を扱うクラス.
 */

#ifndef __BWAVEFORM_H__
#define __BWAVEFORM_H__

/**
 * @brief	音声を扱うクラス.
 */
class BWaveForm
{
public:
	/**
	 * @brief	コンストラクタ.
	 * @param	long  sampleRate		サンプリング周波数. [sample/sec].
	 * @param	short bitsPerSample		量子化ビット. [bit/sample].
	 * @param	short numChannels		チャンネル数.
	 * @param	long  numSamples		サンプル数. [sample/channel].
	 * @return	なし.
	 */
	BWaveForm(
					long  sampleRate=44100,
					short bitsPerSample=8,
					short numChannels=1,
					long  numSamples=44100);
    
	/**
	 * @brief	コピーコンストラクタ.
	 * @param	const BWaveForm &ob
	 * @return	なし.
	 */
	BWaveForm(const BWaveForm &ob);

	/**
	 * @brief	デストラクタ.
	 * @param	なし.
	 * @return	なし.
	 * @note	コンストラクタで確保したメモリの確保.
	 */
	virtual ~BWaveForm()
	{
		delete [] this->m_pdSample;
		this->m_pdSample=0;
	}

	/**
	 * @brief	サンプリング周波数を設定.
	 * @param	long sampleRate	サンプリング周波数.
	 * @return	なし.
	 */
	void setSampleRate(long sampleRate);

	/**
	 * @brief	量子化bitを設定.
	 * @param	short bitsPerSample	量子化ビット.
	 * @return	なし.
	 */
	void setBitsPerSample(short bitsPerSample);

	/**
	 * @brief	チャンネル数を設定.
	 * @param	short numChannels	チャンネル数.
	 * @return	なし.
	 */
	void setNumChannels(short numChannels);

	/**
	 * @brief	1 channelにつき、いくつサンプル数があるかを設定
	 * @param	long samplesPerChannel 
	 * @return	なし.
	 */
	void setSamplesPerChannel(long samplesPerChannel);

	/**
	 * @brief	サンプリング周波数を取得.
	 * @param	なし.
	 * @return	サンプリング周波数.
	 */
	long	getSampleRate() const { return this->m_lSampleRate; }

	/**
	 * @brief	量子化Bitを取得する
	 * @param	なし.
	 * @return	量子化Bit.
	 */
	short	getBitsPerSample() const { return this->m_shBitsPerSample; }

	/**
	 * @brief	チャンネル数を取得する.
	 * @param	なし.
	 * @return	チャンネル数.
	 */
	short	getNumChannels() const { return this->m_shNumChannels; }

	/**
	 * @brief	1 channelにつき、いくつサンプル数があるかを取得
	 * @param	なし.
	 * @return	1チャンネルのサンプル数.
	 */
	long	getSamplesPerChannel() const { return this->m_lSamplesPerChannel; }

	/**
	 * @brief	1つのブロックの区切り(byte)を取得.
	 * @param	なし.
	 * @return	1つのブロックの区切り(byte).
	 */
	short	getBlockAlign() const { return this->m_shNumChannels*this->getBytesPerSample(); }

	/**
	 * @brief	1サンプルにつき、何バイト使うかを取得
	 * @param	なし.
	 * @return	1サンプルにつき、何バイト使うか.
	 */
	short	getBytesPerSample() const;

	/**
	 * @brief	全サンプル数を取得.
	 * @param	なし.
	 * @return	全サンプル数.
	 */
	long	getNumSamples() const { return this->m_lSamplesPerChannel*this->m_shNumChannels; }

	/**
	 * @brief	メモリにサンプル値を書き込む.
	 * @param	double sample
	 * @param	long num
	 * @param	short channel
	 * @return	なし.
	 */
	void	setSample(double sample, long num, short channel=0);

	/**
	 * @brief	メモリからサンプル値を読みこむ.
	 * @param	long num
	 * @param	short channel
	 * @return	サンプル値.
	 */
	double	getSample(long num, short channel=0) const;
    
	/**
	 * @brief	=演算子のオーバーロード.
	 */
	const BWaveForm &operator=(const BWaveForm &right);

	/**
	 * @brief	+=演算子のオーバーロード.
	 */
	const BWaveForm &operator+=(BWaveForm &ob);

	/**
	 * @brief	+演算子のオーバーロード.
	 */
	BWaveForm operator+(const BWaveForm &ob);
    
	/**
	 * @brief	サンプルとサンプルの間の補間.
	 */
	double	interpolation(double i_dThreshold, short i_shChannel);

protected:
	/**
	 * @brief	sinc関数.
	 */
	double sinc(double i_dSample);

	/**
	 * @biref	サンプリング周波数. [sample/sec].
	 */
	long    m_lSampleRate;

	/**
	 * @brief	量子化ビット. [bit/sample].
	 */
	short   m_shBitsPerSample;

	/**
	 * @brief	チャンネルの数.
	 */
	short   m_shNumChannels;

	/**
	 * @brief	１チャンネルのサンプルの数. [sample/channel].
	 */
	long    m_lSamplesPerChannel;

	/**
	 * @brief	サンプル値.
	 */
	double  *m_pdSample;
};

#endif	//__BWAVEFORM_H__

