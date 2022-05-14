#pragma once
#include <SFML/Graphics.hpp>	
#include <iostream>
#include <cmath>
const float pi = 3.14159f;
const float ballRadius = 10.f;
class Ball
{
public:
	Ball();
	void Move(float factor);
	void Draw(sf::RenderWindow* window);
	sf::CircleShape GetShape() { return this->shape; }
	float GetAngle() { return this->ballAngle; }
	float GetSpeed() { return this->ballSpeed; }
	float GetPosX() { return GetShape().getPosition().x; }
	float GetPosY() { return GetShape().getPosition().y; }
	void SetAngle(float angle) { this->ballAngle = angle; }
private:
	sf::CircleShape shape;
	float ballSpeed;
	float ballAngle;
};

