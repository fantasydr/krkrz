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
	TJS_W("������ץȤ����⤬�k�����ޤ���"));

TVP_MSG_DECL(TVPHardwareExceptionRaised,
	TJS_W("�ϩ`�ɥ��������⤬�k�����ޤ���"));

TVP_MSG_DECL(TVPMainCDPName,
	TJS_W("������ץȥ��ǥ��� (�ᥤ��)"));

TVP_MSG_DECL(TVPExceptionCDPName,
	TJS_W("������ץȥ��ǥ��� (����֪ͨ)"));

TVP_MSG_DECL(TVPCannnotLocateUIDLLForFolderSelection,
	TJS_W("�ե����/���`�����֤��x�k������ʾ���褦�Ȥ��ޤ����� ")
		TJS_W("krdevui.dll ��Ҋ�Ĥ���ʤ��ΤǱ�ʾ�Ǥ��ޤ���.\n")
		TJS_W("�g�Ф���ե����/���`�����֤ϥ��ޥ�ɥ饤��������Ȥ���ָ�����Ƥ�������"));

TVP_MSG_DECL(TVPInvalidUIDLL,
	TJS_W("krdevui.dll �����������Щ`�����һ�¤��ޤ���"));

TVP_MSG_DECL(TVPInvalidBPP,
	TJS_W("�o����ɫ��ȤǤ�"));

TVP_MSG_DECL(TVPCannotLoadPlugin,
	TJS_W("�ץ饰���� %1 ���i���z��ޤ���"));

TVP_MSG_DECL(TVPNotValidPlugin,
	TJS_W("%1 ���Є��ʥץ饰����ǤϤ���ޤ���"));

TVP_MSG_DECL(TVPPluginUninitFailed,
	TJS_W("�ץ饰����ν�Ť�ʧ�����ޤ���"));

TVP_MSG_DECL(TVPCannnotLinkPluginWhilePluginLinking,
	TJS_W("�ץ饰����νӾA�Ф����Υץ饰�����ӾA���뤳�ȤϤǤ��ޤޤ���"));

TVP_MSG_DECL(TVPNotSusiePlugin,
	TJS_W("������ Susie �ץ饰����Ǥ�"));

TVP_MSG_DECL(TVPSusiePluginError,
	TJS_W("Susie �ץ饰����ǥ���`���k�����ޤ���/����`���`�� %1"));

TVP_MSG_DECL(TVPCannotReleasePlugin,
	TJS_W("ָ�����줿�ץ饰�����ʹ���ФΤ����ŤǤ��ޤ���"));

TVP_MSG_DECL(TVPNotLoadedPlugin,
	TJS_W("%1 ���i���z�ޤ�Ƥ��ޤ���"));

TVP_MSG_DECL(TVPCannotAllocateBitmapBits,
	TJS_W("�ӥåȥޥå��å����_���Ǥ��ޤ���/%1(size=%2)"));

TVP_MSG_DECL(TVPScanLineRangeOver,
	TJS_W("�������饤�� %1 �Ϲ���(0��%2)�򳬤��Ƥ��ޤ�"));

TVP_MSG_DECL(TVPPluginError,
	TJS_W("�ץ饰����ǥ���`���k�����ޤ���/%1"));

TVP_MSG_DECL(TVPInvalidCDDADrive,
	TJS_W("ָ�����줿�ɥ饤�֤Ǥ� CD-DA �������Ǥ��ޤ���"));

TVP_MSG_DECL(TVPCDDADriveNotFound,
	TJS_W("CD-DA �������Ǥ���ɥ饤�֤�Ҋ�Ĥ���ޤ���"));

TVP_MSG_DECL(TVPMCIError,
	TJS_W("MCI �ǥ���`���k�����ޤ��� : %1"));

TVP_MSG_DECL(TVPInvalidSMF,
	TJS_W("�Є��� SMF �ե�����ǤϤ���ޤ��� : %1"));

TVP_MSG_DECL(TVPMalformedMIDIMessage,
	TJS_W("ָ�����줿��å��`���� MIDI ��å��`���Ȥ����Є�����ʽ�ǤϤ���ޤ���"));

TVP_MSG_DECL(TVPCannotInitDirectSound,
	TJS_W("DirectSound ����ڻ��Ǥ��ޤ��� : %1"));

