#include <stdio.h>
#include <stdlib.h>
#include "AVLTree.h"

int main() {
	Element_t data[] = { 40, 20, 60, 10, 30, 50,
					80, 7, 25, 55, 68, 90 };
	AVLTree* tree = createAVLTree();
	for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
		insertAVLTreeNode(tree, data[i]);
	}
	inOrderAVLTree(tree);
	printf("tree height is %d\n", getHeight(tree->root));
	printf("tree height is %d\n", tree->root->height);

	deleteAVLTreeNode(tree, 60);
	deleteAVLTreeNode(tree, 55);
	inOrderAVLTree(tree);

	releaseAVLTree(tree);

	return 0;
}