#include <stdio.h>
#include <stdlib.h>
#include "ThreadedBinaryTree.h"

/*创建节点*/
TreeNode_t* createTreeNode(Element_t data) {
	TreeNode_t* node = malloc(sizeof(TreeNode_t));
	if (node == NULL) {
		printf("malloc failed\n");
		return NULL;
	}
	//初始化
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->leftTag = 0;
	node->rightTag = 0;

	return node;
}

/*创建线索二叉树*/
ThreadedBinaryTree_t* createThreadedBinaryTree(TreeNode_t* root) {
	if (root == NULL) return NULL;
	ThreadedBinaryTree_t* tree = malloc(sizeof(ThreadedBinaryTree_t));
	if (tree == NULL) {
		printf("malloc failed\n");
		return NULL;
	}
	//初始化
	tree->count = 1;
	tree->root = root;

	return tree;
}

/*插入*/
void insertTreeNode(ThreadedBinaryTree_t* tree, TreeNode_t* parent, TreeNode_t* left, TreeNode_t* right) {
	if (tree == NULL || parent == NULL) return;
	if (left) {
		parent->left = left;
		tree->count++;
	}
	if (right) {
		parent->right = right;
		tree->count++;
	}

	return;
}

/*访问*/
void visitTreeNode(TreeNode_t* node) {
	if (node == NULL) return;
	printf("%c\t", node->data);
}

/*线索化节点*/
static TreeNode_t* pre = NULL;
void inOrderTreeNode(TreeNode_t* node) {
	//递归退出条件
	if (node == NULL) return;
	//访问左孩子
	inOrderTreeNode(node->left);
	//线索化
	if (node->left == NULL) {
		node->left = pre;
		node->leftTag = 1;
	}
	if (pre && pre->right == NULL) {
		pre->right = node;
		pre->rightTag = 1;
	}
	pre = node;
	//访问右孩子
	inOrderTreeNode(node->right);
}

/*线索化*/
void inOrderThreadingBinaryTree(ThreadedBinaryTree_t* tree) {
	inOrderTreeNode(tree->root);
}

/*中序遍历线索二叉树*/
void inOrderThreadedBinaryTree(ThreadedBinaryTree_t* tree) {
	TreeNode_t* node = tree->root;
	while (node) {
		//一路向左
		while (node->leftTag == 0) {
			node = node->left;
		}
		//访问头节点
		visitTreeNode(node);
		//一路向右
		while (node->rightTag == 1 && node->right) {
			node = node->right;
			visitTreeNode(node);
		}
		node = node->right;
	}
	printf("\n");
}

static void freeTreeNode(ThreadedBinaryTree_t* tree, TreeNode_t* node) {
	if (node == NULL) return;
	if (node->leftTag == 0) {
		freeTreeNode(tree, node->left);
	}
	if (node->rightTag == 0) {
		freeTreeNode(tree, node->right);
	}
	free(node);
	tree->count--;
}

/*释放*/
void releaseThreadedBinaryTree(ThreadedBinaryTree_t* tree) {
	freeTreeNode(tree, tree->root);
	printf("tree have %d node\n", tree->count);
	free(tree);
}