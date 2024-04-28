// Jamie Dang -- tasklist.cpp
#include "tasklist.h"

// Constructors

//Name:   default constructor   
//Desc:   this is the default constructor, which sets the count of
//	  TaskList instances to 0 and points the list pointer to nullptr  
//input:  none
//output: none
//return: none
TaskList::TaskList() {
	count = 0;
	head = nullptr;
	tail = nullptr;
}

//Name:   copy constructor
//Desc:   the copy constructor copies all the values from a given list
//        into a new TaskList object
//input:  const TaskList& list
//output: none
//return: none
TaskList::TaskList(const TaskList& list) {
	Node * curr = nullptr;
	Node * otherCurr = list.head;
	Node * prev = nullptr;	

	count = 0;
	head = nullptr;
	tail = nullptr;

	if (list.head != nullptr) { // the copied list isn't empty
		count = list.count;
		while (otherCurr != nullptr) {
			curr = new Node;
			curr->data = otherCurr->data;
			curr->next = nullptr;
			otherCurr = otherCurr->next;
			if (head == nullptr) { // no other items in the list
				head = curr;
				head->next = nullptr;
				prev = curr;
				curr = curr->next;
			} else { // has items in the list, inserting in the middle
				prev->next = curr;
				prev = curr;
				curr = curr->next;
			}
		}

		// Finding the tail node
		curr = head;
		while (curr) {
			prev = curr;
			curr = curr->next;
		}
		tail = prev;
	}
}

//Name:   parameterized constructor
//Desc:   this constructor reads in data for a TaskList object from
//	  a file named fileName[]
//input:  char fileName[]
//output: none
//return: none
TaskList::TaskList(char fileName[]) {
	ifstream inFile;
	Task aTask;
	char taskN[MAXCHAR];
	char personN[MAXCHAR];
	int userDay;
	int userDuration;
	int temp;
	Type userType;

	count = 0;
	head = nullptr;
	tail = nullptr;

	inFile.open(fileName);
	if (!inFile) {
		cout << "Error: Could not open the input file. Program terminating." << endl;
		exit(1);
	}

	// Ignore header row
	inFile.ignore(numeric_limits<streamsize>::max(), '\n');

	// Read in from file
	inFile >> userDay;
	inFile.ignore(5, ';');
	while (!inFile.eof()) {
		inFile.getline(taskN, MAXCHAR, ';');
		inFile >> userDuration;
		inFile.ignore(5, ';');
		inFile.getline(personN, MAXCHAR, ';');
		inFile >> temp;
		userType = static_cast<Type>(temp);
		inFile.ignore(5, '\n');

		// Set up aTask
		aTask.setTaskName(taskN);
		aTask.setPersonName(personN);
		aTask.setDay(userDay);
		aTask.setDuration(userDuration);
		aTask.setType(userType);

		// Add task to list array sorted
		insertSorted(aTask);

		// Continue Reading Loop
		inFile >> userDay;
		inFile.ignore(5, ';');
	}

	inFile.close();
}

//Name:   Destructor
//Desc:   This deallocates the Task array pointed to by the list pointer
//input:  none
//output: none
//return: none 
TaskList::~TaskList() {
	Node * curr = head;
	while(curr) {
		head = curr->next;
		delete curr;
		curr = head;
	}
	tail = nullptr;
}

//Name:   operator=()
//Desc:   operator= overload
//input:  TaskList & rhs
//output: none
//return: TaskList &
TaskList & TaskList::operator=(const TaskList & rhs) {
	TaskList * newTasks;
	if (this != &rhs) {
		newTasks = new TaskList(rhs);
		this->head = newTasks->head;	
		this->count = newTasks->count;
		this->tail = newTasks->tail;
	}
	newTasks->head = nullptr;
	delete newTasks;
	return *this;
}

