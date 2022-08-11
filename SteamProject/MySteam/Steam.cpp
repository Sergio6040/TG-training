#include "Steam.h"
#include <iostream>


void FSteam::RunApp()
{
	while (true)
	{
		int UserOption;
		std::cout << "------ Welcome to Steam! ------" << std::endl;
		std::cout << "\t1 - Add New game \n\t2 - Categories Menu... \n\t3 - Show Games... \n\t4 - Exit \n" << ">>";
		std::cin >> UserOption;

		switch (UserOption)
		{
		case AddGame:
			OpenAddGameMenu();
			break;

		case ShowCategories:
			OpenCategoriesMenu();
			break;

		case ShowGames:
			break;

		case Exit:
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


int FSteam::ValidateInput(const std::string Question)
{
	bool bRepeat;
	do
	{
		std::cout << Question << " >>";
		int Input;
		std::cin >> Input;

		if (std::cin.fail())
		{
			bRepeat = true;
			std::cin.clear();
			std::cin.ignore(100, '\n');
			system("cls");
		}
		else
		{
			bRepeat = false;
			return Input;
		}

	} while (bRepeat);
}

FGame FSteam::AskForNewGame()
{
	bool bRepeat;
	do
	{
		system("cls");

		std::cout << "Enter the game name >>";
		std::string NewGameName;
		std::cin >> NewGameName;

		std::cout << "Enter the name of the studio that develop the game >>";
		std::string NewStudioName;
		std::cin >> NewStudioName;

		int GameDay = ValidateInput("Enter the release day");
		int GameMonth = ValidateInput("Enter the release month");
		int GameYear = ValidateInput("Enter the release year");

		FGame NewGame = FGame(NewGameName, NewStudioName, GameDay, GameMonth, GameYear);

		if (NewGame.IsValid())
		{
			bRepeat = false;
			return NewGame;
		}
		else
		{
			bRepeat = true;
		}

	} while (bRepeat);
}

void FSteam::OpenAddGameMenu()
{
	FGame NewGame = AskForNewGame();

	bool bGameAdded;
	char UserChoice;
	do
	{
		system("cls");
		std::cout << "Do you want to add the game to an existing category?(y/n)\n" << ">>";
		std::cin >> UserChoice;

		if (MainHandler.GetCategoriesAmount() <= 0)
		{
			UserChoice = 'n';
		}

		if (UserChoice == 'y')
		{
			system("cls");
			MainHandler.ShowCategories();
			std::cout << "\nSelect a category >>";
			int CategoryIndex;
			std::cin >> CategoryIndex;

			if (CategoryIndex >= 0 && CategoryIndex < MainHandler.GetCategoriesAmount() && !std::cin.fail())
			{
				bGameAdded = MainHandler.AddGameToCategory(CategoryIndex, NewGame);
				std::cout << "Adding game to " << MainHandler.GetCategory(CategoryIndex).GetCategoryName() << std::endl;
			}
			else
			{
				//repeat loop
				UserChoice = 'r';
				std::cin.clear();
				std::cin.ignore(100, '\n');
			}

		}
		else if (UserChoice == 'n')
		{
			std::cout << "Adding game to Uncategorized" << std::endl;
			bGameAdded =  Uncategorized.AddGame(NewGame);
			break;
		}
		else
		{
			//repeat loop
			UserChoice = 'r';
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}

	} while (UserChoice == 'r');

	if (bGameAdded)
	{
		std::cout << "Game added!" << std::endl;
	}
	else
	{
		std::cout << "Fail to add game!" << std::endl;
	}

}

void FSteam::OpenCategoriesMenu()
{
	int CategoriesOption;
	do
	{
		system("cls");
		std::cout << "-----------------Cateories Menu-----------------" << std::endl;
		std::cout << "\t\t1 - Add category \n\t\t2 - Delete category \n\t\t3 - return to Main menu \n" << std::endl;
		CategoriesOption = ValidateInput("choose an option");

		if (CategoriesOption == 1)
		{
			if (MainHandler.bHasSpace())
			{
				system("cls");
				std::cout << "Enter the name of the category >> ";
				std::string NewCategoryName;
				std::cin >> NewCategoryName;

				if (MainHandler.AddCategory(NewCategoryName))
				{
					std::cout << "Category added!" << std::endl;
					std::cin.ignore();
					std::cin.get();
				}
				else
				{
					std::cout << "Invalid name!" << std::endl;
					std::cin.ignore();
					std::cin.get();
					CategoriesOption = 0;
				}
			}
			else
			{
				std::cout << "You don't have more space for new categories!" << std::endl;
				std::cin.ignore();
				std::cin.get();
				CategoriesOption = 0;
			}
		} 
		else if (CategoriesOption == 2)
		{
			if (MainHandler.GetCategoriesAmount() == 0)
			{
				std::cout << "There are no categories saved." << std::endl;
				std::cin.ignore();
				std::cin.get();
			}
			else
			{
				do
				{
					system("cls");
					MainHandler.ShowCategories();
					int SelectedCategoryIndex = ValidateInput("Choose a category");
					if (SelectedCategoryIndex >= 0 && SelectedCategoryIndex < MainHandler.GetCategoriesAmount())
					{
						MainHandler.DeleteCategory(SelectedCategoryIndex);
						break;
					}
				} while (true);
			}
		}
		else if(CategoriesOption == 3)
		{
			break;
		}
		else
		{
			CategoriesOption = 0;
		}


	} while (CategoriesOption == 0);
}

void FSteam::OpenShowGamesMenu()
{
	MainHandler.
}
