#include <iostream>
#include "Playlist.h"
#include "Song.h"


Playlist::Playlist()
{
	PlaylistTitle = "";
	SongCount = 0;
}

Playlist::Playlist(std::string NewTitle)
{
	PlaylistTitle = NewTitle;
	SongCount = 0;
}

bool Playlist::AddSong(Song NewSong)
{
	if (SongCount < MaxSongCount && NewSong.IsValid()) 
	{
		SongList[SongCount] = NewSong;
		SongCount++;
		return true;
	}
	else
	{
		return false;
	}
}

Song Playlist::GetSong(int SongIndex) const
{
	return SongList[SongIndex];
}

void Playlist::DisplayPlaylist() const
{
	if (PlaylistTitle != "")
	{
		std::cout << "\n	Playlist: " << PlaylistTitle << std::endl;
		std::cout << "Nombre\t\tArtista\t\t\tDuracion" << std::endl;
		std::cout << "------------------------------------------------------------" << std::endl;

		for (Song OutSong : SongList)
		{
			if (OutSong.GetSongTitle() != "")
			{
				std::cout << OutSong.GetSongTitle() << "\t" << OutSong.GetArtistName() << "\t\t" << OutSong.GetFormatedDuration() << std::endl;
			}
		}
		std::cout << "------------------------------------------------------------" << std::endl;
	}

}

std::string Playlist::GetPlaylistTitle() const
{
	return PlaylistTitle;
}

