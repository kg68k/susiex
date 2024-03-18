# SUSIEX
GORRYさんの作成された
[SUSIE: System of Universal SCSI Integrated Engine](http://gorry.haun.org/x68index.html#ARC_X68_SUSIE)
の改造版です。

無保証につき各自の責任で使用して下さい。


## Build
PCやネット上での取り扱いを用意にするために、src/内のファイルはUTF-8で記述されています。
X68000上でビルドする際には、UTF-8からShift_JISへの変換が必要です。

### AP.rのインストール

アセンブラプリプロセッサ「AP.r」のインストールが必要です。

APICGやEELのアーカイブに入っているtools.Lzhの中のAP.rをパスの通ったディレクトリに置いてください。
* TwentyOne +C環境ではファイル名を小文字のap.rにします。
* LZXで圧縮してap.xとしても構いません。

### u8tosjを使用する方法

あらかじめ、[u8tosj](https://github.com/kg68k/u8tosj)をビルドしてインストールしておいてください。

トップディレクトリで`make`を実行してください。以下の処理が行われます。
1. build/ディレクトリの作成。
2. src/内の各ファイルをShift_JISに変換してbuild/へ保存。

次に、カレントディレクトリをbuild/に変更し、`make`を実行してください。
実行ファイルが作成されます。

### u8tosjを使用しない方法

ファイルを適当なツールで適宜Shift_JISに変換してから`make`を実行してください。
UTF-8のままでは正しくビルドできませんので注意してください。


## License
[SSE_121A.LZH](archives/SSE_121A.LZH)内の「使用規定.DOC」ファイルを参照してください。


## Author
TcbnErik / 立花@桑島技研  
https://github.com/kg68k/susiex
