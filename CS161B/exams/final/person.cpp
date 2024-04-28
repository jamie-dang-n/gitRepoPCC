//implememtation file for struct PersonType
#include "person.h"

//function to read from file and populate list
void populatePersons(PersonType list[], int& count, const char fileName[])
{
    ifstream        inFile;
    char            name[MAX_CHAR];
    char            citizen[MAX_CHAR];
    int age = 0;

    inFile.open(fileName);
    if(!inFile)
    {
        cerr << "Fail to open " << fileName << " to populate inventory!" << endl;
        exit(1);
    }
    inFile >> name;
    while(!inFile.eof())
    {
        inFile >> citizen;
        inFile >> age;
        strcpy(list[count].name, name);
        strcpy(list[count].citizenship, citizen);
        list[count].age = age;
        count++;

        inFile >> name;
    }
    inFile.close();
}

//function to print list
void printPersons(const PersonType list[], int count)
{
    //cout << "List of citizen database!" << endl;
    for(int index = 0; index < count; index++)
    {
        cout << list[index].name << ";" << list[index].citizenship;
        cout << ";" << list[index].age << endl;
    }
}

//Name:   addPerson()
//Desc:   This function reads in a PersonType variable from the user,
//	  including all its data members, and inserts it at a position
//	  the user chooses.
//input:  PersonType list[], int &count
//output: prompts for each data member, error messages
//return: boolean value (True or false)
bool addPerson(PersonType list[], int &count) {
	PersonType userPerson;
	int pos;
	if (count < CAPACITY) { // Capacity Verification, capacity is 20
		// User Input
		cout << "Enter your name:" << endl;
		cin.getline(userPerson.name, MAX_CHAR);
		cout << "Enter your citizenship:" << endl;
		cin.getline(userPerson.citizenship, MAX_CHAR);
		cout << "Enter your age:" << endl;
		getInt(userPerson.age);

		// Age Validation
		while (userPerson.age < 1 || userPerson.age > 100) {
			cout << "Invalid age value. Please enter a valid integer." << endl;
			getInt(userPerson.age);
		}

		// Receiving Position to Insert
		cout << "Enter position number:" << endl;
		getInt(pos);

		// Position Validation
		if (pos < 0 || pos > count) { 
			cout << endl; // blank line
			cout << "Error! Invalid position." << endl;
			return false;
		} else {
			for (int i = count; i > pos; i--) {
				list[i] = list[i - 1];
			}
			list[pos] = userPerson;
			count++;
			return true;
		}
	} else { // out of capacity
		cout << endl; //blank line
		cout << "The list is full." << endl;
		return false;
	}
}

//Name:   getInt()
//Desc:   This function reads an integer from the user and validates it. 
//input:  int &num
//output: error message
//return: none
void getInt(int &num) {
	cin >> num;
	while (!cin || cin.peek() != '\n') {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Invalid input, please enter a valid integer." << endl;
		cin >> num;
	}
}
