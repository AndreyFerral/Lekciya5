#undef UNICODE 
#include <Windows.h> 

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) {
	MessageBox(NULL, "Текст", "Текст", NULL);
}