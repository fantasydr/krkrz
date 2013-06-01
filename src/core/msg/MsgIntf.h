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
	
TJS_W("���Ｊ��[���꤭��] 2 �g�Х��� version %1 ( TJS version %2 )\n")
TJS_W("Compiled on ") WIDEN(__DATE__) TJS_W(" ") WIDEN(__TIME__) TJS_W("\n")
TJS_W("SVN Revision: ") TVP_SVN_REVISION TJS_W("\n")
TJS_W("Copyright (C) 1997-2012 W.Dee and contributors All rights reserved.\n")
TJS_W("Contributors in alphabetical order:\n")
TJS_W("  Go Watanabe, Kenjo, Kiyobee, Kouhei Yanagita, mey, MIK, Takenori Imoto, yun\n")
TJS_W("���Ｊ��g�Х�����ʹ��/�䲼/�ĉ�ϡ�\n")
TJS_W("SDK ������ license.txt �˕�����Ƥ���饤���󥹤ˏ��ä��Ф����Ȥ��Ǥ��ޤ�.\n")
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
TJS_W("�h�����\n")
  // important log (environment information, Debug.notice etc.) comes here
);

TVP_MSG_DECL_CONST(TVPVersionInformation,
	
TJS_W("���Ｊ��[���꤭��] 2 �g�Х���/%1 ")
TJS_W("(SVN revision:") TVP_SVN_REVISION TJS_W("; Compiled on ") WIDEN(__DATE__) TJS_W(" ") WIDEN(__TIME__) TJS_W(") TJS2/%2 ")
TJS_W("Copyright (C) 1997-2012 W.Dee and contributors All rights reserved."));

TVP_MSG_DECL_CONST(TVPVersionInformation2,
	TJS_W("�Щ`���������Ԕ���� Ctrl + F12 ����E�Ǥ��ޤ�"));

TVP_MSG_DECL_CONST(TVPDownloadPageURL,
	TJS_W("http://kikyou.info/tvp/"));

TVP_MSG_DECL(TVPInternalError,
	TJS_W("�ڲ�����`���k�����ޤ���: at %1 line %2"));

TVP_MSG_DECL(TVPInvalidParam,
	TJS_W("�����ʥѥ��`���Ǥ�"));

TVP_MSG_DECL(TVPWarnDebugOptionEnabled,
	TJS_W("-debug ���ץ����ָ������Ƥ��뤿�ᡢ�F�� ���Ｊ��ϥǥХå���`�ɤǄ������Ƥ��ޤ����ǥХå���`�ɤǤ�ʮ�֤ʌg���ٶȤ����ʤ����Ϥ�����Τ�ע�⤷�Ƥ�������"));

TVP_MSG_DECL(TVPCommandLineParamIgnoredAndDefaultUsed,
	TJS_W("���ޥ�ɥ饤��ѥ��`�� %1 ��ָ�����줿�� %2 �ϟo���Τ���ǥե���Ȥ��O�����ä��ޤ�"));

TVP_MSG_DECL(TVPInvalidCommandLineParam,
	TJS_W("���ޥ�ɥ饤��ѥ��`�� %1 ��ָ�����줿�� %2 �ϟo���Ǥ�"));

TVP_MSG_DECL(TVPNotImplemented,
	TJS_W("δ�gװ�ΙC�ܤ���ӳ������Ȥ��ޤ���"));

TVP_MSG_DECL(TVPCannotOpenStorage,
	TJS_W("���ȥ�`�� %1 ���_�����Ȥ��Ǥ��ޤ���"));

TVP_MSG_DECL(TVPCannotFindStorage,
	TJS_W("���ȥ�`�� %1 ��Ҋ�Ĥ���ޤ���"));

TVP_MSG_DECL(TVPCannotOpenStorageForWrite,
	TJS_W("���ȥ�`�� %1 ������z���ä��_�����Ȥ��Ǥ��ޤ��󡣥ե����뤬�����z�߽�ֹ�ˤʤäƤ��ʤ��������뤤�ϥե�����˕����z�ߘ��ޤ����뤫�ɤ��������뤤�Ϥ��⤽�⤽�줬�����z�߿��ܤʥ�ǥ�����ե�����ʤΤ���_�J���Ƥ�������"));

