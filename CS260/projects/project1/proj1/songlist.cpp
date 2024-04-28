// Jamie Dang, CS260, Project 1, songlist.cpp
// Implementation File for SongList.h
#include "songlist.h"

// Default Constructor
SongList::SongList() {
	size = 0;
	head = nullptr;
	tail = nullptr;
}



// Parameterized Constructor - reads in data from file
// Calls on insertSorted() to insert into SongList
SongList::SongList(const char* fileName) {
	ifstream inFile; // input from file
	Song aSong; // aSong for insertSorted()
	char songTitle[MAXCHAR]; // for title data member
	char artist[MAXCHAR]; // for artist data member
	float length = 0.0; // for length data member
	int likes = 0; // for likes data member

	// Initalization 	
	size = 0;
	head = nullptr;
	tail = nullptr;

	// Open data file to read in
	inFile.open(fileName);
   	if(!inFile){
		cerr << "Error: Could not open the input file. Program terminating." << endl;
		exit(1);
	}
	
	// Ignore header row
	inFile.ignore(numeric_limits<streamsize>::max(), '\n');

	
	// Read in from file
	inFile.getline(songTitle, MAXCHAR, ';');
	while (!inFile.eof()) {
		inFile.getline(artist, MAXCHAR, ';');
		inFile >> length;
		inFile.ignore(5, ';');
		inFile >> likes;
		inFile.ignore(5, '\n');
		
		// set up aSong
		aSong.setTitle(songTitle);
		aSong.setArtist(artist);
		aSong.setLength(length);
		aSong.setLikes(likes);

		// Add Song to SongList, sorted
		insertSorted(aSong);

		// Continue reading loop
		inFile.getline(songTitle, MAXCHAR, ';');
	}
	inFile.close();
}



// Destructor
SongList::~SongList() {
	Node * curr = head; // pointer for traversal
	while (curr) {
		head = curr->next;
		delete curr;
		curr = head;
	}
	tail = nullptr;
}



// Public Methods
// Name:   add()
// Desc:   Lets the client add a song to the list.
// 		   The song object is created and passed in from main(),
// 		   and insertSorted() is called to help add a song to the list.
// Input:  Song& aSong
// Output: none
// Return: none
void SongList::add(Song& aSong) {
	insertSorted(aSong);	
}



// Name:   edit()
// Desc:   Lets the client edit the number of likes a song has.
// 		   The number of likes and the index of the song chosen is created
// 		   and passed in from main()
// Input:  const int index (index of song to edit -- must be verified in main),
// 		   const int num (new number of likes)
// Output: none
// Return: none
void SongList::edit(const int index, const int num) {
	Node* curr = head; // pointer for traversal
	Song aSong; // to hold a copy of the edited song

	// Traverse to correct position to edit
	// Save edited data into aSong
	if (index == size) {
		tail->data.setLikes(num);
		aSong = tail->data;
	} else {
		if (index != 1) {
			for (int i = 0; i < index - 1; i++) {
				curr = curr->next;
			}
		}
		curr->data.setLikes(num);
		aSong = curr->data;
	}

	// re-sort the list after editing likes
	deleteSong(index-1); // remove the current song object
	insertSorted(aSong); // re-insert aSong with new data, 
   						 // so that the list stays sorted.	
}



// Name:   display()
// Desc:   Lets the client display all of the songs in a song list
// Input:  none
// Output: All songs in current SongList object
// Return: none
void SongList::display() const {
	Node * curr = head; // pointer for traversal
	int index = 1; // int for displaying song index
	int totalLen = ARTIST_LEN + TITLE_LEN + LENGTH_LEN + LIKES_LEN; // for setw() on songList objects
	// Table header
	cout << left << setw(INDEX_LEN) << "Song Index" 
				 << setw(ARTIST_LEN) << "Artist Name" << setw(TITLE_LEN) << "Song Title" 
				 << setw(LENGTH_LEN) << "Length" <<  setw(LIKES_LEN) << "Likes" << endl;
	// Print out whole list
	while (curr) {
		cout << left << setw(INDEX_LEN) << index;
		cout << left << setw(totalLen) << curr->data;
		curr = curr->next;
		index++;
	}
}



// Name:   displayArtist()
// Desc:   Displays all the songs by an artist in order of popularity
// 		   (most ot least), if the artist's name was found. 
// Input:  const char * name (user-given artist's name to be checked)
// Output: All songs by an artist (named by user)
// Return: bool found (True if an artist was found, False otherwise)
bool SongList::displayArtist(const char * name) {
	Node *curr = head; // pointer for traversal
	int totalLen = ARTIST_LEN + TITLE_LEN + LENGTH_LEN + LIKES_LEN; // for setw() on songList objects
	char str1[MAXCHAR]; // to hold user-given artist name
	char str2[MAXCHAR]; // to hold current artist name in list
	bool found = foundName(name); // indicates whether or not name is actually in the list

	// Only display if the name was actually found
	if (found) {
		// set user-given name to lowercase
		strcpy(str1, name);
		for (int i = 0; i < static_cast<int>(strlen(name)); i++) {
			str1[i] = tolower(str1[i]);
		}

		cout << "Songs by " << name << endl;
		cout << left << setw(ARTIST_LEN) << "Artist Name" << setw(TITLE_LEN) << "Song Title" 
			<< setw(LENGTH_LEN) << "Length" <<  setw(LIKES_LEN) << "Likes" << endl;

		// Traverse through the list and print out all songs by the artist	
		while(curr) {
			// set current artist's name to lowercase
			strcpy(str2, curr->data.getArtist());
			for (int i = 0; i < static_cast<int>(strlen(str2)); i++) {
				str2[i] = tolower(str2[i]); 	
			}

			// compare names
			if (strcmp(str1, str2) == 0) {
				// print songs
				cout << left << setw(totalLen) << curr->data;
			}
			curr = curr->next;
		}	
	}
	return found;	
}



