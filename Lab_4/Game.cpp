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
	this->sound = ballSound;
	this->font.loadFromFile("resources/sansation.ttf");
	// Initialize the pause message
	this->pauseMessage.setFont(font);
	this->pauseMessage.setCharacterSize(40);
	this->pauseMessage.setPosition(170.f, 150.f);
	this->pauseMessage.setFillColor(sf::Color::White);
	this->pauseMessage.setString("Welcome to SFML pong!\nPress space to start the game");
	this->isPlaying = false;
	this->ball = Ball();
	this->paddles = Paddles();
}

void Game::ProcessEvents()
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
			if (!getIsPlaying())
			{
				// (re)start the game
				setIsPlaying(true);
				getClock().restart();
				// Reset the position of the paddles and ball
				GetPaddles().GetPlayerPaddle().setPosition(10 + paddleSize.x / 2, gameHeight / 2);
				GetPaddles().GetComputerPaddle().setPosition(gameWidth - 10 - paddleSize.x / 2, gameHeight / 2);
				GetBall().GetShape().setPosition(gameWidth / 2, gameHeight / 2);

				// Reset the ball angle
				do
				{
					// Make sure the ball initial angle is not too much vertical
					GetBall().SetAngle((std::rand() % 360) * 2 * pi / 360);
				} while (std::abs(std::cos(GetBall().GetAngle())) < 0.7f);
			}
		}	
	}
}

void Game::UpdateComputerDirection()
{
	if (GetPaddles().GetAITimer().getElapsedTime() > AITime)
	{
		GetPaddles().GetAITimer().restart();
		if (GetBall().GetPosY() + ballRadius > GetPaddles().GetComputerPosY() + paddleSize.y / 2)
			GetPaddles().SetComputerSpeed(paddleSpeed);
		else if(GetBall().GetPosY() - ballRadius < GetPaddles().GetComputerPosY() - paddleSize.y / 2)
			GetPaddles().SetComputerSpeed(-paddleSpeed);
		else
			GetPaddles().SetComputerSpeed(0.f);
	}
}

void Game::checkBallCollisions()
{
	if (GetBall().GetShape().getPosition().x - ballRadius < 0.f)
	{
		setIsPlaying(false);
		pauseMessage.setString("You lost!\nPress space to restart or\nescape to exit");
	}
	if (GetBall().GetPosX() + ballRadius > gameWidth)
	{
		isPlaying = false;
		pauseMessage.setString("You won!\nPress space to restart or\nescape to exit");
	}
	if (GetBall().GetPosY() - ballRadius < 0.f)
	{
		sound.play();
		GetBall().SetAngle(-GetBall().GetAngle());
		GetBall().GetShape().setPosition(GetBall().GetPosX(), ballRadius + 0.1f);
	}
	if (GetBall().GetPosY() + ballRadius > gameHeight)
	{
		sound.play();
		GetBall().SetAngle(-GetBall().GetAngle());
		GetBall().GetShape().setPosition(GetBall().GetPosX(), gameHeight - ballRadius - 0.1f);
	}
}

void Game::checkPaddlesCollisions()
{
	// Left Paddle
	if (GetBall().GetPosX() - ballRadius < GetPaddles().GetPlayerPosX() + paddleSize.x / 2 &&
		GetBall().GetPosX() - ballRadius > GetPaddles().GetPlayerPosX() &&
		GetBall().GetPosY() + ballRadius >= GetPaddles().GetPlayerPosY() - paddleSize.y / 2 &&
		GetBall().GetPosY() - ballRadius <= GetPaddles().GetPlayerPosY() + paddleSize.y / 2)
	{
		if (GetBall().GetPosY() > GetPaddles().GetPlayerPosY())
			GetBall().SetAngle(pi - GetBall().GetAngle() + (std::rand() % 20) * pi / 180);
		else
			GetBall().SetAngle(pi - GetBall().GetAngle() - (std::rand() % 20) * pi / 180);

		sound.play();
		GetBall().GetShape().setPosition(GetPaddles().GetPlayerPosX() + ballRadius + paddleSize.x / 2 + 0.1f, GetPaddles().GetPlayerPosY());
	}
	// Right Paddle
	if (GetBall().GetPosX() + ballRadius > GetPaddles().GetComputerPosX() - paddleSize.x / 2 &&
		GetBall().GetPosX() + ballRadius < GetPaddles().GetComputerPosX() &&
		GetBall().GetPosY() + ballRadius >= GetPaddles().GetComputerPosY() - paddleSize.y / 2 &&
		GetBall().GetPosY() - ballRadius <= GetPaddles().GetComputerPosY() + paddleSize.y / 2)
	{
		if (GetBall().GetPosY() > GetPaddles().GetComputerPosY())
			GetBall().SetAngle(pi - GetBall().GetAngle() + (std::rand() % 20) * pi / 180);
		else
			GetBall().SetAngle(pi - GetBall().GetAngle() - (std::rand() % 20) * pi / 180);

		sound.play();
		GetBall().GetShape().setPosition(GetPaddles().GetComputerPosX() - ballRadius - paddleSize.x / 2 - 0.1f, GetPaddles().GetComputerPosY());
		GetBall().GetShape().setPosition(GetPaddles().GetComputerPosX() - ballRadius - paddleSize.x / 2 - 0.1f, GetPaddles().GetComputerPosY());
	}
}

void Game::Update(float deltaTime)
{
	// Move the player's and computer's paddles
	GetPaddles().MovePaddles(deltaTime, gameHeight);

	// Update the computer's paddle direction according to the ball position
	UpdateComputerDirection();

	// Move the ball
	float factor = GetBall().GetSpeed() * deltaTime;
	GetBall().Move(factor);

	// Check collisions between the ball and the screen
	checkBallCollisions();

	// Check the collisions between the ball and the paddles
	checkPaddlesCollisions();
}

void Game::Render()
{
	// Clear the window
	window.clear(sf::Color(50, 200, 50));
	if (getIsPlaying())
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
	while (window.isOpen())
	{
		ProcessEvents();
		if (getIsPlaying())
		{
			float deltaTime = getClock().restart().asSeconds();
			Update(deltaTime);
		}	
		Render();
	}
}

