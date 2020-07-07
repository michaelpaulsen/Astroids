#pragma once
#include "Screen.h"
class Player {
	int x, y, r;
public:
	Player() {
		this->x = 0;
		this->y = 0;
		this->r = 0;
	}
	Player(int x, int y) {
		this->x = x;
		this->y = y;
		this->r = 0;
	}
	int getX() {
		return this->x;
	}
	int getY() {
		return this->y;
	}
	int getR() {
		return this->r;
	}
	void setX(int n) {
		this->x = n;
	}
	void setY(int n) {
		this->y = n;
	}
	void setR(int n) {
		this->r = n;
	}
	char getDisplayCharFromAngle() {
		if (this->r < 90) {
			return '╩';
		}
		else if (this->r < 180) {
			return '╠';
		}
		else if (this->r < 270) {
			return '╦';
		}
		else {
			return '╣';
		}
	}
};