TVP_MSG_DECL(TVPStorageInArchiveNotFound,
	TJS_W("���ȥ�`�� %1 �����`������ %2 ���Ф�Ҋ�Ĥ���ޤ���"));

TVP_MSG_DECL(TVPInvalidPathName,
	TJS_W("�ѥ��� %1 �ϟo������ʽ�Ǥ�����ʽ�����������ɤ�����_�J���Ƥ�������"));

TVP_MSG_DECL(TVPUnsupportedMediaName,
	TJS_W("\"%1\" �ό��ꤷ�Ƥ��ʤ���ǥ��������פǤ�"));

TVP_MSG_DECL(TVPCannotUnbindXP3EXE,
	TJS_W("%1 �όg�п��ܥե������Ҋ���ޤ���������˽Y�Ϥ��줿���`�����֤�kҊ�Ǥ��ޤ���Ǥ���"));

TVP_MSG_DECL(TVPCannotFindXP3Mark,
	TJS_W("%1 �� XP3 ���`�����֤ǤϤʤ���������Ǥ��ʤ���ʽ�Ǥ������`�����֥ե������ָ�����٤������ͨ���Υե������ָ���������ϡ����뤤�ό���Ǥ��ʤ����`�����֥ե������ָ���������Ϥʤɤˤ��Υ���`���k�����ޤ��Τǡ��_�J���Ƥ�������"));

TVP_MSG_DECL(TVPMissingPathDelimiterAtLast,
	TJS_W("�ѥ���������ˤ� '>' �ޤ��� '/' ��ָ�����Ƥ������� (���Ｊ� 2.19 beta 14 ��ꥢ�`�����֤����Ф�ӛ�Ť� '#' ���� '>' �ˉ���ޤ���)"));

TVP_MSG_DECL(TVPFilenameContainsSharpWarn,
	TJS_W("(ע��) '#' ���ե������� \"%1\" �˺��ޤ�Ƥ��ޤ������`�����֤����Ф����֤ϼ��Ｊ� 2.19 beta 14 ���'#' ���� '>' �ˉ���ޤ�����")
	TJS_W("�⤷���`�����֤����Ф����֤ΤĤ��� '#' ��ʹ�ä������Ϥϡ��������Ǥ��� '>' �ˉ䤨�Ƥ�������"));

TVP_MSG_DECL(TVPCannotGetLocalName,
	TJS_W("���ȥ�`���� %1 ���`����ե��������ˉ�Q�Ǥ��ޤ��󡣥��`�����֥ե������ڤΥե�����䡢��`����ե�����Ǥʤ��ե�����ϥ�`����ե��������ˉ�Q�Ǥ��ޤ���"));

TVP_MSG_DECL(TVPReadError,
	TJS_W("�i���z�ߥ���`�Ǥ����ե����뤬�Ɠp���Ƥ�������Ԥ䡢�ǥХ���������i���z�ߤ�ʧ�����������Ԥ�����ޤ�"));

TVP_MSG_DECL(TVPWriteError,
	TJS_W("�����z�ߥ���`�Ǥ�"));

TVP_MSG_DECL(TVPSeekError,
	TJS_W("���`����ʧ�����ޤ������ե����뤬�Ɠp���Ƥ�������Ԥ䡢�ǥХ���������i���z�ߤ�ʧ�����������Ԥ�����ޤ�"));

TVP_MSG_DECL(TVPTruncateError,
	TJS_W("�ե�������L�����Ф�ԑ���Τ�ʧ�����ޤ���"));

TVP_MSG_DECL(TVPInsufficientMemory,
	TJS_W("����_����ʧ�����ޤ�����"));

TVP_MSG_DECL(TVPUncompressionFailed,
	TJS_W("�ե������չ�_��ʧ�����ޤ�����δ����ΈR�s��ʽ��ָ�����줿�������뤤�ϥե����뤬�Ɠp���Ƥ�������Ԥ�����ޤ�"));

TVP_MSG_DECL(TVPCompressionFailed,
	TJS_W("�ե�����ΈR�s��ʧ�����ޤ���"));

