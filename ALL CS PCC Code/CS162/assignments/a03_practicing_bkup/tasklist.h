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
		TaskList(const TaskList& list);
		~TaskList();
	
		// FIXME: needs copy constructor and operator=
		Task operator[](int index) const;
		TaskList & operator=(const TaskList& aList);

		void addTask();
		void listTaskN();
		void listTaskT();
		void searchTask();
		void removeTask();
		void writeOut(char fileName[]);
	private:
		struct Node {
			Task data;
			Node * next;
		};
		Node * head;
		Node * tail;
		int count;
		bool isLessThan(char name1[], char name2[]);
		bool validInt(int num, int identifier);
		void insertSorted(Task aTask);
		void printTask(int idx) const;
		int getInt(char prompt[], int identifier);
		void makeLower(char phrase[]);
		Task findNode(int idx) const;
};
