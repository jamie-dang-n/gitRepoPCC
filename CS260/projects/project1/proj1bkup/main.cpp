// Jamie Dang, CS260, Project 1, main.cpp
// Implementation file for main.h; the client application
#include "main.h"

// Start main()
int main() {
	SongList songsList("songs.txt");
	int option = 0;
	
	welcome();
	cout << endl; // newline

	do {
	displayMenu();
	cout << endl; // newline
	getOption(option);
	cout << endl; // newline
	exeMenu(option, songsList);
	cout << endl; // newline
	} while (option != 6);

	return 0;
}
// End Main()


// Function Defintions //
// Name:   welcome() 
// Desc:   Display welcome message
// Input:  None
// Output: welcome message
// Return: none
void welcome() {
	cout << "Welcome to your SongList!" << endl;
}

// Name:   displayMenu() 
// Desc:   Display menu
// Input:  None
// Output: menu
// Return: none
void displayMenu() {
	cout << "(1) Add Song\n"
		 <<	"(2) Edit Likes\n"
		 << "(3) Display all songs\n"
	     << "(4) Display all songs for an artist (in order of popularity)\n"
		 <<	"(5) Remove all songs with fewer than M likes\n"
		 <<	"(6) Quit" << endl;
}

// Name:   getOption()
// Desc:   Read menu option in from user & validate
// Input:  int &option (the user's chosen option)
// Output: prompt and error message
// Return: none
void getOption(int &option) {
	getInt("Enter an option: ", option);
	while (!(option <= 6 && option >= 1)) {
		cout << "Error: Please choose a valid option." << endl;
		getInt("Enter an option: ", option);
	}	
}

// Name:   exeMenu()
// Desc:   Execute menu options
// Input:  int option (user's selected option),
//         SongList &aSongs (SongList object from main)
// Output: confirmation messages, error message
// Return: none
void exeMenu(int option, SongList &songs) {
	switch(option){
		case 1: // Add
			songs.add(getSong());
			cout << "Song added!" << endl;
			break;
	 	case 2: // Edit
			editLikes(songs);
			cout << "Song edited!" << endl;
			break;
		case 3: // Display All
			songs.display();
			break;
		case 4: // Display Artist
			printArtist(songs);
			break;
		case 5: // Remove based on Likes
			removeLikes(songs);
			break;
		case 6: // Quit & Save Data
			cout << "Thank you for using my program!" << endl;
			if (songs.writeOut("songs.txt")) {
				cout << "Your changes were successfully saved." << endl;
			} else {
				cout << "Your changes were not successfully saved." << endl;
			}
			break;
		default: // Invalid option
			cout << "Invalid option!! Please try again!" << endl;
			break;
	}
}


// Name:   editLikes()
// Desc:   Helper function for editing likes (choosing option 2)
// Input:  SongList &aSongs (SongList object from main)
// Output: prompt and error message
// Return: none
void editLikes(SongList &songs) {
		int idx = 0; // index of song to be edited
		int newLikes = 0; // new number of likes
		
		// Clean up the input stream before input
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		// get song index
		getInt("Enter the index of the song to be edited: ", idx);
		while (idx < 0 || idx > songs.getSize()) { // validate idx
			cout << "Error: Invalid Value. Please re-enter." << endl;
			getInt("Enter the index of the song to be edited: ", idx);
		}			
		// get number of new likes
		getInt("Enter the new number of likes (in integer form, like 1000): ", newLikes);
		songs.edit(idx, newLikes); 
}

// Name:   getSong()
// Desc:   Helper function for reading in a song from the user;
// 		   returns the song back to main().
// Input:  none
// Output: prompts for song data
// Return: Song aSong
Song getSong() {
	char title[MAXCHAR]; // for title data member
	char artist[MAXCHAR]; // for artist data member
	float length = 0.0; // for length data member
	int likes = 0; // for likes data member

	// Clean up the input stream before input
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	// User Input -- read in data members
	cout << "Enter the song title (Ex. Here Comes the Sun): ";
	cin.getline(title, MAXCHAR, '\n');
	cout << "Enter the artist name (Ex. The Beatles): ";
	cin.getline(artist, MAXCHAR, '\n');
	getFloat("Enter the length (in minutes decimal form, like 5.23): ", length);	
	getInt("Enter the number of likes (in integer form, like 1000): ", likes);

	// use parameterized constructor to create a new song object
	Song aSong(artist, title, length, likes);
	return aSong;
}

// Name:   getFloat()
// Desc:   Helper function for reading in floats
// Input:  const char * prompt (specific prompt for the float), 
// 		   float& num (the float to be read in)
// Output: error message, prompt
// Return: none
void getFloat(const char * prompt, float& num) {
	cout << prompt;
	cin >> num;
	while (!cin || cin.peek() != '\n' || num <= 0) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Error: Invalid Value. Please re-enter." << endl;
		cout << prompt;
		cin >> num;	}
}

// Name:   getInt()
// Desc:   Helper function for reading in ints
// Input:  const char * prompt (specific prompt for the int),
// 		   int& num (the int to be read in)
// Output: error message, prompt
// Return: none
void getInt(const char * prompt, int& num) {
	cout << prompt;
	cin >> num;
	while (!cin || cin.peek() != '\n' || num <= 0) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Error: Invalid Value. Please re-enter." << endl;
		cout << prompt;
		cin >> num;
	}
}

// Name:   printArtist()
// Desc:   Helper function for displaying all songs by an artist (choosing option 4)
// Input:  SongList &aSongs (SongList object from main)
// Output: prompt, artist to print, confirmation message
// Return: none
void printArtist(SongList &songs) {
	bool success = false; 
	char name[MAXCHAR]; // artist name given by user	
	// Clean up the input stream before input
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	// get artist name from user
	cout << "Enter the full name of the artist to print: ";
	cin.getline(name, MAXCHAR, '\n');
	// display all songs by a particular artist	
	success = songs.displayArtist(name);
	// check success
	if (!success) {
		cout << "Artist \"" << name << "\" was not found. Displaying not successful." << endl;
	} else {
		cout << "Display successful!" << endl;
	}
}

// Name:   removeLikes()
// Desc:   Helper function for removing all songs wtih likes under "m" (choosing option 5)
// Input:  SongList &songs (SongList from main)
// Output: prompt, confirmation message
// Return: none
void removeLikes(SongList &songs) {
	int m = 0; // number of likes to reference
	bool success = false;
	// Clean up the input stream before input
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	// get number of likes
	getInt("Enter the number of likes, \"m\" (in integer form) to reference: ", m);
	// remove all songs below m
	success = songs.remove(m);
	// check success
	if (!success) {
		cout << "Removal not successful." << endl;
	} else {
		cout << "Removal successful!" << endl;
	}
}
