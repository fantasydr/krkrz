#include <windows.h>
#include "tp_stub.h"
#include "MenuItemIntf.h"
#include "resource.h"
#include <tchar.h>
#include <string.h>

const tjs_char* TVPSpecifyWindow = NULL;
const tjs_char* TVPSpecifyMenuItem = NULL;
const tjs_char* TVPInternalError = NULL;
const tjs_char* TVPNotChildMenuItem = NULL;
const tjs_char* TVPMenuIDOverflow = NULL;

static void LoadMessageFromResource() {
	static const int BUFF_SIZE = 1024;
	HINSTANCE hInstance = ::GetModuleHandle(_T("menu.dll"));
	TCHAR buffer[BUFF_SIZE];
	TCHAR* work;
	int len;

	len = ::LoadString( hInstance, IDS_SPECIFY_WINDOW, buffer, BUFF_SIZE );
	work = new TCHAR[len+1];
	_tcscpy_s( work, len+1, buffer );
	TVPSpecifyWindow = work;

	len = ::LoadString( hInstance, IDS_SPECIFY_MENU_ITEM, buffer, BUFF_SIZE );
	work = new TCHAR[len+1];
	_tcscpy_s( work, len+1, buffer );
	TVPSpecifyMenuItem = work;

	len = ::LoadString( hInstance, IDS_INTERNAL_ERROR, buffer, BUFF_SIZE );
	work = new TCHAR[len+1];
	_tcscpy_s( work, len+1, buffer );
	TVPInternalError = work;

	len = ::LoadString( hInstance, IDS_NOT_CHILD_MENU_ITEM, buffer, BUFF_SIZE );
	work = new TCHAR[len+1];
	_tcscpy_s( work, len+1, buffer );
	TVPNotChildMenuItem = work;
	
	len = ::LoadString( hInstance, IDS_MENU_ID_OVERFLOW, buffer, BUFF_SIZE );
	work = new TCHAR[len+1];
	_tcscpy_s( work, len+1, buffer );
	TVPMenuIDOverflow = work;
}
static void FreeMessage() {
	delete[] TVPSpecifyWindow;
	delete[] TVPSpecifyMenuItem;
	delete[] TVPInternalError;
	delete[] TVPNotChildMenuItem;
	delete[] TVPMenuIDOverflow;
	TVPSpecifyWindow = NULL;
	TVPSpecifyMenuItem = NULL;
	TVPInternalError = NULL;
	TVPNotChildMenuItem = NULL;
	TVPMenuIDOverflow = NULL;
}
static std::map<HWND,iTJSDispatch2*> MENU_LIST;
static void AddMenuDispatch( HWND hWnd, iTJSDispatch2* menu ) {
	MENU_LIST.insert( std::map<HWND, iTJSDispatch2*>::value_type( hWnd, menu ) );
}
static iTJSDispatch2* GetMenuDispatch( HWND hWnd ) {
	std::map<HWND, iTJSDispatch2*>::iterator i = MENU_LIST.find( hWnd );
	if( i != MENU_LIST.end() ) {
		return i->second;
	}
	return NULL;
}
static void DelMenuDispatch( HWND hWnd ) {
	MENU_LIST.erase(hWnd);
}
/**
 * ��˥�`���Ф���Ȥ˴��ڤ��ʤ��ʤä�Window�ˤĤ��Ƥ����˥�`���֥������Ȥ���������
 */
