#pragma once

// 枚举颜色类型
enum RedBlackColor {RED, BLACK};
typedef int keyType;

// 节点结构
typedef struct RBNode {
	keyType key;
	char color;
	struct RBNode* left;
	struct RBNode* right;
	struct RBNode* parent;
} RBNode;

typedef struct {
	RBNode* root;
	int count;
} RBTree;

// 初始化红黑树
RBTree* initRBTree();

// 插入
void insertRBTree(RBTree* tree, keyType key);

// 显示红黑树
void printRBTreeNode(RBNode* root, int parentKey, int dir);

// 删除红黑树
void deleteRBTree(RBTree* tree, keyType key);

// 释放红黑树
void releaseRBTree(RBTree* tree);