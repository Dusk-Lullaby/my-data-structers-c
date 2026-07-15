#include <stdio.h>
#include "BinaryTree.h"

BinaryTree_t* initBinaryTree() {
	TreeNode_t* treeA = createTreeNode('A');
	TreeNode_t* treeB = createTreeNode('B');
	TreeNode_t* treeC = createTreeNode('C');
	TreeNode_t* treeD = createTreeNode('D');
	TreeNode_t* treeE = createTreeNode('E');
	TreeNode_t* treeF = createTreeNode('F');
	TreeNode_t* treeG = createTreeNode('G');
	TreeNode_t* treeH = createTreeNode('H');
	TreeNode_t* treeK = createTreeNode('K');

	BinaryTree_t* tree = createBinaryTree(treeA);
	insertTreeNode(tree, treeA, treeB, treeE);
	insertTreeNode(tree, treeB, NULL, treeC);
	insertTreeNode(tree, treeC, treeD, NULL);
	insertTreeNode(tree, treeE, NULL, treeF);
	insertTreeNode(tree, treeF, treeG, NULL);
	insertTreeNode(tree, treeG, treeH, treeK);

	return tree;
}


int main() {
	BinaryTree_t* tree = initBinaryTree();
	levelOrderBinaryTree(tree);
	preOrderBinaryTreeNoRecur(tree);
	preOrderBinaryTree(tree);
	inOrderBinaryTreeNoRecur(tree);
	inOrderBinaryTree(tree);
	postOrderBinaryTree(tree);

	releaseBinaryTree(tree);

	return 0;
}