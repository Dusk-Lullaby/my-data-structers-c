#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"

/*创建树*/
BinarySearchTree_t* createBinarySearchTree() {
	BinarySearchTree_t* tree = malloc(sizeof(BinarySearchTree_t));
	if (tree == NULL) {
		printf("malloc failed\n");
		return NULL;
	}
	//初始化
	tree->count = 0;
	tree->root = NULL;

	return tree;
}

/*创建节点*/
static TreeNode_t* createTreeNode(Element_t data) {
	TreeNode_t* node = malloc(sizeof(TreeNode_t));
	if (node == NULL) {
		printf("malloc failed\n");
		return NULL;
	}
	//初始化
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

/*插入节点*/
static TreeNode_t* insertNode(BinarySearchTree_t* tree, TreeNode_t* node, Element_t data) {
	if (node == NULL) {
		tree->count++;
		return createTreeNode(data);
	}
	if (data < node->data) {
		node->left = insertNode(tree, node->left, data);
	}
	else if (data > node->data) {
		node->right = insertNode(tree, node->right, data);
	}

	return node;
}

/*递归插入*/
void insertTreeNodeRecur(BinarySearchTree_t* tree, Element_t data) {
	if (tree == NULL) return;
	tree->root = insertNode(tree, tree->root, data);
}

/*访问节点数据*/
void visitTreeNode(TreeNode_t* node) {
	if (node) {
		printf("%d\t", node->data);
	}
}

/*释放节点*/
static void releaseTreeNode(BinarySearchTree_t* tree, TreeNode_t* node) {
	if (node == NULL) return;
	releaseTreeNode(tree, node->left);
	releaseTreeNode(tree, node->right);
	free(node);
	tree->count--;
}

/*释放*/
void releaseBinarySearchTree(BinarySearchTree_t* tree) {
	releaseTreeNode(tree, tree->root);
	printf("tree have %d node\n", tree->count);
	free(tree);
}

/*中序遍历节点*/
static void inOrderTreeNode(TreeNode_t* node) {
	if (node == NULL) return;
	inOrderTreeNode(node->left);
	visitTreeNode(node);
	inOrderTreeNode(node->right);
}

/*中序遍历*/
void inOrderBinarySearchTree(BinarySearchTree_t* tree) {
	inOrderTreeNode(tree->root);
	printf("\n");
}

/*高度*/
int heightBinarySearchTree(TreeNode_t* node) {
	if (node == NULL) return 0;

	int rightHeight = heightBinarySearchTree(node->right);
	int leftHeight = heightBinarySearchTree(node->left);
	
	if (leftHeight > rightHeight) {
		return ++leftHeight;
	}
	else {
		return ++rightHeight;
	}
}

/*搜索*/
TreeNode_t* searchTreeNode(BinarySearchTree_t* tree, Element_t data) {
	TreeNode_t* node = tree->root;

	while (node) {
		if (data < node->data) {
			node = node->left;
		}
		else if (data > node->data) {
			node = node->right;
		}
		else return node;
	}

	return NULL;
}

/*插入节点非递归*/
void insertTreeNodeNoRecur(BinarySearchTree_t* tree, Element_t data) {
	if (tree == NULL) return;

	//辅助指针
	TreeNode_t* pre = NULL;
	TreeNode_t* cur = tree->root;

	while (cur) {
		pre = cur;
		if (data < cur->data) {
			cur = cur->left;
		}
		else if (data > cur->data) {
			cur = cur->right;
		}
		//如果相等就直接返回
		else {
			return;
		}
	}

	//创建节点
	TreeNode_t* node = createTreeNode(data);
	if (pre) {
		if (data < pre->data) {
			pre->left = node;
		}
		else {
			pre->right = node;
		}
	}
	//当根节点不存在时，pre和cur都为空
	else {
		tree->root = node;
	}
	tree->count++;
}

//寻找后继节点
static TreeNode_t* miniValueTreeNode(TreeNode_t* node) {
	while (node && node->left) {
		node = node->left;
	}

	return node;
}

//寻找前驱节点
static TreeNode_t* maxiValueTreeNode(TreeNode_t* node) {
	while (node && node->right) {
		node = node->right;
	}

	return node;
}

//递归删除节点
static TreeNode_t* deleteTreeNodeRecur(BinarySearchTree_t* tree, TreeNode_t* node, Element_t data) {
	//归
	if (node == NULL) return NULL;
	
	//递
	if (data < node->data) {
		node->left = deleteTreeNodeRecur(tree, node->left, data);
	}
	else if (data > node->data) {
		node->right = deleteTreeNodeRecur(tree, node->right, data);
	}
	//相等
	else {
		//临时指针
		TreeNode_t* tmp;
		//度为1或者0
		if (node->left == NULL) {
			tmp = node->right;
			free(node);
			tree->count--;
			return tmp;
		}
		//度为1
		if (node->right == NULL) {
			tmp = node->left;
			free(node);
			tree->count--;
			return tmp;
		}

		//当左右孩子都非空，度为2，需要找到前驱或者后继进行替换
		
		//后继
		tmp = miniValueTreeNode(node->right);
		node->data = tmp->data;
		node->right = deleteTreeNodeRecur(tree, node->right, tmp->data);
		//前驱
		//tmp = maxiValueTreeNode(node->left);
		//node->data = tmp->data;
		//node->left = deleteTreeNodeRecur(tree, node->left, tmp->data);
	}

	return node;
}

//递归删除二叉搜索树节点
void deleteBinarySearchTreeNodeRecur(BinarySearchTree_t* tree, Element_t data) {
	if (tree == NULL) return;
	tree->root = deleteTreeNodeRecur(tree, tree->root, data);
}

//非递归删除节点（前驱节点）
static void maxiDeleteTreeNodeNoRecur(BinarySearchTree_t* tree, TreeNode_t* node) {
	TreeNode_t* pre = NULL;
	TreeNode_t* maxi = node->left;

	while (maxi->right) {
		pre = maxi;
		maxi = maxi->right;
	}

	//node->left 就是前驱节点
	if (pre == NULL) {
		node->data = maxi->data;
		node->left = maxi->left;
	}
	else {
		node->data = maxi->data;
		pre->right = maxi->left;
	}
	free(maxi);
	tree->count--;
}

//非递归删除节点（后继节点）
static void miniDeleteTreeNodeNoRecur(BinarySearchTree_t* tree, TreeNode_t* node) {
	TreeNode_t* pre = NULL;
	TreeNode_t* mini = node->right;

	while (mini->left) {
		pre = mini;
		mini = mini->left;
	}

	//node->right 就是后继
	if (pre == NULL) {
		node->data = mini->data;
		node->right = mini->right;
	}
	else {
		node->data = mini->data;
		pre->left = mini->right;
	}

	free(mini);
	tree->count--;
}

//非递归删除二叉搜索树节点
void deleteBinarySearchTreeNodeNoRecur(BinarySearchTree_t* tree, Element_t data) {
	if (tree == NULL) return;
	TreeNode_t* node = tree->root;
	//前置指针
	TreeNode_t* pre = NULL;

	while (node) {
		if (data < node->data) {
			pre = node;
			node = node->left;
		}
		else if (data > node->data) {
			pre = node;
			node = node->right;
		}
		//找到需要删除的节点
		else {
			break;
		}
	}

	if (node == NULL) {
		printf("No %d Element\n", data);
		return;
	}

	//已经找到需要删除的节点
	//辅助指针
	TreeNode_t* tmp;
	if (node->left == NULL) {
		tmp = node->right;
	}
	else if (node->right == NULL) {
		tmp = node->left;
	}
	//度为2
	else {
		//前驱
		//maxiDeleteTreeNodeNoRecur(tree, node);
		//后继
		miniDeleteTreeNodeNoRecur(tree, node);
		return;
	}

	if (pre) {
		if (pre->data > node->data) {
			pre->left = tmp;
		}
		else {
			pre->right = tmp;
		}
		free(node);
	}
	//根节点
	else {
		tree->root = tmp;
		free(node);
	}
	tree->count--;
}