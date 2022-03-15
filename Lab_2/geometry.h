#pragma once
#include <iostream>
#include <conio.h>
#include<SDL.h>
#include "color.h"
using namespace std;
using std::string;
using std::memcmp;
#pragma warning(disable : 4996)

class GeometricVector
{
private:
    int x1;
    int x2;
    int y1; 
    int y2;
    int length;
    struct speed_t {
        int tmpx; 
        int tmpy;
    }speed;
public:
    GeometricVector(int x1, int x2,int y1,int y2, speed_t speed)
    {
        this->x1 = x1;
        this->x2 = x2;
        this->y1 = y1;
        this->y2 = y2;
        this->length = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        this->speed = speed;
    }
    int GetLength(GeometricVector v)
    {
        return sqrt((v.x2 - v.x1) * (v.x2 - v.x1) + (v.y2 - v.y1) * (v.y2 - v.y1));
    }
    GeometricVector& operator +=(const GeometricVector& v2)
    {
        return *this;
    }
    friend GeometricVector operator +(GeometricVector v1, const GeometricVector& v2)
    {
        v1 += v2;
        return v1;
    }
    GeometricVector& operator++()
    {
        // actual increment takes place here
        return *this; // return new value by reference
    }

    // postfix increment
    GeometricVector operator++(int)
    {
        GeometricVector old = *this; // copy old value
        operator++();  // prefix increment
        return old;    // return old value
    }

    // prefix decrement
    GeometricVector& operator--()
    {
        // actual decrement takes place here
        return *this; // return new value by reference
    }

    // postfix decrement
    GeometricVector operator--(int)
    {
        GeometricVector old = *this; // copy old value
        operator--();  // prefix decrement
        return old;    // return old value
    }
    bool isPoint(GeometricVector v)
    {
        if (v.x1 == v.x2 && v.y1 == v.y2)
            return true;
        else
            return false;
    }
};



