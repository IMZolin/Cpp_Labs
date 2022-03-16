#pragma once
#include <iostream>
#include <conio.h>
#include<SDL.h>
#include "color.h"

using namespace std;
using std::string;
using std::memcmp;
#pragma warning(disable : 4996)


class vector2D
{
public:
    vector2D();
    vector2D(double x_, double y_);
    vector2D(const vector2D& v);

    vector2D& operator=(const vector2D& v);

    vector2D operator+(const vector2D& v) const;
    vector2D operator-(const vector2D& v) const;
    vector2D operator-() const;
    vector2D operator*(const double i) const;
    vector2D operator/(const double i) const;

    vector2D& operator+=(const vector2D& v);
    vector2D& operator-=(const vector2D& v);
    vector2D& operator*=(const double i);
    vector2D& operator/=(const double i);

    inline double x() const { return x_; }
    inline double y() const { return y_; }

    inline void setX(double x) { x_ = x; }
    inline void setY(double y) { y_ = y; }

    double lenght() const;

private:
    double x_;
    double y_;
};



