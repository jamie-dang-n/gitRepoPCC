// The implementation file for GameData.h 
#include "GameData.h" 
#include "tools.h"


//Name:   openFile() (overloaded)
//Desc:   This file opens the input file.
//input:  char fileName[], ifstream& inFile
//output: error message
//return: none
void openFile(char fileName[], ifstream& inFile) {
	inFile.open(fileName);
	if (!inFile) {
		cout << "Input File did not open. Program exiting." << endl;
		exit(0);
	}
}

//Name:   openFile() (overloaded)
//Desc:   This file opens the output file.
//input:  char fileName[], ofstream& outFile
//output: error message
//return: none
void openFile(char fileName[], ofstream& outFile) {
	outFile.open(fileName);
	if (!outFile) {
		cout << "Output File idd not open. Program exiting." << endl;
		exit(0);
	}
}


//Name:   loadData()
//Desc:   This function loads data from videogames.txt to the array games[]
//input:  ifstream& inFile, GameData games[], int& count
//output: none
//return: none
void loadData(ifstream& inFile, GameData games[], int& count) {
	count = 0;
	inFile >> games[count].rank;
	inFile.ignore(5, ',');
	while (!inFile.eof()) {
		inFile.getline(games[count].gameName, MAXCHAR, ',');
		inFile.getline(games[count].platform, MAXCHAR, ',');
		inFile >> games[count].releaseYear;
		inFile.ignore(5, '\n');
		count++;
		inFile >> games[count].rank;
		inFile.ignore(5, ',');

	}
}

//Name:   addGame()
//Desc:   This function adds a game to the games[] array based on user input 
//		  for data members.
//input:  GameData games[], int& count
//output: prompts for GameData userGame data members, error messages
//return: none
void addGame(GameData games[], int& count) {
	GameData userGame;
	char releasePrompt[MAXCHAR] = "Enter the year the game released: ";
	char rankPrompt[MAXCHAR] = "Enter the game's rank, relative to the table: ";
	int pos = 0;

	// Clean out Input Stream
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	// User Input for new game
	cout << "Enter the Game Name: ";
	cin.getline(userGame.gameName, MAXCHAR, '\n');
	cout << "Enter the Game Platform (Abbreviate): ";
	cin.getline(userGame.platform, MAXCHAR, '\n');

	// Input Validation
	userGame.releaseYear = getInt(releasePrompt, count);
	while (userGame.releaseYear > 2023) {
		cout << "Invalid Input, please try again." << endl;
		userGame.releaseYear = getInt(releasePrompt, count);
	}

	// Input Validation
	userGame.rank = getInt(rankPrompt, count);
	while (userGame.rank > (count + 1) || userGame.rank >= CAP) {
		cout << "Invalid Input, please try again." << endl;
		userGame.rank = getInt(rankPrompt, count);
	}

	// Finding the index to insert at
	pos = userGame.rank - 1; 

	// Insert the new game by shifting the other games right
	for (int i = count; i > pos; i--) {
		games[i] = games[i - 1];
	}
	games[pos] = userGame;
	count++;

	// Update rank data member
	for (int i = pos + 1; i < count; i++) {
		games[i].rank++;
	}
}


//Name:   removeGame()
//Desc:   This function removes a game from games[] based off its unique rank,
//		  which the user selects.
//input:  GameData games[], int& count
//output: prompt for rank to be removed, confirmation messages
//return: none
void removeGame(GameData games[], int& count) {
	int targetRemove = 0;
	int pos = -1;

	printData(games, count);

	cout << endl; // blank line
	char removePrompt[MAXCHAR] = "Enter the rank of the game to remove: ";
	targetRemove = getInt(removePrompt, count);
	cout << endl; // blank line

	// Find game to remove
	for (int i = 0; i < count; i++) {
		if (games[i].rank == targetRemove) {
			pos = i;
			break;
		}
	}

	// Checking Removal Status
	if (pos == -1) {
		// Game not found, no removal
		cout << "Game not found to remove. No games were removed." << endl;
	}
	else {
		// Game found, removing the game
		for (int i = pos; i < count - 1; i++) {
			games[i] = games[i + 1];
			if (games[i].rank != 1) {
				games[i].rank = games[i].rank - 1;
			}
		}
		count--;
		cout << "Game Removed. Here is your new list: " << endl;
		cout << endl; // blank line
		printData(games, count);
	}
}



//Name:   findGame()
//Desc:   This function finds a game based on the given name from 
//		  the user.
//input:  const GameData games[], const int count
//output: prompt for game name, confirmation message
//return: none
void findGame(const GameData games[], const int count) {
	int i = 0;
	char searchName[MAXCHAR];
	char checkName[MAXCHAR];

	// Clean out Input Stream
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	// Receive name of game to find
	cout << "Enter the Game Name to find: ";
	cin.getline(searchName, MAXCHAR, '\n');
	toLowerCase(searchName);

	// CString Comparisons
	for (i = 0; i < count; i++) {
		strcpy(checkName, games[i].gameName);
		toLowerCase(checkName);
		if (strcmp(checkName, searchName) == 0) {
			break;
		}
	}

	// Output/Results
	if (i == count) {
		cout << "Game not found." << endl;
	}
	else {
		cout << "Here is the information: " << endl;
		printLine(games, i);
	}
}


//Name:   findOldest()
//Desc:   This function finds the oldest game in the games[] list 
//input:  const GameData games[], const int count
//output: data for the oldest videogame (call to printLine())
//return: none
void findOldest(const GameData games[], const int count) {
	int oldestYear = games[0].releaseYear;
	int oldestPos = 0;
	for (int i = 0; i < count; i++) {
		if (games[i].releaseYear < oldestYear) {
			oldestYear = games[i].releaseYear;
			oldestPos = i;
		}
	}
	cout << "The oldest video game is:" << endl;
	printLine(games, oldestPos);
}

//Name:   printData() (overloaded)
//Desc:   This function prints out the entire dataset
//input:  const GameData games[], const int count
//output: the entire dataset, to the console
//return: none
void printData(const GameData games[], const int count) {
	cout << "Rank;Name;Platform;Year" << endl;
	for (int i = 0; i < count; i++) {
		cout << games[i].rank << ";";
		cout << games[i].gameName << ";";
		cout << games[i].platform << ";";
		cout << games[i].releaseYear << endl;
	}
}


//Name:   printData() (overloaded) 
//Desc:   This function writes the data to the file, output-games.txt
//input:  const GameData games[], const int count, ofstream& outFile
//output: the entire dataset, to output-games.txt
//return: none
void printData(const GameData games[], const int count, ofstream& outFile) {
	outFile << "Rank;Name;Platform;Year" << endl;
	for (int i = 0; i < count; i++) {
		outFile << games[i].rank << ","
			<< games[i].gameName << ","
			<< games[i].platform << ","
			<< games[i].releaseYear << endl;
	}
}


//Name:   printLine() 
//Desc:   This function prints out a single line of information, based on 
//		  the int pos parameter.
//input:  const GameData games[], int pos
//output: the line of data where the index is the parameter pos
//return: none
void printLine(const GameData games[], int pos) {
	cout << endl; // blank line
	cout << "Rank: " << games[pos].rank << endl;
	cout << "Name: " << games[pos].gameName << endl;
	cout << "Platform: " << games[pos].platform << endl;
	cout << "Release Year: " << games[pos].releaseYear << endl;
	cout << endl; // blank line
}
