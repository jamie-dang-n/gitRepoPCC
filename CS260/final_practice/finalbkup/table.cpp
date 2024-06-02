#include "table.h"

//Please put the impelementation of the required functions here
// Recursively count the number of nodes in the BST
int numberOfNodes(node * root) {
	if (!root) {
		// base case: tree is empty
		return 0;
	} else {
		// root exists, so the count is at least 1 + whatever 
		// nodes are present in either subtree.
		return numberOfNodes(root->left) + numberOfNodes(root->right) + 1;
	}
}

// Recursively remove the node that contains the smallest value in the tree
void removeSmallest(node *& root) {
	// this is a BST, so the smallest value in the tree is the LEFTMOST value
	if (root->left) {
		removeSmallest(root->left);
	} else {
		deleteNode(root);
	}
}

// Recursively remove all the nodes that contain even numbers in the tree
int removeEven(node *& root) {
	int num = 0;
	if (root) {
		// recursive case: root still exists, so keep traversing
		// use postorder traversal to remove all even numbers
		num = removeEven(root->left);
		num += removeEven(root->right);

		if (root->data % 2 == 0) {
			deleteNode(root);
			return num + 1;
		}
	}
	return num;
}

// Helper function for deleting nodes in the BST
void deleteNode (node *& target) {
	if (!target->left && !target->right) {
		// target node is a leaf
		delete target;
		target = nullptr;
	} else if (!target->right) {
		// target node only has left child
		node * temp = target;
		target = target->left;
		delete temp;
		temp = nullptr;
	} else if (!target->left) {
		// target node only has right child
		node * temp = target;
		target = target->right;
		delete temp;
		temp = nullptr;
	} else {
		// target has 2 children

		// Find inorder successor of the target node (leftmost node of the right subtree)
		node * prev = nullptr;
		node * curr = target->right; // start in the right subtree
		if (!curr->left) {
			// not possible to traverse left, so the right child is the inorder successor
			target->right = curr->right;
		} else {
			// traverse leftward as far as we can
			while (curr->left) {
				prev = curr;
				curr = curr->left;
			}
			prev->left = curr->right; // relink
		}
		target->data = curr->data;
		delete curr;
		prev = nullptr;
		curr = nullptr;
	}
}

