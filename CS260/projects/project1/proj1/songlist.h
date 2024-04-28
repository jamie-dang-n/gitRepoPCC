// Jamie Dang, CS260, Project 1, songlist.h
// Header file for SongList ADT
#ifndef SONGLIST_H
#define SONGLIST_H

#include "song.h"
#include <fstream>
#include <limits>

// int constants for setw() display printing
const int INDEX_LEN = 15;
const int MAXCHAR = 101;

// SongList Class
class SongList {
	public:
		// Constructors
		SongList();
		SongList(const char* fileName);
		// Destructor
		~SongList();
		// Public Interface  methods
		void add(Song& aSong);
		void edit(const int index, const int num);
		void display() const;
		bool displayArtist(const char * name);
		bool remove(int m);
		int getSize() const;
		bool writeOut(const char* fileName) const;
	private:
		// Data members
		struct Node {
			Song data;
			Node * next;
		};
		Node * head;
		Node * tail;
		int size;
		// Helper methods
		void insertSorted(Song& aSong);
		void deleteSong(int pos); 
		bool foundName(const char * name);
};
#endif

