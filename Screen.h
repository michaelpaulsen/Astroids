#pragma once
struct Screen {
	static const int height = 56;
	static const int width = 100;
	static const int lastIndex = Screen::height * Screen::width - 1;
	static int toScreenChord(int x, int y) {
		return Screen::width * y + x;
	};
};
