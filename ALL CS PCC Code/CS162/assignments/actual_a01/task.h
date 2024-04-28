#ifndef TASK_H
#define TASK_H

#include <cstring>
#include <iostream>
using namespace std;

// Constants
const int MAXCHAR = 101;

// Declaring enum data type Type
enum Type {Operations, Maintenance, Inventory, Communications, Others};

// Data type for Task
class Task 
{
	public:		
		Task();
		Task(char [], char [], int, int, int);
		void getTaskName(char []) const;
		void setTaskName(char []);
		void getPersonName(char []) const;
		void setPersonName(char []);
		int getDay() const;
		void setDay(int);
		int getDuration() const;
		void setDuration(int);
		Type getType() const;
		void setType(int);

	private:
		char taskName[MAXCHAR];
		char personName[MAXCHAR];
		int day = 0;
		int duration = 0;
		Type type = static_cast<Type>(0);
		void init(char [], char [], int, int, int); // Helper function
};

 
#endif
