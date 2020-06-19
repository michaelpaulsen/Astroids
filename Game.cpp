#include "Game.h"
int Game::fps = 10;
long Game::frame = 0; 
wchar_t* Game::screen = new wchar_t[Screen::lastIndex + 1];
char Game::bgChar = ' ';
std::chrono::time_point<std::chrono::system_clock> Game::Tp1 = std::chrono::system_clock::now();
std::chrono::time_point<std::chrono::system_clock> Game::Tp2 = std::chrono::system_clock::now();