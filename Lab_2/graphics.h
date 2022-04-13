#ifndef GRAPHICS_H
#define GRAPHICS_H
#pragma once
#include <iostream>
#include <list>
#include <math.h>
#include <SDL.h>
#include "vector2d.h"
#include "trace.h"
#include"graphic_object.h"
#define WIN_WIDTH 800
#define WIN_HEIGHT 600
#define X_START WIN_WIDTH/2
#define Y_START WIN_HEIGHT/2

static SDL_Window* window = NULL;
static SDL_Renderer* renderer = NULL;
static SDL_Event event;
void DeInit(int error);
void Init();
void Painter();
#endif 
