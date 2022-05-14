#pragma once

#include <iostream>
#include <vector>
#include <functional>

#include "SFML/Graphics.hpp"
#include "Window.h"
#include "DialogBox.h"

enum class ButtonState
{
	MAIN,
	HOVER,
	PRESSED
};

enum class ButtonEvent
{
	NONE,
	HOVER,
	CLICK
};

class Window;
class DialogBox;
class Menu;

class Button
{
	//friend class Window;
	//friend class DialogBox;
	//friend class Menu;

public:
	unsigned int id;

	static const sf::Color mainColorDefault;
	static const sf::Color hoverColorDefault;
	static const sf::Color pressedColorDefault;

	Button(unsigned int id, sf::Vector2f size, sf::Vector2f position, std::string text) :
		id(id),
		size(size),
		position(position),
		text(text)
	{
		mainColor = mainColorDefault;
		hoverColor = hoverColorDefault;
		pressedColor = pressedColorDefault;

		state = ButtonState::MAIN;

		shape = sf::RectangleShape(size);
		shape.setFillColor(mainColor);
		shape.setPosition(position);

		if (!Init())
		{
			std::cout << "Can't init button" << std::endl;
		}
	};

	bool Init();

	ButtonEvent CheckMouseEvent();
	void SetMainColor(sf::Color color);
	void SetHoverColor(sf::Color color);
	void SetPressedColor(sf::Color color);
	//void SetTextColor(sf::Color color);
	void SetState(ButtonState state);
	void SetWindow(sf::RenderWindow* window);
	ButtonState GetState() { return this->state; }
	sf::RenderWindow* GetWindow() { return this->window; }
	sf::RectangleShape GetShape() { return this->shape; }
	sf::Color GetMainColor() { return this->mainColor; }
	sf::Color GetHoverColor() { return this->hoverColor; }
	sf::Color GetPressedColor() { return this->pressedColor; }
	sf::Text GetSFMLText() { return this->sfmlText; }
	std::function<void* (Menu*)> onClick;
	//void* (*onClick)(Window*, Button*);

private:
	sf::RenderWindow* window;
	Window* parent;
	sf::RectangleShape shape;
	sf::Color mainColor;
	sf::Color hoverColor;
	sf::Color pressedColor;
	sf::Vector2f position;
	sf::Vector2f size;
	sf::Text sfmlText;
	sf::Font sfmlFont;
	sf::Vector2f textSize;

	std::string text;

	ButtonState state;
};
