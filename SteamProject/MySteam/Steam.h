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

	MenuOptions MenuActive;

	void OpenAddGameMenu();

	void AddGameToCategory();

public:

	FSteam();
	void RunApp();
};