TVP_MSG_DECL(TVPCannotWriteToArchive,
	TJS_W("���`�����֤˥ǩ`��������z�ळ�ȤϤǤ��ޤ���"));

TVP_MSG_DECL(TVPUnsupportedCipherMode,
	TJS_W("%1 ��δ����ΰ��Ż���ʽ�����ǩ`�����Ɠp���Ƥ��ޤ�"));

TVP_MSG_DECL(TVPUnsupportedModeString,
	TJS_W("�J�R�Ǥ��ʤ���`�������Ф�ָ���Ǥ�(%1)"));

TVP_MSG_DECL(TVPUnknownGraphicFormat,
	TJS_W("%1 ��δ֪�λ�����ʽ�Ǥ�"));

TVP_MSG_DECL(TVPCannotSuggestGraphicExtension,
	TJS_W("%1 �ˤĤ����m�Фʒ����Ӥ�֤ä��ե������Ҋ�Ĥ����ޤ���Ǥ���"));

TVP_MSG_DECL(TVPMaskSizeMismatch,
	TJS_W("�ޥ�������Υ��������ᥤ����Υ��������`���ޤ�"));

TVP_MSG_DECL(TVPProvinceSizeMismatch,
	TJS_W("�I���� %1 �ϥᥤ����ȥ��������`���ޤ�"));

TVP_MSG_DECL(TVPImageLoadError,
	TJS_W("�����i���z���Ф˥���`���k�����ޤ���/%1"));

TVP_MSG_DECL(TVPJPEGLoadError,
	TJS_W("JPEG �i���z���Ф˥���`���k�����ޤ���/%1"));

TVP_MSG_DECL(TVPPNGLoadError,
	TJS_W("PNG �i���z���Ф˥���`���k�����ޤ���/%1"));

TVP_MSG_DECL(TVPERILoadError,
	TJS_W("ERI �i���z���Ф˥���`���k�����ޤ���/%1"));

TVP_MSG_DECL(TVPTLGLoadError,
	TJS_W("TLG �i���z���Ф˥���`���k�����ޤ���/%1"));

TVP_MSG_DECL(TVPInvalidImageSaveType,
	TJS_W("�o���ʱ��滭����ʽ�Ǥ�(%1)"));

TVP_MSG_DECL(TVPInvalidOperationFor8BPP,
	TJS_W("8bpp ����ˌ����Ƥ��Ф��ʤ��������Ф����Ȥ��ޤ���"));

TVP_MSG_DECL(TVPSpecifyWindow,
	TJS_W("Window ���饹�Υ��֥������Ȥ�ָ�����Ƥ�������"));

TVP_MSG_DECL(TVPSpecifyLayer,
	TJS_W("Layer ���饹�Υ��֥������Ȥ�ָ�����Ƥ�������"));

TVP_MSG_DECL(TVPCannotCreateEmptyLayerImage,
	TJS_W("���񥵥����κ�����뤤�Ͽk���� 0 ���¤������O�����뤳�ȤϤǤ��ޤ���"));

TVP_MSG_DECL(TVPCannotSetPrimaryInvisible,
	TJS_W("�ץ饤�ޥ�쥤��ϲ���ҕ�ˤǤ��ޤ���"));

TVP_MSG_DECL(TVPCannotMovePrimary,
	TJS_W("�ץ饤�ޥ�쥤����ƄӤǤ��ޤ���"));

TVP_MSG_DECL(TVPCannotSetParentSelf,
	TJS_W("�Է�������H�Ȥ��뤳�ȤϤǤ��ޤ���"));

TVP_MSG_DECL(TVPCannotMoveNextToSelfOrNotSiblings,
	TJS_W("�Է������ǰ����H�ή��ʤ�쥤���ǰ����ƄӤ��뤳�ȤϤǤ��ޤ���"));

TVP_MSG_DECL(TVPCannotMovePrimaryOrSiblingless,
	TJS_W("�ץ饤�ޥ�쥤����ֵܤΟo���쥤���ǰ����ƄӤ��뤳�ȤϤǤ��ޤ���"));

