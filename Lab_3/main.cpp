#include <vector>
#include <functional>

#include "SFML/Graphics.hpp"
#include "Window.h"
#include "Button.h"
#include "DialogBox.h"
#include "Menu.h"

int main()
{
	/*Button button = Button(sf::Vector2f(150, 100), sf::Vector2f(50, 50), "ok, let's go");
	Button btn1 = Button(sf::Vector2f(150, 100), sf::Vector2f(50, 230), "sub menu");
	Button btn2 = Button(sf::Vector2f(150, 100), sf::Vector2f(50, 50), "YES!!!");
	button.onClick = Click0;
	btn1.onClick = Click1;
	std::vector<Button> btns;
	btns.push_back(button);
	btns.push_back(btn1);
	Window mainWindow = Window(sf::Vector2f(800, 600), "Hello", btns);
	mainWindow.AddTab();
	mainWindow.AddButton(&btn2, 1);
	mainWindow.Create();*/

	Menu menu = Menu("menu.txt");

	menu.GetButton(0)->onClick = [](Menu* menu) -> void*
	{
		menu->GetWindow(0)->SwitchTab(1);

		return NULL;
	};

	menu.GetButton(1)->onClick = [](Menu* menu) -> void*
	{
		menu->GetDialogBox(0)->Create();

		return NULL;
	};

	menu.GetButton(2)->onClick = [](Menu* menu) -> void*
	{
		menu->GetWindow(0)->SwitchTab(0);

		return NULL;
	};

	while (true)
	{
		menu.Draw();
	}

	return 0;
}
