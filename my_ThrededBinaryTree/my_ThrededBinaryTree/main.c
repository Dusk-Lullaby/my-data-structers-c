#include <stdio.h>
#include "ThreadedBinaryTree.h"

ThreadedBinaryTree_t* init() {
	TreeNode_t* nodeA = createTreeNode('A');
	TreeNode_t* nodeB = createTreeNode('B');
	TreeNode_t* nodeC = createTreeNode('C');
	TreeNode_t* nodeD = createTreeNode('D');
	TreeNode_t* nodeE = createTreeNode('E');
	TreeNode_t* nodeF = createTreeNode('F');
	TreeNode_t* nodeG = createTreeNode('G');
	TreeNode_t* nodeH = createTreeNode('H');
	TreeNode_t* nodeK = createTreeNode('K');

	ThreadedBinaryTree_t* tree = createThreadedBinaryTree(nodeA);
	insertTreeNode(tree, nodeA, nodeB, nodeE);
	insertTreeNode(tree, nodeB, NULL, nodeC);
	insertTreeNode(tree, nodeC, NULL, NULL);
	insertTreeNode(tree, nodeC, nodeD, NULL);
	insertTreeNode(tree, nodeD, NULL, NULL);
	insertTreeNode(tree, nodeE, NULL, nodeF);
	insertTreeNode(tree, nodeF, nodeG, NULL);
	insertTreeNode(tree, nodeG, nodeH, nodeK);

	return tree;
}

int main() {
	ThreadedBinaryTree_t* tree;
	tree = init();
	printf("tree have %d node\n", tree->count);
	inOrderThreadingBinaryTree(tree);
	inOrderThreadedBinaryTree(tree);
	releaseThreadedBinaryTree(tree);

	return 0;
}