#include "CategoryHandler.h"


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
	if (CategoriesAmount < MaxCategoryAmount)
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

void FCategoryHandler::DeleteCategory(const int index)
{
	for (int i = index; i < CategoriesAmount; i++)
	{
		CategoryArray[i] = CategoryArray[i + 1];
	}
	CategoriesAmount--;

}