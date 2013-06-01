
#include <algorithm>
#include <string>
#include <vector>
#include <windows.h>
#include "Application.h"

#include "tjsCommHead.h"

#include "SysInitIntf.h"
#include "SysInitImpl.h"
#include "DebugIntf.h"
#include "MsgIntf.h"
#include "ScriptMgnIntf.h"
#include "ScriptMgnImpl.h"
#include "tjsError.h"
#include "PluginImpl.h"
#include "SystemIntf.h"

#include "Exception.h"
#include "WindowFormUnit.h"
#include "Resource.h"
#include "MainFormUnit.h"
#include "MouseCursor.h"

#pragma comment( lib, "winmm.lib" )
#pragma comment( lib, "dxguid.lib" )
#pragma comment( lib, "dsound.lib" )
#pragma comment( lib, "ddraw.lib" )
#pragma comment( lib, "version.lib" )
#pragma comment( lib, "mpr.lib" )
#pragma comment( lib, "shlwapi.lib" )
#pragma comment( lib, "vfw32.lib" )
#pragma comment( lib, "imm32.lib" )

#pragma comment( lib, "tvpgl_ia32.lib" )
#pragma comment( lib, "tvpsnd_ia32.lib" )

HINSTANCE hInst;
TApplication* Application;

#if 0
tstring ParamStr( int index ) {
	if( index < (int)Application->CommandLines.size() ) {
		return tstring(Application->CommandLines[index]);
	} else {
		return tstring();
	}
}
#endif
tstring ExePath() {
	TCHAR szFull[_MAX_PATH];
	::GetModuleFileName(NULL, szFull, sizeof(szFull) / sizeof(TCHAR));
	return tstring(szFull);
}

bool TVPCheckCmdDescription();
bool TVPCheckAbout();
bool TVPCheckPrintDataPath();
void TVPOnError();

int _argc;
char ** _argv;
extern void TVPInitCompatibleNativeFunctions();

AcceleratorKeyTable::AcceleratorKeyTable() {
	// �ǥե���Ȥ��i���z��
	hAccel_ = ::LoadAccelerators( (HINSTANCE)GetModuleHandle(0), MAKEINTRESOURCE(IDC_TVPWIN32));
}
AcceleratorKeyTable::~AcceleratorKeyTable() {
	std::map<HWND,AcceleratorKey*>::iterator i = keys_.begin();
	for( ; i != keys_.end(); i++ ) {
		delete (i->second);
	}
}
void AcceleratorKeyTable::AddKey( HWND hWnd, WORD id, WORD key, BYTE virt ) {
	std::map<HWND,AcceleratorKey*>::iterator i = keys_.find(hWnd);
	if( i != keys_.end() ) {
		i->second->AddKey(id,key,virt);
	} else {
		AcceleratorKey* acc = new AcceleratorKey();
		acc->AddKey( id, key, virt );
		keys_.insert( std::map<HWND, AcceleratorKey*>::value_type( hWnd, acc ) );
	}
}
void AcceleratorKeyTable::DelKey( HWND hWnd, WORD id ) {
	std::map<HWND,AcceleratorKey*>::iterator i = keys_.find(hWnd);
	if( i != keys_.end() ) {
		i->second->DelKey(id);
	}
}

