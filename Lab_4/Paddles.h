#pragma once
#include <SFML/Graphics.hpp>	
#include <iostream>
const sf::Vector2f paddleSize(25, 100);
const sf::Time AITime = sf::seconds(0.1f);
const float paddleSpeed = 400.f;
class Paddles
{
public:
	Paddles();

	void Draw();
	void MovePaddles(float deltaTime, const int gameHeight);
	sf::RectangleShape GetPlayerPaddle() { return shape[0]; }
	float GetPlayerPosX() { return shape[0].getPosition().x; }
	float GetPlayerPosY() { return shape[0].getPosition().y; }
	float GetPlayerSpeed() { return speed[0]; }
	sf::RectangleShape GetComputerPaddle() { return shape[1]; }
	float GetComputerPosX() { return shape[1].getPosition().x; }
	float GetComputerPosY() { return shape[1].getPosition().y; }
	float GetComputerSpeed() { return speed[1]; }
	void SetComputerSpeed(float sp) { speed[1] = sp; }
	sf::Clock GetAITimer() { return this->AITimer; }
private:
	sf::RectangleShape shape[2];
	sf::RenderWindow* window;
	float speed[2];
	sf::Clock AITimer;
};