// Name:   remove()
// Desc:   Lets the client remove all songs that have likes less than int m.
// Input:  int m (number of likes to reference)
// Output: none
// Return: bool success (if deletion occurred, success = True, otherwise it is False)
bool SongList::remove(int m) {
	Node * curr = head; // pointer for traversal
	bool deleted = false; // boolean for moving curr/incrementing idx
	bool success = true; // boolean to represent successful removal
	int idx = 0; // index for deleteSong()

	if (size != 0) {
		while (curr && idx < size) {
			if (curr->data.getLikes() < m) {
				curr = curr->next;
				deleteSong(idx);
				deleted = true;
				success = true;		
			}
			if (!deleted) {
				idx++;
				curr = curr->next;
			}
			deleted = false;
		}
	}
	return success;
}



// Name:   getSize()
// Desc:   Lets the client see the size of the songList so that the client
// 		   can send the right index to edit() method 
// Input:  none
// Output: none
// Return: int size
int SongList::getSize() const {
	return size;
}



// Name:   writeOut()
// Desc:   Lets the client write out data to the file
// Input:  const char* fileName (file to be written to)
// Output: SongList contents to fileName
// Return: bool success (True if writing out was possible, False if not)
bool SongList::writeOut(const char* fileName) const {
	bool success = false; // return variable to indicate success	
	ofstream out; // output stream
	Node * curr = head; // for list traversal

	out.open(fileName);
	if (out) {
		// write out information if opening out was successful
		out << "SongTitle;Artist;Length;Likes" << endl;
		while (curr) { 
			out << curr->data.getTitle() << ";";
			out << curr->data.getArtist() << ";";
			out << fixed << setprecision(2) << curr->data.getLength() << ";";
			out << curr->data.getLikes() << endl;
			curr = curr->next;
		}
		success = true;
		out.close();
	}
	return success;
}



// Private methods //
// Name:   deleteSong() 
// Desc:   This method is used to delete a song based on position (index)
// Input:  int pos (position to be deleted; pos must be checked by the client code)
// Output: none
// Return: none
void SongList::deleteSong(int pos) {
	Node *curr = head, *prev = nullptr; // pointers for traversal/removal
	int idx = 0; // index for tracking pos
	if (size != 0 && pos < size) { // traverse only if the list is not empty & pos is in bounds
		while (curr && idx < pos) { // traversal
			prev = curr;
			curr = curr->next;
			idx++;
		}
		// deletion
		if (!prev) { // delete at the start
			head = curr->next;
		} else if (curr == tail) { // delete at the end
			prev->next = curr->next;
			tail = prev;
		} else { // delete inbetween
			prev->next = curr->next;
		}
		delete curr;
		curr = NULL;
		prev = NULL;
		size--;
	}
}



// Name:   foundName()
// Desc:   This method checks to see if an artist name exists in the songlist
// Input:  const char* name (name to be checked) 
// Output: none
// Return: bool found (True if found, False if not)
bool SongList::foundName(const char* name) {
	Node * curr = head; // pointer for traversal
	bool found = false; // boolean to represent finding an artist name
	char str1[MAXCHAR]; // used to hold user-given artist name
	char str2[MAXCHAR]; // used to hold current artist name

	// set user-given name to lowercase
	strcpy(str1, name);
	for (int i = 0; i < static_cast<int>(strlen(name)); i++) {
		str1[i] = tolower(str1[i]);
	}

	// traverse through a SongList and check if a name is found
	while(curr) {
		// set current artist's name to lowercase
		strcpy(str2, curr->data.getArtist());
		for (int i = 0; i < static_cast<int>(strlen(str2)); i++) {
			str2[i] = tolower(str2[i]); 	
		}

		// compare names
		if (strcmp(str1, str2) == 0) {
			found = true;
			break; // exit loop if any instance of user-given name was found in songList
		}
		curr = curr->next;
	}	
	return found;

}



// Name:   insertSorted()
// Desc:   Helper method to insert sorted into a SongList.
// Input:  Song& aSong (this song will be inserted to the list)
// Output: none
// Return: none
void SongList::insertSorted(Song& aSong) {
	Node *newNode = nullptr, *curr = nullptr, *prev = nullptr; // pointers for traversal/insertion
	// Setting up new node using data from aSong
	newNode = new Node;
	newNode->data = aSong;
	newNode->next = nullptr;

	if (head == nullptr) { // the list is empty
		head = newNode;
		tail = newNode;
	} else { // the list is not empty
		curr = head;
		// Insert sorted based on popularity (number of likes)
		while (curr && (curr->data.getLikes() > newNode->data.getLikes())) { // finding position to insert sorted
			prev = curr;
			curr = curr->next;
		}

		// Insertion
		if (curr == nullptr) { // insert at the end of the list
			tail->next = newNode;
			tail = newNode; // set the new tail
		} else if (prev) { // insert inbetween nodes
			newNode->next = curr;
			prev->next = newNode;
		} else { // insert at the start of the list
			newNode->next = curr;
			head = newNode;
		}
	}	
	size++;
}
