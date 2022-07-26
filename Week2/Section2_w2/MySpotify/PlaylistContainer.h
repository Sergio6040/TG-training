/*Exercise 3 - PlaylistContainer
Create a new class called PlaylistContainer. PlaylistContainer should be a collection of playlists, so it should look very similar to the Playlist class.
It should have the following private members:
const static int MaxPlaylistCount;
Playlist playlists[MaxPlaylistCount];
int playlistCount;

The class should have a default constructor, a method to add a playlist, a method to get a playlist with an index, and a method to know the current playlist count.

Test your program up until here. Create a main.cpp file and implement the main method. In here, create a couple playlists with a couple songs and add them to a PlaylistContainer instance.
Then, get those same playlists using the getter from the instance and display the playlists in the console. 

What happens when you try to get a playlist with an out of bounds index? How would you handle it?
When you make sure everything is working, you can continue to the next exercise.
*/
#pragma once
#include "Playlist.h"

class PlaylistContainer
{
private:
	const static int MaxPlaylistCount = 5;
	Playlist PlaylistArray[MaxPlaylistCount];
	int PlaylistCount;

public:
	PlaylistContainer();

	void AddPlaylist(Playlist NewPlaylist);

	Playlist GetPlaylist(int Index) const;

	int GetPlaylistCount() const;

	void DisplayContainer() const;
};
