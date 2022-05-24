#include "Paddles.h"
Paddles::Paddles()
{
	//1-st paddle (blue - player)
	this->shape[0].setFillColor(sf::Color(100, 100, 200));
	this->shape[0].setSize(paddleSize - sf::Vector2f(3, 3));
	this->shape[0].setOutlineThickness(3);
	this->shape[0].setOutlineColor(sf::Color::Black);
	this->shape[0].setOrigin(paddleSize / 2.f);
	this->speed[0] = 400.f;
	//2-nd paddle (red - computer)
	this->shape[1].setFillColor(sf::Color(200, 100, 100));
	this->shape[1].setSize(paddleSize - sf::Vector2f(3, 3));
	this->shape[1].setOutlineThickness(3);
	this->shape[1].setOutlineColor(sf::Color::Black);
	this->shape[1].setOrigin(paddleSize / 2.f);
	this->speed[1] = 0.f;
	SetPlayerPosition({ (float)(10 + paddleSize.x / 2), (400.f) });
	SetComputerPosition({(float)( 800 - 10 - paddleSize.x / 2),(float) (600 / 2 )});
}

void Paddles::Move(float deltaTime, const int gameHeight)
{
	// Move the player's paddle
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
		(GetPlayerPosY() - paddleSize.y / 2 > 5.f))
	{
		//std::cout << "Up \n";
		//std::cout << -GetPlayerSpeed() <<" " << deltaTime << "\n";
		//GetPlayerPaddle().move(0.f, -GetPlayerSpeed() * deltaTime);
		MovePlayer(deltaTime, -GetPlayerSpeed());
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
		(GetPlayerPosY() + paddleSize.y / 2 < gameHeight - 5.f))
	{
		//std::cout << "Down \n";
		//GetPlayerPaddle().move(0.f, GetPlayerSpeed() * deltaTime);
		MovePlayer(deltaTime, GetPlayerSpeed());
		//std::cout << GetPlayerSpeed() << " " << deltaTime << "\n";
	}

	// Move the computer's paddle
	if (((GetComputerSpeed() < 0.f) && (GetComputerPosY() - paddleSize.y / 2 > 5.f)) ||
		((GetComputerSpeed() > 0.f) && (GetComputerPosY() + paddleSize.y / 2 < gameHeight - 5.f)))
	{
		//std::cout << "AI \n";
		//GetComputerPaddle().move(0.f, GetComputerSpeed() * deltaTime);
		MoveComputer(deltaTime, GetComputerSpeed());
		//std::cout << GetPlayerSpeed() << " " << deltaTime << "\n";
	}
}

void Paddles::UpdateDirection(Ball ball, sf::Clock& AITimer)
{
	if (AITimer.getElapsedTime() > AITime)
	{
		AITimer.restart();
		if (ball.GetPosY() + ballRadius > GetComputerPosY() + paddleSize.y / 2)
			SetComputerSpeed(paddleSpeed);
		else if(ball.GetPosY() - ballRadius < GetComputerPosY() - paddleSize.y / 2)
			SetComputerSpeed(-paddleSpeed);
		else
			SetComputerSpeed(0.f);
		//std::cout << GetComputerSpeed() << "\n";
	}
}

void Paddles::CheckCollisions(Ball& ball)
{
	// Left Paddle
	if (ball.GetPosX() - ballRadius < GetPlayerPosX() + paddleSize.x / 2 &&
		ball.GetPosX() - ballRadius > GetPlayerPosX() &&
		ball.GetPosY() + ballRadius >= GetPlayerPosY() - paddleSize.y / 2 &&
		ball.GetPosY() - ballRadius <= GetPlayerPosY() + paddleSize.y / 2)
	{
		if (ball.GetPosY() > GetPlayerPosY())
			ball.SetAngle(pi - ball.GetAngle() + (std::rand() % 20) * pi / 180);
		else
			ball.SetAngle(pi - ball.GetAngle() - (std::rand() % 20) * pi / 180);
		ball.SetPosition({ GetPlayerPosX() + ballRadius + paddleSize.x / 2 + 0.1f, GetPlayerPosY() });
	}
	// Right Paddle
	if (ball.GetPosX() + ballRadius > GetComputerPosX() - paddleSize.x / 2 &&
		ball.GetPosX() + ballRadius < GetComputerPosX() &&
		ball.GetPosY() + ballRadius >= GetComputerPosY() - paddleSize.y / 2 &&
		ball.GetPosY() - ballRadius <= GetComputerPosY() + paddleSize.y / 2)
	{
		//std::cout << "BINGO\n";
		if (ball.GetPosY() > GetComputerPosY())
			ball.SetAngle(pi - ball.GetAngle() + (std::rand() % 20) * pi / 180);
		else
			ball.SetAngle(pi - ball.GetAngle() - (std::rand() % 20) * pi / 180);
		/*std::cout << "BEFORE\n";
		std::cout << ball.GetAngle() << "\n";*/
		ball.SetPosition({ GetComputerPosX() - ballRadius - paddleSize.x / 2 - 0.1f, ball.GetPosY()});
		/*std::cout << "AFTER\n";
		std::cout << ball.GetAngle() << "\n";*/
	}
}