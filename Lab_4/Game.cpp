#include "Game.h"

Game::Game()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	this->window.create(sf::VideoMode(gameWidth, gameHeight, 32), "SFML Pong",sf::Style::Titlebar | sf::Style::Close);
	this->window.setVerticalSyncEnabled(true);
	// Load the sounds used in the game
	sf::SoundBuffer ballSoundBuffer;
	ballSoundBuffer.loadFromFile("resources/ball.wav");
	sf::Sound ballSound(ballSoundBuffer);
	this->font.loadFromFile("resources/sansation.ttf");
	// Initialize the pause message
	this->pauseMessage.setFont(font);
	this->pauseMessage.setCharacterSize(40);
	this->pauseMessage.setPosition(170.f, 150.f);
	this->pauseMessage.setFillColor(sf::Color::White);
	this->pauseMessage.setString("Welcome to SFML pong!\nPress space to start the game");
	this->ball = Ball();
	this->paddles = Paddles();
}

void Game::ProcessEvents(sf::Clock clock, bool& state)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		// Window closed or escape key pressed: exit
		if ((event.type == sf::Event::Closed) ||
			((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
		{
			window.close();
			break;
		}
		// Space key pressed: play
		if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Space))
		{
			if (!state)
			{
				// (re)start the game
				state = true;
				clock.restart();
				// Reset the position of the paddles and ball
				SetPosPlayer({ (float)(10 + paddleSize.x / 2),(float)(gameHeight / 2) });
				SetPosComputer({ (float)(gameWidth - 10 - paddleSize.x / 2),(float)(gameHeight/2) });
				SetPosBall({ (float)(gameWidth / 2), (float)(gameHeight / 2) });
				// Reset the ball angle
				ResetBallAngle();
				std::cout << GetBall().GetAngle();
			}
		}	
	}
}

void Game::Update(bool& state, float deltaTime, sf::Clock& AITimer)
{
	/*Paddles p = GetPaddles();
	Ball ball = GetBall();*/

	MovePaddles(deltaTime);
	UpdateComputerDirection(AITimer);
	MoveBall(deltaTime);
	sf::String message;
	sf::String& str = message;
	checkBallCollisions(state,str);
	if (str != "")
		SetMessage(str);
	checkPaddlesCollisions(this->ball);
}

void Game::Render(bool& state)
{
	// Clear the window
	window.clear(sf::Color(50, 200, 50));
	if (state)
	{
		// Draw the paddles and the ball
		window.draw(GetPaddles().GetPlayerPaddle());
		window.draw(GetPaddles().GetComputerPaddle());
		window.draw(GetBall().GetShape());
	}
	else
	{
		// Draw the pause message
		window.draw(pauseMessage);
	}
	// Display things on screen
	window.display();
}

void Game::gameLoop()
{
	sf::Clock clock;
	sf::Clock aiTimer;
	bool isPlaying = false;
	bool& state = isPlaying;
	while (window.isOpen())
	{
		ProcessEvents(clock, state);
		if (state)
		{
			float deltaTime = clock.restart().asSeconds();
			Update(state,deltaTime, aiTimer);
		}	
		Render(state);
	}
}

