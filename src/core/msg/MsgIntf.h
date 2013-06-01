//---------------------------------------------------------------------------
/*
	TVP2 ( T Visual Presenter 2 )  A script authoring tool
	Copyright (C) 2000 W.Dee <dee@kikyou.info> and contributors

	See details of license at "license.txt"
*/
//---------------------------------------------------------------------------
// Definition of Messages and Message Related Utilities
//---------------------------------------------------------------------------
#ifndef MsgIntfH
#define MsgIntfH

#include "tjs.h"
#include "tjsMessage.h"

#ifndef TVP_MSG_DECL
	#define TVP_MSG_DECL(name, msg) extern tTJSMessageHolder name;
	#define TVP_MSG_DECL_CONST(name, msg) extern tTJSMessageHolder name;
#endif

#include "MsgImpl.h"
#include "svn_revision.h"

#define WIDEN2(x) L ## x
#define WIDEN(x) WIDEN2(x)
//---------------------------------------------------------------------------
// Message Strings ( these should be localized )
//---------------------------------------------------------------------------
// Japanese localized messages
TVP_MSG_DECL_CONST(TVPAboutString,
	
TJS_W("吉里吉里[きりきり] 2 実行コア version %1 ( TJS version %2 )\n")
TJS_W("Compiled on ") WIDEN(__DATE__) TJS_W(" ") WIDEN(__TIME__) TJS_W("\n")
TJS_W("SVN Revision: ") TVP_SVN_REVISION TJS_W("\n")
TJS_W("Copyright (C) 1997-2012 W.Dee and contributors All rights reserved.\n")
TJS_W("Contributors in alphabetical order:\n")
TJS_W("  Go Watanabe, Kenjo, Kiyobee, Kouhei Yanagita, mey, MIK, Takenori Imoto, yun\n")
TJS_W("吉里吉里実行コアの使用/配布/改変は、\n")
TJS_W("SDK 付属の license.txt に書かれているライセンスに従って行うことができます.\n")
TJS_W("------------------------------------------------------------------------------\n")
TJS_W("Thanks for many libraries, contributers and supporters not listible here.\n")
TJS_W("This software is based in part on the work of Independent JPEG Group.\n")
TJS_W("Regex++ Copyright (c) 1998-2003 Dr John Maddock\n")
TJS_W("ERINA-Library Copyright (C) 2001 Leshade Entis, Entis-soft.\n")
TJS_W("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n")
TJS_W("Using \"A C-program for MT19937\"\n")
TJS_W("\n")
TJS_W("   Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura,\n")
TJS_W("   All rights reserved.\n")
TJS_W("\n")
TJS_W("   Redistribution and use in source and binary forms, with or without\n")
TJS_W("   modification, are permitted provided that the following conditions\n")
TJS_W("   are met:\n")
TJS_W("\n")
TJS_W("     1. Redistributions of source code must retain the above copyright\n")
TJS_W("        notice, this list of conditions and the following disclaimer.\n")
TJS_W("\n")
TJS_W("     2. Redistributions in binary form must reproduce the above copyright\n")
TJS_W("        notice, this list of conditions and the following disclaimer in the\n")
TJS_W("        documentation and/or other materials provided with the distribution.\n")
TJS_W("\n")
TJS_W("     3. The names of its contributors may not be used to endorse or promote\n")
TJS_W("        products derived from this software without specific prior written\n")
TJS_W("        permission.\n")
TJS_W("\n")
TJS_W("   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS\n")
TJS_W("   \"AS IS\" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT\n")
TJS_W("   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR\n")
TJS_W("   A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR\n")
TJS_W("   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,\n")
TJS_W("   EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,\n")
TJS_W("   PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR\n")
TJS_W("   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF\n")
TJS_W("   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING\n")
TJS_W("   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS\n")
TJS_W("   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.\n")
TJS_W("------------------------------------------------------------------------------\n")
TJS_W("環境情報\n")
  // important log (environment information, Debug.notice etc.) comes here
);

