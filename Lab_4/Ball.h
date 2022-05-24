#pragma once
#include <SFML/Graphics.hpp>	
#include <iostream>
#include <cmath>
const float pi = 3.14159f;
const float ballRadius = 10.f;
//float Angle = 0.f;
class Ball
{
public:
	Ball();
	void Move(float deltaTime);
	sf::CircleShape GetShape() { return this->shape; }
	float GetAngle() { return this->ballAngle; }
	float GetSpeed() { return this->ballSpeed; }
	float GetPosX() { return this->shape.getPosition().x; }
	float GetPosY() { return this->shape.getPosition().y; }
	void SetAngle(float angle) { this->ballAngle = angle; }
	void SetPosition(sf::Vector2f coord) { this->shape.setPosition(coord); }
	void SetSpeed(float speed) { this->ballSpeed = speed; }
	void ResetAngle();
	void CheckCollisions(bool& isPlaying, sf::String& message, const int gameWidth, const int gameHeight);
private:
	sf::CircleShape shape;
	float ballSpeed;
	float ballAngle;
};