//Name:   insertSorted()
//Desc:   This function inserts a task, sorted, into a TaskList object
//	  (specifically, into the private data member Task* list)
//input:  Task aTask
//output: none
//return: none
void TaskList::insertSorted(Task aTask) {  
	Node *newNode = nullptr;
	Node *curr = nullptr;
	Node *prev = nullptr;
	char name1[MAXCHAR];
	char name2[MAXCHAR];

	newNode = new Node;
	newNode->data = aTask;
	newNode->next = nullptr;

	if (head == nullptr) {
		head = newNode;
		tail = newNode;
	} else {
		curr = head;
		curr->data.getPersonName(name1);
		newNode->data.getPersonName(name2);
		// Finding location to insert
		while (curr && isLessThan(name1, name2)) {
			prev = curr;
			curr = curr->next;
			if (curr) {
				curr->data.getPersonName(name1);
			}		
		}

		// Insertion
		if (curr == nullptr) { // insert at the end of the list
			tail->next = newNode;
			tail = newNode;
		} else if (prev) { // insert inbetween nodes
			newNode->next = curr;
			prev->next = newNode;
		} else { // insert at the start of the list
			newNode->next = curr;
			head = newNode;
		}
	}

	count++;
}

//Name:   addTask()  
//Desc:   A function that allows the user to add a task to the list inside
//	  a TaskList object
//input:  none
//output: prompts
//return: none
void TaskList::addTask() {
	// Variables to hold input
	char personN[MAXCHAR];
	char taskN[MAXCHAR];
	int userDuration;
	int userDay;
	Type userType;
	int temp;
	Task aTask;

	char dayPrompt[MAXCHAR] = "Enter the day of the task (whole numbers between 1 and 30): ";
	char durationPrompt[MAXCHAR] = "Enter the number of hours (whole numbers between 1 and 10): ";
	char typePrompt[MAXCHAR] = "Enter the task type 0-Operations, 1-Maintenance, 2-Inventory, 3-Communications, and 4-Others): ";
	char taskPrompt[MAXCHAR] = "Enter the task name (50 characters or less): ";
	char namePrompt[MAXCHAR] = "Enter the person’s name (50 characters or less): ";
	char error[MAXCHAR] = "Error: Please enter a name that is 50 characters or less.";

	// Receive input

	cout << endl; // blank line

	// Day Input
	userDay = getInt(dayPrompt, VALID_DAY);
	cin.ignore(5, '\n'); // remove the newline

	// Task Name Input
	cout << taskPrompt;
	cin.getline(taskN, MAXCHAR, '\n');
	while (strlen(taskN) > 50) {
		cout << error << endl;
		cout << taskPrompt;
		cin.getline(taskN, MAXCHAR, '\n');
	}

	// Person Name Input
	cout << namePrompt;
	cin.getline(personN, MAXCHAR, '\n');
	while (strlen(personN) > 50) {
		cout << error << endl;
		cout << namePrompt;
		cin.getline(personN, MAXCHAR, '\n');
	}

	// Duration and Type input
	userDuration = getInt(durationPrompt, VALID_DURATION);
	temp = getInt(typePrompt, VALID_TYPE);
	userType = static_cast<Type>(temp);

	// Set up aTask
	aTask.setTaskName(taskN);
	aTask.setPersonName(personN);
	aTask.setDay(userDay);
	aTask.setDuration(userDuration);
	aTask.setType(userType);

	// Insert sorted alphabetically by person name
	insertSorted(aTask);	
	cout << endl; // blank line
	cout << "Task added!" << endl;
	listTaskN();
}

