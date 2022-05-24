#pragma once
#include <SFML/Graphics.hpp>	
#include <iostream>
#include "Ball.h"
const sf::Vector2f paddleSize(25, 100);
const sf::Time AITime = sf::seconds(0.1f);
const float paddleSpeed = 400.f;

class Paddles
{
public:
	Paddles();
	void Move(float deltaTime, const int gameHeight);
	void MovePlayer(float deltaTime, float speed) { this->shape[0].move(0.f, speed * deltaTime); };
	void MoveComputer(float deltaTime, float speed) { this->shape[1].move(0.f, speed * deltaTime); };
	sf::RectangleShape GetPlayerPaddle() { return this->shape[0]; }
	float GetPlayerPosX() { return this->shape[0].getPosition().x; }
	float GetPlayerPosY() { return this->shape[0].getPosition().y; }
	float GetPlayerSpeed() { return this->speed[0]; }
	sf::RectangleShape GetComputerPaddle() { return this->shape[1]; }
	float GetComputerPosX() { return this->shape[1].getPosition().x; }
	float GetComputerPosY() { return this->shape[1].getPosition().y; }
	float GetComputerSpeed() { return this->speed[1]; }

	void SetComputerSpeed(float sp) { speed[1] = sp; }
	void SetPlayerPosition(sf::Vector2f coord) { this->shape[0].setPosition(coord); }
	void SetComputerPosition(sf::Vector2f coord) { this->shape[1].setPosition(coord); }
	void UpdateDirection(Ball ball, sf::Clock& AITimer);
	void CheckCollisions(Ball& ball);
private:
	sf::RectangleShape shape[2];
	float speed[2];
	sf::Clock AITimer;
};
