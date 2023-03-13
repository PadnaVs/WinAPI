// ls_7.1_M_P.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "ls_7.1_M_P.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_LS71MP, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LS71MP));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LS71MP));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LS71MP);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}


HANDLE hMutex;


HWND SetElement(HWND hDlg, HDC& mem, WORD IdBitmap, WORD IdProgress)
{
    HBITMAP hBitmap = LoadBitmap(hInst, MAKEINTRESOURCE(IdBitmap));
    HDC hdc = GetDC(hDlg);
    mem = CreateCompatibleDC(hdc);
    ReleaseDC(hDlg, hdc);
    SelectObject(mem, hBitmap);
    HWND handle = GetDlgItem(hDlg, IdProgress);
    SendMessage(handle, PBM_SETRANGE, 0, 30 << 16);
    SendMessage(handle, PBM_SETSTEP, 1, 0);
    SendMessage(handle, PBM_SETPOS, 0, 0);
    return handle;
}



unsigned __stdcall MyThread1(void* param) {
    HWND hWnd = (HWND)param;
    HDC hdc, mem;
    int t = 0;
    HWND hProgress = SetElement(hWnd, mem, IDB_BITMAP1, IDC_PROGRESS1);
    while (1)
    {
        WaitForSingleObject(hMutex, INFINITE);
        hdc = GetDC(hWnd);
        BitBlt(hdc, 370, 70, 50, 50, mem, 0, 0, SRCCOPY);
        ReleaseDC(hWnd, hdc);
        Sleep(500);
        if (++t > 30) t = 0;
        SendMessage(hProgress, PBM_SETPOS, t, 0);
        ReleaseMutex(hMutex);
    }
    return 0;
}

unsigned __stdcall MyThread2(void* param)
{
    HWND hWnd = (HWND)param;
    HDC hdc, mem;
    int t = 0;
    HWND hProgress = SetElement(hWnd, mem, IDB_BITMAP2, IDC_PROGRESS2);
    while (1)
    {
        WaitForSingleObject(hMutex, INFINITE);
        hdc = GetDC(hWnd);
        BitBlt(hdc, 370, 70, 50, 50, mem, 0, 0, SRCCOPY);
        ReleaseDC(hWnd, hdc);
        Sleep(500);
        if (++t > 30) t = 0;
        SendMessage(hProgress, PBM_SETPOS, t, 0);
        ReleaseMutex(hMutex);
    }
    return 0;
}

//INT_PTR CALLBACK Dialog1(HWND, UINT, WPARAM, LPARAM);


INT_PTR CALLBACK Dialog(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_INITDIALOG:
        static HANDLE hThread1, hThread2;
        //InitCommonControls();
        hMutex = CreateMutex(NULL, FALSE, NULL);
        hThread1 = (HANDLE)_beginthreadex(NULL, 0, MyThread1, hDlg, 0, NULL);
        hThread2 = (HANDLE)_beginthreadex(NULL, 0, MyThread2, hDlg, 0, NULL);
        return 1;
    case WM_COMMAND:
        if (LOWORD(wParam) == IDCANCEL)
        {
            TerminateThread(hThread1, 0);
            TerminateThread(hThread2, 0);
            CloseHandle(hThread1);
            CloseHandle(hThread2);
            EndDialog(hDlg, 0);
            return 1;
        }
        break;
    }
    return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message) {
    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case ID_SEMAPHORE:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, (DLGPROC)Dialog);
            break;
        case IDM_EXIT: DestroyWindow(hWnd); break;
        default: return DefWindowProc(hWnd, message, wParam, lParam);
        }
        break;
    case WM_DESTROY: PostQuitMessage(0); break;
    default: return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}



INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
