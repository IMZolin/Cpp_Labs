#ifndef TRACE_H
#define TRACE_H
#pragma once
#include <SDL.h>
#include "vector2d.h"
#define MAX_LENGTH 7
class Trace
{
public:
	Trace(int x, int y) : coord(x, y), opacity(200) {};
	int getOpacity() {return opacity;}
	void setOpacity(int opacity) { this->opacity = opacity; }
	void Draw(SDL_Renderer* renderer, Vector2d length);
private:
	Vector2d coord;
	int opacity;
};

#endif 