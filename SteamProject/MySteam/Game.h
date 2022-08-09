#pragma once
#include <string>

class Game
{
    std::string GameName;
    std::string StudioName;
    std::string ReleaseDate;
    
public:

    Game();

    Game(const std::string NewGameName, const std::string NewStudioName, const std::string NewReleaseDate);
    
    std::string GetGameName() const;

    std::string GetStudioName() const;

    std::string GetDate() const;

    void SetGameName(const std::string NewGameName);

    void SetStudioName(const std::string NewStudioName);

    void SetReleaseDate(const std::string NewReleaseDate);

    bool IsValid() const;

};
