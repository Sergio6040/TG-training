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

    FGame(const std::string& NewGameName, const std::string& NewStudioName, const int& NewReleaseDay, const int& NewReleaseMonth, const int& NewReleaseYear);

    FGame(const FGame &InGame);

    ~FGame();
    
    const std::string& GetGameName() const;

    const std::string& GetStudioName() const;
    
    const std::string GetReleaseDate() const;
    
    void SetGameName(const std::string& NewGameName);

    void SetStudioName(const std::string& NewStudioName);

    void SetReleaseDay(const int& ReleaseDay);
    
    void SetReleaseMonth(const int& NewReleaseMonth);

    void SetReleaseYear(const int& NewReleaseYear);
    
    bool IsValid() const;

    void PrintGame() const;
};
