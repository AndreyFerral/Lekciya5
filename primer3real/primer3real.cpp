#include <windows.h>
WNDPROC OldWndProc; //переменная для хранения адреса старой оконной процедуры
LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wparam, LPARAM lparam) {
	switch (uMsg) {
	case WM_LBUTTONUP: MessageBeep(0xFFFFFFFF); break;
	default: return CallWindowProc(OldWndProc, hwnd, uMsg, wparam, lparam);
	}
	return (0);
}
int WINAPI DllMain(HINSTANCE hInstance, HANDLE hModule, DWORD dwReason, LPVOID lpReserved) {
	HWND hwnd;
	switch (dwReason) {
	case DLL_PROCESS_ATTACH:
		hwnd = CreateWindow(L"BUTTON", L"", 0, 0, 0, 0, 0, NULL, NULL, hInstance, NULL);
		OldWndProc = (WNDPROC)SetClassLong(hwnd, GCL_WNDPROC, (LONG)WndProc);
	DestroyWindow(hwnd);
	}
	return TRUE;
}