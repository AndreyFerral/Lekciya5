#include <windows.h>
WNDPROC OldWndProc; //переменная для хранения адреса старой оконной процедуры
//Это наша процедура обработки сообщений кнопки
LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wparam, LPARAM lparam) {
    switch (uMsg) {
    case WM_LBUTTONUP: DestroyWindow(hwnd); break;
    case WM_DESTROY: PostQuitMessage(0); break;
    default: //Все сообщения, кроме первых двух, отправляем на обработку в
    // стандартную оконную процедуру кнопки
        return CallWindowProc(OldWndProc, hwnd, uMsg, wparam, lparam);
    }
    return (0);
}
//А это главный модуль программы
int WINAPI WinMain(HINSTANCE hinst, HINSTANCE d2, LPSTR d3, int d4) {
    MSG msg;
    HWND hwnd;
    //Создаем стандартное окно кнопки
    hwnd = CreateWindow(L"BUTTON", L"Hello World!!!", WS_VISIBLE | BS_CENTER, 100,
        100, 100, 80, NULL, NULL, hinst, NULL);
    //Меняем на нем стандартную процедуру на свою. Адрес старой процедуры - запоминаем
    OldWndProc = (WNDPROC)SetWindowLong(hwnd, GWL_WNDPROC, (LONG)WndProc);
    while (GetMessage(&msg, NULL, 0, 0))
        DispatchMessage(&msg);
    return (msg.wParam);
}
