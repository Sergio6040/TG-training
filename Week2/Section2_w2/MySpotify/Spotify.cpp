/*
* Exercise 4 - Spotify Setup
* Finally, let’s use everything we’ve done to make an app. Create a class called Spotify.
* We’ll need to create 3 different menus for this app: a Main Menu, a Create Playlist Menu, and a Browse Playlist Menu. We also need our app to have a list of playlists, so let’s do that.
*
* The class should have the following private members.
* PlaylistContainer playlists;
*
* enum class MenuCommand { MainMenu, CreatePlaylist, BrowsePlaylists, Exit };
* MenuCommand activeCommand;
*
* Remember to also add a default constructor to the class.
*
* The menu commands will allow us to navigate between menus with ease, changing menus when the activeCommand changes.
*
* To do this, we need to define the following public method
* void runApp();
*
* runApp should run a loop that will exit if the activeMenuCommand is set to Exit. 
* If it’s not, it should do a switch on the activeMenuCommand to determine what it should do next. 
* The implementations of each switch case can be empty for now, we just need somewhere to include the logic later.
*/

#include "PlaylistContainer.h"



class Spotify
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
	Spotify()
	{
		ActiveCommand = MainMenu;
	}

	void RunApp()
	{
		while (ActiveCommand != Exit)
		{
			switch (ActiveCommand)
			{
			case MainMenu:
				//code

				break;
			case CreatePlaylist:
				break;
			case BrowsePlaylist:
				break;
			case Exit:
				break;
			default:
				break;
			}

		}
	}
};