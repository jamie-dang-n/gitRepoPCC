#include "task.h"

// Constructors

//Name:   default constructor
//Desc:   This is the default constructor for tasks, which sets all char array 
//	  data members to "none" and all numeric data members to 0
//input:  none
//output: none
//return: none
Task::Task() {
	char defaultName[] = "none";
	init(defaultName, defaultName, 0, 0, 0);
}

//Name:   parameterized constructor
//Desc:   This constructor initializes a task with parameters char taskN[], char personN[],
//	  ints userDay, userDuration, and userType
//input:  char taskN[], char personN[], ints userDay, userDuration, userType
//output: none
//return: none
Task::Task(char taskN[], char personN[], int userDay, int userDuration, int userType) {
	init(taskN, personN, userDay, userDuration, userType);
}

//Name:   init()
//Desc:   This is a private helper function to help the constructors initiate a task object
//input:  char taskN[], char personN[], int userDay, int userDuration, int userType
//output: none
//return: none
void Task::init(char taskN[], char personN[], int userDay, int userDuration, int userType) {
	strcpy(taskName, taskN);
	strcpy(personName, personN);
	day = userDay;
	duration = userDuration;
	type = static_cast<Type>(userType);
}

// Getters

//Name:   getTaskName()
//Desc:   Copies taskName to returnName so the user can access the task name
//input:  char returnName[]
//output: none
//return: none
void Task::getTaskName(char returnName[]) const{
	strcpy(returnName, taskName);
}

//Name:   getPersonName()
//Desc:   Copies personName to returnName so the user can access the person name data member
//input:  char returnName[]
//output: none
//return: none
void Task::getPersonName(char returnName[]) const{
	strcpy(returnName, personName);
}

//Name:   getDay()  
//Desc:   Returns day data member
//input:  none
//output: none
//return: int day
int Task::getDay() const{
	return day;
}

//Name:   getDuration()
//Desc:   Returns duration data member
//input:  none
//output: none
//return: int duration
int Task::getDuration() const{
	return duration;
}

//Name:   getType()
//Desc:   Returns task type data member
//input:  none
//output: none
//return: Type type
Type Task::getType() const{
	return type;
}

// Setters

//Name:   setTaskName()
//Desc:   Copies taskN to taskName to set taskName
//input:  char taskN[]
//output: none
//return: none
void Task::setTaskName(char taskN[]) {
	strcpy(taskName, taskN);
}


//Name:   setPersonName()
//Desc:   Copies personN to personName to set personName
//input:  char personN[]
//output: none
//return: none
void Task::setPersonName(char personN[]) {
	strcpy(personName, personN);
}

//Name:   setDay() 
//Desc:   sets day to be the parameter userDay
//input:  int userDay
//output: none
//return: none
void Task::setDay(int userDay) {
	day = userDay;	
}

//Name:   setDuration()
//Desc:   sets duration to be the parameter userDuration
//input:  int userDuration
//output: none
//return: none
void Task::setDuration(int userDuration) {
	duration = userDuration;
}

//Name:   setType() 
//Desc:   sets the type data member to be the parameter
//	  userTypeNum using static casting
//input:  int userTypeNum
//output: none
//return: none
void Task::setType(int userTypeNum) {
	Type temp;
	temp = static_cast<Type>(userTypeNum);
	type = temp;
}
