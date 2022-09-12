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

    FCategory(const std::string& NewCategoryName);

    FCategory(const FCategory &InCategory);

    ~FCategory();
    
    const std::string& GetCategoryName() const;

    void SetCategoryName(const std::string& NewCategoryName);

    bool AddGame(const FGame& NewGame);

    bool HasSpaceForGames() const;

    bool IsValid() const;

    void ShowAllGames() const;

    bool GetGameAt(const int& Index, FGame& OutGame) const;

};
