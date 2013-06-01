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
	TJS_W("スクリプトで例外が発生しました"));

TVP_MSG_DECL(TVPHardwareExceptionRaised,
	TJS_W("ハードウェア例外が発生しました"));

TVP_MSG_DECL(TVPMainCDPName,
	TJS_W("スクリプトエディタ (メイン)"));

TVP_MSG_DECL(TVPExceptionCDPName,
	TJS_W("スクリプトエディタ (例外通知)"));

TVP_MSG_DECL(TVPCannnotLocateUIDLLForFolderSelection,
	TJS_W("フォルダ/アーカイブの選択画面を表示しようとしましたが ")
		TJS_W("krdevui.dll が見つからないので表示できません.\n")
		TJS_W("実行するフォルダ/アーカイブはコマンドラインの引数として指定してください"));

TVP_MSG_DECL(TVPInvalidUIDLL,
	TJS_W("krdevui.dll が異常か、バージョンが一致しません"));

TVP_MSG_DECL(TVPInvalidBPP,
	TJS_W("無効な色深度です"));

TVP_MSG_DECL(TVPCannotLoadPlugin,
	TJS_W("プラグイン %1 を読み込めません"));

TVP_MSG_DECL(TVPNotValidPlugin,
	TJS_W("%1 は有効なプラグインではありません"));

TVP_MSG_DECL(TVPPluginUninitFailed,
	TJS_W("プラグインの解放に失敗しました"));

TVP_MSG_DECL(TVPCannnotLinkPluginWhilePluginLinking,
	TJS_W("プラグインの接続中に他のプラグインを接続することはできまません"));

TVP_MSG_DECL(TVPNotSusiePlugin,
	TJS_W("異常な Susie プラグインです"));

TVP_MSG_DECL(TVPSusiePluginError,
	TJS_W("Susie プラグインでエラーが発生しました/エラーコード %1"));

TVP_MSG_DECL(TVPCannotReleasePlugin,
	TJS_W("指定されたプラグインは使用中のため解放できません"));

TVP_MSG_DECL(TVPNotLoadedPlugin,
	TJS_W("%1 は読み込まれていません"));

TVP_MSG_DECL(TVPCannotAllocateBitmapBits,
	TJS_W("ビットマップ用メモリを確保できません/%1(size=%2)"));

TVP_MSG_DECL(TVPScanLineRangeOver,
	TJS_W("スキャンライン %1 は範囲(0～%2)を超えています"));

TVP_MSG_DECL(TVPPluginError,
	TJS_W("プラグインでエラーが発生しました/%1"));

TVP_MSG_DECL(TVPInvalidCDDADrive,
	TJS_W("指定されたドライブでは CD-DA を再生できません"));

TVP_MSG_DECL(TVPCDDADriveNotFound,
	TJS_W("CD-DA を再生できるドライブが見つかりません"));

TVP_MSG_DECL(TVPMCIError,
	TJS_W("MCI でエラーが発生しました : %1"));

TVP_MSG_DECL(TVPInvalidSMF,
	TJS_W("有効な SMF ファイルではありません : %1"));

TVP_MSG_DECL(TVPMalformedMIDIMessage,
	TJS_W("指定されたメッセージは MIDI メッセージとして有効な形式ではありません"));

TVP_MSG_DECL(TVPCannotInitDirectSound,
	TJS_W("DirectSound を初期化できません : %1"));

TVP_MSG_DECL(TVPCannotCreateDSSecondaryBuffer,
	TJS_W("DirectSound セカンダリバッファを作成できません : %1/%2"));

TVP_MSG_DECL(TVPInvalidLoopInformation,
	TJS_W("ループ情報 %1 は異常です"));

TVP_MSG_DECL(TVPNotChildMenuItem,
	TJS_W("指定されたメニュー項目はこのメニュー項目の子ではありません"));

TVP_MSG_DECL(TVPCannotInitDirectDraw,
	TJS_W("DirectDraw を初期化できません : %1"));

TVP_MSG_DECL(TVPCannotFindDisplayMode,
	TJS_W("適合する画面モードが見つかりません : %1"));

TVP_MSG_DECL(TVPCannotSwitchToFullScreen,
	TJS_W("フルスクリーンに切り替えられません : %1"));

TVP_MSG_DECL(TVPInvalidPropertyInFullScreen,
	TJS_W("フルスクリーン中では操作できないプロパティを設定しようとしました"));

TVP_MSG_DECL(TVPInvalidMethodInFullScreen,
	TJS_W("フルスクリーン中では操作できないメソッドを呼び出そうとしました"));

TVP_MSG_DECL(TVPCannotLoadCursor,
	TJS_W("マウスカーソル %1 の読み込みに失敗しました"));

TVP_MSG_DECL(TVPCannotLoadKrMovieDLL,
	TJS_W("ビデオ/Shockwave Flash を再生するためには krmovie.dll / krflash.dll ")
		TJS_W("が必要ですが 読み込むことができません"));

TVP_MSG_DECL(TVPInvalidKrMovieDLL,
	TJS_W("krmovie.dll/krflash.dll が異常か 対応できないバージョンです"));

TVP_MSG_DECL(TVPErrorInKrMovieDLL,
	TJS_W("krmovie.dll/krflash.dll 内でエラーが発生しました/%1"));

TVP_MSG_DECL(TVPWindowAlreadyMissing,
	TJS_W("ウィンドウはすでに存在していません"));

TVP_MSG_DECL(TVPPrerenderedFontMappingFailed,
	TJS_W("レンダリング済みフォントのマッピングに失敗しました : %1"));

TVP_MSG_DECL_CONST(TVPConfigFailOriginalFileCannotBeRewritten,
	TJS_W("%1 に書き込みできません。ソフトウェアが実行中のままになっていないか、あるいは")
		TJS_W("書き込み権限があるかどうかを確認してください"));

TVP_MSG_DECL(TVPConfigFailTempExeNotErased,
	TJS_W("%1 の終了を確認できないため、これを削除できませんでした(このファイルは削除して結構です)"));

TVP_MSG_DECL_CONST(TVPExecutionFail,
	TJS_W("%1 を実行できません"));

TVP_MSG_DECL(TVPPluginUnboundFunctionError,
	TJS_W("プラグインから関数 %1 を要求されましたが、その関数は本体内に存在しません。プラグインと")
			TJS_W("本体のバージョンが正しく対応しているか確認してください"));

TVP_MSG_DECL(TVPExceptionHadBeenOccured,
	TJS_W(" = (例外発生)"));

TVP_MSG_DECL(TVPConsoleResult,
	TJS_W("コンソール : "));


//---------------------------------------------------------------------------



#endif
