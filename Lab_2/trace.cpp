#include "trace.h"

void Trace::Draw(SDL_Renderer* renderer, Vector2d length)
{
	SDL_SetRenderDrawColor(renderer, 255 - opacity, 255, 255, 255);
	for (int i = 0; i < 6; i++) {
		SDL_RenderDrawLine(renderer, coord.getX(), coord.getY() + i, coord.getX() + MAX_LENGTH * length.getX(), coord.getY() + i);
	}
}