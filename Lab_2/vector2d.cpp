#include"vector2d.h"
vector2D::vector2D() : x_(0.0), y_(0.0)
{
}

vector2D::vector2D(double x, double y) : x_(x), y_(y)
{
}

vector2D::vector2D(const vector2D& v) : x_(v.x_), y_(v.y_)
{
}

vector2D& vector2D::operator=(const vector2D& v)
{
    if (&v != this)
    {
        x_ = v.x_;
        y_ = v.y_;
    }
    return *this;
}

vector2D vector2D::operator+(const vector2D& v) const
{
    return vector2D(x_ + v.x_, y_ + v.y_);
}

vector2D vector2D::operator-(const vector2D& v) const
{
    return vector2D(x_ - v.x_, y_ - v.y_);
}

vector2D vector2D::operator-() const
{
    return vector2D(-x_, -y_);
}

vector2D vector2D::operator*(const double i) const
{
    return vector2D(x_ * i, y_ * i);
}

vector2D vector2D::operator/(const double i) const
{
    return vector2D(x_ / i, y_ / i);
}

vector2D& vector2D::operator+=(const vector2D& v)
{
    x_ += v.x_;
    y_ += v.y_;
    return *this;
}

vector2D& vector2D::operator-=(const vector2D& v)
{
    x_ -= v.x_;
    y_ -= v.y_;
    return *this;
}

vector2D& vector2D::operator*=(const double i)
{
    x_ *= i;
    y_ *= i;
    return *this;
}

vector2D& vector2D::operator/=(const double i)
{
    x_ /= i;
    y_ /= i;
    return *this;
}

double vector2D::lenght() const
{
    return sqrt(pow(x_, 2) + pow(y_, 2));
}
