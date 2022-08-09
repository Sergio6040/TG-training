#include "Category.h"

Category::Category()
{
    CategoryName = "";
    GamesAmount = 0;
}

Category::Category(const std::string NewCategoryName)
{
    CategoryName = NewCategoryName;
    GamesAmount = 0;
}
    
std::string Category::GetCategoryName() const
{
    return CategoryName;
}

void Category::SetCategoryName(const std::string NewCategoryName)
{
    CategoryName = NewCategoryName;
}

bool Category::AddGame(Game NewGame)
{
    if(HasSpaceForGames())
    {
        GameArray[GamesAmount] = NewGame;
        return true;
    }
    else
    {
        return false;
    }
    
}

bool Category::HasSpaceForGames() const
{
    return GamesAmount < MaxGamesAmount;
}
