#include <stdio.h>
#include <stdlib.h>
#include "RedBlackTree.h"

int main() {
	int data[] = { 55, 40, 65, 60, 75, 57, 63, 56 };

	RBTree* tree = initRBTree();
	for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
		insertRBTree(tree, data[i]);
	}
	printRBTreeNode(tree->root, tree->root->key, 0);
	printf("===================\n");
	deleteRBTree(tree, 40);
	printRBTreeNode(tree->root, tree->root->key, 0);
	releaseRBTree(tree);

	return 0;
}