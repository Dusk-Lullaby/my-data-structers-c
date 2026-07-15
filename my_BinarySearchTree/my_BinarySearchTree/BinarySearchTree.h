#pragma once

typedef int Element_t;
//定义节点结构
typedef struct treenode {
	Element_t data;
	struct treenode* left;
	struct treenode* right;
}TreeNode_t;

//定义二叉搜索树结构
typedef struct {
	int count;
	TreeNode_t* root;
}BinarySearchTree_t;

/*
	功能： 创建二叉搜索树
	参数： 无
	返回值： 二叉搜索树
*/
BinarySearchTree_t* createBinarySearchTree();

/*
	功能： 递归插入节点
	参数： 二叉搜索树 节点数据
	返回值： 无
*/
void insertTreeNodeRecur(BinarySearchTree_t* tree, Element_t data);

/*
	功能： 访问节点数据
	参数： 节点
	返回值： 无
*/
void visitTreeNode(TreeNode_t* node);

/*
	功能： 释放二叉搜索树
	参数： 二叉搜索树
	返回值： 无
*/
void releaseBinarySearchTree(BinarySearchTree_t* tree);

/*
	功能： 中序遍历
	参数： 二叉搜索树
	返回值： 无
*/
void inOrderBinarySearchTree(BinarySearchTree_t* tree);

/*
	功能： 获取二叉搜索树高度
	参数： 二叉搜索树
	返回值：高度
*/
int heightBinarySearchTree(TreeNode_t* node);

/*
	功能： 搜索节点
	参数： 二叉搜索树 节点数据
	返回值： 节点
*/
TreeNode_t* searchTreeNode(BinarySearchTree_t* tree, Element_t data);

/*
	功能：非递归插入节点
	参数：二叉搜索树 节点数据
	返回值：无
*/
void insertTreeNodeNoRecur(BinarySearchTree_t* tree, Element_t data);

/*
	功能：递归删除节点
	参数：二叉搜索树 节点数据
	返回值：无
*/
void deleteBinarySearchTreeNodeRecur(BinarySearchTree_t* tree, Element_t data);

/*
	功能：非递归删除节点
	参数：二叉搜索树 节点数据
	返回值：无
*/
void deleteBinarySearchTreeNodeNoRecur(BinarySearchTree_t* tree, Element_t data);


