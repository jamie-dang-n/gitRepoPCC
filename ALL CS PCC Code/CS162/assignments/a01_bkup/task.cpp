#include "task.h"
#include "main.h"

//Name:   addNewTask()
//Desc:   This function adds a new Task struct variable to the tasks[] list
//input:  Task tasks[], int &count
//output: prompts for each data member in the Task aTask variable, to be 
//	  input to tasks[]
//return: none
void addNewTask(Task tasks[], int &count) {
	// Variables
	Task aTask;
	Type aType;

	int userTask;

	// Prompt + error Char Arrays
	char dayPrompt[] = "Enter the day of the task (whole numbers between 1 and 30): ";
	char dayError[] =  "Invalid day! Must be between 1 and 30 inclusive!";
	char hourPrompt[] =  "Enter the number of hours (whole numbers beteen 1 and 10): ";
	char hourError[] =  "Invalid hour! Must be between 1 and 10 inclusive!";
	char typePrompt[] = "Enter the task type 0 - Operations, 1 - Maintenance, 2 - Inventory, 3 - Communications, and 4 - Others: ";
	char typeError[] = "Invalid Task type! Please select between 0-4, as listed above.";

	cout << endl; // blank line
	
	// Read in aTask
	// Day
	aTask.day = getInt(VERIFY_DAY, dayPrompt, dayError);
	cin.ignore(5, '\n');

	// Task Name
	cout << "Enter the task name (50 characters or less): ";
	cin.getline(aTask.taskName, MAXCHAR, '\n');

	// Person Name
	cout << "Enter the person's name (50 characters or less): ";
	cin.getline(aTask.personName, MAXCHAR, '\n');

	// Hours
	aTask.hoursDuration = getInt(VERIFY_HOUR, hourPrompt, hourError);
        cin.ignore(5, '\n');
	
	// Type
	userTask = getInt(VERIFY_TYPE, typePrompt, typeError);
	cin.ignore(5, '\n');

	aType = readType(userTask);
	aTask.type = aType;

	// Insert the task, sorted by name
	insertSorted(tasks, count, aTask);
	cout << "\nTask added!" << endl;
	outputTasks(tasks, count);
}

//Name:   readType()
//Desc:   This function reads in an integer value and casts it 
//	  to the enum datatype, Type.
//input:  int num
//output: none
//return: Type tempType
Type readType(int num) {
	Type tempType;
	switch(num) {	
		case 0:
			tempType = static_cast<Type>(0);
			break;
		case 1:
			tempType = static_cast<Type>(1);
			break;
		case 2:
			tempType = static_cast<Type>(2);
			break;
		case 3:
			tempType = static_cast<Type>(3);
			break;
		case 4:
			tempType = static_cast<Type>(4);
			break;
	}	
	return tempType;
}

//Name:   outputTasks()
//Desc:   This function is overloaded. This version outputs each task
//	  to the console, formatted for users to read from the console.
//input:  const Task tasks[], const int count
//output: all of the data in tasks[]
//return: none
void outputTasks(const Task tasks[], const int count) {
	cout << endl; // blank line
	for (int i = 0; i < count; i++) {
		cout << i + 1 << ". ";
		cout << tasks[i].day << ";" << tasks[i].taskName << ";" << tasks[i].hoursDuration 
		     << ";" << tasks[i].personName << ";";
		printType(tasks[i].type); 
	}
	cout << endl; // blank line
}

//Name:   printType()
//Desc:   This function takes in a Type value, and displays the respective
//        cstrings of each Type value.
//input:  Type aType
//output: The respective cstrings of each Type value
//return: none
void printType(Type aType) {
	switch(aType) {
			case 0:
				cout << "Operations" << endl;
				break;
			case 1:
				cout << "Maintenance" << endl;
				break;
			case 2:
				cout << "Inventory" << endl;
				break;
			case 3:
				cout << "Communications" << endl;
				break;
			default:
				cout << "Others" << endl;
				break;
	}
}

//Name:   outputTasks()
//Desc:   This function is overloaded. This version writes each task 
//	  to the data file (tasks.txt), to save new changes to the tasks list.  
//input:  const Task tasks[], const int count, const char fileName[]
//output: error message, data header, data from tasks[]
//return: none
void outputTasks(const Task tasks[], const int count, const char fileName[]) { // Overloaded
	ofstream out;
	out.open("tasks.txt");
	if (!out) {
		cout << "Error: Could not open datafile to save Data. Terminating Program now." << endl;
		exit(1);
	}

	out << "Day;task name;duration;person name;category" << endl;
	for (int i = 0; i < count; i++) {
		out << tasks[i].day << ";" << tasks[i].taskName << ";" << tasks[i].hoursDuration 
		    << ";" << tasks[i].personName << ";" << tasks[i].type << endl;
	}
	out.close();
}

//Name:   removeTasks()
//Desc:   This function uses the left shift algorithm to remove a task that
//	  the user selects.
//input:  Task tasks[], int &count, int idxRemove
//output: prompt for index to remove, error messages
//return: none
void removeTasks(Task tasks[], int &count) {
	int idxRemove = 0;
	outputTasks(tasks, count);
	cout << "Enter index of the task to remove: ";
	cin >> idxRemove;
	while (idxRemove > count || idxRemove < 0 || !cin || cin.peek() != '\n') {
		cout << "Error: Please enter a valid index to remove." << endl;
		cout << "Enter index of the task to remove: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> idxRemove;
	}
	idxRemove--; // The user sees each index as 1 more than the actual value when the list is displayed
	for (int i = idxRemove; i < count - 1; i++) {
		tasks[i] = tasks[i + 1];
	}
	count--;
	cout << "Task Removed!" << endl;
	outputTasks(tasks, count);
}

