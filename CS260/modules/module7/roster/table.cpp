#include "table.h"

Table::Table() : root(nullptr), size(0)
{
}

Table::Table(const Table& aTable) : root(nullptr), size(0)
{
	*this = aTable;
}

Table::~Table()
{
	destroy(root);
}

void Table::destroy(Node *& currRoot)
{
	if(currRoot)
	{
		destroy(currRoot->left);
		destroy(currRoot->right);
		delete currRoot->data;
		delete currRoot;
		currRoot = nullptr;
	}
}

void Table::add(const Student& aStudent)
{
	add(this->root, aStudent);
	size++;
}

void Table::add(Node *& currRoot, const Student& aStudent)
{
	if(!currRoot)
	{
		currRoot = new Node(aStudent);
	}
	else if(aStudent < *(currRoot->data))
	{
		add(currRoot->left, aStudent);
	}
	else
	{
		add(currRoot->right, aStudent);
	}
}

const Table& Table::operator= (const Table& tableSrc)
{
	if(this == &tableSrc)
		return *this;
	if(this->root)
	{
		destroy(this->root);
	}
	size = tableSrc.size;
	copy(tableSrc.root, this->root);
	return *this;
}	

void Table::copy(Node * srcRoot, Node *& destRoot)
{
	if(srcRoot)
	{
		destRoot = new Node(*(srcRoot->data));
		copy(srcRoot->left, destRoot->left);
		copy(srcRoot->right, destRoot->right);
	}
	else
	{
		destRoot = nullptr;
	}
}

ostream& operator<< (ostream& out, const Table& srcTable)
{
	out << endl << "Displaying the tree ..." << endl;
	srcTable.display(out, srcTable.root);
	return out;
}

void Table::display(ostream& out, Node * currRoot) const
{
	out << endl << "Pre-order showing the tree ..." << endl;
	displayPreorder(out, currRoot);
	out << endl << "In-order showing the tree ..." << endl;
	displayInorder(out, currRoot);
	out << endl << "Post-order showing the tree ..." << endl;
	displayPostorder(out, currRoot);
}	

void Table::displayPreorder(ostream& out, Node * currRoot) const
{
	if(currRoot)
	{
		out << *(currRoot->data) << endl;
		displayPreorder(out, currRoot->left);
		displayPreorder(out, currRoot->right);
	}
}
void Table::displayInorder(ostream& out, Node * currRoot) const
{
	if(currRoot)
	{
		displayInorder(out, currRoot->left);
		out << *(currRoot->data) << endl;
		displayInorder(out, currRoot->right);
	}
}
void Table::displayPostorder(ostream& out, Node * currRoot) const
{
	if(currRoot)
	{
		displayPostorder(out, currRoot->left);
		displayPostorder(out, currRoot->right);
		out << *(currRoot->data) << endl;
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

	saveToFile(out, this->root);
	out.close();
}

void Table::saveToFile(ostream& out, Node * currRoot) const
{
	if(currRoot)
	{
		out << currRoot->data->getName() << ';' << currRoot->data->getGpa() << endl;
		saveToFile(out, currRoot->left);
		saveToFile(out, currRoot->right);
	}	
}

bool Table::remove(const char * key, Student& aStudent)
{
	return remove(this->root, key, aStudent);
}

bool Table::remove(Node *& currRoot, const char * key, Student& aStudent)
{
	if(!currRoot)
	{
		return false;
	}
	int temp = strcmp(key, currRoot->data->getName());
	if(temp == 0)
	{
		aStudent = *(currRoot->data);
		deleteNode(currRoot);
		size--;
		return true;
	}
	else if(temp < 0)
	{
		return remove(currRoot->left, key, aStudent);
	}
	else
	{
		return remove(currRoot->right, key, aStudent);
	}
}

void Table::deleteNode(Node *& target)
{
	//target node is a leaf
	if(!target->left && !target->right)
	{
		delete target->data;
		delete target;
		target = nullptr;
	}
	//target node only has left child
	else if(!target->right)
	{
		Node * temp = target;
		target = target->left;
		delete temp->data;
		delete temp;
	}
	//target node only has right child
	else if(!target->left)
	{
		Node * temp = target;
		target = target->right;
		delete temp->data;
		delete temp;
	}	
	//target node has two children
	else
	{
		//find the inorder successor of target node	
		Node * prev = nullptr;
		Node * curr = target->right; 	//start with the right child
		if(!curr->left)					//the right child is the inorder successor
		{
			target->right = curr->right;
		}
		else
		{
			while(curr->left)
			{
				prev = curr;
				curr = curr->left; 			//then go all the way to the left
			}
			prev->left = curr->right;
		}
		delete target->data;
		target->data = curr->data;
		delete curr;
		return;
	}
}
