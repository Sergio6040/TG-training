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

	const FGame& AskForNewGame();

	int ValidateInput(const std::string& Question) const;

	bool AddCategoryMenu();

	void DeleteCategoryMenu();

	bool AddGameMenu(const FGame& InGame);

public:

	void RunApp();
};