TVP_MSG_DECL_CONST(TVPVersionInformation,
	
TJS_W("吉里吉里[きりきり] 2 実行コア/%1 ")
TJS_W("(SVN revision:") TVP_SVN_REVISION TJS_W("; Compiled on ") WIDEN(__DATE__) TJS_W(" ") WIDEN(__TIME__) TJS_W(") TJS2/%2 ")
TJS_W("Copyright (C) 1997-2012 W.Dee and contributors All rights reserved."));

TVP_MSG_DECL_CONST(TVPVersionInformation2,
	TJS_W("バージョン情報の詳細は Ctrl + F12 で閲覧できます"));

TVP_MSG_DECL_CONST(TVPDownloadPageURL,
	TJS_W("http://kikyou.info/tvp/"));

TVP_MSG_DECL(TVPInternalError,
	TJS_W("内部エラーが発生しました: at %1 line %2"));

TVP_MSG_DECL(TVPInvalidParam,
	TJS_W("不正なパラメータです"));

TVP_MSG_DECL(TVPWarnDebugOptionEnabled,
	TJS_W("-debug オプションが指定されているため、現在 吉里吉里はデバッグモードで動作しています。デバッグモードでは十分な実行速度が出ない場合があるので注意してください"));

TVP_MSG_DECL(TVPCommandLineParamIgnoredAndDefaultUsed,
	TJS_W("コマンドラインパラメータ %1 に指定された値 %2 は無効のためデフォルトの設定を用います"));

TVP_MSG_DECL(TVPInvalidCommandLineParam,
	TJS_W("コマンドラインパラメータ %1 に指定された値 %2 は無効です"));

TVP_MSG_DECL(TVPNotImplemented,
	TJS_W("未実装の機能を呼び出そうとしました"));

TVP_MSG_DECL(TVPCannotOpenStorage,
	TJS_W("ストレージ %1 を開くことができません"));

TVP_MSG_DECL(TVPCannotFindStorage,
	TJS_W("ストレージ %1 が見つかりません"));

TVP_MSG_DECL(TVPCannotOpenStorageForWrite,
	TJS_W("ストレージ %1 を書き込み用に開くことができません。ファイルが書き込み禁止になっていないか、あるいはファイルに書き込み権限があるかどうか、あるいはそもそもそれが書き込み可能なメディアやファイルなのかを確認してください"));

TVP_MSG_DECL(TVPStorageInArchiveNotFound,
	TJS_W("ストレージ %1 がアーカイブ %2 の中に見つかりません"));

TVP_MSG_DECL(TVPInvalidPathName,
	TJS_W("パス名 %1 は無効な形式です。形式が正しいかどうかを確認してください"));

TVP_MSG_DECL(TVPUnsupportedMediaName,
	TJS_W("\"%1\" は対応していないメディアタイプです"));

TVP_MSG_DECL(TVPCannotUnbindXP3EXE,
	TJS_W("%1 は実行可能ファイルに見えますが、これに結合されたアーカイブを発見できませんでした"));

TVP_MSG_DECL(TVPCannotFindXP3Mark,
	TJS_W("%1 は XP3 アーカイブではないか、対応できない形式です。アーカイブファイルを指定すべき場面で通常のファイルを指定した場合、あるいは対応できないアーカイブファイルを指定した場合などにこのエラーが発生しますので、確認してください"));

TVP_MSG_DECL(TVPMissingPathDelimiterAtLast,
	TJS_W("パス名の最後には '>' または '/' を指定してください (吉里吉里２ 2.19 beta 14 よりアーカイブの区切り記号が '#' から '>' に変わりました)"));

TVP_MSG_DECL(TVPFilenameContainsSharpWarn,
	TJS_W("(注意) '#' がファイル名 \"%1\" に含まれています。アーカイブの区切り文字は吉里吉里２ 2.19 beta 14 より'#' から '>' に変わりました。")
	TJS_W("もしアーカイブの区切り文字のつもりで '#' を使用した場合は、お手数ですが '>' に変えてください"));

TVP_MSG_DECL(TVPCannotGetLocalName,
	TJS_W("ストレージ名 %1 をローカルファイル名に変換できません。アーカイブファイル内のファイルや、ローカルファイルでないファイルはローカルファイル名に変換できません。"));