TVP_MSG_DECL(TVPCannotMoveToUnderOtherPrimaryLayer,
	TJS_W("�e�Υץ饤�ޥ�쥤���¤˥쥤����ƄӤ��뤳�ȤϤǤ��ޤ���"));

TVP_MSG_DECL(TVPInvalidImagePosition,
	TJS_W("�쥤���I��˻���Οo���I�򤬰k�����ޤ���"));

TVP_MSG_DECL(TVPCannotSetModeToDisabledOrModal,
	TJS_W("���Ǥ˥�`����ʥ쥤����H�쥤�䡢���뤤�ϲ���ҕ/�o���ʥ쥤����`����ˤ��뤳�ȤϤǤ��ޤ���"));

TVP_MSG_DECL(TVPNotDrawableLayerType,
	TJS_W("���� type �Υ쥤��Ǥ��軭�仭���i���z�ߤ仭�񥵥���/λ�äΉ��/ȡ�äϤǤ��ޤ���"));

TVP_MSG_DECL(TVPSourceLayerHasNoImage,
	TJS_W("ܞ��Ԫ�쥤��ϻ����֤äƤ��ޤ���"));

TVP_MSG_DECL(TVPUnsupportedLayerType,
	TJS_W("%1 �Ϥ��� type �Υ쥤��Ǥ�ʹ�äǤ��ޤ���"));

TVP_MSG_DECL(TVPNotDrawableFaceType,
	TJS_W("%1 �ǤϤ��� face ���軭�Ǥ��ޤ���"));

TVP_MSG_DECL(TVPCannotConvertLayerTypeUsingGivenDirection,
	TJS_W("ָ�����줿�쥤�䥿���׉�Q�ϤǤ��ޤ���"));

TVP_MSG_DECL(TVPNegativeOpacityNotSupportedOnThisFace,
	TJS_W("ؓ�β�͸���ȤϤ��� face �Ǥ�ָ���Ǥ��ޤ���"));

TVP_MSG_DECL(TVPSrcRectOutOfBitmap,
	TJS_W("ܞ��Ԫ���ӥåȥޥå�����I��򺬤�Ǥ��ޤ�������������˅��ޤ�褦��ܞ��Ԫ��ָ�����Ƥ�������"));

TVP_MSG_DECL(TVPBoxBlurAreaMustContainCenterPixel,
	TJS_W("���Υ֥�`�ι���ϱؤ�(0,0)�򤽤��Ф˺����Ҫ������ޤ���left��right���I���Ȥ��������������뤤�ρI���Ȥ�ؓ�������Ȥ���ָ���ϤǤ��ޤ���(top��bottom�ˌ����Ƥ�ͬ��)"));

TVP_MSG_DECL(TVPBoxBlurAreaMustBeSmallerThan16Million,
	TJS_W("���Υ֥�`�ι��줬�󤭤����ޤ������Υ֥�`�ι����1677�����¤Ǥ����Ҫ������ޤ�"));

TVP_MSG_DECL(TVPCannotChangeFocusInProcessingFocus,
	TJS_W("�ե��`��������I���Фϥե��`�������¤��ˉ�����뤳�ȤϤǤ��ޤ���"));

TVP_MSG_DECL(TVPWindowHasNoLayer,
	TJS_W("������ɥ��˥쥤�䤬����ޤ���"));

TVP_MSG_DECL(TVPWindowHasAlreadyPrimaryLayer,
	TJS_W("������ɥ��ˤϤ��Ǥ˥ץ饤�ޥ�쥤�䤬����ޤ�"));

TVP_MSG_DECL(TVPSpecifiedEventNeedsParameter,
	TJS_W("���٥�� %1 �ˤϥѥ��`������Ҫ�Ǥ�"));

TVP_MSG_DECL(TVPSpecifiedEventNeedsParameter2,
	TJS_W("���٥�� %1 �ˤϥѥ��`�� %2 ����Ҫ�Ǥ�"));

TVP_MSG_DECL(TVPSpecifiedEventNameIsUnknown,
	TJS_W("���٥���� %1 ��δ֪�Υ��٥�����Ǥ�"));

TVP_MSG_DECL(TVPOutOfRectangle,
	TJS_W("�������ָ������ޤ���"));

