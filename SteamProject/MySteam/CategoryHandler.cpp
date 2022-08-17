#include "CategoryHandler.h"
#include <iostream>


FCategoryHandler::FCategoryHandler()
{
	CategoriesAmount = 0;
}

int FCategoryHandler::GetCategoriesAmount() const
{
	return CategoriesAmount;
}

bool FCategoryHandler::AddCategory(const FCategory NewCategory)
{
	if (CategoriesAmount < MaxCategoryAmount && NewCategory.IsValid())
	{
		CategoryArray[CategoriesAmount] = NewCategory;
		CategoriesAmount++;
		return true;
	}
	return false;
}

bool FCategoryHandler::HasSpace() const
{
	return CategoriesAmount < MaxCategoryAmount;
}


bool FCategoryHandler::AddGameToCategory(const int Index, const FGame NewGame)
{
	return CategoryArray[Index].AddGame(NewGame);
}

void FCategoryHandler::DeleteCategory(const int Index)
{
	CategoriesAmount--;
	for (int i = Index; i < CategoriesAmount; i++)
	{
		CategoryArray[i] = CategoryArray[i + 1];
	}
}

void FCategoryHandler::ShowCategories()
{
	std::cout << "You have " << CategoriesAmount << "categories saved." << std::endl;
	std::cout << "----------------------------------------------------\n" << std::endl;
	for (int i = 0; i < CategoriesAmount; i++)
	{
		std::cout << "\t" << i << " - " << CategoryArray[i].GetCategoryName() << std::endl;
	}
}

FCategory FCategoryHandler::GetCategory(const int Index)
{
	if (Index < CategoriesAmount && Index >= 0)
	{
		return CategoryArray[Index];
	}

	return FCategory();
}

void FCategoryHandler::ShowAllCategories() const
{
	for (FCategory LoopCategory : CategoryArray)
	{
		if (!LoopCategory.GetCategoryName().empty())
		{
			std::cout << "\n---------------------------------------------------" << std::endl;
			std::cout << "\tCategory name: " << LoopCategory.GetCategoryName() << std::endl;
			LoopCategory.ShowAllGames();
		}
	}
}
