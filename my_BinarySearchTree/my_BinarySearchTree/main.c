#include <stdio.h>
#include "BinarySearchTree.h"

void test01() {
	BinarySearchTree_t* tree = createBinarySearchTree();
	Element_t data[] = { 55, 33, 45, 100, 22, 88, 8, 130};
	printf("========================\n");
	for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
		insertTreeNodeRecur(tree, data[i]);
	}
	printf("inOrder: ");
	inOrderBinarySearchTree(tree);
	int height = heightBinarySearchTree(tree->root);
	printf("tree height is %d\n", height);
	printf("tree have %d node\n", tree->count);

	printf("release: ");
	releaseBinarySearchTree(tree);
}

void test02() {
	BinarySearchTree_t* tree = createBinarySearchTree();
	Element_t data[] = { 55, 33, 45, 100, 22, 88, 8, 130, 120, 121, 122 };
	printf("========================\n");
	for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
		insertTreeNodeNoRecur(tree, data[i]);
	}
	printf("inOrder: ");
	inOrderBinarySearchTree(tree);
	int height = heightBinarySearchTree(tree->root);
	printf("tree height is %d\n", height);
	printf("tree have %d node\n", tree->count);
	//É¾³ý
	deleteBinarySearchTreeNodeRecur(tree, 100);
	deleteBinarySearchTreeNodeNoRecur(tree, 33);
	printf("inOrder: ");
	inOrderBinarySearchTree(tree);
	height = heightBinarySearchTree(tree->root);
	printf("tree height is %d\n", height);
	printf("tree have %d node\n", tree->count);


	printf("release: ");
	releaseBinarySearchTree(tree);

}

int main() {
	test01();
	test02();

	return 0;
}