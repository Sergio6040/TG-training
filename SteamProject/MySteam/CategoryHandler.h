#pragma once
#include <string>
#include "Game.h"
#include "Category.h"

class FCategoryHandler
{
	const static int MaxCategoryAmount = 5;
	FCategory CategoryArray[MaxCategoryAmount];
	int CategoriesAmount;


public:

	FCategoryHandler();

	FCategoryHandler(const FCategoryHandler &InHandler);

	~FCategoryHandler();

	int GetCategoriesAmount() const;

	bool AddCategory(const FCategory& NewCategory);

	bool HasSpace() const;

	void DeleteCategory(const int& Index);

	void ShowCategories();

	bool AddGameToCategory(const int& Index, const FGame& NewGame);

	const FCategory& GetCategory(const int& Index);

	void ShowAllCategories() const;

};