void AcceleratorKeyTable::DelTable( HWND hWnd ) {
	std::map<HWND,AcceleratorKey*>::iterator i = keys_.find(hWnd);
	if( i != keys_.end() ) {
		delete (i->second);
		keys_.erase(i);
	}
}
AcceleratorKey::AcceleratorKey() : hAccel_(NULL), keys_(NULL), key_count_(0) {
}
AcceleratorKey::~AcceleratorKey() {
	if( hAccel_ != NULL ) ::DestroyAcceleratorTable( hAccel_ );
	delete[] keys_;
}
void AcceleratorKey::AddKey( WORD id, WORD key, BYTE virt ) {
	// �ޤ��ϴ��ڤ��뤫�����å�����
	bool found = false;
	int index = 0;
	for( int i = 0; i < key_count_; i++ ) {
		if( keys_[i].cmd == id ) {
			index = i;
			found = true;
			break;
		}
	}
	if( found ) {
		// �Ȥ˵��h����Ƥ��륳�ޥ�ɤʤΤǥ��`���θ��¤��Ф�
		if( keys_[index].key == key && keys_[index].fVirt == virt ) {
			// �������Ƥ��ʤ�
			return;
		}
		keys_[index].key = key;
		keys_[index].fVirt = virt;
		HACCEL hAccel = ::CreateAcceleratorTable( keys_, key_count_ );
		if( hAccel_ != NULL ) ::DestroyAcceleratorTable( hAccel_ );
		hAccel_ = hAccel;
	} else {
		ACCEL* table = new ACCEL[key_count_+1];
		for( int i = 0; i < key_count_; i++ ) {
			table[i] = keys_[i];
		}
		table[key_count_].cmd = id;
		table[key_count_].key = key;
		table[key_count_].fVirt = virt;
		key_count_++;
		HACCEL hAccel = ::CreateAcceleratorTable( table, key_count_ );
		if( hAccel_ != NULL ) ::DestroyAcceleratorTable( hAccel_ );
		hAccel_ = hAccel;
		delete[] keys_;
		keys_ = table;
	}

}
void AcceleratorKey::DelKey( WORD id ) {
	// �ޤ��ϴ��ڤ��뤫�����å�����
	bool found = false;
	for( int i = 0; i < key_count_; i++ ) {
		if( keys_[i].cmd == id ) {
			found = true;
			break;
		}
	}
	if( found == false ) return;

	// ���ڤ�����������ֱ��
	ACCEL* table = new ACCEL[key_count_-1];
	int dest = 0;
	for( int i = 0; i < key_count_; i++ ) {
		if( keys_[i].cmd != id ) {
			table[dest] = keys_[i];
			dest++;
		}
	}
	key_count_--;
	HACCEL hAccel = ::CreateAcceleratorTable( table, key_count_ );
	if( hAccel_ != NULL ) ::DestroyAcceleratorTable( hAccel_ );
	hAccel_ = hAccel;
	delete[] keys_;
	keys_ = table;
}
int APIENTRY WinMain( _In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow ) {
	TVPInitCompatibleNativeFunctions();

	hInst = hInstance;

	_argc = __argc;
	_argv = __argv;

	MouseCursor::Initialize();

	Application = new TApplication();
	Application->ArgC = __argc;
	Application->ArgV = __argv;
	for( int i = 0; i < __argc; i++ ) {
		Application->CommandLines.push_back( std::string(__argv[i]) );
	}
	Application->CheckConsole();

	// try starting the program!
	bool engine_init = false;
	try {
		if(TVPCheckProcessLog()) return 0; // sub-process for processing object hash map log

		TVPInitScriptEngine();
		engine_init = true;

		// banner
		TVPAddImportantLog(TJS_W("Program started on ") + TVPGetOSName() +
			TJS_W(" (") + TVPGetPlatformName() + TJS_W(")"));

		// TVPInitializeBaseSystems
		TVPInitializeBaseSystems();

		Application->Initialize();

		if(TVPCheckPrintDataPath()) return 0;
		if(TVPCheckCmdDescription()) return 0;
		//if(TVPExecuteUserConfig()) return 0; // userconf ���󥸥��O�����ӤϤ��ʤ� TODO

		TVPSystemInit();

		if(TVPCheckAbout()) return 0; // version information dialog box;

		Application->SetTitle( _T("���Ｊ��") );
		// Application->CreateForm(__classid(TTVPMainForm), &TVPMainForm);
		TVPMainForm = new TTVPMainForm();

		TVPLoadPluigins(); // load plugin module *.tpm

		if(TVPProjectDirSelected) TVPInitializeStartupScript();

		Application->Run();

		try {
			TVPSystemUninit();
		} catch(...) {
			// ignore errors
		}
	} catch (EAbort &) {
		// nothing to do
	} catch (Exception &exception) {
		TVPOnError();
		if(!TVPSystemUninitCalled)
			Application->ShowException(&exception);
	} catch (eTJSScriptError &e) {
		TVPOnError();
		if(!TVPSystemUninitCalled)
			Application->ShowException(&Exception(e.GetMessage().AsStdString()));
	} catch (eTJS &e) {
		TVPOnError();
		if(!TVPSystemUninitCalled)
			Application->ShowException(&Exception(e.GetMessage().AsStdString()));
	} catch(...) {
		Application->ShowException(&Exception(_T("Unknown error!")));
	}

	if(engine_init) TVPUninitScriptEngine();

	Application->CloseConsole();

#ifndef _DEBUG
	// delete application and exit forcely
	// this prevents ugly exception message on exit

	delete Application;
	::ExitProcess(TVPTerminateCode);
#endif
	return TVPTerminateCode;
}
/**
 * ���󥽩`�뤫������Ӥ��_�J�������󥽩`�뤫������ӤΈ��Ϥϡ��˜ʳ������굱�Ƥ�
 */
