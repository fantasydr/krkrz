

#ifndef __MOUSE_CURSOR_H__
#define __MOUSE_CURSOR_H__

#include "stdafx.h"

class MouseCursor {
	enum {
		CURSOR_APPSTARTING,	// 標準矢印カーソルおよび小型砂時計カーソル
		CURSOR_ARROW,		// 標準矢印カーソル
		CURSOR_CROSS,		// 十字カーソル
		CURSOR_HAND,		// ハンドカーソル
		CURSOR_IBEAM,		// アイビーム (縦線) カーソル
		CURSOR_HELP,		// 矢印と疑問符
		CURSOR_NO,			// 禁止カーソル
		CURSOR_SIZEALL,		// 4 方向矢印カーソル
		CURSOR_SIZENESW,	// 斜め左下がりの両方向矢印カーソル
		CURSOR_SIZENS,		// 上下両方向矢印カーソル
		CURSOR_SIZENWSE,	// 斜め右下がりの両方向矢印カーソル
		CURSOR_SIZEWE,		// 左右両方向矢印カーソル
		CURSOR_UPARROW,		// 垂直の矢印カーソル
		CURSOR_WAIT,		// 砂時計カーソル 
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
