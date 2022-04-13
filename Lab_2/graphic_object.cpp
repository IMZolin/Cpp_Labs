#include "graphic_object.h"

void GraphicObject::Draw(SDL_Renderer* renderer)
{
	while (!traces.empty() && traces.front().getOpacity() <= 0) {
		traces.pop_front();
	}

	for (auto& trace : traces) {
		trace.Draw(renderer, length);
	}

	SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
	for (int i = 0; i < 6; i++) {
		SDL_RenderDrawLine(renderer, coord.getX(), coord.getY() + i, coord.getX() + MAX_LENGTH * length.getX(), coord.getY() + i);
	}
}

void GraphicObject::UpdateScreen(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
	this->Draw(renderer);
	SDL_RenderPresent(renderer);
}

void GraphicObject::ReduceOpacity()
{
	for (auto& trace : traces) {
		trace.setOpacity(trace.getOpacity() - 1);
	}
}

void GraphicObject::Move(SDL_Renderer* renderer)
{
	for (int i = 0; i < speed.length(); i++) {
		if ((coord + speed + length).getX() < WIN_WIDTH
			&& (coord + speed).getY() < WIN_HEIGHT
			&& (coord + speed).getX() > 0
			&& (coord + speed).getY() > 0) {
			traces.push_back(Trace(coord.getX(), coord.getY()));
			coord = coord + speed;
			this->UpdateScreen(renderer);
		}
	}

	this->ReduceOpacity();
}

void GraphicObject::CheckDirectionChanging(Vector2d tmp)
{
	if (speed.cos(tmp) == 1) {
		if (speed.length() < max_speed) {
			speed = speed + tmp;
		}
	}
	else {
		speed = tmp;
	}
}