void TApplication::CheckConsole() {
#ifdef TVP_LOG_TO_COMMANDLINE_CONSOLE
	if( ::AttachConsole(ATTACH_PARENT_PROCESS) ) {
		_wfreopen_s( &oldstdin_, L"CON", L"r", stdin );     // �˜������θ�굱��
		_wfreopen_s( &oldstdout_, L"CON", L"w", stdout);    // �˜ʳ����θ�굱��
		is_attach_console_ = true;

		TCHAR console[256];
		::GetConsoleTitle( console, 256 );
		console_title_ = tstring( console );

		//printf( __argv[0] );
		printf("\n");
	}
#endif
}
void TApplication::CloseConsole() {
	if( is_attach_console_ ) {
		printf("Exit code: %d\n",TVPTerminateCode);
		FILE *tmpout, *tmpin;
		_wfreopen_s( &tmpin, L"CON", L"r", oldstdin_ );
		_wfreopen_s( &tmpout, L"CON", L"w", oldstdout_);
		::SetConsoleTitle( console_title_.c_str() );
		::FreeConsole();
	}
}
HWND TApplication::GetHandle() {
	if( windows_list_.size() > 0 ) {
		return windows_list_[0]->GetHandle();
	} else if (TVPMainForm) {
		return TVPMainForm->GetHandle();
	} else {
		return INVALID_HANDLE_VALUE;
	}
}
void TApplication::Minimize() {
	size_t size = windows_list_.size();
	for( size_t i = 0; i < size; i++ ) {
		::ShowWindow( windows_list_[i]->GetHandle(), SW_MINIMIZE );
	}
}
void TApplication::Restore() {
	size_t size = windows_list_.size();
	for( size_t i = 0; i < size; i++ ) {
		::ShowWindow( windows_list_[i]->GetHandle(), SW_RESTORE );
	}
}

