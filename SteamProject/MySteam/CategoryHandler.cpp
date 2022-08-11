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
	else
	{
		return false;
	}
}

bool FCategoryHandler::bHasSpace() const
{
	return CategoriesAmount < MaxCategoryAmount;
}


bool FCategoryHandler::AddGameToCategory(const int index, const FGame NewGame)
{
	return CategoryArray[index].AddGame(NewGame);
}

void FCategoryHandler::DeleteCategory(const int index)
{
	for (int i = index; i < CategoriesAmount; i++)
	{
		if (i + 1 < MaxCategoryAmount)
		{
			CategoryArray[i] = CategoryArray[i + 1];
		}
	}
	CategoriesAmount--;

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

FCategory FCategoryHandler::GetCategory(const int index)
{
	if (index < CategoriesAmount && index >= 0)
	{
		return CategoryArray[index];
	}
}

FCategory FCategoryHandler::GetCategory(const std::string NewCategoryName)
{
	for (FCategory LoopCategory : CategoryArray)
	{
		if (LoopCategory.GetCategoryName() == NewCategoryName)
		{
			return LoopCategory;
		}
	}
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
