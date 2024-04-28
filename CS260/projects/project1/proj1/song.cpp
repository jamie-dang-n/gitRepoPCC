// Jamie Dang, CS260, Project 1, song.cpp
// Implementation file for song.h
#include "song.h"

// Default Constructor
Song::Song() {
	artist = nullptr;
	title = nullptr;
	length = 0.0;
	likes = 0;

}



// Copy Constructor
Song::Song(const Song &aSong) {
	artist = new char[strlen(aSong.artist)+1];
	title = new char [strlen(aSong.title)+1];
	*this = aSong;
}



// Parameterized Constructor
Song::Song(const char * artist, const char * title, const float length, const int likes) {
	this->artist = new char[strlen(artist) + 1];
	strcpy(this->artist, artist);

	this->title = new char[strlen(title) + 1];
	strcpy(this->title, title);

	this->length = length;
	this->likes = likes;
}



// Destructor
Song::~Song() {
	length = 0.0;
	likes = 0;

	// deleting dynamically allocated data
	if (artist) {
		delete [] artist;
	}
	if (title) {
		delete [] title;
	}

	title = nullptr;
	artist = nullptr;
}




// Getters
// Returns artist name
const char * Song::getArtist() const {
	return artist;
}



// Returns Song Title
const char * Song::getTitle() const {
	return title;
}



// Returns song length
float Song::getLength() const {
	return length;
}



// Returns number of likes
int Song::getLikes() const {
	return likes;
}



// Setters
// sets artist's name (dynamic char array)
void Song::setArtist(const char * artist) {
	if (this->artist) {
		delete [] this->artist;
		this->artist = nullptr;
	}

	this->artist = new char[strlen(artist)+1];
	strcpy(this->artist, artist);
}



// sets song title (dynamic char array)
void Song::setTitle(const char * title) {
	if (this->title) {
		delete [] this->title;
		this->title = nullptr;
	}

	this->title = new char[strlen(title)+1];
	strcpy(this->title, title);
}



/// sets song length (float)
void Song::setLength(float length) {
	this->length = length;
}



// sets number of likes (int)
void Song::setLikes(int likes) {
	this->likes = likes;
}




// Operator Overloads
// operator= overload for deep copy
const Song& Song::operator= (const Song& aSong) {
	if (this == &aSong) {
		return *this;
	}

	setArtist(aSong.artist);
	setTitle(aSong.title);
	setLength(aSong.length);
	setLikes(aSong.likes);
	return *this;
}



// insertion operator overload
ostream& operator<< (ostream& out, const Song& aSong) {
	out << left << setw(ARTIST_LEN) <<  aSong.artist;
	out << setw(TITLE_LEN) << aSong.title << setw(LENGTH_LEN) << fixed << setprecision(2) << aSong.length;
	out << setw(LIKES_LEN) << aSong.likes << endl;
	return out;
}