TVP_MSG_DECL(TVPReadError,
	TJS_W("読み込みエラーです。ファイルが破損している可能性や、デバイスからの読み込みに失敗した可能性があります"));

TVP_MSG_DECL(TVPWriteError,
	TJS_W("書き込みエラーです"));

TVP_MSG_DECL(TVPSeekError,
	TJS_W("シークに失敗しました。ファイルが破損している可能性や、デバイスからの読み込みに失敗した可能性があります"));

TVP_MSG_DECL(TVPTruncateError,
	TJS_W("ファイルの長さを切り詰めるのに失敗しました"));

TVP_MSG_DECL(TVPInsufficientMemory,
	TJS_W("メモリ確保に失敗しました。"));

TVP_MSG_DECL(TVPUncompressionFailed,
	TJS_W("ファイルの展開に失敗しました。未対応の圧縮形式が指定されたか、あるいはファイルが破損している可能性があります"));

TVP_MSG_DECL(TVPCompressionFailed,
	TJS_W("ファイルの圧縮に失敗しました"));

TVP_MSG_DECL(TVPCannotWriteToArchive,
	TJS_W("アーカイブにデータを書き込むことはできません"));

TVP_MSG_DECL(TVPUnsupportedCipherMode,
	TJS_W("%1 は未対応の暗号化形式か、データが破損しています"));

TVP_MSG_DECL(TVPUnsupportedModeString,
	TJS_W("認識できないモード文字列の指定です(%1)"));

TVP_MSG_DECL(TVPUnknownGraphicFormat,
	TJS_W("%1 は未知の画像形式です"));

TVP_MSG_DECL(TVPCannotSuggestGraphicExtension,
	TJS_W("%1 について適切な拡張子を持ったファイルを見つけられませんでした"));

TVP_MSG_DECL(TVPMaskSizeMismatch,
	TJS_W("マスク画像のサイズがメイン画像のサイズと違います"));

TVP_MSG_DECL(TVPProvinceSizeMismatch,
	TJS_W("領域画像 %1 はメイン画像とサイズが違います"));

TVP_MSG_DECL(TVPImageLoadError,
	TJS_W("画像読み込み中にエラーが発生しました/%1"));

TVP_MSG_DECL(TVPJPEGLoadError,
	TJS_W("JPEG 読み込み中にエラーが発生しました/%1"));

TVP_MSG_DECL(TVPPNGLoadError,
	TJS_W("PNG 読み込み中にエラーが発生しました/%1"));

TVP_MSG_DECL(TVPERILoadError,
	TJS_W("ERI 読み込み中にエラーが発生しました/%1"));

TVP_MSG_DECL(TVPTLGLoadError,
	TJS_W("TLG 読み込み中にエラーが発生しました/%1"));

TVP_MSG_DECL(TVPInvalidImageSaveType,
	TJS_W("無効な保存画像形式です(%1)"));

TVP_MSG_DECL(TVPInvalidOperationFor8BPP,
	TJS_W("8bpp 画像に対しては行えない操作を行おうとしました"));

TVP_MSG_DECL(TVPSpecifyWindow,
	TJS_W("Window クラスのオブジェクトを指定してください"));

TVP_MSG_DECL(TVPSpecifyLayer,
	TJS_W("Layer クラスのオブジェクトを指定してください"));

TVP_MSG_DECL(TVPCannotCreateEmptyLayerImage,
	TJS_W("画像サイズの横幅あるいは縦幅を 0 以下の数に設定することはできません"));

TVP_MSG_DECL(TVPCannotSetPrimaryInvisible,
	TJS_W("プライマリレイヤは不可視にできません"));

TVP_MSG_DECL(TVPCannotMovePrimary,
	TJS_W("プライマリレイヤは移動できません"));

TVP_MSG_DECL(TVPCannotSetParentSelf,
	TJS_W("自分自身を親とすることはできません"));

TVP_MSG_DECL(TVPCannotMoveNextToSelfOrNotSiblings,
	TJS_W("自分自身の前後や親の異なるレイヤの前後に移動することはできません"));

TVP_MSG_DECL(TVPCannotMovePrimaryOrSiblingless,
	TJS_W("プライマリレイヤや兄弟の無いレイヤは前後に移動することはできません"));

