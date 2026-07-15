#pragma once

typedef char Element_t;
//定义线索二叉树节点结构
typedef struct treenode {
	Element_t data;
	struct treenode* left;
	struct treenode* right;
	int leftTag;	//0表示left指向节点，1表示线索化（前驱）
	int rightTag;	//0表示right指向节点，1表示线索化（后继）
}TreeNode_t;

//定义线索二叉树结构
typedef struct {
	TreeNode_t* root;
	int count;
}ThreadedBinaryTree_t;

/*
	功能： 创建线索二叉树
	参数： 根节点
	返回值： 线索二叉树
*/
ThreadedBinaryTree_t* createThreadedBinaryTree(TreeNode_t* root);

/*
	功能： 创建节点
	参数： 节点数据
	返回值： 节点
*/
TreeNode_t* createTreeNode(Element_t data);

/*
	功能： 释放线索二叉树
	参数： 线索二叉树
	返回值： 无
*/
void releaseThreadedBinaryTree(ThreadedBinaryTree_t* tree);

/*
	功能： 插入节点
	参数： 二叉树 父亲节点 左孩子 右孩子
	返回值： 无
*/
void insertTreeNode(ThreadedBinaryTree_t* tree, TreeNode_t* parent, TreeNode_t* left, TreeNode_t* right);

/*
	功能： 线索化
	参数： 二叉树
	返回值: 无
*/
void inOrderThreadingBinaryTree(ThreadedBinaryTree_t* tree);

/*
	功能： 访问节点数据
	参数： 节点
	返回值： 无
*/
void visitTreeNode(TreeNode_t* node);

/*
	功能: 中序遍历线索二叉树
	参数： 线索二叉树
	返回值： 无
*/
void inOrderThreadedBinaryTree(ThreadedBinaryTree_t* tree);