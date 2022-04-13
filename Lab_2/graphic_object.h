#ifndef GRAPHIC_OBJECT_H
#define GRAPHIC_OBJECT_H
#pragma once
#include "vector2d.h"
#include "trace.h"
#include"graphics.h"
#include <list>
using namespace std;
class GraphicObject
{
public:
	GraphicObject(int x, int y, int length) : speed(0, 0), length(length, 0), max_speed(5), coord(x, y) {}
	Vector2d getCoords() { return coord; }
	Vector2d getSpeed() { return speed; }
	Vector2d getLength() { return length; }
	list<Trace> getTraces() { return traces; }
	void SetSpeed(int speedX, int speedY){ this->speed = Vector2d(speedX, speedY); }
	void Draw(SDL_Renderer* renderer);
	void UpdateScreen(SDL_Renderer* renderer);
	void Move(SDL_Renderer* renderer);
	void ReduceOpacity();
	void CheckDirectionChanging(Vector2d tmp);
private:
	Vector2d coord;
	Vector2d speed;
	Vector2d length;
	int max_speed;
	std::list<Trace> traces;
};


#endif 