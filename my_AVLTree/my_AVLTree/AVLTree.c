#include <stdio.h>
#include <stdlib.h>
#include "AVLTree.h"

//创建平衡二叉树
AVLTree* createAVLTree() {
	AVLTree* tree = malloc(sizeof(AVLTree));
	if (tree == NULL) return NULL;

	tree->count = 0;
	tree->root = NULL;

	return tree;
}

//释放节点
static  void releaseTreeNode(AVLTree* tree, TreeNode* node) {
	if (node == NULL) return;

	releaseTreeNode(tree, node->left);
	releaseTreeNode(tree, node->right);
	free(node);
	tree->count--;
}

//释放平衡二叉树
void releaseAVLTree(AVLTree* tree) {
	if (tree == NULL) return;

	releaseTreeNode(tree, tree->root);
	printf("release: tree have %d node\n", tree->count);
}

//访问节点
void visitTreeNode(TreeNode* node) {
	if (node == NULL) return;
	printf("%d\t", node->data);
}

//中序遍历
static void inOrderTreeNode(TreeNode* node) {
	if (node == NULL) return;

	inOrderTreeNode(node->left);
	visitTreeNode(node);
	inOrderTreeNode(node->right);
}

//中序遍历平衡二叉树
void inOrderAVLTree(AVLTree* tree) {
	if (tree == NULL) return;
	inOrderTreeNode(tree->root);
	printf("\n");
}

//获取高度
int getHeight(TreeNode* node) {
	if (node == NULL) return 0;

	int leftHeight = getHeight(node->left);
	int rightHeight = getHeight(node->right);

	return leftHeight > rightHeight ? ++leftHeight : ++rightHeight;
}

//创建节点
static TreeNode* createTreeNode(Element_t data) {
	TreeNode* node = malloc(sizeof(TreeNode));
	if (node == NULL) return NULL;

	node->data = data;
	node->height = 1;
	node->left = NULL;
	node->right = NULL;

	return node;
}

//获取较大值
static int maxNum(int a, int b) {
	return a > b ? a : b;
}

//获取高度
static int h(TreeNode* node) {
	if (node == NULL) return 0;

	return node->height;
}

//计算平衡因子
static int getBalance(TreeNode* node) {
	if (node == NULL) return 0;

	return h(node->left) - h(node->right);
}

/*
		p					p
		|					|
		x					y
	  /   \				  /   \
	 lx    y			 x    ry
		 /   \		   /  \		\
		ly    ry	  lx  ly
				\
*/
//左旋，x是失衡节点
static TreeNode* leftRotate(TreeNode* x) {
	//旋转
	TreeNode* y = x->right;
	x->right = y->left;
	y->left = x;

	//更改高度
	x->height = maxNum(h(x->left), h(x->right)) + 1;
	y->height = maxNum(h(y->left), h(y->right)) + 1;

	return y;
}

/*
				p					p
				|					|
				y					x
			  /   \				  /   \
			x      ry			lx     y
		  /    \			   /     /   \
		lx    rx					rx    ry
	   /
*/
//右旋，y是失衡节点
static TreeNode* rightRotate(TreeNode* y) {
	//旋转
	TreeNode* x = y->left;
	y->left = x->right;
	x->right = y;

	//更改高度
	y->height = maxNum(h(y->left), h(y->right)) + 1;
	x->height = maxNum(h(x->left), h(x->right)) + 1;

	return x;
}

//插入节点
static TreeNode* insertTreeNode(AVLTree* tree, TreeNode* node, Element_t data) {
	if (node == NULL) {
		tree->count++;
		return createTreeNode(data);
	}
	
	if (data < node->data) {
		node->left = insertTreeNode(tree, node->left, data);
	}
	else if (data > node->data) {
		node->right = insertTreeNode(tree, node->right, data);
	}
	//相等
	else {
		return NULL;
	}

	//获取高度
	node->height = maxNum(h(node->left), h(node->right)) + 1;
	//计算平衡因子
	int balance = getBalance(node);

	//L
	if (balance > 1) {
		//R
		if (data > node->left->data) {
			node->left = leftRotate(node->left);
		}
		return rightRotate(node);
	}
	//R
	else if (balance < -1) {
		//L
		if (data < node->right->data) {
			node->right = rightRotate(node->right);
		}
		return leftRotate(node);
	}

	return node;
}

//插入平衡二叉树节点
void insertAVLTreeNode(AVLTree* tree, Element_t data) {
	if (tree == NULL) return;

	tree->root = insertTreeNode(tree, tree->root, data);
}

//删除节点
static TreeNode* deleteTreeNode(AVLTree* tree, TreeNode* node, Element_t data) {
	if (node == NULL) return NULL;

	//临时节点
	TreeNode* tmp;
	if (data < node->data) {
		node->left = deleteTreeNode(tree, node->left, data);
	}
	else if (data > node->data) {
		node->right = deleteTreeNode(tree, node->right, data);
	}
	//找到删除节点
	else {
		//度为0或者1
		if (node->left == NULL || node->right == NULL) {
			tmp = node->left == NULL ? node->right : node->left;

			//度为0
			if (tmp == NULL) {
				free(node);
				tree->count--;
				return NULL;
			}
			//度为1
			else {
				node->data = tmp->data;
				node->left = tmp->left;
				node->right = tmp->right;
				free(tmp);
				tree->count--;
				return node;
			}
		}
		//度为2
		else {
			//找到前驱节点
			tmp = node->left;
			while (tmp->right) {
				tmp = tmp->right;
			}

			//替换
			node->data = tmp->data;
			node->left = deleteTreeNode(tree, node->left, tmp->data);
		}
	}

	//计算高度
	node->height = maxNum(h(node->left), h(node->right)) + 1;
	//平衡因子
	int balance = getBalance(node);

	//R
	if (balance < -1) {
		//L
		if (getBalance(node->right) > 0) {
			node->right = rightRotate(node->right);
		}
		return leftRotate(node);
	}
	//L
	else if (balance > 1) {
		//R
		if (getBalance(node->left) < 0) {
			node->left = leftRotate(node->left);
		}
		return rightRotate(node);
	}

	return node;
}

//删除二叉平衡树节点
void deleteAVLTreeNode(AVLTree* tree, Element_t data) {
	if (tree == NULL) return;

	tree->root = deleteTreeNode(tree, tree->root, data);
}
