#include "Game.h"

FGame::FGame()
{
    GameName = "";
    StudioName = "";
}

FGame::FGame(const std::string NewGameName, const std::string NewStudioName, const std::string NewReleaseDate)
{
    GameName = NewGameName;
    StudioName = NewStudioName;
}


//----------------------getters------------------------
std::string FGame::GetGameName() const
{
    return GameName;
}

std::string FGame::GetStudioName() const
{
    return StudioName;
}

std::string FGame::GetReleaseDate() const
{
    return std::to_string(ReleaseDay) + "/" + std::to_string(ReleaseMonth) + "/" + std::to_string(ReleaseYear);
}


//----------------------setters------------------------
void FGame::SetGameName(const std::string NewGameName)
{
    GameName = NewGameName;
}

void FGame::SetStudioName(const std::string NewStudioName)
{
    StudioName = NewStudioName;
}

void FGame::SetReleaseDay(int NewReleaseDay)
{
    ReleaseDay = NewReleaseDay;
}


void FGame::SetReleaseMonth(int NewReleaseMonth)
{
    ReleaseMonth = NewReleaseMonth;
}

void FGame::SetReleaseYear(int NewReleaseYear)
{
    ReleaseYear = NewReleaseYear;
}

bool FGame::IsValid() const
{
    return !GameName.empty();
}