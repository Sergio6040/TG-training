#include "Song.h"
#include <string>

Song::Song()
{
	SongTitle = "";
	ArtistName = "";
	Duration = 0;
}

Song::Song(const std::string NewSongTitle, const std::string NewArtistName, const int NewDuration)
{
	SongTitle = NewSongTitle;
	ArtistName = NewArtistName;
	Duration = NewDuration;
}

std::string Song::GetFormatedDuration()
{
	std::string Minutes = std::to_string(Duration / 100);
	std::string Seconds = std::to_string(Duration - (Duration / 100) * 100);
	return Minutes + ":" + Seconds;
}

bool Song::IsValid()
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
std::string Song::GetSongTitle() const
{
	return SongTitle;
}

void Song::SetSongTitle(std::string NewSongTitle)
{
	SongTitle = NewSongTitle;
}

//Artist Name
std::string Song::GetArtistName() const
{
	return ArtistName;
}

void Song::SetArtistName(std::string NewArtistName)
{
	ArtistName = NewArtistName;
}

//Duration
int Song::GetDuration() const
{
	return Duration;
}

void Song::SetDuration(const int NewDuration)
{
	Duration = NewDuration;
}