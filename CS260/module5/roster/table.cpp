#include "table.h"

Table::Table() : size(0)
{
	currCapacity = INIT_CAP;
	aTable = new Node*[currCapacity];
	for(int i=0; i<currCapacity; i++)
	{
		aTable[i] = nullptr;
	}
}

Table::Table(const Table& aTable) : aTable(nullptr), size(0)
{
	*this = aTable;
}

Table::~Table()
{
	destroy();
}

void Table::destroy()
{
	for(int i=0; i<currCapacity; i++)
	{
		destroyChain(aTable[i]);
	}
	if(aTable)
		delete [] aTable;
}

void Table::destroyChain(Node *& currHead)
{
	if(currHead)
	{
		destroyChain(currHead->next);
		delete currHead->data;
		delete currHead;
		currHead = nullptr;
	}
}

void Table::add(const Student& aStudent)
{
	int 	index = calculateIndex(aStudent.getName());	
	Node *	newNode = new Node(aStudent);
	newNode->next = aTable[index];
	aTable[index] = newNode;
	size++;
}

/*
A naive hashing function that only adds the ASCII value of each char in the
key field and mods the capacity of the table. i.e. "abc" and "cba" will result 
in the same index since it doesn't consider position value.
*/
int Table::calculateIndex(const char * key) const
{
	int hashingResult;

	//version 1
	hashingResult = 0;
	for(int i=0; i<strlen(key); i++)
	{
		hashingResult += key[i];
	}

	//version 2
	hashingResult = 0;
	int	keyLength = strlen(key);
	for(int i=0; i<keyLength; i++)
	{
		hashingResult += key[i];
	}

	//version 3
	hashingResult = 0;
	for(; *key != '\0'; key++)
	{
		hashingResult += *key;
	}	

	return hashingResult % currCapacity;
}

const Table& Table::operator= (const Table& tableSrc)
{
	if(this == &tableSrc)
		return *this;
	if(this->aTable)
	{
		destroy();
	}
	size = tableSrc.size;
	currCapacity = tableSrc.currCapacity;
	aTable = new Node*[currCapacity];
	for(int i=0; i<currCapacity; i++)
	{
		aTable[i] = nullptr;
		copyChain(tableSrc.aTable[i], this->aTable[i]);
	}
	return *this;
}	

void Table::copyChain(Node * srcHead, Node *& destHead)
{
	if(srcHead)
	{
		destHead = new Node(*(srcHead->data));
		copyChain(srcHead->next, destHead->next);
	}
}

ostream& operator<< (ostream& out, const Table& srcTable)
{
	out << endl << "Displaying the table ..." << endl;
	for(int i=0; i<srcTable.currCapacity; i++)
	{
		out << "Chain #" << i << " ... " << endl;
		srcTable.displayChain(out, srcTable.aTable[i]);
		out << endl;
	}
	return out;
}

void Table::displayChain(ostream& out, Node * currHead) const
{
	if(currHead)
	{
		out << *(currHead->data) << endl;
		displayChain(out, currHead->next);
	}
}

void Table::loadFromFile(const char * fileName)
{
	ifstream 	in;
	Student		currStudent;
	const int 	MAX_CHAR = 101;
	char		currName[MAX_CHAR];
	float		currGpa;

	in.open(fileName);
	if(!in)
	{
		cerr << "Fail to open " << fileName << " for reading!" << endl;
		exit(1);
	}

	in.get(currName, MAX_CHAR, ';');
	while(!in.eof())
	{
		in.get();
		in >> currGpa;
		in.ignore(MAX_CHAR, '\n');
		
		currStudent.setName(currName);
		currStudent.setGpa(currGpa);
		add(currStudent);
		in.get(currName, MAX_CHAR, ';');
	}
	in.close();
}

void Table::saveToFile(const char * fileName) const
{
	ofstream	out;
	
	out.open(fileName);
	if(!out)
	{
		cerr << "Fail to open " << fileName << " for writing!" << endl;
		exit(1);
	}

	for(int i=0; i<currCapacity; i++)
	{
		writeOutChain(out, aTable[i]);
	}
	out.close();
}

void Table::writeOutChain(ostream& out, Node * currHead) const
{
	if(currHead)
	{
		out << currHead->data->getName() << ';' << currHead->data->getGpa() << endl;	
		writeOutChain(out, currHead->next);
	}
}	
