#include "Ball.h"

Ball::Ball() 
{
	this->shape.setRadius(ballRadius - 3);
	this->shape.setOutlineThickness(3);
	this->shape.setFillColor(sf::Color::White);
	this->shape.setOrigin(ballRadius / 2, ballRadius / 2);
	this->shape.setOutlineColor(sf::Color::Black);
	this->ballAngle = 0.f;
	SetSpeed(200.f);
	this->shape.setPosition({ 400.f, 300.f });
	SetPosition({ 400.f, 300.f });
}

void Ball::ResetAngle()
{
	do
	{
		SetAngle((float)((std::rand() % 360) * 2 * pi / 360));
	} while (std::abs(std::cos(GetAngle()) < 0.7f));
}
void Ball::Move(float deltaTime)
{
	float factor = GetSpeed() * deltaTime;
	this->shape.move(std::cos(GetAngle()) * factor, std::sin(GetAngle()) * factor); 
	//std::cout << "After move ball " << GetPosX() <<"; " << GetPosY() <<"\n";
}

void Ball::CheckCollisions(bool& isPlaying, sf::String& message, const int gameWidth, const int gameHeight)
{
	if (GetPosX() - ballRadius < 0.f)
	{
		isPlaying = false;
		message.clear();
		message.insert(0, "You lost!\nPress space to restart or\nescape to exit");
	}
	if (GetPosX() + ballRadius > gameWidth)
	{
		isPlaying = false;
		message.clear();
		message.insert(0, "You won!\nPress space to restart or\nescape to exit");
	}
	if (GetPosY() - ballRadius < 0.f)
	{
		SetAngle(-GetAngle());
		SetPosition({ GetPosX(), ballRadius + 0.1f });
		/*isPlaying = false;
		message.clear();
		message.insert(0, "Up");*/
	}
	if (GetPosY() + ballRadius > gameHeight)
	{
		SetAngle(-GetAngle());
		SetPosition({ GetPosX(), gameHeight - ballRadius - 0.1f });
		/*isPlaying = false;
		message.clear();
		message.insert(0, "Down");*/
	}
}