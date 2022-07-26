#include "Song.h" 
#include "Playlist.h"
#include <iostream>

int main()
{
	Song newSong = Song("arabella", "Arctic Monkeys", 327);
	Song newSong2 = Song("Arabella2", "Arctic Monkeys2", 327);
	Song newSong3 = Song("Arabella3", "Arctic Monkeys3", 327);

	Playlist MyPlaylist = Playlist("Los monos articos");

	if (!MyPlaylist.AddSong(newSong)) { std::cout << "error al añadir cancion: " << std::endl; }
	if (!MyPlaylist.AddSong(newSong2)) { std::cout << "error al añadir cancion: " << std::endl; }
	if (!MyPlaylist.AddSong(newSong3)) { std::cout << "error al añadir cancion: " << std::endl; }

	MyPlaylist.DisplayPlaylist();


}
