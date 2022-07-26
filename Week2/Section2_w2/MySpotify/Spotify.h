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

public:
	FSpotify();

	void RunApp();

	void OpenMainMenu();
};
