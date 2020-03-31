#include <windows.h>
WNDPROC OldWndProc; //переменная для хранения адреса старой оконной процедуры
LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wparam, LPARAM lparam) {
	switch (uMsg) {
	case WM_LBUTTONUP: MessageBeep(0xFFFFFFFF); break;
	default: return CallWindowProc(OldWndProc, hwnd, uMsg, wparam, lparam);
	}
	return (0);
}
int WINAPI WinMain(HINSTANCE hinst, HINSTANCE d2, LPSTR d3, int d4) {
	MSG msg;
	HWND hwnd;
	hwnd = CreateWindow(L"BUTTON", L"", 0, 0, 0, 0, 0, NULL, NULL, hinst, NULL);
	OldWndProc = (WNDPROC)SetClassLong(hwnd, GCL_WNDPROC, (LONG)WndProc);
	DestroyWindow(hwnd);
	MessageBox(NULL, L"Hello World", L"", MB_OK);
}