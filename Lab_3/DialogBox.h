#pragma once

#include <vector>

#include "SFML/Graphics.hpp"

#include "Button.h"

enum class DialogType
{
	NOTIFY,
	ERROR,
	QUESTION
};

class Button;
class Menu;

class DialogBox : public sf::RenderWindow
{
	//friend class Menu;

public:
	unsigned int id;

	DialogBox(unsigned int id, sf::Vector2f size, std::string name, std::string text, DialogType type = DialogType::NOTIFY,
		std::vector<Button> buttons = std::vector<Button>()) :
		id(id),
		size(size),
		name(name),
		type(type),
		buttons(buttons) {
		SetText(text); Init();
	};

	void Init();
	void SetText(std::string text);
	void Draw();
	DialogBox* Create();

private:
	DialogType type;
	std::vector<Button> buttons;
	sf::Vector2f size;
	sf::Vector2f textSize;
	sf::Font sfmlFont;
	sf::Text sfmlText;
	std::string name;
	std::string text;
};
