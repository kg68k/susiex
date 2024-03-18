/*
 *	Block Device Driver Utility
 *	Copyright (C)1994 GORRY.
 *	$Id: DevDrv.h,v 1.2 1995/05/21 14:46:34 GORRY Exp GORRY $
 */


						// HUWK : Human68kワーク
#define	HUWK_XDRVPtr	0x1c38		// XDRVへのポインタ
#define	HUWK_XDPBPtr	0x1c3c		// XDPBへのポインタ
#define	HUWK_LastDrive	0x1c73		// LastDriveの値(Z:=$19)
#define	HUWK_DriveNum	0x1c74		// 接続されている物理ドライブ数
#define	HUWK_XDNO	0x1c7e		// ドライブ番号テーブル(XDNO)


struct	DINF;
struct	XDRV;
struct	XDPB;
struct	DEVH;
struct	REQH;


						// DINF : デバイスドライバ情報
struct	DINF {
	long	PDriveNo;		// 物理ドライブ番号
	struct DEVH *DEVHPtr;		// デバイスヘッダ(DEVH)へのポインタ
	struct XDPB *XDPBPtr;		// 内部DPB(XDPB)へのポインタ
};


						// XDRV : ドライブワークテーブル
						//	 ドライブ数の分だけ続く
struct	XDRV {
	UBYTE	Magic00;		// 物理ドライブ番号(A:="A",B:="B"・・・)。
	UBYTE	Magic01;		// ":"（物理ドライブ番号マーク）
	UBYTE	Magic02;		// $09（ルートディレクトリマーク）
	UBYTE	Path[61];		// 現在のカレントパス、またはSubDrv・Dir先。\FOO\BARなら"FOO",$09,"BAR",$00。
	ULONG	Magic40;		// 不明
	UBYTE	Magic44;		// 不明
	UBYTE	DrvKind;		// ドライブ種別。$40=物理Drv、$50=SubDrv(DirをDrv化)、$60=SubDir(DrvをDir化)。
	struct XDPB *XDPBPtr;		// 内部DPBテーブル(XDPB)へのポインタ
	UWORD	Magic4A;		// $0000または$FFFFが書かれる
	UWORD	Magic4C;		// 不明
};


						// XDNO : ドライブ番号テーブル
						//	 ドライブ数の分だけ続く


						// XDPB : 内部DPBテーブル
struct	XDPB {
	UBYTE	DriveNo;		// 物理ドライブ番号(A:=0,B:=1・・・)
	UBYTE	UnitNo;			// 同一デバイス内でのユニット番号
	struct DEVH *DEVHPtr;		// デバイスドライバ(DEVH)へのポインタ
	struct XDPB *NextXDPBPtr;	// 次の内部DPBテーブル(XDPB)へのポインタ
	UWORD	SecByte;		// １セクタのバイト数
	UBYTE	CluSec;			// １クラスタのセクタ数-1
	UBYTE	SftCluSec;		// クラスタ->セクタのシフトカウント
	UWORD	FATSec;			// FATのセクタ位置
	UBYTE	FATNum;			// FATの個数
	UBYTE	FATSize;		// FATのセクタ数
	UWORD	RootEntryNum;		// ルートディレクトリに記録できるエントリ数
	UWORD	DataSec;		// データ領域のセクタ位置
	UWORD	CluNum;			// データ部のクラスタ数+1
	UWORD	RootSec;		// ルートディレクトリのセクタ位置
	UBYTE	MediaID;		// メディアID
	UBYTE	SftSecByte;		// セクタ->バイトのシフトカウント
	UWORD	FATSearchPos;		// 次のFATサーチ位置
};


						// DEVH : デバイスヘッダ
struct	DEVH {
	struct DEVH *NextDEVHPtr;	// 次のDEVHへのポインタ
	UWORD	Flag;			// デバイスの属性
	void	*StrategyPtr;		// ストラテジルーチンへのポインタ
	void	*InterruptPtr;		// インタラプトルーチンへのポインタ
	char	Name[8];		// デバイス名
};


						// REQH : リクエストヘッダ
struct	REQH {
	UBYTE	Magic00;		// 常に26
	UBYTE	UnitNo;			// ユニット番号
	UBYTE	CommandCode;		// コマンドコード
	UBYTE	ErrCodeL;		// エラーコード下位
	UBYTE	ErrCodeH;		// エラーコード上位
	UBYTE	Magic05;		// 未使用
	UBYTE	Magic06;		// 未使用
	UBYTE	Magic07;		// 未使用
	UBYTE	Magic08;		// 未使用
	UBYTE	Magic09;		// 未使用
	UBYTE	Magic0A;		// 未使用
	UBYTE	Magic0B;		// 未使用
	UBYTE	Magic0C;		// 未使用

	union {
		UBYTE	UnitNum;	// ユニット数
		UBYTE	InnerCmd;	// 内部コマンド
		UBYTE	DriveStatus;	// ドライブの状態
		UBYTE	MediaID;	// メディアバイト
		UBYTE	SearchAtr;	// CD:検索属性
		UBYTE	SeekMode;	// CD:シークモード
	} U0D;

	union {
		void	*DevDrvEndPtr;	// デバイスドライバ終了アドレス
		void	*DataBufferPtr;	// データバッファへのポインタ
		void	*BPBTablePtr;	// BPBテーブルへのポインタ
		UBYTE	ExchangeFlag;	// メディア交換フラグ
		void	*OSFileNamePtr;	// CD:OSファイル名へのポインタ
	} U0E;

	union {
		void	*ParamPtr;	// パラメータへのポインタ
		ULONG	ByteNum;	// バイト数
		ULONG	SecNum;		// セクタ数
		UBYTE	AllocDriveNo;	// OSから割り当てのドライブ番号(A:=0,B:=1)
		void	*BPBPtrPtr;	// BPBテーブルへのポインタへのポインタ
		UWORD	SPIOCTRLCmd;	// 特殊IOコントロールコマンド
		UWORD	DirListPtr;	// CD:ディレクトリリストへのポインタ
		ULONG	AccessSize;	// CD:アクセスサイズ
		ULONG	Result;		// CD:リザルトコード
	} U12;

	union {
		ULONG	Sec;		// 開始セクタ番号
		ULONG	FileInfoPtr;	// ファイル情報へのポインタ
	} U16;
};


long	_AskDrive( long DriveNo, struct DINF * );
long	_RegistDriveDriver( long DriveNo, struct DINF * );


