/*the includes*/
#include <iostream>
#include <Windows.h>
#include <winuser.h>
#include "Game.cpp"
bool bUsePlayerColision = true;
//windows vars
int main()
{
	/**windows vars */
	wchar_t* screen = new wchar_t[Screen::width * Screen::height];
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD dwBytesWritten = 0;
	/**set up the wait loop*/
	
	
	bool playing = true;
	/**game loop*/
	while (playing) {
		Game::display();
		Game::frame++;
		/**write the screen to the buffer*/
		WriteConsoleOutputCharacter(hConsole, Game::screen, Screen::lastIndex + 1, { 0,0 }, &dwBytesWritten);
	}
}