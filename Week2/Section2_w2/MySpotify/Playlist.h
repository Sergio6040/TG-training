/*
Exercise 2 - Playlists
Create a new class called Playlist. Playlists should be containers for songs, so it should let the user add songs to the playlist.

It should have the following private members. 
const static int MaxSongCount;
std::string playlistTitle;
Song songs[MaxSongCount];
int songCount;

The class should have a default constructor, a constructor that initializes the playlist title, and a getter and setter for the playlist name.

Additionally, implement the following methods:
bool addSong(Song song);
Song getSong(int songIndex);
void displayPlaylist();

Since we’re using a fixed array of songs, addSong should not allow any more songs than the MaxSongCount to be added. It also shouldn’t add invalid songs. In any of these cases where a song can’t be added, you should return false.

displayPlaylist should display the songs in the following format:
Song Title		Artist Name		Duration
-----------------------------------------------------------------------
Song #1		Artist #1		Duration #1
Song #2		Artist #2		Duration #2
*/

#pragma once

#include <string>
#include "Song.h"
#include <vector>

class Playlist
{
	const static int MaxSongCount = 25;
	std::string PlaylistTitle;
	Song SongList[MaxSongCount];
	int SongListLength;
	int SongCount;
	
public:
	Playlist()
	{
		PlaylistTitle = "";
		SongCount = 0;
		SongListLength = 0;
	}

	Playlist(std::string NewTitle)
	{
		PlaylistTitle = NewTitle;
		SongCount = 0;
		SongListLength = 0;
	}

	bool AddSong(Song NewSong)
	{
		if (SongListLength < 25) {
			SongList[SongListLength] = NewSong;
			SongListLength++;
			return true;
		}
		else
		{
			return false;
		}
	}

	Song GetSong(int SongIndex) const
	{
		return SongList[SongIndex];
	}

	void DisplayPlaylist() const
	{
		std::cout << "\n	Playlist: " << PlaylistTitle << std::endl;
		std::cout << "Nombre\t\tArtista\t\t\tDuracion" << std::endl;
		std::cout << "------------------------------------------------------------" << std::endl;
		for (Song  OutSong : SongList)
		{
			std::cout << OutSong.GetSongTitle() << "\t" << OutSong.GetArtistName() << "\t\t" << OutSong.GetFormatedDuration() << std::endl;
		}
		std::cout << "------------------------------------------------------------"  << std::endl;

	}
};
