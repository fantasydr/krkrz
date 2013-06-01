#include <windows.h>
#include "tp_stub.h"
#include "KAGParser.h"

//---------------------------------------------------------------------------
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved) {
	return 1;
}
//---------------------------------------------------------------------------
static tjs_int GlobalRefCountAtInit = 0;
extern "C" __declspec(dllexport) HRESULT _stdcall V2Link(iTVPFunctionExporter *exporter)
{
	// �����֤γ��ڻ�(�ؤ�ӛ������)
	TVPInitImportStub(exporter);

	tTJSVariant val;

	// TJS �Υ���`�Х륪�֥������Ȥ�ȡ�ä���
	iTJSDispatch2 * global = TVPGetScriptDispatch();

	{
		//-----------------------------------------------------------------------
		iTJSDispatch2 * tjsclass = TVPCreateNativeClass_KAGParser();
		val = tTJSVariant(tjsclass);
		tjsclass->Release();
		global->PropSet( TJS_MEMBERENSURE, TJS_W("KAGParser"), NULL, &val, global );
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

		global->DeleteMember( 0, TJS_W("KAGParser"), NULL, global );
	}

	// - global �� Release ����
	if(global) global->Release();

	// �����֤�ʹ�ýK��(�ؤ�ӛ������)
	TVPUninitImportStub();

	return S_OK;
}
//---------------------------------------------------------------------------
