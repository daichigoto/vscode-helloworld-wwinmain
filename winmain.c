/*
 * Reference:
 *    https://docs.microsoft.com/en-us/windows/win32/learnwin32/your-first-windows-program
 */

#ifndef UNICODE
#define UNICODE
#endif 

#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
    // Register the window class.
    const wchar_t CLASS_NAME[]  = L"Sample Window Class";
    
    WNDCLASS wc;

    wc.lpfnWndProc   = WindowProc;
    //wc.lpfnWndProc   = DefWindowProc;
    wc.hInstance     = hInstance;
    wc.lpszClassName = CLASS_NAME;

    wc.style         = CS_HREDRAW | CS_VREDRAW;
//    wc.cbClsExtra    = 0;
//    wc.cbWndExtra    = 0;
//    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
//    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
//    wc.hbrBackground = (HBRUSH) (COLOR_WINDOW + 1);
//    wc.lpszMenuName  = NULL;

    RegisterClass(&wc);

if (RegisterClass(&wc)) {
  MessageBox(NULL, L"RegisterClass OK", L"DEBUG", MB_OK);
}
else {
  MessageBox(NULL, L"RegisterClass NG", L"DEBUG", MB_OK);
}


    // Create the window.

    HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles.
        CLASS_NAME,                     // Window class
        L"Learn to Program Windows",    // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,       // Parent window    
        NULL,       // Menu
        hInstance,  // Instance handle
        NULL        // Additional application data
        );

    if (hwnd == NULL)
    {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    // Run the message loop.

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

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
