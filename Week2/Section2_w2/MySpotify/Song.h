/*Exercise 1 - Songs
* Create a Song class in your project. Make sure to declare it in a .h and define it in a .cpp.
*
* Your Song class should have the following private members:
* std::string songTitle;
* std::string artistName;
* int duration;
*
* It should have a default constructor, a constructor with parameters to initialize the private members, getters, and setters.
*
* Additionally, implement the following methods:
* std::string getFormatedDuration(); // Should return duration in the mm:ss format
* bool isValid(); // You decide how a song is considered valid or not
*/

#pragma once
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