void TApplication::BringToFront() {
	size_t size = windows_list_.size();
	for( size_t i = 0; i < size; i++ ) {
		windows_list_[i]->BringToFront();
	}
}
void TApplication::ShowException( class Exception* e ) {
	::MessageBox( NULL, e->what(), _T("�����Ĥʥ���`"), MB_OK );
}
void TApplication::Run() {
	MSG msg;
	HACCEL hAccelTable;
	//hAccelTable = LoadAccelerators( (HINSTANCE)GetModuleHandle(0), MAKEINTRESOURCE(IDC_TVPWIN32));

	// �ᥤ�� ��å��`�� ��`��:
	HWND mainWnd = INVALID_HANDLE_VALUE;
	if( ( windows_list_.size() > 0 ) ) {
		mainWnd = windows_list_[0]->GetHandle();
	}
	while( windows_list_.size() > 0 ) {
		BOOL ret = TRUE;
		while( ::PeekMessage( &msg, NULL, 0, 0, PM_NOREMOVE) ) {
			ret = ::GetMessage( &msg, NULL, 0, 0);
			hAccelTable = accel_key_.GetHandle(msg.hwnd);
			if( ret && !TranslateAccelerator(msg.hwnd, hAccelTable, &msg) ) {
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		if( ret == 0 ) {
			if( msg.hwnd == mainWnd ) break;
		}
		bool done = true;
		if( TVPMainForm ) {
			done = TVPMainForm->ApplicationIdel();
		}
		if( done ) { // idle �I���K��ä��顢��å��`��������
			BOOL dret = ::GetMessage( &msg, NULL, 0, 0 );
			hAccelTable = accel_key_.GetHandle(msg.hwnd);
			if( dret && !TranslateAccelerator(msg.hwnd, hAccelTable, &msg) ) {
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			if( dret == 0 ) {
				if( msg.hwnd == mainWnd ) break;
			}
		}
	}
	TVPTerminateCode = 0;
	if( ::PeekMessage( &msg, NULL, 0, 0, PM_REMOVE) ) {
		if( msg.message == WM_QUIT ) {
			TVPTerminateCode = msg.wParam;
		}
	}
}

void TApplication::SetTitle( const tstring& caption ) {
	title_ = caption;
	if( windows_list_.size() > 0 ) {
		windows_list_[0]->SetCaption( caption );
	}
	if( is_attach_console_ ) {
		::SetConsoleTitle( caption.c_str() );
	}
}
HWND TApplication::GetMainWindowHandle() {
	if( windows_list_.size() > 0 ) {
		return windows_list_[0]->GetHandle();
	}
	return INVALID_HANDLE_VALUE;
}

void TApplication::RemoveWindow( TTVPWindowForm* win ) {
	std::vector<class TTVPWindowForm*>::iterator it = std::remove( windows_list_.begin(), windows_list_.end(), win );
	windows_list_.erase( it, windows_list_.end() );
}

void TApplication::PostMessageToMainWindow(UINT message, WPARAM wParam, LPARAM lParam) {
	if( windows_list_.size() > 0 ) {
		::PostMessage( windows_list_[0]->GetHandle(), message, wParam, lParam );
	}
}
void TApplication::GetDisableWindowList( std::vector<class TTVPWindowForm*>& win ) {
	size_t count = windows_list_.size();
	for( size_t i = 0; i < count; i++ ) {
		if( windows_list_[i]->GetEnable() == false ) {
			win.push_back( windows_list_[i] );
		}
	}
}

void TApplication::DisableWindows() {
	size_t count = windows_list_.size();
	for( size_t i = 0; i < count; i++ ) {
		windows_list_[i]->SetEnable( false );
	}
}
void TApplication::EnableWindows( const  std::vector<TTVPWindowForm*>& ignores ) {
	size_t count = windows_list_.size();
	for( size_t i = 0; i < count; i++ ) {
		TTVPWindowForm* win = windows_list_[i];
		std::vector<TTVPWindowForm*>::const_iterator f = std::find( ignores.begin(), ignores.end(), win );
		if( f == ignores.end() ) {
			windows_list_[i]->SetEnable( true );
		}
	}
}

void TApplication::RegisterAcceleratorKey(HWND hWnd, char virt, short key, short cmd) {
	accel_key_.AddKey( hWnd, cmd, key, virt );
}
void TApplication::UnregisterAcceleratorKey(HWND hWnd, short cmd) {
	accel_key_.DelKey( hWnd, cmd );
}
void TApplication::DeleteAcceleratorKeyTable( HWND hWnd ) {
	accel_key_.DelTable( hWnd );
}
/**
 ���gװ TODO
*/
std::vector<std::string>* LoadLinesFromFile( const tstring& path ) {
	FILE *fp = NULL;
	_tfopen_s( &fp, path.c_str(), _T("r"));
    if( fp == NULL ) {
		return NULL;
    }
	char buff[1024];
	std::vector<std::string>* ret = new std::vector<std::string>();
    while( fgets(buff, 1024, fp) != NULL ) {
		ret->push_back( std::string(buff) );
    }
    fclose(fp);
	return ret;
}

void TVPRegisterAcceleratorKey(HWND hWnd, char virt, short key, short cmd) {
	if( Application ) Application->RegisterAcceleratorKey( hWnd, virt, key, cmd );
}
void TVPUnregisterAcceleratorKey(HWND hWnd, short cmd) {
	if( Application ) Application->UnregisterAcceleratorKey( hWnd, cmd );
}
void TVPDeleteAcceleratorKeyTable( HWND hWnd ) {
	if( Application ) Application->DeleteAcceleratorKeyTable( hWnd );
}
