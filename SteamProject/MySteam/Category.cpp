#include "Category.h"
#include <iostream>

FCategory::FCategory()
{
    GamesAmount = 0;
}

//-------------------------------------------------------------------------------------------------------------

FCategory::FCategory(const std::string& NewCategoryName)
{
    CategoryName = NewCategoryName;
    GamesAmount = 0;
}

FCategory::FCategory(const FCategory &InCategory)
{
    CategoryName = InCategory.CategoryName;
    GamesAmount = InCategory.GamesAmount;

    //Memory copie array
    memcpy_s(GameArray, sizeof GameArray, InCategory.GameArray, sizeof InCategory.GameArray);

    /*
    for (int i=0; i < GamesAmount; i++)
    {
        GameArray[i] = InCategory.GameArray[i];
    }*/

}

FCategory::~FCategory()
{
    //the destructor
}
    
//-------------------------------------------------------------------------------------------------------------

const std::string& FCategory::GetCategoryName() const
{
    return CategoryName;
}

//-------------------------------------------------------------------------------------------------------------

void FCategory::SetCategoryName(const std::string& NewCategoryName)
{
    CategoryName = NewCategoryName;
}

//-------------------------------------------------------------------------------------------------------------

bool FCategory::AddGame(const FGame& NewGame)
{
    if(HasSpaceForGames())
    {
        GameArray[GamesAmount] = NewGame;
        GamesAmount++;
        return true;
    }
    return false;
}

//-------------------------------------------------------------------------------------------------------------

bool FCategory::HasSpaceForGames() const
{
    return GamesAmount < MaxGamesAmount;
}

//-------------------------------------------------------------------------------------------------------------

bool FCategory::IsValid() const
{
    return !CategoryName.empty();
}

//-------------------------------------------------------------------------------------------------------------

void FCategory::ShowAllGames() const
{
    for (const FGame& LoopGame : GameArray)
    {
        if (LoopGame.IsValid())
        {
            LoopGame.PrintGame();
        }
    }
}

//-------------------------------------------------------------------------------------------------------------

bool FCategory::GetGameAt(const int& Index, FGame& OutGame) const
{
    if (Index >= 0 && Index < GamesAmount)
    {
        OutGame = GameArray[Index];
        return true;
    }
    return false;
}