TVP_MSG_DECL(TVPCannotMoveToUnderOtherPrimaryLayer,
	TJS_W("別のプライマリレイヤ下にレイヤを移動することはできません"));

TVP_MSG_DECL(TVPInvalidImagePosition,
	TJS_W("レイヤ領域に画像の無い領域が発生しました"));

TVP_MSG_DECL(TVPCannotSetModeToDisabledOrModal,
	TJS_W("すでにモーダルなレイヤの親レイヤ、あるいは不可視/無効なレイヤをモーダルにすることはできません"));

TVP_MSG_DECL(TVPNotDrawableLayerType,
	TJS_W("この type のレイヤでは描画や画像読み込みや画像サイズ/位置の変更/取得はできません"));

TVP_MSG_DECL(TVPSourceLayerHasNoImage,
	TJS_W("転送元レイヤは画像を持っていません"));

TVP_MSG_DECL(TVPUnsupportedLayerType,
	TJS_W("%1 はこの type のレイヤでは使用できません"));

TVP_MSG_DECL(TVPNotDrawableFaceType,
	TJS_W("%1 ではこの face に描画できません"));

TVP_MSG_DECL(TVPCannotConvertLayerTypeUsingGivenDirection,
	TJS_W("指定されたレイヤタイプ変換はできません"));

TVP_MSG_DECL(TVPNegativeOpacityNotSupportedOnThisFace,
	TJS_W("負の不透明度はこの face では指定できません"));

TVP_MSG_DECL(TVPSrcRectOutOfBitmap,
	TJS_W("転送元がビットマップ外の領域を含んでいます。正しい範囲に収まるように転送元を指定してください"));

TVP_MSG_DECL(TVPBoxBlurAreaMustContainCenterPixel,
	TJS_W("矩形ブラーの範囲は必ず(0,0)をその中に含む必要があります。leftとrightが両方とも正の数値、あるいは両方とも負の数値という指定はできません(topとbottomに対しても同様)"));

TVP_MSG_DECL(TVPBoxBlurAreaMustBeSmallerThan16Million,
	TJS_W("矩形ブラーの範囲が大きすぎます。矩形ブラーの範囲は1677万以下である必要があります"));

TVP_MSG_DECL(TVPCannotChangeFocusInProcessingFocus,
	TJS_W("フォーカス変更処理中はフォーカスを新たに変更することはできません"));

TVP_MSG_DECL(TVPWindowHasNoLayer,
	TJS_W("ウィンドウにレイヤがありません"));

TVP_MSG_DECL(TVPWindowHasAlreadyPrimaryLayer,
	TJS_W("ウィンドウにはすでにプライマリレイヤがあります"));

TVP_MSG_DECL(TVPSpecifiedEventNeedsParameter,
	TJS_W("イベント %1 にはパラメータが必要です"));

TVP_MSG_DECL(TVPSpecifiedEventNeedsParameter2,
	TJS_W("イベント %1 にはパラメータ %2 が必要です"));

TVP_MSG_DECL(TVPSpecifiedEventNameIsUnknown,
	TJS_W("イベント名 %1 は未知のイベント名です"));

TVP_MSG_DECL(TVPOutOfRectangle,
	TJS_W("矩形外を指定されました"));

TVP_MSG_DECL(TVPInvalidMethodInUpdating,
	TJS_W("画面更新中はこの機能を実行できません"));

TVP_MSG_DECL(TVPCannotCreateInstance,
	TJS_W("このクラスはインスタンスを作成できません"));

TVP_MSG_DECL(TVPUnknownWaveFormat,
	TJS_W("%1 は対応できない Wave 形式です"));

TVP_MSG_DECL(TVPCurrentTransitionMustBeStopping,
	TJS_W("現在のトランジションを停止させてから新しいトランジションを開始してください。同じレイヤに対して複数のトランジションを同時に実行しようとするとこのエラーが発生します"));

TVP_MSG_DECL(TVPTransHandlerError,
	TJS_W("トランジションハンドラでエラーが発生しました : %1"));

TVP_MSG_DECL(TVPTransAlreadyRegistered,
	TJS_W("トランジション %1 は既に登録されています"));

