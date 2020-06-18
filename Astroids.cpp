/*the includes*/
#include <iostream>
#include <Windows.h>
#include <winuser.h>
#include "Window.cpp"
#include "Game.cpp"
int main()
{
	/**windows vars */
	SetConsoleActiveScreenBuffer(Window::hConsole);
	bool playing = true;
	/**game loop*/
	while (playing) {
		Game::display();
		Game::frame++;

		/**write the screen to the buffer*/
		WriteConsoleOutputCharacter(Window::hConsole, Game::screen, Screen::lastIndex + 1, { 0,0 }, &Window::dwBytesWritten);
	}
}