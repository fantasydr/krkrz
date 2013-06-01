//---------------------------------------------------------------------------
/*
	TVP2 ( T Visual Presenter 2 )  A script authoring tool
	Copyright (C) 2000 W.Dee <dee@kikyou.info> and contributors

	See details of license at "license.txt"
*/
//---------------------------------------------------------------------------
// System Main Window (Controller)
//---------------------------------------------------------------------------
#ifndef MainFormUnitH
#define MainFormUnitH
//---------------------------------------------------------------------------
#include <windows.h>
#include <string>
#include "tstring.h"
//---------------------------------------------------------------------------
class TTVPMainForm
{
private:	// ��`���`����
	bool ContinuousEventCalling;
	bool AutoShowConsoleOnError;
	bool ApplicationStayOnTop;
	bool ApplicationActivating;
	bool ApplicationNotMinimizing;

	bool EventEnable;

	DWORD LastCompactedTick;
	DWORD LastContinuousTick;
	DWORD LastCloseClickedTick;
	DWORD LastShowModalWindowSentTick;
	DWORD LastRehashedTick;

	DWORD MixedIdleTick;
public:
	TTVPMainForm();

	void InvokeEvents();
	void CallDeliverAllEventsOnIdle();

	void BeginContinuousEvent();
	void EndContinuousEvent();

	void NotifyEventDelivered();

	void SetVisible( bool b );
	bool GetVisible() const;

	void SetEventButtonDown( bool b ) {
		EventEnable = b;
	}
	bool GetEventButtonDown() const { return EventEnable; }

	bool GetApplicationStayOnTop();
	void SetApplicationStayOnTop( bool );

	void NotifySystemError();

	bool GetConsoleVisible();
	void SetConsoleVisible( bool );
	
	bool GetApplicationActivating() const { return ApplicationActivating; }
	bool GetApplicationNotMinimizing() const { return ApplicationNotMinimizing; }

	HWND GetHandle() { return NULL; }

	bool ApplicationIdel();
private:
	void DeliverEvents();
};
enum {
  mtWarning = MB_ICONWARNING,
  mtError = MB_ICONERROR,
  mtInformation = MB_ICONINFORMATION,
  mtConfirmation = MB_ICONQUESTION,
  mtCustom = 0
};
/*
MB_ABORTRETRYIGNORE	��å��`���ܥå����ˣ���ֹ�ݡ�����ԇ�Уݡ��۟oҕ�ݤθ��ץå���ܥ�����ʾ���ޤ���
MB_CANCELTRYCONTINUE	Windows 2000����å��`���ܥå����ˣۥ���󥻥�ݡ����ٌg�Уݡ��۾A�Уݤθ��ץå���ܥ�����ʾ���ޤ���MB_ABORTRETRYIGNORE �δ����ˡ����Υ�å��`���ܥå��������פ�ʹ�äƤ���������
MB_HELP	Windows 95/98��Windows NT 4.0 �Խ�����å��`���ܥå����ˣۥإ�ףݥܥ����׷�Ӥ��ޤ�����`���`���ۥإ�ףݥܥ���򥯥�å����뤫 F1 ���`��Ѻ���ȡ������ƥ�ϥ��`�ʩ`�� ��å��`�������Ť��ޤ���
MB_OK	��å��`���ܥå����ˣ�OK�ݥץå���ܥ���������ʾ���ޤ�������ϼȶ��Υ�å��`���ܥå��������פǤ���
MB_OKCANCEL	��å��`���ܥå����ˣ�OK�ݡ��ۥ���󥻥�ݤθ��ץå���ܥ�����ʾ���ޤ���
MB_RETRYCANCEL	��å��`���ܥå����ˣ���ԇ�Уݡ��ۥ���󥻥�ݤθ��ץå���ܥ�����ʾ���ޤ���
MB_YESNO	��å��`���ܥå����ˣۤϤ��ݡ��ۤ������ݤθ��ץå���ܥ�����ʾ���ޤ���
MB_YESNOCANCEL	��å��`���ܥå����ˣۤϤ��ݡ��ۤ������ݡ��ۥ���󥻥�ݤθ��ץå���ܥ�����ʾ���ޤ���
*/
inline int MessageDlg( const tstring& string, int type, int buttons, void* helpCtx ) {
	return ::MessageBox( NULL, string.c_str(), _T(""), type | buttons );
}

extern TTVPMainForm *TVPMainForm;

extern bool TVPMainFormAlive;

#endif