TVP_MSG_DECL(TVPCannotFindTransHander,
	TJS_W("トランジションハンドラ %1 が見つかりません"));

TVP_MSG_DECL(TVPSpecifyTransitionSource,
	TJS_W("トランジション元を指定してください"));

TVP_MSG_DECL(TVPLayerCannotHaveImage,
	TJS_W("このレイヤは画像を持つことはできません"));

TVP_MSG_DECL(TVPTransitionSourceAndDestinationMustHaveImage,
	TJS_W("トランジション元とトランジション先はともに画像を持っている必要があります"));

TVP_MSG_DECL(TVPCannotLoadRuleGraphic,
	TJS_W("ルール画像 %1 を読み込むことができません"));

TVP_MSG_DECL(TVPSpecifyOption,
	TJS_W("オプション %1 を指定してください"));

TVP_MSG_DECL(TVPTransitionLayerSizeMismatch,
	TJS_W("トランジション元(%1)とトランジション先(%2)のレイヤのサイズが一致しません"));

TVP_MSG_DECL(TVPTransitionMutualSource,
	TJS_W("トランジション元のトランジション元が自分自身です"));

TVP_MSG_DECL(TVPHoldDestinationAlphaParameterIsNowDeprecated,
	TJS_W("警告 : メソッド %1 の %2 番目に渡された hda パラメータは、吉里吉里２ 2.23 beta 2 より無視されるようになりました。代わりに Layer.holdAlpha プロパティを用いてください。"));

TVP_MSG_DECL(TVPCannotConnectMultipleWaveSoundBufferAtOnce,
	TJS_W("複数の WaveSoundBuffer を一つのフィルタで同時に使用することはできません"));

TVP_MSG_DECL(TVPInvalidWindowSizeMustBeIn64to32768,
	TJS_W("window は 64～32768 の範囲の 2 の累乗で無ければなりません"));

TVP_MSG_DECL(TVPInvalidOverlapCountMustBeIn2to32,
	TJS_W("overlap は 2～32 の範囲の 2 の累乗で無ければなりません"));


//---------------------------------------------------------------------------
// Utility Functions
//---------------------------------------------------------------------------
TJS_EXP_FUNC_DEF(ttstr, TVPFormatMessage, (const tjs_char *msg, const ttstr & p1));
TJS_EXP_FUNC_DEF(ttstr, TVPFormatMessage, (const tjs_char *msg, const ttstr & p1,
	const ttstr & p2));
TJS_EXP_FUNC_DEF(void, TVPThrowExceptionMessage, (const tjs_char *msg));
TJS_EXP_FUNC_DEF(void, TVPThrowExceptionMessage, (const tjs_char *msg,
	const ttstr &p1, tjs_int num));
TJS_EXP_FUNC_DEF(void, TVPThrowExceptionMessage, (const tjs_char *msg, const ttstr &p1));
TJS_EXP_FUNC_DEF(void, TVPThrowExceptionMessage, (const tjs_char *msg,
	const ttstr & p1, const ttstr & p2));

TJS_EXP_FUNC_DEF(ttstr, TVPGetAboutString, ());
TJS_EXP_FUNC_DEF(ttstr, TVPGetVersionInformation, ());
TJS_EXP_FUNC_DEF(ttstr, TVPGetVersionString, ());

#define TVPThrowInternalError \
	TVPThrowExceptionMessage(TVPInternalError, __FILE__,  __LINE__)
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
// version retrieving
//---------------------------------------------------------------------------
extern tjs_int TVPVersionMajor;
extern tjs_int TVPVersionMinor;
extern tjs_int TVPVersionRelease;
extern tjs_int TVPVersionBuild;
//---------------------------------------------------------------------------
extern void TVPGetVersion();
/*
	implement in each platforms;
	fill these four version field.
*/
//---------------------------------------------------------------------------
TJS_EXP_FUNC_DEF(void, TVPGetSystemVersion, (tjs_int &major, tjs_int &minor,
	tjs_int &release, tjs_int &build));
TJS_EXP_FUNC_DEF(void, TVPGetTJSVersion, (tjs_int &major, tjs_int &minor,
	tjs_int &release));
//---------------------------------------------------------------------------


#endif
