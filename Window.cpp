#include "Window.h";
HANDLE Window::hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
DWORD Window::dwBytesWritten = 0;