//Name:   getInt()   
//Desc:   This function receives an integer from the user and validates it
//input:  char prompt[], int identifier
//output: prompts, error messages
//return: int num
int TaskList::getInt(char prompt[], int identifier) {
	int num = 0;
	char errorDay[MAXCHAR] = "Invalid day! Must be between 1 and 30 inclusive!";
	char errorDuration[MAXCHAR] = "Invalid duration: Must be between 1 and 10 inclusive!";
	char errorType[MAXCHAR] = "Invalid type: Must be chosen from 0 to 4.";
	char errorIdx[MAXCHAR] = "Invalid index: Must be within the size of the array.";

	cout << prompt;
	cin >> num;	
	while (!cin || cin.peek() != '\n' || !(validInt(num, identifier))) {
		switch (identifier) {
			case VALID_DAY:
				cout << errorDay << endl;
				break;
			case VALID_DURATION:
				cout << errorDuration << endl;
				break;
			case VALID_TYPE:
				cout << errorType << endl;
				break;
			case VALID_IDX:
				cout << errorIdx << endl;
				break;
		}
		cout << prompt;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> num;
	}
	return num;
}

//Name:   validInt()  
//Desc:   This function checks to see if an integer is valid,
//	  a helper function to the validation process in getInt()
//input:  int num, int identifier
//output: none
//return: bool isValid
bool TaskList::validInt(int num, int identifier) {
	bool isValid = false;
	switch(identifier){
		case VALID_DAY:
			if (num >= 1 && num <= 30) {
				isValid = true;
			}
			break;
		case VALID_DURATION:
			if (num >= 1 && num <= 10) {
				isValid = true;
			}
			break;
		case VALID_TYPE:
			if (num >=0 && num <= 4) {
				isValid = true;
			}
			break;
		case VALID_IDX:
			if (num > 0 && num <= count) {
				isValid = true;
			}
			break;
	}
	return isValid;
}

//Name:   isLessThan()  
//Desc:   A function that checks for what char array comes first
//	  alphebetically using strcmp()
//input:  char name1[], char name2[]
//output: none
//return: bool isLess
bool TaskList::isLessThan(char name1[], char name2[]) {
	bool isLess = false;
	if (strcmp(name1, name2) < 0) {
		isLess = true;
	}
	return isLess;
}

//Name:   findNode()
//Desc:   This function returns a node at a specific index
//Input:  int idx
//Output: none
//Return: Node * curr
Task TaskList::findNode(int idx) const{
	Node * curr = head;
	int pos = 0;
	while (curr && pos < idx) {
		curr = curr->next;
		pos++;
	}
	return curr->data;
}

//Name:   listTaskN()
//Desc:   This function lists all tasks in a TaskList object
//input:  none
//output: all tasks in Task list[CAP]
//return: none
void TaskList::listTaskN() {
	cout << endl; // blank line
	for (int i = 0; i < count; i++) {
		cout << (i + 1) << ". ";
		printTask(i);
	}
}

//Name:   listTaskT()
//Desc:   This function lists all tasks of a specific type
//input:  none
//output: all tasks of a specific type
//return: none
void TaskList::listTaskT() {
	int userNum;
	int i = 0;
	int j = 1;
	Type userType;
	Node * curr = head;
	char prompt[MAXCHAR] = "Enter Type number(0-Operations, 1-Maintenance, 2-Inventory, 3-Communications, and 4-Others): ";
	cout << endl; // blank line
	userNum = getInt(prompt, VALID_TYPE);
	cout << endl; // blank line
	userType = static_cast<Type>(userNum);
	while(curr) {
		if (curr->data.getType() == userType) {
			cout << j << ". ";
			printTask(i);
			j++;
		}
		curr = curr->next;
		i++;
	}
}

//Name:   printTask()
//Desc:   This function prints an individual task to the console in the right format
//input:  int idx, this function has the keyword const as well, so it should not
//	  modify any private data members
//output: all of the data for a single task
//return: none
void TaskList::printTask(int idx) const{
	char temp[MAXCHAR];
	Type tempType;
	Task aTask;
	aTask = findNode(idx);
	cout << aTask.getDay();
	cout << ";";
	aTask.getTaskName(temp);
	cout << temp;
	cout << ";";
	cout << aTask.getDuration();
	cout << ";";
	aTask.getPersonName(temp);
	cout << temp;
	cout << ";";
	tempType = aTask.getType();
	switch(tempType) {
		case Operations:
			cout << "Operations" << endl;
			break;
		case Maintenance:
			cout << "Maintenance" << endl;
			break;
		case Inventory:
			cout << "Inventory" << endl;
			break;
		case Communications:
			cout << "Communiations" << endl;
			break;
		case Others:
			cout << "Others" << endl;
			break;
	}
}

