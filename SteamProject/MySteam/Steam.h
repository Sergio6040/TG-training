#pragma once
#include "CategoryHandler.h"
#include "Category.h"

class FSteam
{
	FCategoryHandler MainHandler = FCategoryHandler();
	FCategory Uncategorized = FCategory("Uncategorized");

	enum MenuOptions
	{
		MainMenu,
		AddGame,
		ShowCategories,
		ShowGames,
		Exit
	};

	void OpenAddGameMenu();

	void OpenCategoriesMenu();

	void OpenShowGamesMenu();

	FGame AskForNewGame();

	int ValidateInput(const std::string Question);

public:

	void RunApp();
};