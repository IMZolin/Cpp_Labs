#include "graphics.h"
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
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("Coudn't init SDL! Error: %s", SDL_GetError());
        system("pause");
        DeInit(1);
    }
    SDL_Window* window = SDL_CreateWindow("Window for lab", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_INPUT_GRABBED | SDL_WINDOW_RESIZABLE);
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

void KeyPressEvent(GraphicObject object, bool* quit)
{
    while (SDL_PollEvent(&event) != 0)
    {
        switch (event.type) 
        {
            case SDL_QUIT:
            // handling of close button
                *quit = 1;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_UP:
                        object.CheckDirectionChanging(Vector2d(0, -1));
                    case SDLK_DOWN:
                        object.CheckDirectionChanging(Vector2d(0, 1));
                    case SDLK_LEFT:
                        object.CheckDirectionChanging(Vector2d(-1, 0));
                    case SDLK_RIGHT:
                        object.CheckDirectionChanging(Vector2d(1, 0));
                    case SDLK_SPACE:
                        object.SetSpeed(0, 0);
                    case SDLK_ESCAPE:
                        *quit = 1;
                }
            default:
                *quit = 1;
                break;
        }
    }
}

void Painter()
{
    bool quit = false;
    GraphicObject object = GraphicObject(X_START, Y_START, MAX_LENGTH);
    object.UpdateScreen(renderer);
    while (!quit)
    {
        object.Move(renderer);
        SDL_Delay(10);
        KeyPressEvent(object, &quit);
    }
}