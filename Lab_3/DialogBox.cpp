#include <iostream>

#include "DialogBox.h"

void DialogBox::Init()
{
	if (!buttons.empty())
	{
		return;
	}

	switch (type)
	{
	case DialogType::NOTIFY:
	{
		sf::Vector2f btnSize = sf::Vector2f(size.x / 5, size.y / 3 - 30);
		sf::Vector2f btnPosition = sf::Vector2f(size.x - 15 - btnSize.x, 2 * size.y / 3 + 15);
		Button* ok = new Button(0, btnSize, btnPosition, "OK");

		buttons.push_back(*ok);
	} break;

	case DialogType::ERROR:
	{
		sf::Vector2f btnSize = sf::Vector2f(size.x / 5, size.y / 3 - 30);
		sf::Vector2f btnPosition = sf::Vector2f(size.x - 15 - btnSize.x, 2 * size.y / 3 + 15);
		Button* cancel = new Button(0, btnSize, btnPosition, "Cancel");

		buttons.push_back(*cancel);
	} break;

	case DialogType::QUESTION:
	{
		sf::Vector2f yesSize = sf::Vector2f(size.x / 5, size.y / 3 - 30);
		sf::Vector2f yesPosition = sf::Vector2f(size.x - 15 - yesSize.x, 2 * size.y / 3 + 15);
		Button* yes = new Button(0, yesSize, yesPosition, "Yes");

		sf::Vector2f noSize = sf::Vector2f(size.x / 5, size.y / 3 - 30);
		sf::Vector2f noPosition = sf::Vector2f(size.x - 30 - noSize.x * 2, 2 * size.y / 3 + 15);
		Button* no = new Button(1, noSize, noPosition, "No");

		buttons.push_back(*yes);
		buttons.push_back(*no);
	} break;

	default:
		break;
	}

	for (auto& button : buttons)
	{
		button.SetWindow(this);
		button.SetMainColor(sf::Color(230, 230, 230));
		button.SetHoverColor(sf::Color(210, 210, 240));
		button.SetPressedColor(sf::Color(250, 250, 250));
	}

	if (!sfmlFont.loadFromFile("resources/sansation.ttf"))
	{
		std::cout << "Can't load font in DialogBox class" << std::endl;
	}

	sfmlText = sf::Text(text, sfmlFont, 16);
	sfmlText.setFillColor(sf::Color::Black);

	sf::Vector2f textPosition = sfmlText.getPosition();
	sf::Vector2f lastCharPosition = sfmlText.findCharacterPos(text.size());

	textSize = sf::Vector2f(abs(textPosition.x - lastCharPosition.x), abs(textPosition.y - sfmlText.getCharacterSize()));
	sfmlText.setPosition(sf::Vector2f(15, 15));
}

void DialogBox::SetText(std::string text)
{
	this->text = text;
}

void DialogBox::Draw()
{
	if (isOpen())
	{
		clear(sf::Color::White);

		sf::Event windowEvent;

		while (pollEvent(windowEvent))
		{
			if (windowEvent.type == sf::Event::Closed)
			{
				close();
			}
		}

		for (auto button : buttons)
		{
			button.CheckMouseEvent();

			switch (button.GetState())
			{
			case ButtonState::MAIN:
			{
				button.GetShape().setFillColor(button.GetMainColor());
			} break;

			case ButtonState::HOVER:
			{
				button.GetShape().setFillColor(button.GetHoverColor());
			} break;

			case ButtonState::PRESSED:
			{
				button.GetShape().setFillColor(button.GetPressedColor());
			} break;

			default:
			{
				button.GetShape().setFillColor(button.GetMainColor());
			} break;
			}

			draw(button.GetShape());
			draw(button.GetSFMLText());
		}

		draw(sfmlText);

		display();
	}
}

DialogBox* DialogBox::Create()
{
	create(sf::VideoMode(size.x, size.y), name, sf::Style::Titlebar | sf::Style::Close);

	return this;
}
