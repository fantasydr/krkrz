//---------------------------------------------------------------------------
/*
	TVP2 ( T Visual Presenter 2 )  A script authoring tool
	Copyright (C) 2000 W.Dee <dee@kikyou.info> and contributors

	See details of license at "license.txt"
*/
//---------------------------------------------------------------------------
// Definition of Messages and Message Related Utilities
//---------------------------------------------------------------------------
#ifndef MsgImplH
#define MsgImplH

#include "tjsMessage.h"
#include "MsgIntf.h"

#ifndef TVP_MSG_DECL
	#define TVP_MSG_DECL(name, msg) extern tTJSMessageHolder name;
#endif

//---------------------------------------------------------------------------
// Message Strings ( these should be localized )
//---------------------------------------------------------------------------
// Japanese localized messages
TVP_MSG_DECL(TVPScriptExceptionRaised,
	TJS_W("スクリプトで箭翌が�k伏しました"));

TVP_MSG_DECL(TVPHardwareExceptionRaised,
	TJS_W("ハ�`ドウェア箭翌が�k伏しました"));

TVP_MSG_DECL(TVPMainCDPName,
	TJS_W("スクリプトエディタ (メイン)"));

TVP_MSG_DECL(TVPExceptionCDPName,
	TJS_W("スクリプトエディタ (箭翌宥岑)"));

TVP_MSG_DECL(TVPCannnotLocateUIDLLForFolderSelection,
	TJS_W("フォルダ/ア�`カイブの�x�k鮫中を燕幣しようとしましたが ")
		TJS_W("krdevui.dll が��つからないので燕幣できません.\n")
		TJS_W("�g佩するフォルダ/ア�`カイブはコマンドラインの哈方として峺協してください"));

TVP_MSG_DECL(TVPInvalidUIDLL,
	TJS_W("krdevui.dll が��械か、バ�`ジョンが匯崑しません"));

TVP_MSG_DECL(TVPInvalidBPP,
	TJS_W("�o�燭壁�侮業です"));

TVP_MSG_DECL(TVPCannotLoadPlugin,
	TJS_W("プラグイン %1 を�iみ�zめません"));

TVP_MSG_DECL(TVPNotValidPlugin,
	TJS_W("%1 は嗤�燭淵廛薀哀ぅ鵑任呂△蠅泙擦�"));

TVP_MSG_DECL(TVPPluginUninitFailed,
	TJS_W("プラグインの盾慧に払�，靴泙靴�"));

TVP_MSG_DECL(TVPCannnotLinkPluginWhilePluginLinking,
	TJS_W("プラグインの俊�A嶄に麿のプラグインを俊�Aすることはできまません"));

TVP_MSG_DECL(TVPNotSusiePlugin,
	TJS_W("��械な Susie プラグインです"));

TVP_MSG_DECL(TVPSusiePluginError,
	TJS_W("Susie プラグインでエラ�`が�k伏しました/エラ�`コ�`ド %1"));

TVP_MSG_DECL(TVPCannotReleasePlugin,
	TJS_W("峺協されたプラグインは聞喘嶄のため盾慧できません"));

TVP_MSG_DECL(TVPNotLoadedPlugin,
	TJS_W("%1 は�iみ�zまれていません"));

TVP_MSG_DECL(TVPCannotAllocateBitmapBits,
	TJS_W("ビットマップ喘メモリを�_隠できません/%1(size=%2)"));

TVP_MSG_DECL(TVPScanLineRangeOver,
	TJS_W("スキャンライン %1 は����(0゛%2)を階えています"));

TVP_MSG_DECL(TVPPluginError,
	TJS_W("プラグインでエラ�`が�k伏しました/%1"));

TVP_MSG_DECL(TVPInvalidCDDADrive,
	TJS_W("峺協されたドライブでは CD-DA を壅伏できません"));

TVP_MSG_DECL(TVPCDDADriveNotFound,
	TJS_W("CD-DA を壅伏できるドライブが��つかりません"));

TVP_MSG_DECL(TVPMCIError,
	TJS_W("MCI でエラ�`が�k伏しました : %1"));

