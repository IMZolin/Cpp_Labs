#pragma once
#include <iostream>
#include <conio.h>
using namespace std;
using std::string;
#pragma warning(disable : 4996)
class Point {
public:
    Point(int x, int y, int speed)
    {
        this->x = x;
        this->y = y;
        this->speed = speed;
    }
    Point& move(int tmpx, int tmpy)
    {
        this->x += tmpx;
        this->y += tmpy;
    }
    void set(int a, int b) {
        x = a;
        y = b;
    }
    void show()
    {
        std::cout << '('<< x << ',' << y <<')'<< std::endl;
        std::cout << "Speed: " << speed << std::endl;
    }
    int distance(Point& A, Point& B) {
       return sqrt((B.x - A.x) * (B.x - A.x) + (B.y - A.y) * (B.y - A.y));
    }
    void Format();
private:
    int x;
    int y;
    int speed;
};

class Segment : public Point
{
public:

    /*Segment(Point mA, Point mB, int speed)
    {
        A = mA;
        B = mB;
        speed = speed;
    }*///int Length(Segment s) { return sqrt((b.x - this->A.x) * (b.x - this->x) + (b.y - this->y) * (b.y - this->y)) }
    int length() { return distance(A, B); }
private:
    Point A;
    Point B;
    int speed;
};



