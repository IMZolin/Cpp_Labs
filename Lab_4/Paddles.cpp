#include "Paddles.h"
Paddles::Paddles()
{
	//1-st paddle (blue)
	this->shape[0].setFillColor(sf::Color(100, 100, 200));
	this->shape[0].setSize(paddleSize - sf::Vector2f(3, 3));
	this->shape[0].setOutlineThickness(3);
	this->shape[0].setOutlineColor(sf::Color::Black);
	this->shape[0].setOrigin(paddleSize / 2.f);
	this->speed[0] = 400.f;
	//2-nd paddle (red)
	this->shape[1].setFillColor(sf::Color(200, 100, 100));
	this->shape[1].setSize(paddleSize - sf::Vector2f(3, 3));
	this->shape[1].setOutlineThickness(3);
	this->shape[1].setOutlineColor(sf::Color::Black);
	this->shape[1].setOrigin(paddleSize / 2.f);
	this->speed[1] = 0.f;
}

void Paddles::MovePaddles(float deltaTime, const int gameHeight)
{
	// Move the player's paddle
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
		(GetComputerPosY() - paddleSize.y / 2 > 5.f))
	{
		GetPlayerPaddle().move(0.f, -GetPlayerSpeed() * deltaTime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
		(GetComputerPosY() + paddleSize.y / 2 < gameHeight - 5.f))
	{
		GetPlayerPaddle().move(0.f, GetPlayerSpeed() * deltaTime);
	}

	// Move the computer's paddle
	if (((GetComputerSpeed() < 0.f) && (GetComputerPaddle().getPosition().y - paddleSize.y / 2 > 5.f)) ||
		((GetComputerSpeed() > 0.f) && (GetComputerPaddle().getPosition().y + paddleSize.y / 2 < gameHeight - 5.f)))
	{
		GetComputerPaddle().move(0.f, GetComputerSpeed() * deltaTime);
	}
}

void Paddles::Draw()
{
	
}