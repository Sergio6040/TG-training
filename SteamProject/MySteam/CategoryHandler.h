#pragma once
#include <string>
#include "Game.h"
#include "Category.h"

class FCategoryHandler
{
	const static int MaxCategoryAmount = 25;
	FCategory CategoryArray[MaxCategoryAmount];
	int CategoriesAmount;

public:

	FCategoryHandler();

	int GetCategoriesAmount() const;

	bool AddCategory(const FCategory NewCategory);

	void DeleteCategory(const int index);

	void ShowCategories();

};
