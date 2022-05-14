#include "Window.h"

void Window::Init()
{
	tab = 0;
	tabs = 1;

	for (auto& button : buttons[0])
	{
		button->Init();
		button->Init();
	}
}

void Window::Draw()
{
	if (isOpen())
	{
		clear();

		if (tab >= tabs)
		{
			tab = 0;
		}

		sf::Event windowEvent;

		while (pollEvent(windowEvent))
		{
			if (windowEvent.type == sf::Event::Closed)
			{
				close();
			}
		}

		for (auto button : buttons[tab])
		{
			ButtonEvent event = button->CheckMouseEvent();

			if (event == ButtonEvent::CLICK)
			{
				if (button->onClick != NULL)
				{
					button->onClick(parent);
				}
			}

			switch (button->GetState())
			{
			case ButtonState::MAIN:
			{
				button->GetShape().setFillColor(button->GetMainColor());
			} break;

			case ButtonState::HOVER:
			{
				button->GetShape().setFillColor(button->GetHoverColor());
			} break;

			case ButtonState::PRESSED:
			{
				button->GetShape().setFillColor(button->GetPressedColor());
			} break;

			default:
			{
				button->GetShape().setFillColor(button->GetMainColor());
			} break;
			}

			draw(button->GetShape());
			draw(button->GetSFMLText());
		}

		display();
	}
}

Window* Window::Create()
{
	create(sf::VideoMode(size.x, size.y), name, sf::Style::Titlebar | sf::Style::Close);

	return this;
}

void Window::AddButton(Button* button, size_t tab)
{
	if (tab >= tabs)
	{
		return;
	}
	//sf::RenderWindow* window = button->GetWindow();
	button->SetWindow(this);
	//button->GetWindow() = this;

	buttons[tab].push_back(button);
}

void Window::AddTab()
{
	++tabs;

	buttons.push_back(std::vector<Button*>());
}

void Window::SwitchTab(size_t tab)
{
	if (tab >= tabs)
	{
		return;
	}

	this->tab = tab;
}
