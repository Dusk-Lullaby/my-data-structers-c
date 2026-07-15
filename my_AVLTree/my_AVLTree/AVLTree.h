#pragma once

typedef int Element_t;

//申明节点结构
typedef struct _node {
	Element_t data;
	int height;
	struct _node* left;
	struct _node* right;
} TreeNode;

//申明平衡二叉树结构
typedef struct {
	TreeNode* root;
	int count;
}AVLTree;

/*
	功能：创建平衡二叉树
	参数：无
	返回值：平衡二叉树
*/
AVLTree* createAVLTree();

/*
	功能：释放平衡二叉树
	参数：平衡二叉树
	返回值：无
*/
void releaseAVLTree(AVLTree* tree);

/*
	功能：访问节点数据
	参数：平衡二叉树节点
	返回值：无
*/
void visitTreeNode(TreeNode* node);

/*
	功能：中序遍历
	参数：平衡二叉树
	返回值：无
*/
void inOrderAVLTree(AVLTree* tree);

/*
	功能：获取高度
	参数：平衡二叉树根节点
	返回值：高度
*/
int getHeight(TreeNode* node);

/*
	功能：插入二叉平衡树节点
	参数：平衡二叉树 节点数据
	返回值：无
*/
void insertAVLTreeNode(AVLTree* tree, Element_t data);

/*
	功能：删除平衡二叉树节点
	参数：平衡二叉树 节点数据
	返回值：无
*/
void deleteAVLTreeNode(AVLTree* tree, Element_t data);