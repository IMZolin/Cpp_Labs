#ifndef VECTOR2D_H
#define VECTOR2D_H
#pragma once
#include <iostream>
#include <math.h>

class Vector2d
{
public:
	Vector2d(int x, int y) {
		this->x = x;
		this->y = y;
	}
	int getX() { return x; }
	int getY() { return y; }
	Vector2d operator +(Vector2d& right) const { return Vector2d(this->x + right.getX(), this->y + right.getY()); }
	Vector2d operator -(Vector2d& right) const { return Vector2d(this->x - right.getX(), this->y - right.getY()); }
	Vector2d operator *(Vector2d& right) const { return Vector2d(this->x * right.getX(), this->y * right.getY()); }
	//Vector2d operator ~=(Vector2d& v);
	double length() { return sqrt(this->x * this->x + this->y * this->y); }
	double cos(Vector2d right) { return (this->x * (double)right.x + this->y * (double)right.y) / sqrt(this->length() * this->length() * right.length() * right.length()); }
private:
    int x;
    int y;
};
#endif 