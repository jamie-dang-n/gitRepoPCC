// Jamie Dang, CS260, Project 1, song.h
// Header file for Song ADT
#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

// int constants for setw() display printing
const int TITLE_LEN = 40;
const int ARTIST_LEN = 20;
const int LENGTH_LEN = 10;
const int LIKES_LEN = 15;

// Song Class
class Song {
	public:
		// Constructors and Destructor
		Song();
		Song(const Song &aSong);
		Song(const char * artist, const char * title, const float length, const int likes);
		~Song();

		// Getters
		const char * getArtist() const;
		const char * getTitle() const;
		float getLength() const;
		int getLikes() const;
		
		// Setters
		void setArtist(const char* artist);
		void setTitle(const char* title);
		void setLength(float length);
		void setLikes(int likes);	

		// Operators
		const Song& operator= (const Song& aSong);
		friend ostream& operator<< (ostream& out, const Song& aSong);
	private:
		char * artist;
		char * title;
		float length;
		int likes;
};
#endif
