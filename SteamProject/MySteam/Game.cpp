#include "Game.h"

FGame::FGame()
{
    ReleaseDay = 0;
    ReleaseMonth = 0;
    ReleaseYear = 0;
}

//-------------------------------------------------------------------------------------------------------------

FGame::FGame(const std::string& NewGameName, const std::string& NewStudioName, const int& NewReleaseDay, const int& NewReleaseMonth, const int& NewReleaseYear)
{
    GameName = NewGameName;
    StudioName = NewStudioName;
    ReleaseDay = NewReleaseDay;
    ReleaseMonth = NewReleaseMonth;
    ReleaseYear = NewReleaseYear;
}

//-------------------------------------------------------------------------------------------------------------

FGame::FGame(const FGame& InGame)
{
    GameName = InGame.GameName;
    StudioName = InGame.StudioName;
    ReleaseDay = InGame.ReleaseDay;
    ReleaseMonth = InGame.ReleaseMonth;
    ReleaseYear = InGame.ReleaseYear;
}

//-------------------------------------------------------------------------------------------------------------

FGame::~FGame()
{
    //the destructor
}

/* -------------------------------------------------------------------------------------------------------------
*                               Getters      
* -------------------------------------------------------------------------------------------------------------*/
const std::string& FGame::GetGameName() const
{
    return GameName;
}

//-------------------------------------------------------------------------------------------------------------
const std::string& FGame::GetStudioName() const
{
    return StudioName;
}

//-------------------------------------------------------------------------------------------------------------
const std::string& FGame::GetReleaseDate() const
{
    return std::to_string(ReleaseDay) + "/" + std::to_string(ReleaseMonth) + "/" + std::to_string(ReleaseYear);
}


/* -------------------------------------------------------------------------------------------------------------
*                               Setters
* -------------------------------------------------------------------------------------------------------------*/

void FGame::SetGameName(const std::string& NewGameName)
{
    GameName = NewGameName;
}

//-------------------------------------------------------------------------------------------------------------

void FGame::SetStudioName(const std::string& NewStudioName)
{
    StudioName = NewStudioName;
}

//-------------------------------------------------------------------------------------------------------------

void FGame::SetReleaseDay(const int& NewReleaseDay)
{
    ReleaseDay = NewReleaseDay;
}

//-------------------------------------------------------------------------------------------------------------

void FGame::SetReleaseMonth(const int& NewReleaseMonth)
{
    ReleaseMonth = NewReleaseMonth;
}

//-------------------------------------------------------------------------------------------------------------

void FGame::SetReleaseYear(const int& NewReleaseYear)
{
    ReleaseYear = NewReleaseYear;
}

//-------------------------------------------------------------------------------------------------------------

bool FGame::IsValid() const
{
    const bool bDateIsValid = (ReleaseDay > 0 && ReleaseDay < 32) && (ReleaseMonth > 0 && ReleaseMonth < 13) && (ReleaseYear > 1958);
    return !GameName.empty() && !StudioName.empty() && bDateIsValid;
}