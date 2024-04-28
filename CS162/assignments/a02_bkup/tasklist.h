// Jamie Dang -- tasklist.h
#include "task.h"
#include <fstream>
#include <limits>

// Constants
const int MAXCHAR = 101;
const int VALID_DAY = 0;
const int VALID_DURATION = 1;
const int VALID_TYPE = 2;
const int VALID_IDX = 3;

class TaskList {
	public:
		TaskList();
		TaskList(char fileName[]);
		~TaskList();
		void addTask();
		void listTaskN();
		void listTaskT();
		void searchTask();
		void removeTask();
		void writeOut(char fileName[]);
	private:
		const static int INIT_CAP = 30;
		const static int GROWTH_FACTOR = 2;
		Task * list;
		int count;
		int currCapacity = INIT_CAP;
		bool isLessThan(char name1[], char name2[]);
		bool validInt(int num, int identifier);
		void insertSorted(Task aTask);
		void printTask(int idx) const;
		int getInt(char prompt[], int identifier);
		void makeLower(char phrase[]);
		void expandArray();
};
