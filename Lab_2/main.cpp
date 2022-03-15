#include"geometry.h"

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Event event;
void DeInit(int error)
{
	if (window != NULL)
	{
		SDL_DestroyWindow(window);
	}
	if (renderer != NULL)
	{
		SDL_DestroyRenderer(renderer);
	}
	SDL_Quit();
	exit(error);
}

void Init()
{
	const int window_width = 800;
	const int window_height = 300;
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		printf("Coudn't init SDL! Error: %s", SDL_GetError());
		system("pause");
		DeInit(1);
	}
	SDL_Window* window = SDL_CreateWindow("Window for lab", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, window_width, window_height, SDL_WINDOW_SHOWN | SDL_WINDOW_INPUT_GRABBED | SDL_WINDOW_RESIZABLE);
	if (window == NULL)
	{
		printf("Coudn't create window! Error: %s", SDL_GetError());
		system("pause");
		DeInit(1);
	}
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
	{
		printf("Coudn't create renderer! Error: %s", SDL_GetError());
		system("pause");
		DeInit(1);
	}
}

void Draw()
{

}

int main(int argc, char* argv[])
{
	int x_start = 0, y_start = 0;
	int x_finish = 1, y_finish = 1;
	int tmp_x = 1, tmp_y = 1;
	GeometricVector v(x_start, x_finish, y_start, y_finish,{ tmp_x,tmp_y });

	Init();
	SDL_Delay(5000);
	/*if (mySDL->key_wait(SDLK_ESCAPE)) exit(0);*/
	DeInit(0);
	return 0;
}