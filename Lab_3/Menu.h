#pragma once

#include <vector>

#include "Button.h"
#include "DialogBox.h"
#include "Window.h"

class Menu
{
public:
	Menu(std::vector<Window*> windows = std::vector<Window*>(),
		std::vector<DialogBox*> dialogBoxes = std::vector<DialogBox*>(),
		std::vector<Button*> buttons = std::vector<Button*>()) :
		windows(windows),
		dialogBoxes(dialogBoxes),
		buttons(buttons) {};
	Menu(std::string fileName);

	bool LoadFromFile(std::string fileName);
	void Draw();
	Button* GetButton(unsigned int id);
	DialogBox* GetDialogBox(unsigned int id);
	Window* GetWindow(unsigned int id);

private:
	std::vector<Window*> windows;
	std::vector<DialogBox*> dialogBoxes;
	std::vector<Button*> buttons;
};

