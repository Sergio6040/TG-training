#include "Game.h"

Game::Game()
{
    GameName = "";
    StudioName = "";
}

Game::Game(const std::string NewGameName, const std::string NewStudioName, const std::string NewReleaseDate)
{
    GameName = NewGameName;
    StudioName = NewStudioName;
}


//----------------------getters------------------------
std::string Game::GetGameName() const
{
    return GameName;
}

std::string Game::GetStudioName() const
{
    return StudioName;
}

std::string Game::GetReleaseDate() const
{
    return std::to_string(ReleaseDay) + "/" + std::to_string(ReleaseMonth) + "/" + std::to_string(ReleaseYear);
}


//----------------------setters------------------------
void Game::SetGameName(const std::string NewGameName)
{
    GameName = NewGameName;
}

void Game::SetStudioName(const std::string NewStudioName)
{
    StudioName = NewStudioName;
}

void Game::SetReleaseDay(int NewReleaseDay)
{
    ReleaseDay = NewReleaseDay;
}


void Game::SetReleaseMonth(int NewReleaseMonth)
{
    ReleaseMonth = NewReleaseMonth;
}

void Game::SetReleaseYear(int NewReleaseYear)
{
    ReleaseYear = NewReleaseYear;
}

bool Game::IsValid() const
{
    return !GameName.empty();
}