#include <chrono>
#include "../Skele_lib/utils/Utils.h"
struct Screen {
	static const int height = 56;
	static const int width = 100;
	static const int lastIndex = Screen::height * Screen::width - 1;
	static int toScreenChord(int x, int y) {
		return Screen::width * y + x;
	};
};
struct Game{
	static char bgChar;
	static wchar_t* screen;
	static int fps ; // the fps that the game should run at (defalt 10)
	static long frame;// the frame that the game is on 
	static void displayFrame() {
		Game::screen[2] = Skele_lib::Utils::longToChar(Game::frame);
		Game::screen[1] = Skele_lib::Utils::longToChar(Game::frame / 10);
		Game::screen[0] = Skele_lib::Utils::longToChar(Game::frame / 100);
	}
	static void display() {
		for (int y = 0; y < Screen::height; y++) {
			for (int x = 0; x < Screen::width; x++) {
					Game::screen[Screen::toScreenChord(x, y)] = Game::bgChar;
				if (y % 2 == 0) {
					Game::screen[Screen::toScreenChord(x,y)] = 2;
				}
				Game::displayFrame(); 
			}
		}
		Game::Wait();
		Game::screen[Screen::lastIndex] = '\0';
	}
	static void Wait() {
		/*wait loop */
		Tp2 = std::chrono::system_clock::now();
		std::chrono::duration<float> difference = Tp2 - Tp1;
		while (difference.count() < 1.0 / Game::fps) {
			Tp2 = std::chrono::system_clock::now();
			difference = Tp2 - Tp1;
		}
		/**reset the chrono time*/
		Tp1 = std::chrono::system_clock::now();

	}; 
	static std::chrono::time_point<std::chrono::system_clock> Tp1;
	static std::chrono::time_point<std::chrono::system_clock> Tp2;
};
int Game::fps = 10;
long Game::frame = 0; 
wchar_t* Game::screen = new wchar_t[Screen::lastIndex + 1];
char Game::bgChar = ' ';
std::chrono::time_point<std::chrono::system_clock> Game::Tp1 = std::chrono::system_clock::now();
std::chrono::time_point<std::chrono::system_clock> Game::Tp2 = std::chrono::system_clock::now();