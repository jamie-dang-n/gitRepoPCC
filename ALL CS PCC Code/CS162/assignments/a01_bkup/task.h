#ifndef TASK_H
#define TASK_H

// Constants
const int MAXCHAR = 101;
const int VERIFY_DAY = 1;
const int VERIFY_HOUR = 2;
const int VERIFY_TYPE = 3;

// enumerated data type for displaying the Type of task
enum Type {Operations, Maintenance, Inventory, Communications, Others};

// Data type for Task
struct Task 
{
	int day;
	char taskName[MAXCHAR];
	int hoursDuration;
	char personName[MAXCHAR];
	Type type;
};

// Function Prototypes
void addNewTask(Task tasks[], int &count);
void outputTasks(const Task tasks[], const int count); // overloaded, write to console
void outputTasks(const Task tasks[], const int count, const char fileName[]); // overloaded, write to file
void removeTasks(Task tasks[], int &count);
void findTask(const Task tasks[], const int count);
void insertSorted(Task tasks[], int &count, Task userTask);
void loadData(Task tasks[], int &count);
Type readType(int num);
void printType(Type aType);
bool isLessThan(char name1[], char name2[]); 
void listByType(const Task tasks[], const int count);
#endif
