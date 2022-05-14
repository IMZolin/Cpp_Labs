#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Paddles.h"
#include "Ball.h"
const int gameWidth = 800;
const int gameHeight = 600;

class Game
{
public:
	Game();
	//Main game function 
	void gameLoop();
	// Handle events
	void ProcessEvents();
	// Update the computer's paddle direction according to the ball position
	void UpdateComputerDirection();
	//Update objects
	void Update(float deltaTime);
	//Draw objects
	void Render();
	// Check collisions between the ball and the screen
	void checkBallCollisions();
	// Check the collisions between the ball and the paddles
	void checkPaddlesCollisions();

	bool getIsPlaying() { return this->isPlaying; }
	void setIsPlaying(bool state) { this->isPlaying = state; }
	sf::Clock getClock() { return this->clock; }
	Ball GetBall() { return this->ball; }
	Paddles GetPaddles() { return this->paddles; }
	void SetBall(Ball ball) { this->ball = ball; }
private:
	bool isPlaying;
	sf::Clock clock;
	sf::RenderWindow window;
	Ball ball;
	Paddles paddles;
	sf::Sound sound;
	sf::Font font;
	sf::Text pauseMessage;
};

																																																																																																																																																																																																																																																																																																																		