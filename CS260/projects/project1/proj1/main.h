// Jamie Dang, CS260, Project 1, main.h
// Header File for main.cpp
#ifndef MAIN_H
#define MAIN_H
#include "song.h"
#include "songlist.h"

// Function Prototypes
void welcome();
void displayMenu();
void getOption(int &option);
void exeMenu(int option, SongList &songs);
void getSong(Song& aSong);
void getFloat(const char* prompt, float& num);
void getInt(const char* prompt, int& num);
void editLikes(SongList &songs);
void printArtist(SongList &songs);
void removeLikes(SongList &songs);
#endif
