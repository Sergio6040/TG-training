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

#include "Spotify.h"
#include <iostream>

FSpotify::FSpotify()
{
	ActiveCommand = MainMenu;
}

void FSpotify::RunApp()
{
	while (ActiveCommand != Exit)
	{
		switch (ActiveCommand)
		{
		case MainMenu:
			OpenMainMenu();
			break;

		case CreatePlaylist:
			OpenCreatePlaylistMenu();
			break;

		case BrowsePlaylist:
			OpenBrowsePlaylistsMenu();
			break;

		default:
			break;
		}
		system("cls");

	}
}

void FSpotify::OpenMainMenu()
{
	int Input;
	std::cout << "Welcome to Spotify! What would you like to do?\n1 - Create a Playlist\n2 - Browse Playlists\n3 - Exit" << std::endl;
	std::cout << ">>";
	std::cin >> Input;

	if (Input > 0 && Input < 4 && !std::cin.fail())
	{
		switch (Input)
		{
		case 1:
			ActiveCommand = CreatePlaylist;
			break;

		case 2:
			ActiveCommand = BrowsePlaylist;
			break;

		case 3:
			ActiveCommand = Exit;
			break;
		}
	}
	else
	{
		std::cin.clear();
		std::cin.ignore(100, '\n');
		ActiveCommand = MainMenu;
	}
}

void FSpotify::OpenCreatePlaylistMenu() 
{
	std::cout << "Enter a name for the Playlist: ";
	std::string NewPlaylistName;
	std::cin >> NewPlaylistName;

	Playlist NewPlaylist = Playlist(NewPlaylistName);

	int UserChoice = 1;

	do
	{

		if (UserChoice == 1)
		{
			std::cout << "add a song to " << NewPlaylist.GetPlaylistTitle() << "\n" << std::endl;

			std::cout << "Please enter the song name: ";
			std::string NewSongName;
			std::cin >> NewSongName;

			std::cout << "Please enter the artist name: ";
			std::string NewArtistName;
			std::cin >> NewArtistName;

			int NewDuration;
			do
			{
				std::cout << "Please enter the song duration: ";
				std::cin >> NewDuration;

				if (std::cin.fail() || NewDuration < 0) {
					NewDuration = 0;
					std::cin.clear();
					std::cin.ignore(100, '\n');
					std::cout << "Invalid duration" << std::endl;
				}

			} while (NewDuration == 0);

			Song NewSong = Song(NewSongName, NewArtistName, NewDuration);

			bool bSongAdded = NewPlaylist.AddSong(NewSong);

			if (bSongAdded)
			{
				std::cout << "\nSong added!\n" << std::endl;
			}
			else
			{
				std::cout << "\nFail to add the song!\n" << std::endl;
			}

		}
		
		std::cout << "1 - Enter another song \n2 - Go back to main menu" << std::endl;
		std::cout << ">>";
		std::cin >> UserChoice;

		if ((UserChoice < 1 || UserChoice > 2) || std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(100, '\n');
			UserChoice = 0;
		}

		if (UserChoice == 2)
		{
			ActiveCommand = MainMenu;
		}
		system("cls");
	} 
	while (UserChoice == 0 || UserChoice == 1);

	if (!MainPlaylist.AddPlaylist(NewPlaylist))
	{
		std::cout << "Error at adding new playlist" << std::endl;
		std::cin.get();
		ActiveCommand = MainMenu;
	}
}

void FSpotify::OpenBrowsePlaylistsMenu()
{
	MainPlaylist.DisplayContainer();

	std::cout << "Press Enter to return to the Main menu" << std::endl;
	std::cout << "Which playlist do you want to see? >>";

	std::cin.clear();
	std::cin.ignore(1000, '\n');

	if (std::cin.peek() == '\n')
	{
		ActiveCommand = MainMenu;
		return;
	}

	int UserInput;
	std::cin >> UserInput;
	
	if (!std::cin.fail() && UserInput < MainPlaylist.GetPlaylistCount() && UserInput >= 0)
	{
		int SecondInput;
		Playlist OutPlaylist = MainPlaylist.GetPlaylist(UserInput);

		do
		{
			system("cls");
			MainPlaylist.GetPlaylist(UserInput).DisplayPlaylist();

			std::cout << "\n1 - Pick another playlist\n2 - Go back to main menu\n\nWhat do you want to do: ";
			std::cin >> SecondInput;

			if (SecondInput == 1)
			{
				continue;
			}
			else if (SecondInput == 2)
			{
				ActiveCommand = MainMenu;
			}
			else
			{
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				SecondInput = 0;
			}
		}
		while (SecondInput == 0);


	}
	else
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
	}

	system("cls");

}
