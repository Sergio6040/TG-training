#pragma once
#include <string>

class Game
{
    std::string GameName;
    std::string StudioName;
    int ReleaseDay;
    int ReleaseMonth;
    int ReleaseYear;
    
public:

    Game();

    Game(const std::string NewGameName, const std::string NewStudioName, const std::string NewReleaseDate);
    
    std::string GetGameName() const;

    std::string GetStudioName() const;
    
    std::string GetReleaseDate() const;
    
    void SetGameName(const std::string NewGameName);

    void SetStudioName(const std::string NewStudioName);

    void SetReleaseDay(int ReleaseDay);
    
    void SetReleaseMonth(int NewReleaseMonth);

    void SetReleaseYear(int NewReleaseYear);
    
    bool IsValid() const;
};
