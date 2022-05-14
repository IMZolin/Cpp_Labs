#pragma once

#include <iostream>
#include <vector>

#include "SFML/Graphics.hpp"
#include "Button.h"

class Button;
class Menu;

class Window : public sf::RenderWindow
{
	//friend class Menu;

public:
	unsigned int id;

	Window(unsigned int id, sf::Vector2f size, std::string name, std::vector<Button*> buttons = std::vector<Button*>()) :
		id(id), size(size), name(name), RenderWindow() {
		this->buttons.push_back(buttons); Init();
	};
	size_t GetTabs() { return this->tabs; }
	Menu* GetParent() { return this->parent; }
	void SetParent(Menu* parent) { this->parent = parent; }
	void Init();
	void AddButton(Button* button, size_t tab);
	void Draw();
	void AddTab();
	void SwitchTab(size_t tab);
	Window* Create();

private:
	size_t tab;
	size_t tabs;
	Menu* parent;
	std::vector<std::vector<Button*>> buttons;
	std::string name;
	sf::Vector2f size;
};

