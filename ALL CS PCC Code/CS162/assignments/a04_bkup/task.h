// Jamie Dang - task.h
#ifndef TASK_H
#define TASK_H

#include <cstring>
#include <iostream>
using namespace std;

// Declaring enum data type Type
enum Type {Operations, Maintenance, Inventory, Communications, Others};

// Data type for Task
class Task 
{
	public:		
		Task();
		Task(char [], char [], int, int, int);
		Task(Task &);
		~Task();

		const Task & operator=(const Task &);

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
		void print();

	private:
		char * taskName;
		char * personName;
		int day;
		int duration;
		Type type;
		void init(char [], char [], int, int, int); // Helper function
};

#endif
