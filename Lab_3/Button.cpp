#include "Button.h"
#include "Window.h"

const sf::Color Button::mainColorDefault = sf::Color::White;
const sf::Color Button::hoverColorDefault = sf::Color(200, 200, 255, 255);
const sf::Color Button::pressedColorDefault = sf::Color::Blue;

bool Button::Init()
{

	if (!sfmlFont.loadFromFile("resources/sansation.ttf"))
	{
		std::cout << "Can't load font in Button class" << std::endl;
		return false;
	}
	sfmlText = sf::Text(text, sfmlFont, 16);
	sfmlText.setFillColor(sf::Color::Black);

	sf::Vector2f textPosition = sfmlText.getPosition();
	sf::Vector2f lastCharPosition = sfmlText.findCharacterPos(text.size());

	textSize = sf::Vector2f(abs(textPosition.x - lastCharPosition.x), abs(textPosition.y - sfmlText.getCharacterSize()));
	sfmlText.setPosition(sf::Vector2f(position.x + (size.x - textSize.x) / 2, position.y + (size.y - textSize.y) / 2));

	return true;
}

ButtonEvent Button::CheckMouseEvent()
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
	if (mousePos.x >= this->position.x && mousePos.x <= (this->position.x + this->size.x))
	{
		if (mousePos.y >= this->position.y && mousePos.y <= (this->position.y + this->size.y))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			{
				if (state != ButtonState::PRESSED)
				{
					SetState(ButtonState::PRESSED);
					return ButtonEvent::CLICK;
				}
			}
			else
			{
				if (state != ButtonState::HOVER)
				{
					SetState(ButtonState::HOVER);
					return ButtonEvent::HOVER;
				}
			}
		}
	}

	SetState(ButtonState::MAIN);
	return ButtonEvent::NONE;
}

void Button::SetState(ButtonState state)
{
	this->state = state;
}

void Button::SetWindow(sf::RenderWindow* window)
{
	this->window = window;
}

void Button::SetMainColor(sf::Color color)
{
	mainColor = color;
}

void Button::SetHoverColor(sf::Color color)
{
	hoverColor = color;
}

void Button::SetPressedColor(sf::Color color)
{
	pressedColor = color;
}
