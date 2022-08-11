#include "Category.h"
#include <iostream>

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

bool FCategory::AddGame(const FGame NewGame)
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

bool FCategory::IsValid() const
{
    return !CategoryName.empty();
}

void FCategory::ShowAllGames() const
{
    for (FGame LoopGame : GameArray)
    {
        if (!LoopGame.GetGameName().empty())
        {
            std::cout << LoopGame.GetGameName() << "\t" << LoopGame.GetStudioName() << "\t" << LoopGame.GetReleaseDate() << std::endl;
        }
    }
}

