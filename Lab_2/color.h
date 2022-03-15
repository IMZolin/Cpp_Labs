#pragma once
#include <iostream>
#include <conio.h>
#include<SDL.h>
class Color {
public:
    Color(Uint8 red, Uint8 green, Uint8 blue) : R(red), G(green), B(blue) {};
    double R, G, B;
};