#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

/*创建二叉树*/
BinaryTree_t* createBinaryTree(TreeNode_t* root) {
	if (root) {
		//开辟空间
		BinaryTree_t* tree = malloc(sizeof(BinaryTree_t));
		if (tree == NULL) { 
			printf("malloc failed\n");
			return NULL; 
		}
		//初始化
		tree->num = 1;
		tree->root = root;

		return tree;
	}

	return NULL;
}

/*创建结点*/
TreeNode_t* createTreeNode(Element_t e) {
	//开辟空间
	TreeNode_t* node = malloc(sizeof(TreeNode_t));
	if (node == NULL) {
		printf("malloc failed\n");
	}
	//初始化
	node->data = e;
	node->left = NULL;
	node->right = NULL;

	return node;
}

/*插入*/
void insertTreeNode(BinaryTree_t* tree, TreeNode_t* parent, TreeNode_t* left, TreeNode_t* right) {
	if (tree && parent) {
		if (left) {
			parent->left = left;
			tree->num++;
		}
		if (right) {
			parent->right = right;
			tree->num++;
		}
	}
}

/*打印*/
void showTreeNode(TreeNode_t* node) {
	if (node == NULL) return;
	printf("%c\t", node->data);
}

/*广度优先遍历*/
#define MAX_QUEUE_SIZE 10
void levelOrderBinaryTree(BinaryTree_t* tree) {
	//创建队列
	TreeNode_t* queue[MAX_QUEUE_SIZE];
	int front = -1;
	int rear = -1;
	//预激活队列
	queue[0] = tree->root;
	front = 0;
	rear = 1;
	TreeNode_t* node;
	printf("levelOrder:\n");
	while (front != rear) {
		//出队
		node = queue[front];
		printf("%c\t", node->data);
		front = (front + 1) % MAX_QUEUE_SIZE;
		//入队
		if (node->left) {
			if ((rear + 1) % MAX_QUEUE_SIZE == front) {
				printf("overflow\n");
				return;
			}
			queue[rear] = node->left;
			rear = (rear + 1) % MAX_QUEUE_SIZE;
		}
		if (node->right) {
			if ((rear + 1) % MAX_QUEUE_SIZE == front) {
				printf("overflow\n");
				return;
			}
			queue[rear] = node->right;
			rear = (rear + 1) % MAX_QUEUE_SIZE;
		}
	}
	printf("\n");
}

/*先序遍历结点*/
static void preOrderTreeNode(TreeNode_t* node) {
	if (node == NULL) return;
	showTreeNode(node);
	preOrderTreeNode(node->left);
	preOrderTreeNode(node->right);
}

/*先序遍历*/
void preOrderBinaryTree(BinaryTree_t* tree) {
	printf("preOrder:\n");
	preOrderTreeNode(tree->root);
	printf("\n");
}

static void inOrderTreeNode(TreeNode_t* node) {
	if (node == NULL) return;
	inOrderTreeNode(node->left);
	showTreeNode(node);
	inOrderTreeNode(node->right);
}

/*中序遍历*/
void inOrderBinaryTree(BinaryTree_t* tree) {
	printf("inOrder:\n");
	inOrderTreeNode(tree->root);
	printf("\n");
}

static void postOrderTreeNode(TreeNode_t* node) {
	if (node == NULL) return;
	postOrderTreeNode(node->left);
	postOrderTreeNode(node->right);
	showTreeNode(node);
}

/*后序遍历*/
void postOrderBinaryTree(BinaryTree_t* tree) {
	printf("postOrder:\n");
	postOrderTreeNode(tree->root);
	printf("\n");
}

/*先序非递归*/
#define MAX_STACK_SIZE 10
void preOrderBinaryTreeNoRecur(BinaryTree_t* tree) {
	//申请栈满递增栈
	TreeNode_t* stack[MAX_STACK_SIZE];
	int top = -1;
	//预激活，放入第一个任务
	stack[++top] = tree->root;
	TreeNode_t* node;
	printf("preOrderNoRecur:\n");
	while (top >= 0) {
		//出栈
		node = stack[top--];
		showTreeNode(node);
		//入栈
		if (node->right) {
			stack[++top] = node->right;
		}
		if (node->left) {
			stack[++top] = node->left;
		}
	}
	printf("\n");
}

/*中序非递归*/
void inOrderBinaryTreeNoRecur(BinaryTree_t* tree) {
	//申请栈
	TreeNode_t* stack[MAX_STACK_SIZE];
	int top = -1;
	//预激活
	printf("inOrderNoRecur:\n");
	TreeNode_t* node = tree->root;
	while (top >= 0 || node) {
		if (node) {
			stack[++top] = node;
			node = node->left;
		}
		else {
			node = stack[top--];
			showTreeNode(node);
			node = node->right;
		}
	}
	printf("\n");
}

static void releaseTreeNode(BinaryTree_t* tree, TreeNode_t* node) {
	if (node == NULL) return;
	releaseTreeNode(tree, node->left);
	releaseTreeNode(tree, node->right);
	free(node);
	tree->num--;
}

/*释放*/
void releaseBinaryTree(BinaryTree_t* tree) {
	if (tree) {
		releaseTreeNode(tree, tree->root);
		printf("tree have %d node\n", tree->num);
		free(tree);
	}
}