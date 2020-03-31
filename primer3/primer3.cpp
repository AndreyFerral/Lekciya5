#include "framework.h"
#include <Windows.h>
WNDPROC OldWndProc; // глоб. переменная - для хранения адреса старой оконной функции
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); // объявление новой оконной функции


int APIENTRY _tWinMain(HINSTANCE hInstance,   // дескриптор текущего приложения
	HINSTANCE hPrevInstance, // В современных системах всегда 0
	LPTSTR    lpCmdLine,     // Командная строка
	int       nCmdShow)	  // Режим отображения окна
{
	MSG msg;

	// <--- начало фрагмента кода некоторой функции ---
	// создание суперкласса "button".
	WNDCLASS wc;
	//Берем структуру описания окна из стандартного класса кнопки и
	GetClassInfo(hInstance, L"button", &wc);
	//Заполняем её поля своими значениями
	wc.lpszClassName = L"beepbutton";
	wc.hInstance = hInstance;
	OldWndProc = wc.lpfnWndProc;
	wc.lpfnWndProc = (WNDPROC)WndProc;
	//и регистрируем новое окно, которое будет работать как кнопка, но со звуком
	RegisterClass(&wc);
	//создаем кнопку нового класса на экране
	HWND hWnd = CreateWindow(L"beepbutton", L"superclassing", WS_VISIBLE | BS_CENTER,
		100, 100, 200, 50, NULL, NULL, hInstance, NULL);
	// --- конец фрагмента кода некоторой функции --->

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (int)msg.wParam;
}

//Собственная оконная процедура, которую ставим в новом классе кнопки
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg) {
	case WM_LBUTTONDOWN: MessageBeep(-1);
	default: return CallWindowProc(OldWndProc, hWnd, msg, wParam, lParam);
	}
	return 0l;
}
