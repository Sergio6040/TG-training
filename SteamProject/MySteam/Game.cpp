#include "Game.h"

Game::Game()
{
    GameName = "";
    StudioName = "";
    ReleaseDate =  "";
}

Game::Game(const std::string NewGameName, const std::string NewStudioName, const std::string NewReleaseDate)
{
    GameName = NewGameName;
    StudioName = NewStudioName;
    ReleaseDate =  NewReleaseDate;
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

std::string Game::GetDate() const
{
    return ReleaseDate;
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

void Game::SetReleaseDate(const std::string NewReleaseDate)
{
    ReleaseDate = NewReleaseDate;
}

bool Game::IsValid() const
{
    return !GameName.empty();
}