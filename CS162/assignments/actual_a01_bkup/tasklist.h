#include "task.h"
#include <fstream>
#include <limits>

// Constants
const int CAP = 30;
const int VALID_DAY = 0;
const int VALID_DURATION = 1;
const int VALID_TYPE = 2;
const int VALID_IDX = 3;

class TaskList {
	public:
		TaskList();
		TaskList(char fileName[]);
		void addTask();
		void listTaskN();
		void listTaskT();
		void searchTask();
		void removeTask();
		void writeOut(char fileName[]);
	private:
		Task list[CAP];
		int count;
		bool isLessThan(char name1[], char name2[]);
		bool validInt(int num, int identifier);
		void insertSorted(Task aTask);
		void printTask(int idx) const;
		int getInt(char prompt[], int identifier);
		void makeLower(char phrase[]);
};