TVP_MSG_DECL(TVPInvalidMethodInUpdating,
	TJS_W("��������ФϤ��ΙC�ܤ�g�ФǤ��ޤ���"));

TVP_MSG_DECL(TVPCannotCreateInstance,
	TJS_W("���Υ��饹�ϥ��󥹥��󥹤����ɤǤ��ޤ���"));

TVP_MSG_DECL(TVPUnknownWaveFormat,
	TJS_W("%1 �ό���Ǥ��ʤ� Wave ��ʽ�Ǥ�"));

TVP_MSG_DECL(TVPCurrentTransitionMustBeStopping,
	TJS_W("�F�ڤΥȥ�󥸥�����ֹͣ�����Ƥ����¤����ȥ�󥸥������_ʼ���Ƥ���������ͬ���쥤��ˌ������}���Υȥ�󥸥�����ͬ�r�ˌg�Ф��褦�Ȥ���Ȥ��Υ���`���k�����ޤ�"));

TVP_MSG_DECL(TVPTransHandlerError,
	TJS_W("�ȥ�󥸥����ϥ�ɥ�ǥ���`���k�����ޤ��� : %1"));

TVP_MSG_DECL(TVPTransAlreadyRegistered,
	TJS_W("�ȥ�󥸥���� %1 �ϼȤ˵��h����Ƥ��ޤ�"));

TVP_MSG_DECL(TVPCannotFindTransHander,
	TJS_W("�ȥ�󥸥����ϥ�ɥ� %1 ��Ҋ�Ĥ���ޤ���"));

TVP_MSG_DECL(TVPSpecifyTransitionSource,
	TJS_W("�ȥ�󥸥����Ԫ��ָ�����Ƥ�������"));

TVP_MSG_DECL(TVPLayerCannotHaveImage,
	TJS_W("���Υ쥤��ϻ����֤Ĥ��ȤϤǤ��ޤ���"));

TVP_MSG_DECL(TVPTransitionSourceAndDestinationMustHaveImage,
	TJS_W("�ȥ�󥸥����Ԫ�ȥȥ�󥸥�����ȤϤȤ�˻����֤äƤ����Ҫ������ޤ�"));

TVP_MSG_DECL(TVPCannotLoadRuleGraphic,
	TJS_W("��`�뻭�� %1 ���i���z�ळ�Ȥ��Ǥ��ޤ���"));

TVP_MSG_DECL(TVPSpecifyOption,
	TJS_W("���ץ���� %1 ��ָ�����Ƥ�������"));

TVP_MSG_DECL(TVPTransitionLayerSizeMismatch,
	TJS_W("�ȥ�󥸥����Ԫ(%1)�ȥȥ�󥸥������(%2)�Υ쥤��Υ�������һ�¤��ޤ���"));

TVP_MSG_DECL(TVPTransitionMutualSource,
	TJS_W("�ȥ�󥸥����Ԫ�Υȥ�󥸥����Ԫ���Է�����Ǥ�"));

TVP_MSG_DECL(TVPHoldDestinationAlphaParameterIsNowDeprecated,
	TJS_W("���� : �᥽�å� %1 �� %2 ��Ŀ�˶ɤ��줿 hda �ѥ��`���ϡ����Ｊ� 2.23 beta 2 ���oҕ�����褦�ˤʤ�ޤ����������� Layer.holdAlpha �ץ�ѥƥ����ä��Ƥ���������"));

TVP_MSG_DECL(TVPCannotConnectMultipleWaveSoundBufferAtOnce,
	TJS_W("�}���� WaveSoundBuffer ��һ�ĤΥե��륿��ͬ�r��ʹ�ä��뤳�ȤϤǤ��ޤ���"));

TVP_MSG_DECL(TVPInvalidWindowSizeMustBeIn64to32768,
	TJS_W("window �� 64��32768 �ι���� 2 ���ہ\�ǟo����Фʤ�ޤ���"));

TVP_MSG_DECL(TVPInvalidOverlapCountMustBeIn2to32,
	TJS_W("overlap �� 2��32 �ι���� 2 ���ہ\�ǟo����Фʤ�ޤ���"));


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
