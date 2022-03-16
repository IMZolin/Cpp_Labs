#include"vector2d.h"
#define SPEED 10
vector2D speedX(SPEED, 0);
vector2D speedY(0, SPEED);
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
void KeyPressEvent(vector2D v)
{
	while (SDL_PollEvent(&event) != 0)
	{
		if (event.type == SDL_KEYDOWN)
		{
			switch (event.key.keysym.sym)
			{
				case SDLK_UP:
					v += speedY;
				case SDLK_DOWN:
					v -= speedY;
				case SDLK_RIGHT:
					v += speedX;
				case SDLK_LEFT:
					v -= speedX;

				default:
					break;
			}		
		}
		exit(1);
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
	//vector2D v(x_start, x_finish, y_start, y_finish,{ tmp_x,tmp_y });

	Init();
	SDL_Delay(5000);
	/*if (mySDL->key_wait(SDLK_ESCAPE)) exit(0);*/
	DeInit(0);
	return 0;
}