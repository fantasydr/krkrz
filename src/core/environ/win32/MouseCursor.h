

#ifndef __MOUSE_CURSOR_H__
#define __MOUSE_CURSOR_H__

#include "stdafx.h"

class MouseCursor {
	enum {
		CURSOR_APPSTARTING,	// �˜�ʸӡ���`���뤪���С��ɰ�rӋ���`����
		CURSOR_ARROW,		// �˜�ʸӡ���`����
		CURSOR_CROSS,		// ʮ�֥��`����
		CURSOR_HAND,		// �ϥ�ɥ��`����
		CURSOR_IBEAM,		// �����ө`�� (�k��) ���`����
		CURSOR_HELP,		// ʸӡ���Ɇ���
		CURSOR_NO,			// ��ֹ���`����
		CURSOR_SIZEALL,		// 4 ����ʸӡ���`����
		CURSOR_SIZENESW,	// б�����¤���΁I����ʸӡ���`����
		CURSOR_SIZENS,		// ���I����ʸӡ���`����
		CURSOR_SIZENWSE,	// б�����¤���΁I����ʸӡ���`����
		CURSOR_SIZEWE,		// ���ҁI����ʸӡ���`����
		CURSOR_UPARROW,		// ��ֱ��ʸӡ���`����
		CURSOR_WAIT,		// ɰ�rӋ���`���� 
		CURSOR_EOT,
	};
	static const LPTSTR CURSORS[CURSOR_EOT];
	static HCURSOR CURSOR_HANDLES[CURSOR_EOT];
	static const int INVALID_CURSOR_INDEX = 0x7FFFFFFF;
	static bool is_cursor_hide_;

public:
	static void Initialize();
	static void SetMouseCursor( int index );

private:
	HCURSOR hCursor_;
	int cursor_index_;

public:
	MouseCursor() : hCursor_(INVALID_HANDLE_VALUE), cursor_index_(INVALID_CURSOR_INDEX) {}
	MouseCursor( int index ) : hCursor_(INVALID_HANDLE_VALUE), cursor_index_(index) {}

	void SetCursor();

	bool IsCurrentCursor( int index ) {
		return cursor_index_ == index;
	}
	void SetCursorIndex( int index );
};

#endif