//Name:   findTask()
//Desc:   This function finds and prints the data of a task that the user
//	  searches for (by name).
//input:  const Task tasks[], const int count, char userTaskName[MAXCHAR]
//output: prompt for userTaskName, error message, task info
//return: none
void findTask(const Task tasks[], const int count) {
	char userTaskName[MAXCHAR];
	char tempListName[MAXCHAR];
	int taskPos = -1;
	
	// Clear input Stream
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << endl; // blank line	
	cout << "Enter the name of the task you want to find: ";
	cin.getline(userTaskName, MAXCHAR, '\n');
	for (int i = 0; i < count; i++) {
		makeLower(userTaskName);
		strcpy(tempListName, tasks[i].taskName);
		makeLower(tempListName);
		if(strstr(tempListName, userTaskName) != NULL) {
			taskPos = i;
			break;
		}	
	}
	if (taskPos == -1) {
		cout << endl; // blank line
		cout << "The task name you entered was not found." << endl;
	} else {
		cout << endl; // blank line
		cout << "Here is the task you searched for:" << endl;
		cout << endl; // blank line
		cout << tasks[taskPos].day << ";" << tasks[taskPos].taskName 
		     << ";" << tasks[taskPos].hoursDuration << ";" 
		     << tasks[taskPos].personName << ";";
		printType(tasks[taskPos].type);
	}

	cout << endl; // blank line
	
}

//Name:   loadData()
//Desc:   This functions loads in all of the data from tasks.txt 
//	  and saves them to the array of Task structs, tasks[]
//input:  Task tasks[], int &count, tasks.txt data file
//output: Error message if file doesn't open
//return: none
void loadData(Task tasks[], int &count) {
	ifstream in;
	Task aTask;
	Type aType;
	int tempType;

	// Open Input Stream
	in.open("tasks.txt");
	if (!in) {
		cout << "Error: File could not be opened. Terminating the Program." << endl;
		exit(1);
	}	
	
	in.ignore(numeric_limits<streamsize>::max(), '\n'); //Remove header 	
	
	// Input to aTask
	in >> aTask.day;
	in.ignore(5, ';');
	while (!in.eof()) {
		in.getline(aTask.taskName, MAXCHAR, ';');
		in >> aTask.hoursDuration;
		in.ignore(5, ';');
		in.getline(aTask.personName, MAXCHAR, ';');
		in >> tempType;
		aType = readType(tempType);
		aTask.type = aType;
		in.ignore(5, '\n');
		// Insert Sorted
		if (count == 0) {
			tasks[0] = aTask;
			count++;
		} else {
			insertSorted(tasks, count, aTask);
		}
		in >> aTask.day;
		in.ignore(5,';');
	}

	in.close();
}

//Name:   insertSorted()
//Desc:   This function inserts Task variables into the tasks[] array,
//	  sorted alphabetically by personName (data member of Task structs)
//input:  Task tasks[], int &count, Task userTask
//output: none
//return: none
void insertSorted(Task tasks[], int &count, Task userTask) {
	int i = 0;
	for (i = 0; i < count; i++) {
		if (!isLessThan(tasks[i].personName,userTask.personName)) {
			break;	
		}
	}
	for (int j = count; j > i; j--) {
		tasks[j] = tasks[j - 1];
	}
	tasks[i] = userTask;
	count++;
}

//Name:   isLessThan()
//Desc:   This is a helper function, which determines whether a cstring is less 
//	  than another cstring. This is used in insertSorted() to determine 
//	  alphabetical order 
//input:  char name1[], char name2[]
//output: none
//return: bool isLess
bool isLessThan(char name1[], char name2[]) {
	bool isLess = false;
	if(strcmp(name1, name2) < 0) {
		isLess = true;
	} else {
		isLess = false;
	}
	return isLess;
}

//Name:   listByType()
//Desc:   This function reads an integer from the user, converts it to
//	  Type, then displays each item in the list tasks[] that have
//	  the same type
//input:  const Task tasks[], const int count
//output: prompt, error message, tasks
//return: none
void listByType(const Task tasks[], const int count) {
	int j = 0;
	int i = 0; 
	int temp = 0;
	Type userType;
	char prompt[MAXCHAR] = "Enter Type number(0-Operations, 1-Maintenance, 2-Inventory, 3-Communications, and 4-Others): ";
	char error[MAXCHAR] = "Invalid Task type! Please select between 0-4, as listed above.";

	cout << endl; // blank line
	temp = getInt(VERIFY_TYPE, prompt, error);
	userType = static_cast<Type>(temp);

	cout << endl << "Here are the tasks you searched for:" << endl;

	cout << endl; // blank line
	for (i = 0; i < count; i++) {
		if (tasks[i].type == userType) {
			j++;
			cout << j << ". ";
			cout << tasks[i].day << ";" << tasks[i].taskName << ";" << tasks[i].hoursDuration << ";" << tasks[i].personName << ";";
			printType(tasks[i].type);
		}
	}

	if (j == 0) {
		cout << "No tasks of that type were found." << endl;
	}
	cout << endl; //blank line
}



