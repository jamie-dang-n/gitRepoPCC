#include "table.h"

int count(node * root) {
	if (!root) {
		return 0;
	} else {
		// root exists, so the count is at least 1 + whatever
		// nodes are present in either subtree
		return count(root->left) + count(root->right) + 1;
	}
}


int sum(node * root) {
	if (!root) {
		return 0;
	} else {
		// root exists, so the count is at least root->data +
		// whaetever data exists in the other nodes in the subtrees
		return sum(root->left) + sum(root->right) + root->data;
	}	
}

// Finds the height of the tree by looking at the height of both subtrees
int height(node * root) {
	if (!root) {
		return 0;
	} else {
		int left = height(root->left); // look at height of left subtree
		int right = height(root->right); // look at height of right subtree

		// compare heights and return the higher one
		if (left > right) {
			return left + 1;
		} else {
			return right + 1;
		}
	}
}

