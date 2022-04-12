/*
 * Reference:
 *    https://docs.microsoft.com/en-us/windows/win32/learnwin32/your-first-windows-program
 *    https://docs.microsoft.com/en-us/windows/win32/api/winuser/ns-winuser-wndclassa
 */

#ifndef UNICODE
#define UNICODE
#endif 

#include <windows.h>

#define	BACKGROUND_COLOR (HBRUSH) (COLOR_WINDOW + 1)

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

/*
 * ウィンドウプログラムエントリポイント関数
 */
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
    // ウィンドウクラス名
    const wchar_t CLASS_NAME[]  = L"ウィンドウ作成の学習用プログラムクラス";

    // ウィンドウタイトル
    const wchar_t WINDOW_TITLE[]  = L"ウィンドウプログラミング学習";

    // ウィンドウクラス構造体を用意
    WNDCLASS wc;

    wc.style         = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc   = WindowProc;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = hInstance;
    wc.hIcon         = NULL;
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = NULL;
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = CLASS_NAME;

    // style         ウィンドウクラススタイル
    // lpfnWndProc   ウィンドウプロシージャ
    // cbClsExtra    クラス構造体以降の追加確保分指定
    // cbWndExtra    ウィンドウインスタンス以降の追加確保分指定
    // hInstance     ウィンドウプロシージャインスタンス
    // hIcon         クラスアイコンハンドラ
    // hCursor       クラスカーソルハンドラ
    // hbrBackground ウィンドウ背景色
    // lpszMenuName  クラスメニューのリソース名
    // lpszClassName ウィンドウクラス名

    // ウィンドウクラス構造体を登録
    RegisterClass(&wc);

    // ウィンドウを作成
    HWND hwnd = CreateWindowEx(
        0,                   // 拡張ウィンドウスタイル
        CLASS_NAME,          // ウィンドウクラス名
        WINDOW_TITLE,        // ウィンドウタイトル
        WS_OVERLAPPEDWINDOW, // ウィンドウスタイル

        // サイズとポジション
        CW_USEDEFAULT, 	     // X座標
	CW_USEDEFAULT, 	     // Y座標
	1200, 	             // 幅
	800,	             // 高さ

        NULL,                // 親ウィンドウハンドラ
        NULL,                // メニューハンドラ
        hInstance,           // インスタンスハンドラ
        NULL                 // 追加のアプリケーションデータ
        );

    if (hwnd == NULL)
    {
        return 0;
    }

    // ウィンドウを表示
    ShowWindow(hwnd, nCmdShow);

    // メッセージループを実行
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

/*
 * ウィンドウプロシージャ関数
 */
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            FillRect(hdc, &ps.rcPaint, BACKGROUND_COLOR);

            EndPaint(hwnd, &ps);
        }
        return 0;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
