//---------------------------------------------------------------------------
// option information for kirikiri configurator
//---------------------------------------------------------------------------

#ifndef __OptionInfoH__
#define __OptionInfoH__

#include <windows.h>
#include "tp_stub.h"


//---------------------------------------------------------------------------
// GetOptionInfoString: returns option information string for kirikiri conf.
//---------------------------------------------------------------------------
static inline const wchar_t * GetOptionInfoString()
{
	if(GetACP() == 932) // 932 = Japan
	{
		return
L"デバッグ:ROTテ�`ブルへの鞠�h;ム�`ビ�`壅伏�rに"
L"ROT(Running Object Table)へ鞠�hするかどうかの�O協です。"
L"仝する々を�x�kすると、DirectX SDK原奉のGraphEditを喘いて"
L"ム�`ビ�`壅伏トラブルの盾裂を佩うことができます。仝ポ�`ズ々を�x�kすると、さらに"
L"グラフの���B岷瘁にメッセ�`ジボックスを燕幣して匯�r唯峭するようになります。|"
L"movie_reg_rot|select,*no;いいえ,yes;はい,pause;ポ�`ズ\n";
	}
	else
	{
		return
		// for other languages; currently only English information is available.
L"Debug:ROT registration;Whether to register into ROT(Running Object Table) when "
L"playbacking movies. Choosing 'Yes' enables you to inspect the trouble related with movies, "
L"using GraphEdit(available from DirectX SDK). 'Pause' not only enables ROT registeration, "
L"but makes the program also displaying message-box (this interrupts the program and makes a pause) "
L"after the graph is built.|"
L"movie_reg_rot|select,*no;No,yes;Yes,pause;Pause\n";
	}
}


//---------------------------------------------------------------------------
// GetShouldRegisterToROT: returns whether to register the process into ROT
//---------------------------------------------------------------------------
static inline bool GetShouldRegisterToROT()
{
	static bool cached = false;
	static bool state = false;
	if(!cached)
	{
		tTJSVariant val;
		if(TVPGetCommandLine(TJS_W("-movie_reg_rot"), &val))
		{
			if(ttstr(val) == TJS_W("yes") || ttstr(val) == TJS_W("pause") )
				state = true;
		}
		cached = true;
	}
	return state;
}
//---------------------------------------------------------------------------
// MakeAPause: display a message-box if the option specified it
//---------------------------------------------------------------------------
static inline void MakeAPause(bool _error)
{
	// _error specifies reason of this pause.
	// The pause is caused by an error during building graph if _error is true.
	// Successful if false.

	static bool cached = false;
	static bool state = false;
	if(!cached)
	{
		tTJSVariant val;
		if(TVPGetCommandLine(TJS_W("-movie_reg_rot"), &val))
		{
			if(ttstr(val) == TJS_W("pause")) state = true;
		}
		cached = true;
	}
	if(state)
	{
		MessageBox(TVPGetApplicationWindowHandle(),
			_error?
				_T("The graph was not properly built. Pausing."):
				_T("The graph was successfully built. Pausing."), _T("Pause"), MB_OK);
	}
}

#endif