//Name:   searchTask()
//Desc:   This function searches TaskList for a task whose name matches
//	  the name the user enters
//input:  none
//output: the task the user searched for
//return: none
void TaskList::searchTask() {
	char taskN[MAXCHAR];
	char currTask[MAXCHAR];
	int i = 0;
	int j = 0;
	Node * curr = head;
	Task tempTask;
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clean up input stream
	cout << endl; // blank line
	cout << "Enter task name: ";
	cin.getline(taskN, MAXCHAR, '\n');
	makeLower(taskN);
	cout << endl; // blank line 
	while(curr) {
		tempTask = findNode(i);
		tempTask.getTaskName(currTask);
		makeLower(currTask);
		if (strstr(currTask, taskN) != NULL) {
			j++;
			cout << j << ". ";
			printTask(i);	
		}
		i++;
		curr = curr->next;
	}

	if (j == 0) {
		cout << "No tasks with that name were found." << endl;
	}
}

//Name:   makeLower()
//Desc:   This is a helper function that turns a char array lowercase
//input:  char phrase[]
//output: none
//return: none
void TaskList::makeLower(char phrase[]) {
	int length = strlen(phrase);
	for (int i = 0; i < length; i++) {
		phrase[i] = tolower(phrase[i]);
	}
}

//Name:   removeTask()
//Desc:   This function allows a user to remove a task from the list in TaskList
//	  objects
//input:  none
//output: prompt for index, confirmation message
//return: none
void TaskList::removeTask() {
	int idxRemove = -1, i = 0;
	Node * curr = nullptr;
	Node * prev = nullptr;

	char prompt[MAXCHAR] =  "Enter index of task to remove: ";


	// Display Task List Currently
	listTaskN();

	// Receive Input
	cout << endl; // blank line
	idxRemove = getInt(prompt, VALID_IDX);
	idxRemove--; // The user sees the index as 1 higher than it actually is

	//FIXME: Removal, for assignment 4
	cout << endl; // blank line
	curr = head;
	while (curr && i < idxRemove) { // find node to remove
		prev = curr;
		curr = curr->next;
		i++;
	}

	// Exit loop, node found-- start removal
	if (curr == head) { // case 1: removal at head
		head = head->next;
		delete curr;	
		count--;
	} else if (curr == tail) { // case 2: removal at tail
		tail = prev;
		tail->next = nullptr;
		delete curr;
		count--;
	} else { // case 3: removal somewhere inside the list, not head or tail
		prev->next = curr->next;
		delete curr;
		count--;
	}	

	cout << "Task removed!" << endl;

	// Display Task List After
	listTaskN();
}

//Name:   writeOut()
//Desc:   This function writes out the current TaskList object data to a file, whose name
//	  is passed as a char array parameter
//input:  char fileName[]
//output: all TaskList data in proper format to fileName.txt
//return: none
void TaskList::writeOut(char fileName[]) {
	ofstream out;
	char temp[MAXCHAR];
	Node * curr = head;

	out.open(fileName);
	if (!out) {
		cout << "Could not open the datafile to save data. Program terminating." << endl;
		exit(1);
	}
	out << "Day;task name;duration;person name;category" << endl;
	while (curr) {	
		out << curr->data.getDay() << ";";
		curr->data.getTaskName(temp);
		out << temp << ";";
		out << curr->data.getDuration() << ";";
		curr->data.getPersonName(temp);
		out << temp << ";";
		out << curr->data.getType() << endl;
		curr = curr->next;
	}
	out.close();
}
