[WaveFormOperator](https://github.com/kantoku009/WaveFormOperator)
====================

# はじめに
C++言語にてWAVEファイルを読み/書きできるプログラムを作成した。


GitHubのリポジトリと全ソースコードのダウンロードは以下URLから行える。

- [Githubのリポジトリ](https://github.com/kantoku009/WaveFormOperator)
- [全ソースコードのダウンロード](https://github.com/kantoku009/WaveFormOperator/archive/master.zip)

----

# WAVEファイル フォーマット
WAVEファイルの構造を以下ファイルで解説している。  
[Wave File Formatの解説](https://github.com/kantoku009/WaveFormOperator/blob/master/document/WAVE_FORMAT.md)

----

# UML
クラス図とシーケンス図を作成した。  
以下からダウンロード可能。  

 - [UML](https://github.com/kantoku009/WaveFormOperator/blob/master/document/UML.asta?raw=true)

UMLの作成には無償のUMLモデリングツール[astah community](http://astah.change-vision.com/ja/)を使用している。  

----

# ビルド
<dl>
	<dt><strong>コマンド</strong></dt>
	<dd>Unix系のOSでビルドするのを想定している。</dd>
	<dd>以下コマンドが必要。</dd>
</dl>

	g++
	make

<dl>
	<dt><strong>make</strong></dt>
	<dd>zipファイルを解凍</dd>
	<dd>コマンドラインからカレントディレクトリの移動</dd>
	<dd>makeを実行</dd>
</dl>

	%unzip WaveFormOperator-master.zip
	%cd ./source/test_source
	%make

<dl>
	<dt><strong>実行ファイル生成</strong></dt>
	<dd>以下の実行ファイルが出来上がる。</dd>
</dl>


	test_WaveFormatOperator

# 使用方法
WAVEファイルをコピーする為のプログラムを作成した。  
使用方法は以下を参照。  
実行すると"out.wav"が出来上がる。

	%./test_WaveFormatOperator [WAVEファイル名]
