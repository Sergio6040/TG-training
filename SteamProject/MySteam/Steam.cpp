#include "Steam.h"
#include <iostream>
#include <string>


void FSteam::RunApp()
{
	while (true)
	{
		system("cls");
		int UserOption;
		UserOption = ValidateInput("------ Welcome to Steam! ------\n\t1 - Add New game \n\t2 - Categories Menu... \n\t3 - Show Games... \n\t4 - Exit \n");

		switch (UserOption)
		{
		case AddGame:
			OpenAddGameMenu();
			break;

		case ShowCategories:
			OpenCategoriesMenu();
			break;

		case ShowGames:
			OpenShowGamesMenu();
			break;

		case Exit:
			return;
		}
	}
}

//-------------------------------------------------------------------------------------------------------------

int FSteam::ValidateInput(const std::string& Question) const
{
	int Input;
	std::cout << Question << " >>";
	std::cin >> Input;

	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(100, '\n');
		system("cls");
		std::cout << Question << " >>";
		std::cin >> Input;
	}
	return Input;
}

//-------------------------------------------------------------------------------------------------------------

const FGame FSteam::AskForNewGame() const
{
	FGame NewGame;
	do
	{
		system("cls");
		std::cin.ignore(100, '\n');

		std::cout << "Enter the game name >>";
		std::string NewGameName;
		std::getline(std::cin, NewGameName);

		std::cout << "Enter the name of the studio that develop the game >>";
		std::string NewStudioName;
		std::getline(std::cin, NewStudioName);

		const int GameDay = ValidateInput("Enter the release day");
		const int GameMonth = ValidateInput("Enter the release month");
		const int GameYear = ValidateInput("Enter the release year");

		NewGame = FGame(NewGameName, NewStudioName, GameDay, GameMonth, GameYear);

		if (!NewGame.IsValid())
		{
			std::cout << "Invalid Game...";
			std::cin.ignore(100, '\n');
			std::cin.get();
		}

	} while (std::cin.fail() || !NewGame.IsValid());
	return NewGame;
}

//-------------------------------------------------------------------------------------------------------------

void FSteam::OpenAddGameMenu()
{
	FGame NewGame = AskForNewGame();

	bool bGameAdded;
	char UserChoice;

	if (MainHandler.GetCategoriesAmount() > 0)
	{
		do
		{
			system("cls");
			std::cout << "Do you want to add the game to an existing category?(y/n)\n" << ">>";
			std::cin >> UserChoice;

			if (UserChoice == 'y')
			{
				bGameAdded = AddGameMenu(NewGame);
			}
			else if (UserChoice == 'n')
			{
				std::cout << "Adding game to Uncategorized" << std::endl;
				std::cin.ignore();
				std::cin.get();
				bGameAdded = Uncategorized.AddGame(NewGame);
				break;
			}
			else
			{
				bGameAdded = false;
				std::cin.clear();
				std::cin.ignore(100, '\n');
			}

		} while (!bGameAdded);
	}
	else
	{
		std::cout << "Adding game to Uncategorized" << std::endl;
		std::cin.ignore();
		std::cin.get();
		bGameAdded = Uncategorized.AddGame(NewGame);
	}

}

//-------------------------------------------------------------------------------------------------------------

void FSteam::OpenCategoriesMenu()
{
	int CategoriesOption;
	do
	{
		system("cls");
		std::cout << "-----------------Cateories Menu-----------------" << std::endl;
		std::cout << "\t\t1 - Add category \n\t\t2 - Delete category \n\t\or Press Enter to return to the Main menu \n" << std::endl;

		std::cin.clear();
		std::cin.ignore(1000, '\n');
		if (std::cin.peek() == '\n')
		{
			break;
		}
		CategoriesOption = ValidateInput("");

		switch (CategoriesOption)
		{
		case 1:
			AddCategoryMenu();
			break;

		case 2:
			DeleteCategoryMenu();
			break;
		}

	} while (CategoriesOption < 1 || CategoriesOption > 2);
}

//-------------------------------------------------------------------------------------------------------------

void FSteam::OpenShowGamesMenu()
{
	system("cls");
	std::cout << "\n---------------------------------------------------" << std::endl;
	std::cout << "\tCategory name: " << Uncategorized.GetCategoryName() << std::endl;
	Uncategorized.ShowAllGames();

	std::cout << "Games: " << std::endl;
	MainHandler.ShowAllCategories();

	std::cout << "\npress ENTER to return to main menu...";
	std::cin.ignore();
	std::cin.get();
}

//-------------------------------------------------------------------------------------------------------------

bool FSteam::AddCategoryMenu()
{
	if (MainHandler.HasSpace())
	{
		system("cls");
		std::cin.ignore(100, '\n');
		std::cout << "Enter the name of the category >> ";
		std::string NewCategoryName;
		std::getline(std::cin, NewCategoryName);

		if (MainHandler.AddCategory(NewCategoryName))
		{
			std::cout << "Category added!" << std::endl;
			std::cin.ignore();
			//std::cin.get();
			return true;
		}
		else
		{
			std::cout << "Invalid name!" << std::endl;
			std::cin.ignore();
			std::cin.get();
			return false;
		}
	}
	else
	{
		std::cout << "You don't have more space for new categories!" << std::endl;
		std::cin.ignore();
		std::cin.get();
		return false;

	}
}

//-------------------------------------------------------------------------------------------------------------

void FSteam::DeleteCategoryMenu()
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

//-------------------------------------------------------------------------------------------------------------

bool FSteam::AddGameMenu(const FGame& InGame)
{
	system("cls");
	MainHandler.ShowCategories();
	std::cout << "\nSelect a category >>";
	int CategoryIndex;
	std::cin >> CategoryIndex;

	if (CategoryIndex >= 0 && CategoryIndex < MainHandler.GetCategoriesAmount() && std::cin.good())
	{
		std::cout << "Adding game to " << MainHandler.GetCategory(CategoryIndex).GetCategoryName() << std::endl;
		return MainHandler.AddGameToCategory(CategoryIndex, InGame);
		std::cout << "Game successfully added!" << std::endl;
		std::cin.ignore();
		std::cin.get();
	}
	else
	{
		std::cout << "Fail to add game!" << std::endl;
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cin.get();
		return false;
	}
}