static void UpdateMenuList() {
	std::map<HWND, iTJSDispatch2*>::iterator i = MENU_LIST.begin();
	for( ; i != MENU_LIST.end(); ) {
		HWND hWnd = i->first;
		BOOL exist = ::IsWindow( hWnd );
		if( exist == 0 ) {
			// �Ȥˤʤ��ʤä�Window
			std::map<HWND, iTJSDispatch2*>::iterator target = i;
			i++;
			iTJSDispatch2* menu = target->second;
			MENU_LIST.erase( target );
			menu->Release();
			TVPDeleteAcceleratorKeyTable( hWnd );
		} else {
			i++;
		}
	}
}
class WindowMenuProperty : public tTJSDispatch {
	tjs_error TJS_INTF_METHOD PropGet( tjs_uint32 flag,	const tjs_char * membername, tjs_uint32 *hint, tTJSVariant *result,	iTJSDispatch2 *objthis ) {
		tTJSVariant var;
		if( TJS_FAILED(objthis->PropGet(0, TJS_W("HWND"), NULL, &var, objthis)) ) {
			return TJS_E_INVALIDOBJECT;
		}
		HWND hWnd = (HWND)(tjs_int64)var;
		iTJSDispatch2* menu = GetMenuDispatch( hWnd );
		if( menu == NULL ) {
			UpdateMenuList();
			menu = TVPCreateMenuItemObject(objthis);
			AddMenuDispatch( hWnd, menu );
		}
		*result = tTJSVariant(menu, menu);
		return TJS_S_OK;
	}
	tjs_error TJS_INTF_METHOD PropSet( tjs_uint32 flag, const tjs_char *membername,	tjs_uint32 *hint, const tTJSVariant *param,	iTJSDispatch2 *objthis ) {
		return TJS_E_ACCESSDENYED;
	}
} *gWindowMenuProperty;
//---------------------------------------------------------------------------
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved) {
	return 1;
}
//---------------------------------------------------------------------------
static tjs_int GlobalRefCountAtInit = 0;
extern "C" __declspec(dllexport) HRESULT _stdcall V2Link(iTVPFunctionExporter *exporter)
{
	LoadMessageFromResource();

	// �����֤γ��ڻ�(�ؤ�ӛ������)
	TVPInitImportStub(exporter);

	tTJSVariant val;

	// TJS �Υ���`�Х륪�֥������Ȥ�ȡ�ä���
	iTJSDispatch2 * global = TVPGetScriptDispatch();

	{
		gWindowMenuProperty = new WindowMenuProperty();
		val = tTJSVariant(gWindowMenuProperty);
		gWindowMenuProperty->Release();
		tTJSVariant win;
		if( TJS_SUCCEEDED(global->PropGet(0,TJS_W("Window"),NULL,&win,global)) ) {
			iTJSDispatch2* obj = win.AsObjectNoAddRef();
			obj->PropSet(TJS_MEMBERENSURE,TJS_W("menu"),NULL,&val,obj);
		}

		//-----------------------------------------------------------------------
		iTJSDispatch2 * tjsclass = TVPCreateNativeClass_MenuItem();
		val = tTJSVariant(tjsclass);
		tjsclass->Release();
		global->PropSet( TJS_MEMBERENSURE, TJS_W("MenuItem"), NULL, &val, global );
		//-----------------------------------------------------------------------
		
	}

	// - global �� Release ����
	global->Release();

	// val �򥯥ꥢ���롣
	// ����ϱؤ��Ф����������ʤ��� val �����֤��Ƥ��륪�֥�������
	// �� Release ���줺���Τ�ʹ�� TVPPluginGlobalRefCount �����_�ˤʤ�ʤ���
	val.Clear();


	// ���Εr��Ǥ� TVPPluginGlobalRefCount �΂���
	GlobalRefCountAtInit = TVPPluginGlobalRefCount;
	// �Ȥ��ƿؤ��Ƥ�����TVPPluginGlobalRefCount �Ϥ��Υץ饰�����ڤ�
	// ������Ƥ��� tTJSDispatch �������֥������Ȥβ��ե����󥿤ξtӋ�ǡ�
	// ��ŕr�ˤϤ����ͬ��������������٤ʤ��ʤäƤʤ��Ȥʤ�ʤ���
	// �����ʤäƤʤ���С��ɤ����e�ΤȤ�����v���ʤɤ����դ���Ƥ��ơ�
	// �ץ饰����Ͻ�ŤǤ��ʤ����Ԥ����Ȥˤʤ롣

	return S_OK;
}
//---------------------------------------------------------------------------
extern "C" __declspec(dllexport) HRESULT _stdcall V2Unlink()
{
	// ���Ｊ��Ȥ��顢�ץ饰������Ť��褦�Ȥ���Ȥ��˺��Ф���v����

	// �⤷�Τ餫�������ǥץ饰������ŤǤ��ʤ����Ϥ�
	// ���Εr��� E_FAIL �򷵤��褦�ˤ��롣
	// �����Ǥϡ�TVPPluginGlobalRefCount �� GlobalRefCountAtInit ����
	// �󤭤��ʤäƤ����ʧ���Ȥ������Ȥˤ��롣
	if(TVPPluginGlobalRefCount > GlobalRefCountAtInit) return E_FAIL;
		// E_FAIL ������ȡ�Plugins.unlink �᥽�åɤςΤ򷵤�

	/*
		�����������饹�Έ��ϡ����ܤˡ����֥������Ȥ�ʹ���ФǤ��롹�Ȥ������Ȥ�
		֪�뤹�٤�����ޤ��󡣻����Ĥˤϡ�Plugins.unlink �ˤ��ץ饰����ν�Ť�
		ΣꓤǤ���ȿ����Ƥ������� (���ä��� Plugins.link �ǥ�󥯤����顢�����
		�ǥץ饰������Ť������ץ����K�ˤ�ͬ�r���ԄӵĤ˽�Ť�����Τ���)��
	*/

	// �ץ�ѥƥ��_��
	// - �ޤ���TJS �Υ���`�Х륪�֥������Ȥ�ȡ�ä���
	iTJSDispatch2 * global = TVPGetScriptDispatch();

	// ��˥�`�Ͻ�Ť���ʤ��Ϥ��ʤΤǡ���ʾ�ĤˤϽ�Ť��ʤ�

	// - global �� DeleteMember �᥽�åɤ��ä������֥������Ȥ���������
	if(global)
	{
		// TJS ���夬�Ȥ˽�Ť���Ƥ����Ȥ��ʤɤ�
		// global �� NULL �ˤʤ�ä�Τ� global �� NULL �Ǥʤ�
		// ���Ȥ�����å�����

		global->DeleteMember( 0, TJS_W("MenuItem"), NULL, global );
	}

	// - global �� Release ����
	if(global) global->Release();

	// �����֤�ʹ�ýK��(�ؤ�ӛ������)
	TVPUninitImportStub();

	FreeMessage();
	return S_OK;
}
//---------------------------------------------------------------------------
