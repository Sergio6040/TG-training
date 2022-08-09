#include "Category.h"

FCategory::FCategory()
{
    CategoryName = "";
    GamesAmount = 0;
}

FCategory::FCategory(const std::string NewCategoryName)
{
    CategoryName = NewCategoryName;
    GamesAmount = 0;
}
    
std::string FCategory::GetCategoryName() const
{
    return CategoryName;
}

void FCategory::SetCategoryName(const std::string NewCategoryName)
{
    CategoryName = NewCategoryName;
}

bool FCategory::AddGame(FGame NewGame)
{
    if(HasSpaceForGames())
    {
        GameArray[GamesAmount] = NewGame;
        GamesAmount++;
        return true;
    }
    else
    {
        return false;
    }
    
}

bool FCategory::HasSpaceForGames() const
{
    return GamesAmount < MaxGamesAmount;
}
