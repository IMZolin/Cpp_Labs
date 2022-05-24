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
	void ProcessEvents(sf::Clock clock, bool& state);
	// Update the computer's paddle direction according to the ball position
	void UpdateComputerDirection(sf::Clock& AITimer) { this->paddles.UpdateDirection(this->ball, AITimer); }
	//Update objects
	void Update(bool& state,float deltaTime, sf::Clock& AITimer);
	//Draw objects
	void Render(bool& state);
	// Check collisions between the ball and the screen
	void checkBallCollisions(bool& state, sf::String& str) { this->ball.CheckCollisions(state, str, gameWidth, gameHeight); }
	// Check the collisions between the ball and the paddles
	void checkPaddlesCollisions(Ball& ball){ this->paddles.CheckCollisions(ball); }
	// Move the ball
	void MoveBall(float deltaTime) { this->ball.Move(deltaTime); };
	// Move the player's and computer's paddles
	void MovePaddles(float deltaTime) { this->paddles.Move(deltaTime, gameHeight); };

	Ball& GetBall() { return this->ball; }
	Paddles& GetPaddles() { return this->paddles; }
	void SetPosBall(sf::Vector2f coord) { this->ball.SetPosition(coord); }
	void SetPosPlayer(sf::Vector2f coord) { this->paddles.SetPlayerPosition(coord); }
	void SetPosComputer(sf::Vector2f coord) { this->paddles.SetComputerPosition(coord); }
	void ResetBallAngle() { this->ball.ResetAngle(); }
	void SetMessage(sf::String& str) { this->pauseMessage.setString(str); }
private:
	sf::RenderWindow window;
	Ball ball;
	Paddles paddles;
	sf::Font font;
	sf::Text pauseMessage;
};

																																																																																																																																																																																																																																																																																																																		