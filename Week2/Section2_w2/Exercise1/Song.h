#pragma once
#include <iostream>
#include <string>

class Song
{
private:
	std::string SongTitle;
	std::string ArtistName;
	int Duration;

public:
	Song(const std::string NewSongTitle, const std::string NewArtistName, const int NewDuration)
	{
		SongTitle = NewSongTitle;
		ArtistName = NewArtistName;
		Duration = NewDuration;
	}

	std::string GetFormatedDuration()
	{
		std::string Minutes = std::to_string(Duration / 100);
		std::string Seconds = std::to_string(Duration - (Duration / 100) * 100);
		return Minutes + ":" + Seconds;
	}

	bool IsValid()
	{
		if (isupper(SongTitle[0]))
		{
			return true; //if the song name starts with an uppercase letter, is valid
		}
		else
		{
			return false;
		}
	}

	//--------------------------getters & Setters--------------------------
	/*
	* the const statment goes after the funtion name, it means that the funtion is const
	* if example" const int FFunction() " means that the return value is const **Bad**
	*/

	//Song Title
	std::string GetSongTitle() const
	{
		return SongTitle;
	}

	void SetSongTitle(std::string NewSongTitle)
	{
		SongTitle = NewSongTitle;
	}

	//Artist Name
	std::string GetArtistName() const
	{
		return ArtistName;
	}

	void SetArtistName(std::string NewArtistName)
	{
		ArtistName = NewArtistName;
	}

	//Duration
	int GetDuration() const
	{
		return Duration;
	}

	void SetDuration(const int NewDuration)
	{
		Duration = NewDuration;
	}
};
