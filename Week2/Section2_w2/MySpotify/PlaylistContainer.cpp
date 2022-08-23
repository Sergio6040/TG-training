#include "PlaylistContainer.h"
#include <iostream>

PlaylistContainer::PlaylistContainer()
{
	PlaylistCount = 0;
}

bool PlaylistContainer::AddPlaylist(Playlist NewPlaylist)
{
	if (PlaylistCount < MaxPlaylistCount)
	{
		PlaylistArray[PlaylistCount] = NewPlaylist;
		PlaylistCount++;
		return true;
	}
	else
	{
		return false;
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

	for (int i = 0; i < PlaylistCount; i++)
	{
		std::cout << i << " - " << PlaylistArray[i].GetPlaylistTitle() << std::endl;
	}

	std::cout << "------------------------------------------------------------" << std::endl;
}
