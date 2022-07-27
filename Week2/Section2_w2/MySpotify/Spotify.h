#pragma once

#include "PlaylistContainer.h"

class FSpotify
{
private:
	PlaylistContainer MainPlaylist;

	enum MenuCommand
	{
		MainMenu,
		CreatePlaylist,
		BrowsePlaylist,
		Exit
	};

	MenuCommand ActiveCommand;

	void OpenMainMenu();

	void OpenCreatePlaylistMenu();

	bool AskForNewSong(Playlist PassPlaylist);

public:
	FSpotify();

	void RunApp();

};
