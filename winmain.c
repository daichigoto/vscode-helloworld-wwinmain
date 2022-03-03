/*
 * Reference:
 *    https://docs.microsoft.com/en-us/windows/win32/learnwin32/your-first-windows-program
 *    https://docs.microsoft.com/en-us/windows/win32/api/winuser/ns-winuser-wndclassa
 */

#ifndef UNICODE
#define UNICODE
#endif 

#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
    // ウィンドウクラス名
    const wchar_t CLASS_NAME[]  = L"ウィンドウ作成の学習用プログラムクラス";

    // ウィンドウクラス構造体を用意
    WNDCLASS wc;

    wc.style         = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc   = WindowProc;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = hInstance;
    wc.hIcon         = NULL;
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH) (COLOR_WINDOW + 1);
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = CLASS_NAME;

    // ウィンドウクラス構造体を登録
    RegisterClass(&wc);

    // ウィンドウを作成
    HWND hwnd = CreateWindowEx(
        0,                               // ウィンドウスタイル(オプション)
        CLASS_NAME,                      // ウィンドウクラス名
        L"ウィンドウプログラミング学習", // ウィンドウタイトル
        WS_OVERLAPPEDWINDOW,             // ウィンドウスタイル

        // サイズとポジション
        CW_USEDEFAULT, 
	CW_USEDEFAULT, 
	CW_USEDEFAULT, 
	CW_USEDEFAULT,

        NULL,       // 親ウィンドウ
        NULL,       // メニュー
        hInstance,  // インスタンスハンドル
        NULL        // 追加のアプリケーションデータ
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
 * ウィンドウプロシージャ
 */
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));

            EndPaint(hwnd, &ps);
        }
        return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