TVP_MSG_DECL(TVPCannotCreateDSSecondaryBuffer,
	TJS_W("DirectSound ���������Хåե������ɤǤ��ޤ��� : %1/%2"));

TVP_MSG_DECL(TVPInvalidLoopInformation,
	TJS_W("��`����� %1 �Ϯ����Ǥ�"));

TVP_MSG_DECL(TVPNotChildMenuItem,
	TJS_W("ָ�����줿��˥�`�Ŀ�Ϥ��Υ�˥�`�Ŀ���ӤǤϤ���ޤ���"));

TVP_MSG_DECL(TVPCannotInitDirectDraw,
	TJS_W("DirectDraw ����ڻ��Ǥ��ޤ��� : %1"));

TVP_MSG_DECL(TVPCannotFindDisplayMode,
	TJS_W("�m�Ϥ��뻭���`�ɤ�Ҋ�Ĥ���ޤ��� : %1"));

TVP_MSG_DECL(TVPCannotSwitchToFullScreen,
	TJS_W("�ե륹����`����Ф��椨���ޤ��� : %1"));

TVP_MSG_DECL(TVPInvalidPropertyInFullScreen,
	TJS_W("�ե륹����`���ФǤϲ����Ǥ��ʤ��ץ�ѥƥ����O�����褦�Ȥ��ޤ���"));

TVP_MSG_DECL(TVPInvalidMethodInFullScreen,
	TJS_W("�ե륹����`���ФǤϲ����Ǥ��ʤ��᥽�åɤ���ӳ������Ȥ��ޤ���"));

TVP_MSG_DECL(TVPCannotLoadCursor,
	TJS_W("�ޥ������`���� %1 ���i���z�ߤ�ʧ�����ޤ���"));

TVP_MSG_DECL(TVPCannotLoadKrMovieDLL,
	TJS_W("�ӥǥ�/Shockwave Flash ���������뤿��ˤ� krmovie.dll / krflash.dll ")
		TJS_W("����Ҫ�Ǥ��� �i���z�ळ�Ȥ��Ǥ��ޤ���"));

TVP_MSG_DECL(TVPInvalidKrMovieDLL,
	TJS_W("krmovie.dll/krflash.dll �������� ����Ǥ��ʤ��Щ`�����Ǥ�"));

TVP_MSG_DECL(TVPErrorInKrMovieDLL,
	TJS_W("krmovie.dll/krflash.dll �ڤǥ���`���k�����ޤ���/%1"));

TVP_MSG_DECL(TVPWindowAlreadyMissing,
	TJS_W("������ɥ��Ϥ��Ǥ˴��ڤ��Ƥ��ޤ���"));

TVP_MSG_DECL(TVPPrerenderedFontMappingFailed,
	TJS_W("������󥰜g�ߥե���ȤΥޥåԥ󥰤�ʧ�����ޤ��� : %1"));

TVP_MSG_DECL_CONST(TVPConfigFailOriginalFileCannotBeRewritten,
	TJS_W("%1 �˕����z�ߤǤ��ޤ��󡣥��եȥ��������g���ФΤޤޤˤʤäƤ��ʤ��������뤤��")
		TJS_W("�����z�ߘ��ޤ����뤫�ɤ�����_�J���Ƥ�������"));

TVP_MSG_DECL(TVPConfigFailTempExeNotErased,
	TJS_W("%1 �νK�ˤ�_�J�Ǥ��ʤ����ᡢ����������Ǥ��ޤ���Ǥ���(���Υե�������������ƽY���Ǥ�)"));

TVP_MSG_DECL_CONST(TVPExecutionFail,
	TJS_W("%1 ��g�ФǤ��ޤ���"));

TVP_MSG_DECL(TVPPluginUnboundFunctionError,
	TJS_W("�ץ饰���󤫤��v�� %1 ��Ҫ�󤵤�ޤ������������v���ϱ����ڤ˴��ڤ��ޤ��󡣥ץ饰�����")
			TJS_W("����ΥЩ`��������������ꤷ�Ƥ��뤫�_�J���Ƥ�������"));

TVP_MSG_DECL(TVPExceptionHadBeenOccured,
	TJS_W(" = (����k��)"));

TVP_MSG_DECL(TVPConsoleResult,
	TJS_W("���󥽩`�� : "));


//---------------------------------------------------------------------------



#endif
