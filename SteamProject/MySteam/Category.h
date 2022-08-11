#pragma once
#include <string>

#include "Game.h"

class FCategory
{

    std::string CategoryName;
    const static int MaxGamesAmount = 25; 
    FGame GameArray[MaxGamesAmount];
    int GamesAmount;

public:

    FCategory();

    FCategory(const std::string NewCategoryName);
    
    std::string GetCategoryName() const;

    void SetCategoryName(const std::string NewCategoryName);

    bool AddGame(FGame NewGame);

    bool HasSpaceForGames() const;

    bool IsValid() const;

    void ShowAllGames() const;

    
};
