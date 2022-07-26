#include "PlaylistContainer.h"
#include <iostream>

PlaylistContainer::PlaylistContainer()
{
	PlaylistCount = 0;
}

void PlaylistContainer::AddPlaylist(Playlist NewPlaylist)
{
	if (PlaylistCount < MaxPlaylistCount)
	{
		PlaylistArray[PlaylistCount] = NewPlaylist;
		PlaylistCount++;
	}
}

Playlist PlaylistContainer::GetPlaylist(int Index) const
{
	if (Index < MaxPlaylistCount)
	{
		return PlaylistArray[Index];
	}
	else
	{
		return PlaylistArray[PlaylistCount];
	}
}

int PlaylistContainer::GetPlaylistCount() const
{
	return PlaylistCount;
}

void PlaylistContainer::DisplayContainer() const
{
	std::cout << "\n	you have: " << PlaylistCount << " playlist" << std::endl;
	std::cout << "------------------------------------------------------------" << std::endl;
	for (Playlist OutPlaylist : PlaylistArray)
	{
		std::cout << OutPlaylist.GetPlaylistTitle() << std::endl;
	}
	std::cout << "------------------------------------------------------------" << std::endl;
}
