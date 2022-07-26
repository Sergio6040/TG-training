#include "Song.h" 
#include "Playlist.h"
#include "PlaylistContainer.h"
#include <iostream>

/*Test your program up until here. Create a main.cpp file and implement the main method. In here, create a couple playlists with a couple songs and add them to a PlaylistContainer instance. 
Then, get those same playlists using the getter from the instance and display the playlists in the console. 

What happens when you try to get a playlist with an out of bounds index? How would you handle it?
When you make sure everything is working, you can continue to the next exercise.*/

int main()
{
	Song newSong[] =
	{
		Song("arabella", "Arctic Monkeys", 327),
		Song("Arabella", "Arctic Monkeys", 327),
		Song("R U mine?", "Arctic Monkeys", 322),
		Song("Broken   ", "Gorillaz", 240),
		Song("Fell good ink.", "Gorillaz", 312)
	};

	Playlist MyPlaylist = Playlist("Los monos articos");
	Playlist MyPlaylist2 = Playlist("Los Gorillaz");

	PlaylistContainer MyContainer;

	for (Song wukong : newSong)
	{
		MyPlaylist.AddSong(wukong);
		MyPlaylist2.AddSong(wukong);
	}

	MyPlaylist.AddSong(newSong[2]);

	MyContainer.AddPlaylist(MyPlaylist);
	MyContainer.AddPlaylist(MyPlaylist2);

	MyContainer.DisplayContainer();

	for (int i = 0; i < 7; i++)
	{
		MyContainer.GetPlaylist(i).DisplayPlaylist();
	}

}

