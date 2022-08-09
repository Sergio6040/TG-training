#pragma once
#include <string>

#include "Game.h"

class Category
{

    std::string CategoryName;
    const static int MaxGamesAmount = 25; 
    Game GameArray[MaxGamesAmount];
    int GamesAmount;

public:

    Category();

    Category(const std::string NewCategoryName);
    
    std::string GetCategoryName() const;

    void SetCategoryName(const std::string NewCategoryName);

    bool AddGame(Game NewGame);

    bool HasSpaceForGames() const;
};
