

#ifndef __IME_CONTROL_H__
#define __IME_CONTROL_H__

#include <imm.h>
// imm32.lib
#include "TFont.h"

class ImeControl {
public:
	enum {
		ModeDisable,
		ModeClose,
		ModeOpen,
		ModeDontCare,
		ModeSAlpha,
		ModeAlpha,
		ModeHira,
		ModeSKata,
		ModeKata,
		ModeChinese,
		ModeSHanguel,
		ModeHanguel,
	};

private:
	HWND hWnd_;
	HIMC hOldImc_;
	bool default_open_;

public:
	ImeControl( HWND hWnd ) {
		hWnd_ = hWnd;
		default_open_ = IsOpen();
		hOldImc_ = INVALID_HANDLE_VALUE;
	}
	~ImeControl() {
	}
	bool IsOpen() {
		if( hOldImc_ != INVALID_HANDLE_VALUE ) return false;

		HIMC hImc = ::ImmGetContext(hWnd_);
		BOOL result = ::ImmGetOpenStatus(hImc);
		::ImmReleaseContext(hWnd_,hImc);
		return 0!=result;
	}
	void Open() {
		Enable();
		HIMC hImc = ::ImmGetContext(hWnd_);
		::ImmSetOpenStatus(hImc,TRUE);
		::ImmReleaseContext(hWnd_,hImc);
	}
	void Close() {
		Enable();
		HIMC hImc = ::ImmGetContext(hWnd_);
		::ImmSetOpenStatus(hImc,FALSE);
		::ImmReleaseContext(hWnd_,hImc);
	}
	bool IsEnableThisLocale() {
		HKL hKl = ::GetKeyboardLayout(0);
		return 0!=::ImmIsIME(hKl);
	}
	// ImmSetStatusWindowPos �v������ӳ����ȡ����ץꥱ�`������ IMN_SETSTATUSWINDOWPOS ��å��`�������Ť���ޤ���
	void SetStatusPosition( int x, int y ) {
		POINT pt = {x,y};
		HIMC hImc = ::ImmGetContext(hWnd_);
		::ImmSetStatusWindowPos( hImc, &pt );
		::ImmReleaseContext(hWnd_,hImc);
	}
	void GetStatusPosition( int &x, int &y ) {
		POINT pt = {0,0};
		HIMC hImc = ::ImmGetContext(hWnd_);
		::ImmGetStatusWindowPos( hImc, &pt );
		::ImmReleaseContext(hWnd_,hImc);
		x = pt.x;
		y = pt.y;
	}
	void Reset() {
		if( default_open_ ) {
			Open();
		} else {
			Close();
		}
	}
	/**
	 ���Υ���åɤ�IME��o���ˤ���
	 */
	void Disable() {
		if( hOldImc_ == INVALID_HANDLE_VALUE ) {
			hOldImc_ = ::ImmAssociateContext(hWnd_,0);
		}
	}
	void Enable() {
		if( hOldImc_ != INVALID_HANDLE_VALUE ) {
			::ImmAssociateContext(hWnd_,hOldImc_);
			hOldImc_ = INVALID_HANDLE_VALUE;
		}
	}
	// �����v������ӳ����ȡ����ץꥱ�`������ IMN_SETCOMPOSITIONFONT ��å��`�������Ť���ޤ���
	void SetCompositionFont( TFont* font ) {
		LOGFONT logfont={0};
		font->GetFont(&logfont);
		HIMC hImc = ::ImmGetContext(hWnd_);
		::ImmSetCompositionFont( hImc, &logfont );
		::ImmReleaseContext(hWnd_,hImc);
	}
	void SetCompositionWindow( int x, int y ) {
		COMPOSITIONFORM pos;
		pos.dwStyle = CFS_POINT;
		pos.ptCurrentPos.x = x;
		pos.ptCurrentPos.y = y;
		HIMC hImc = ::ImmGetContext(hWnd_);
		::ImmSetCompositionWindow( hImc, &pos );
		::ImmReleaseContext(hWnd_,hImc);
	}
	void GetCompositionWindow( int &x, int &y ) {
		COMPOSITIONFORM pos = {0};
		pos.dwStyle = CFS_POINT;
		HIMC hImc = ::ImmGetContext(hWnd_);
		::ImmGetCompositionWindow( hImc, &pos );
		::ImmReleaseContext(hWnd_,hImc);
		x = pos.ptCurrentPos.x;
		y = pos.ptCurrentPos.y;
	}
	/**
	 * conversion : ������`�ɤ΂���ָ�����ޤ���
	 * 		IME_CMODE_ALPHANUMERIC(0x0000) 	Ӣ����`��
	 * 		IME_CMODE_NATIVE(0x0001) 	�������Z����(ON)��Ӣ������(OFF) ��`��
	 * 		IME_CMODE_CHINESE
	 * 		IME_CMODE_HANGEUL
	 * 		IME_CMODE_JAPANESE �Ǥⶨ�x���Ƥ���
	 * 		IME_CMODE_KATAKANA(0x0002) 	��������(ON)���Ҥ餬��(OFF) ��`��
	 * 		IME_CMODE_FULLSHAPE(0x0008) 	ȫ�ǥ�`��
	 * 		IME_CMODE_ROMAN(0x0010) 	��`���֥�`��
	 * 		IME_CMODE_CHARCODE(0x0020) 	����饯��������`��
	 * 		IME_CMODE_HANJACONVERT(0x0040) 	�ϥ󥰥����։�Q��`��
	 * 		IME_CMODE_SOFTKBD(0x0080) 	���եȥ��`�ܩ`�ɥ�`��
	 * 		IME_CMODE_NOCONVERSION(0x0100) 	�o��Q��`��
	 * 		IME_CMODE_EUDC(0x0200) 	EUD��Q��`��
	 * 		IME_CMODE_SYMBOL(0x0400) 	����ܥ��`��
	 * sentence : ��Q��`�ɤ΂���ָ�����ޤ���
	 * 		IME_SMODE_NONE(0x0000) 	�o��Q
	 * 		IME_SMODE_PLURALCLAUSE(0x0001) 	�}���Z����
	 * 		IME_SMODE_SINGLECONVERT(0x0002) 	�g��Q
	 * 		IME_SMODE_AUTOMATIC(0x0004) 	�ԄӉ�Q
	 * 		IME_SMODE_PHRASEPREDICT(0x0008) 	�B�Ĺ���Q

imDisable ��ָ������ȡ�IME�ϟo���ˤʤ�ޤ���IME��ʹ�ä��������ϤǤ��ޤ��󤷡���`���β����Ǥ�IME���Є��ˤ��뤳�ȤϤǤ��ޤ���
	Disable
	
imClose ��ָ������ȡ�IME�ϟo���ˤʤ�ޤ���imDisable�Ȯ��ʤꡢ��`���β�����IME���Є��ˤ��뤳�Ȥ��Ǥ��ޤ���
	Close
	
imOpen ��ָ������ȡ�IME���Є��ˤʤ�ޤ���
	Open
	
imDontCare ��ָ������ȡ�IME���Є�/�o����״�B�ϡ�ǰ��״�B�������@���ޤ�����`���β����ˤ�ä�IME���Є��ˤ�����o���ˤ����ꤹ�뤳�Ȥ��Ǥ��ޤ����ձ��Z�����ˤ����Ƥϡ����/ȫ�����֤��`�������ɤ�������������Ϥ�һ��Ĥʥ�`�ɤǤ���
	
	
imSAlpha ��ָ������ȡ�IME���Є��ˤʤꡢ��ǥ���ե��٥å�������`�ɤˤʤ�ޤ���
	IME_CMODE_ALPHANUMERIC
	
imAlpha ��ָ������ȡ�IME���Є��ˤʤꡢȫ�ǥ���ե��٥å�������`�ɤˤʤ�ޤ���
	IME_CMODE_FULLSHAPE
	
imHira ��ָ������ȡ�IME���Є��ˤʤꡢ�Ҥ餬��������`�ɤˤʤ�ޤ���
imSKata ��ָ������ȡ�IME���Є��ˤʤꡢ��ǥ�������������`�ɤˤʤ�ޤ���
	IME_CMODE_KATAKANA
imKata ��ָ������ȡ�IME���Є��ˤʤꡢȫ�ǥ�������������`�ɤˤʤ�ޤ���
	IME_CMODE_KATAKANA IME_CMODE_NATIVE
imChinese ��ָ������ȡ�IME���Є��ˤʤꡢ2�Х����й��Z�������ܤ��������`�ɤˤʤ�ޤ����ձ��Z�h���Ǥ�ʹ�äǤ��ޤ���
	IME_CMODE_CHINESE
imSHanguel ��ָ������ȡ�IME���Є��ˤʤꡢ1�Х����n���Z�������ܤ��������`�ɤˤʤ�ޤ����ձ��Z�h���Ǥ�ʹ�äǤ��ޤ���
	IME_CMODE_HANJACONVERT
imHanguel ��ָ������ȡ�IME���Є��ˤʤꡢ2�Х����n���Z�������ܤ��������`�ɤˤʤ�ޤ����ձ��Z�h���Ǥ�ʹ�äǤ��ޤ���
	IME_CMODE_HANGEUL
	 */
	/*
	bool SetConversionStatus( int conversion, int sentence ) {
		return 0!=::ImmSetConversionStatus( hImc_, conversion, sentence );
	}
	*/
	void SetIme( int mode ) {
		HIMC hImc = ::ImmGetContext(hWnd_);
		DWORD conversion, sentence;
		::ImmGetConversionStatus( hImc, &conversion, &sentence );
		switch( mode ) {
		case ModeDisable:
			if( hOldImc_ == INVALID_HANDLE_VALUE ) {
				hOldImc_ = ::ImmAssociateContext(hWnd_,0);
			}
			break;
		case ModeClose:
			::ImmSetOpenStatus(hImc,FALSE);
			break;
		case ModeOpen:
			::ImmSetOpenStatus(hImc,TRUE);
			break;
		case ModeDontCare:
			break;
		case ModeSAlpha:
			::ImmSetOpenStatus(hImc,TRUE);
			::ImmSetConversionStatus( hImc, IME_CMODE_ALPHANUMERIC, sentence );
			break;
		case ModeAlpha:
			::ImmSetOpenStatus(hImc,TRUE);
			::ImmSetConversionStatus( hImc, IME_CMODE_ALPHANUMERIC | IME_CMODE_FULLSHAPE, sentence );
			break;
		case ModeHira:
			::ImmSetOpenStatus(hImc,TRUE);
			::ImmSetConversionStatus( hImc, IME_CMODE_NATIVE | IME_CMODE_FULLSHAPE, sentence );
			break;
		case ModeSKata:
			::ImmSetOpenStatus(hImc,TRUE);
			::ImmSetConversionStatus( hImc, IME_CMODE_NATIVE | IME_CMODE_KATAKANA, sentence );
			break;
		case ModeKata:
			::ImmSetOpenStatus(hImc,TRUE);
			::ImmSetConversionStatus( hImc, IME_CMODE_NATIVE | IME_CMODE_KATAKANA | IME_CMODE_FULLSHAPE, sentence );
			break;
		case ModeChinese:
			::ImmSetOpenStatus(hImc,TRUE);
			::ImmSetConversionStatus( hImc, IME_CMODE_NATIVE | IME_CMODE_FULLSHAPE, sentence );
			break;
		case ModeSHanguel:
			::ImmSetOpenStatus(hImc,TRUE);
			::ImmSetConversionStatus( hImc, IME_CMODE_NATIVE, sentence );
			break;
		case ModeHanguel:
			::ImmSetOpenStatus(hImc,TRUE);
			::ImmSetConversionStatus( hImc, IME_CMODE_NATIVE | IME_CMODE_FULLSHAPE, sentence );
			break;
		}
		::ImmReleaseContext(hWnd_,hImc);
	}
};


#endif // __IME_CONTROL_H__
