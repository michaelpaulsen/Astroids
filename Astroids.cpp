/*the includes*/
#include <iostream>
#include <Windows.h>
#include <winuser.h>
#include "Window.cpp"
#include "Game.cpp"
#include "Player.h"
#include "../Skele_lib/utils/Utils.h"
int main()
{
	
	Player player1 = Player(Screen::width/2,Screen::height/2);

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