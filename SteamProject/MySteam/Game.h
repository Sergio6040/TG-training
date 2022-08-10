#pragma once
#include <string>

class FGame
{
    std::string GameName;
    std::string StudioName;
    int ReleaseDay;
    int ReleaseMonth;
    int ReleaseYear;
    
public:

    FGame();

    FGame(const std::string NewGameName, const std::string NewStudioName, const int NewReleaseDay, const int NewReleaseMonth, const int NewReleaseYear);
    
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
