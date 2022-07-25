#pragma once
#include <iostream>

class Song
{
private:
	std::string SongTitle;
	std::string ArtistName;
	int Duration;

public:
	Song(const std::string ReferenceSongTitle, const std::string ReferenceArtistName, const int ReferenceDuration)
	{
		SongTitle = ReferenceSongTitle;
		ArtistName = ReferenceArtistName;
		Duration = ReferenceDuration;
	}

	std::string GetFormatedDuration()
	{

		std::string minutes = 
		// Should return duration in the mm:ss format
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
