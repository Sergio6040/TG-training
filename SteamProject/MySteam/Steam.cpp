#include "Steam.h"
#include <iostream>

FSteam::FSteam()
{
	MenuActive = MainMenu;
}

void FSteam::RunApp()
{
	while (true)
	{
		int UserOption;
		std::cout << "------ Welcome to Steam! ------" << std::endl;
		std::cout << "\t1 - Add New game \n\t2 - Working on... \n\t3 - Working on... \n\t4 - Exit \n" << ">>";
		std::cin >> UserOption;

		switch (UserOption)
		{
		case AddGame:
			OpenAddGameMenu();
			break;

		case ShowCategories:
			break;

		case ShowGames:
			break;

		case Exit:
			//MenuActive = Exit;
			exit(1);
			break;

		default:
			std::cin.clear();
			std::cin.ignore(100, '\n');
			break;
		}

		system("cls");
	}
}

void FSteam::OpenAddGameMenu()
{
	if (MainHandler.GetCategoriesAmount() > 0)
	{
		char UserChoice;
		do
		{
			std::cout << "Do you want to add the game to an existing category?(y/n)\n" << ">>";
			std::cin >> UserChoice;

			if (UserChoice == 'y')
			{
			}
			else if (UserChoice == 'n')
			{
				break;
			}
			else
			{
				UserChoice = 'r';
				std::cin.clear();
				std::cin.ignore(100, '\n');
			}

		} while (UserChoice == 'r');

	}
}

