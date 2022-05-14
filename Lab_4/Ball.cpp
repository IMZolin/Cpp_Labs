#include "Ball.h"

Ball::Ball() 
{
	this->shape.setRadius(ballRadius - 3);
	this->shape.setOutlineThickness(3);
	this->shape.setFillColor(sf::Color::White);
	this->shape.setOrigin(ballRadius / 2, ballRadius / 2);
	this->shape.setOutlineColor(sf::Color::Black);
	this->ballAngle = 0.f;
	this->ballSpeed = 400.f;
}

void Ball::Move(float factor)
{
	GetShape().move(std::cos(GetAngle()) * factor, std::sin(GetAngle()) * factor);
}