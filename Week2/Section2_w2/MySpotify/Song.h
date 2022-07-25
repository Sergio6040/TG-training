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
	Song();
	Song(const std::string NewSongTitle, const std::string NewArtistName, const int NewDuration);

	std::string GetFormatedDuration();
	bool IsValid();

	//Song Title
	std::string GetSongTitle() const;
	void SetSongTitle(std::string NewSongTitle);

	//Artist Name
	std::string GetArtistName() const;
	void SetArtistName(std::string NewArtistName);

	//Duration
	int GetDuration() const;
	void SetDuration(const int NewDuration);
};