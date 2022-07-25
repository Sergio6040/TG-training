/*Exercise 1 - Songs
* Create a Song class in your project. Make sure to declare it in a .h and define it in a .cpp.
*
* Your Song class should have the following private members:
* std::string songTitle;
* std::string artistName;
* int duration;
*
* It should have a default constructor, a constructor with parameters to initialize the private members, getters, and setters.
*
* Additionally, implement the following methods:
* std::string getFormatedDuration(); // Should return duration in the mm:ss format
* bool isValid(); // You decide how a song is considered valid or not
*/

#include "Song.h" //<--contains <iostream>
#include "Playlist.h"

int main()
{
	Song newSong = Song("Arabella", "Arctic Monkeys", 327);
	Song newSong2 = Song("Arabella2", "Arctic Monkeys2", 327);
	Song newSong3 = Song("Arabella3", "Arctic Monkeys3", 327);

	Playlist MyPlaylkist = Playlist("Los monos articos");

	MyPlaylkist.AddSong(newSong);
	MyPlaylkist.AddSong(newSong2);
	MyPlaylkist.AddSong(newSong3);

	MyPlaylkist.DisplayPlaylist();


}