TVP_MSG_DECL(TVPInvalidSMF,
	TJS_W("嗤�燭� SMF ファイルではありません : %1"));

TVP_MSG_DECL(TVPMalformedMIDIMessage,
	TJS_W("峺協されたメッセ�`ジは MIDI メッセ�`ジとして嗤�燭偏諒修任呂△蠅泙擦�"));

TVP_MSG_DECL(TVPCannotInitDirectSound,
	TJS_W("DirectSound を兜豚晒できません : %1"));

TVP_MSG_DECL(TVPCannotCreateDSSecondaryBuffer,
	TJS_W("DirectSound セカンダリバッファを恬撹できません : %1/%2"));

TVP_MSG_DECL(TVPInvalidLoopInformation,
	TJS_W("ル�`プ秤�� %1 は��械です"));

TVP_MSG_DECL(TVPNotChildMenuItem,
	TJS_W("峺協されたメニュ�`��朕はこのメニュ�`��朕の徨ではありません"));

TVP_MSG_DECL(TVPCannotInitDirectDraw,
	TJS_W("DirectDraw を兜豚晒できません : %1"));

TVP_MSG_DECL(TVPCannotFindDisplayMode,
	TJS_W("�m栽する鮫中モ�`ドが��つかりません : %1"));

TVP_MSG_DECL(TVPCannotSwitchToFullScreen,
	TJS_W("フルスクリ�`ンに俳り紋えられません : %1"));

TVP_MSG_DECL(TVPInvalidPropertyInFullScreen,
	TJS_W("フルスクリ�`ン嶄では荷恬できないプロパティを�O協しようとしました"));

TVP_MSG_DECL(TVPInvalidMethodInFullScreen,
	TJS_W("フルスクリ�`ン嶄では荷恬できないメソッドを柵び竃そうとしました"));

TVP_MSG_DECL(TVPCannotLoadCursor,
	TJS_W("マウスカ�`ソル %1 の�iみ�zみに払�，靴泙靴�"));

TVP_MSG_DECL(TVPCannotLoadKrMovieDLL,
	TJS_W("ビデオ/Shockwave Flash を壅伏するためには krmovie.dll / krflash.dll ")
		TJS_W("が駅勣ですが �iみ�zむことができません"));

TVP_MSG_DECL(TVPInvalidKrMovieDLL,
	TJS_W("krmovie.dll/krflash.dll が��械か ��鬉任�ないバ�`ジョンです"));

TVP_MSG_DECL(TVPErrorInKrMovieDLL,
	TJS_W("krmovie.dll/krflash.dll 坪でエラ�`が�k伏しました/%1"));

TVP_MSG_DECL(TVPWindowAlreadyMissing,
	TJS_W("ウィンドウはすでに贋壓していません"));

TVP_MSG_DECL(TVPPrerenderedFontMappingFailed,
	TJS_W("レンダリング�gみフォントのマッピングに払�，靴泙靴� : %1"));

TVP_MSG_DECL_CONST(TVPConfigFailOriginalFileCannotBeRewritten,
	TJS_W("%1 に��き�zみできません。ソフトウェアが�g佩嶄のままになっていないか、あるいは")
		TJS_W("��き�zみ�慙泙�あるかどうかを�_�Jしてください"));

TVP_MSG_DECL(TVPConfigFailTempExeNotErased,
	TJS_W("%1 の�K阻を�_�Jできないため、これを��茅できませんでした(このファイルは��茅して�Y��です)"));

TVP_MSG_DECL_CONST(TVPExecutionFail,
	TJS_W("%1 を�g佩できません"));

TVP_MSG_DECL(TVPPluginUnboundFunctionError,
	TJS_W("プラグインから�v方 %1 を勣箔されましたが、その�v方は云悶坪に贋壓しません。プラグインと")
			TJS_W("云悶のバ�`ジョンが屎しく��鬉靴討い襪��_�Jしてください"));

TVP_MSG_DECL(TVPExceptionHadBeenOccured,
	TJS_W(" = (箭翌�k伏)"));

TVP_MSG_DECL(TVPConsoleResult,
	TJS_W("コンソ�`ル : "));


//---------------------------------------------------------------------------



#endif
