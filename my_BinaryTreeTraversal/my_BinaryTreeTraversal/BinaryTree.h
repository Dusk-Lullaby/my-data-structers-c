#pragma once

typedef char Element_t;
typedef struct tree_node{
	Element_t data;
	struct tree_node* left;
	struct tree_node* right;
}TreeNode_t;

typedef struct {
	TreeNode_t* root;
	int num;
}BinaryTree_t;

/*
	功能： 创建二叉树
	参数： 根结点
	返回值： 无
*/
BinaryTree_t* createBinaryTree(TreeNode_t* root);

/*
	功能： 创建结点
	参数： 需要创建的结点元素
	返回值： 结点
*/
TreeNode_t* createTreeNode(Element_t e);

/*
	功能： 插入结点
	参数： 二叉树 父亲结点 左孩子 右孩子
	返回值： 无
*/
void insertTreeNode(BinaryTree_t* tree, TreeNode_t* parent, TreeNode_t* left, TreeNode_t* right);

/*
	功能： 打印结点数据域
	参数： 二叉树结点
	返回值： 无
*/
void showTreeNode(TreeNode_t* node);

/*
	功能： 广度优先遍历
	参数： 二叉树
	返回值： 无
*/
void levelOrderBinaryTree(BinaryTree_t* tree);

/*
	功能： 先序遍历
	参数： 二叉树
	返回值： 无
*/
void preOrderBinaryTree(BinaryTree_t* tree);

/*
	功能： 中序遍历
	参数： 二叉树
	返回值： 无
*/
void inOrderBinaryTree(BinaryTree_t* tree);

/*
	功能： 后序遍历
	参数： 二叉树
	返回值： 无
*/
void postOrderBinaryTree(BinaryTree_t* tree);

/*
	功能： 先序非递归
	参数： 二叉树
	返回值： 无
*/
void preOrderBinaryTreeNoRecur(BinaryTree_t* tree);

/*
	功能： 中序非递归
	参数： 二叉树
	返回值：无
*/
void inOrderBinaryTreeNoRecur(BinaryTree_t* tree);

/*
	功能： 释放二叉树
	参数： 二叉树
	返回值： 无
*/
void releaseBinaryTree(BinaryTree_t* tree);