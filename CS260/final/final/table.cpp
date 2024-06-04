#include "table.h"
//Please put the impelementation of the required functions here

//Recursively calculate the sum of all the leaf nodes (nodes that have no children) in the tree.
int sumOfLeafNodes(node * root) {
	int sum = 0;
	if (root) {
		// root exists, so traverse both sides (postorder) and increment if the node is a leaf
		sum = sumOfLeafNodes(root->left);
		sum += sumOfLeafNodes(root->right);

		if (root->left == nullptr && root->right == nullptr) {
			return sum + root->data;
		}

	}
	return sum;
}

//Recursively copy all the nodes that contain even number in the source tree with root. 
//newRoot is the root for destination tree. The destination tree should only contain 
//the copies of the nodes that contain even number in the source tree.
void copyEven(node * root, node *& newRoot) {
	// this function will traverse in pre-order, checking the
	// data in each node. if the data is even, we call add() for
	// the newRoot tree.
	if (root) {
		if (root->data % 2 == 0) {
			add(newRoot, root->data);
		}
		// the add function will traverse for us, so only change
		// the root for the current tree so we can keep scanning for
		// even numbers. add() can handle traversing through newRoot.
		copyEven(root->left, newRoot);
		copyEven(root->right, newRoot);
	}

}

//Helper function to add data into newRoot for copyEven
//the add function always adds new nodes as a leaf
void add(node *& root, int num) {
	if (!root) {
		// reached end of branch, add new leaf
		root = new node;
		root->left = nullptr;
		root->right = nullptr;
		root->data = num;
	} else if (num < root->data) {
		add(root->left, num);
	} else {
		add(root->right, num);
	}
}
