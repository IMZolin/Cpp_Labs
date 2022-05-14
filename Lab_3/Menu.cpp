#include <sstream>
#include <iostream>
#include <fstream>

#include "Menu.h"

inline bool ValidStringPos(size_t marker)
{
	return marker != std::string::npos;
}

Menu::Menu(std::string fileName)
{
	if (!LoadFromFile(fileName))
	{
		std::cout << "Can't create object Menu" << std::endl;
	}
}

bool Menu::LoadFromFile(std::string fileName)
{
	if (fileName.empty())
	{
		std::cout << "Empty file name string" << std::endl;
	}

	std::ifstream input(fileName);

	if (!input.is_open())
	{
		std::cout << "Can't open file: " + fileName << std::endl;
		return false;
	}

	std::string line;

	struct
	{
		bool menu;
		bool window;
	} flags{ false, false };

	int marker;

	Window* curWindow = 0;

	while (std::getline(input, line))
	{
		if (flags.menu == false)
		{
			marker = line.find("&menu");
			if (!ValidStringPos(marker))
			{
				continue;
			}
			else
			{
				flags.menu = true;
			}
		}
		else
		{
			if (flags.window == true)
			{
				marker = line.find("&dialog_box");
				if (ValidStringPos(marker))
				{
					curWindow = NULL;
					flags.window = false;

					unsigned int id = 0;
					DialogType type;
					unsigned int width = 0;
					unsigned int height = 0;
					std::string name = "";
					std::string text = "";

					std::stringstream stream;

					for (int i = 0; i < 5; ++i)
					{
						if (std::getline(input, line))
						{
							marker = line.find("id");
							if (ValidStringPos(marker))
							{
								marker = line.find(':');
								stream << line.substr(marker + 1);
								stream >> id;

								stream.str("");
								stream.clear();

								continue;
							}

							marker = line.find("type");
							if (ValidStringPos(marker))
							{
								marker = line.find("error");
								if (ValidStringPos(marker))
								{
									type = DialogType::ERROR;
								}

								marker = line.find("notify");
								if (ValidStringPos(marker))
								{
									type = DialogType::NOTIFY;
								}

								marker = line.find("question");
								if (ValidStringPos(marker))
								{
									type = DialogType::QUESTION;
								}

								continue;
							}

							marker = line.find("size");
							if (ValidStringPos(marker))
							{
								marker = line.find(':');
								stream << line.substr(marker + 1);
								stream >> width;

								stream.str("");
								stream.clear();

								marker = line.find(',');
								stream << line.substr(marker + 1);
								stream >> height;

								stream.str("");
								stream.clear();

								continue;
							}

							marker = line.find("name");
							if (ValidStringPos(marker))
							{
								marker = line.find('"');
								stream << line.substr(marker + 1, line.find('"', marker + 1) - marker - 1);
								std::getline(stream, name);

								stream.str("");
								stream.clear();

								continue;
							}

							marker = line.find("text");
							if (ValidStringPos(marker))
							{
								marker = line.find('"');
								stream << line.substr(marker + 1, line.find_last_of('"') - marker - 1);
								std::getline(stream, text);

								stream.str("");
								stream.clear();

								continue;
							}
						}
					}

					DialogBox* dialogBox = new DialogBox(id, sf::Vector2f(width, height), name, text, type);
					dialogBoxes.push_back(dialogBox);
				}

				if (curWindow == nullptr)
				{
					curWindow = windows.back();
				}

				marker = line.find("&button");
				if (ValidStringPos(marker))
				{
					unsigned int id = 0;
					unsigned int xPos = 0;
					unsigned int yPos = 0;
					unsigned int width = 0;
					unsigned int height = 0;
					std::string text = "";

					std::stringstream stream;

					for (int i = 0; i < 4; i++)
					{
						if (std::getline(input, line))
						{
							marker = line.find("id");
							if (ValidStringPos(marker))
							{
								marker = line.find(':');
								stream << line.substr(marker + 1);
								stream >> id;

								stream.str("");
								stream.clear();

								continue;
							}

							marker = line.find("position");
							if (ValidStringPos(marker))
							{
								marker = line.find(':');
								stream << line.substr(marker + 1);
								stream >> xPos;

								stream.str("");
								stream.clear();

								marker = line.find(',');
								stream << line.substr(marker + 1);
								stream >> yPos;

								stream.str("");
								stream.clear();

								continue;
							}

							marker = line.find("size");
							if (ValidStringPos(marker))
							{
								marker = line.find(':');
								stream << line.substr(marker + 1);
								stream >> width;

								stream.str("");
								stream.clear();

								marker = line.find(',');
								stream << line.substr(marker + 1);
								stream >> height;

								stream.str("");
								stream.clear();

								continue;
							}

							marker = line.find("text");
							if (ValidStringPos(marker))
							{
								marker = line.find('"');
								stream << line.substr(marker + 1, line.find_last_of('"') - marker - 1);
								std::getline(stream, text);

								stream.str("");
								stream.clear();

								continue;
							}
						}
					}

					Button* button = new Button(id, sf::Vector2f(width, height), sf::Vector2f(xPos, yPos), text);
					curWindow->AddButton(button, curWindow->GetTabs() - 1);
					buttons.push_back(button);
				}

				marker = line.find("&sub_menu");
				if (ValidStringPos(marker))
				{
					curWindow->AddTab();
				}
			}
			else
			{
				marker = line.find("&window");
				if (marker != std::string::npos)
				{
					unsigned int id = 0;
					std::string name = "";
					unsigned int width = 0;
					unsigned int height = 0;

					std::stringstream stream;

					for (int i = 0; i < 3; ++i)
					{
						if (std::getline(input, line))
						{
							marker = line.find("id");
							if (ValidStringPos(marker))
							{
								marker = line.find(':');
								stream << line.substr(marker + 1);
								stream >> id;

								stream.str("");
								stream.clear();

								continue;
							}

							marker = line.find("name");
							if (ValidStringPos(marker))
							{
								marker = line.find('"');
								stream << line.substr(marker + 1, line.find('"', marker + 1) - marker - 1);
								std::getline(stream, name);

								stream.str("");
								stream.clear();

								continue;
							}

							marker = line.find("size");
							if (ValidStringPos(marker))
							{
								marker = line.find(':');
								stream << line.substr(marker + 1);
								stream >> width;

								stream.str("");
								stream.clear();

								marker = line.find(',');
								stream << line.substr(marker + 1);
								stream >> height;

								stream.str("");
								stream.clear();

								continue;
							}
						}
					}

					Window* wnd = new Window(id, sf::Vector2f(width, height), name);
					wnd->setFramerateLimit(60);
					wnd->SetParent(this);
					windows.push_back(wnd);
					curWindow = wnd;
					flags.window = true;

					continue;
				}

				marker = line.find("&dialog_box");
				if (ValidStringPos(marker))
				{
					curWindow = NULL;
					flags.window = false;

					unsigned int id = 0;
					DialogType type;
					unsigned int width;
					unsigned int height;
					std::string name;
					std::string text;

					std::stringstream stream;

					for (int i = 0; i < 5; ++i)
					{
						if (std::getline(input, line))
						{
							marker = line.find("id");
							if (ValidStringPos(marker))
							{
								marker = line.find(':');
								stream << line.substr(marker + 1);
								stream >> id;

								stream.str("");
								stream.clear();

								continue;
							}

							marker = line.find("type");
							if (ValidStringPos(marker))
							{
								marker = line.find("error");
								if (ValidStringPos(marker))
								{
									type = DialogType::ERROR;
								}

								marker = line.find("notify");
								if (ValidStringPos(marker))
								{
									type = DialogType::NOTIFY;
								}

								marker = line.find("question");
								if (ValidStringPos(marker))
								{
									type = DialogType::QUESTION;
								}

								continue;
							}

							marker = line.find("size");
							if (ValidStringPos(marker))
							{
								marker = line.find(':');
								stream << line.substr(marker + 1);
								stream >> width;

								stream.str("");
								stream.clear();

								marker = line.find(',');
								stream << line.substr(marker + 1);
								stream >> height;

								stream.str("");
								stream.clear();

								continue;
							}

							marker = line.find("name");
							if (ValidStringPos(marker))
							{
								marker = line.find('"');
								stream << line.substr(marker + 1, line.find('"', marker + 1) - marker - 1);
								std::getline(stream, name);

								stream.str("");
								stream.clear();

								continue;
							}

							marker = line.find("text");
							if (ValidStringPos(marker))
							{
								marker = line.find('"');
								stream << line.substr(marker + 1, line.find_last_of('"') - marker - 1);
								std::getline(stream, text);

								stream.str("");
								stream.clear();

								continue;
							}
						}
					}

					DialogBox* dialogBox = new DialogBox(id, sf::Vector2f(width, height), name, text, type);
					dialogBoxes.push_back(dialogBox);

					continue;
				}
			}
		}
	}

	if (!windows.empty())
	{
		windows[0]->Create();
	}
	else
	{
		if (!dialogBoxes.empty())
		{
			dialogBoxes[0]->Create();
		}
	}

	return true;
}

void Menu::Draw()
{
	for (auto window : windows)
	{
		window->Draw();
	}

	for (auto dialogBox : dialogBoxes)
	{
		dialogBox->Draw();
	}
}

Button* Menu::GetButton(unsigned int id)
{
	for (auto button : buttons)
	{
		if (button->id == id)
		{
			return button;
		}
	}
}

Window* Menu::GetWindow(unsigned int id)
{
	for (auto window : windows)
	{
		if (window->id == id)
		{
			return window;
		}
	}
}

DialogBox* Menu::GetDialogBox(unsigned int id)
{
	for (auto dialogBox : dialogBoxes)
	{
		if (dialogBox->id == id)
		{
			return dialogBox;
		}
	}
}
