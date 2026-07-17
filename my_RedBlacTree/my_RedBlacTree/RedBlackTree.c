#include <stdio.h>
#include <stdlib.h>
#include "RedBlackTree.h"

// 初始化
RBTree* initRBTree() {
	RBTree* tree = malloc(sizeof(RBTree));
	if (tree == NULL) return NULL;
	memset(tree, 0, sizeof(RBTree));
	return tree;
}

// 创建红黑树节点
static RBNode* createRBNode(keyType key) {
	RBNode* node = malloc(sizeof(RBNode));
	if (node == NULL) return NULL;
	memset(node, 0, sizeof(RBNode));
	node->color = RED;
	node->key = key;
	return node;
}

/*
*		  px
*         |
*         x
*       /  \
*      lx   y
*          / \
*		  ly  ry
*
*/
static void leftRotate(RBTree* tree, RBNode* x) {
	RBNode* y = x->right;
	x->right = y->left;
	if (y->left) {
		y->left->parent = x;
	}
	y->parent = x->parent;
	if (x->parent) {
		if (x->parent->left == x) {
			x->parent->left = y;
		}
		else {
			x->parent->right = y;
		}
	}
	else {
		tree->root = y;
	}
	y->left = x;
	x->parent = y;
}

/*
*		  px
*         |
*         x
*        / \
*      y    rx
*     / \
*	 ly	 ry
*
*/
static void rightRotate(RBTree* tree, RBNode* x) {
	RBNode* y = x->left;
	x->left = y->right;
	if (y->right) {
		y->right->parent = x;
	}
	y->parent = x->parent;
	if (x->parent) {
		if (x->parent->left == x) {
			x->parent->left = y;
		}
		else {
			x->parent->right = y;
		}
	}
	else {
		tree->root = y;
	}
	y->right = x;
	x->parent = y;
}

/*
* 如果node的父节点是黑色，那么不需要修复，直接返回
* 如果node的父节点是红色，那么出现红红，进行调整
*	叔叔节点是红色
*		父节点和叔叔节点变为黑色，祖父节点变为红色，将祖父节点看作新节点重新判断
*	叔叔节点是黑色
*		旋转，交换父节点和祖父节点的颜色
*/
static void insertFixUp(RBTree* tree, RBNode* node) {
	RBNode* parent = node->parent;
	RBNode* grandparent = NULL;
	RBNode* uncle = NULL;
	RBNode* tmp = NULL;
	// 父节点存在且为红红，在红黑树中，根节点一定为黑色，所以根节点不为空
	while (parent && parent->color == RED) {
		// 找到祖父节点，根据祖父节点和父节点的关系找到叔叔节点
		grandparent = parent->parent;
		uncle = grandparent->left == parent ? grandparent->right : grandparent->left;
		// 叔叔节点存在且是红色的
		if (uncle && uncle->color == RED) {
			// 1. 把父节点和叔叔节点都变为黑色
			parent->color = BLACK;
			uncle->color = BLACK;
			// 2. 把祖父节点变为红色
			grandparent->color = RED;
			// 3. 将祖父节点看成新节点继续往上循环
			node = grandparent;
			parent = grandparent->parent;
			continue;
		}
		// 叔叔节点是黑色
		if (grandparent->left == parent) {	// L
			// LR
			if (parent->right == node) {
				leftRotate(tree, parent);
				tmp = node;
				node = parent;
				parent = tmp;
			}
			// LL
			rightRotate(tree, grandparent);
			grandparent->color = RED;
			parent->color = BLACK;
		}
		else {	// R
			// RL
			if (parent->left == node) {
				rightRotate(tree, parent);
				tmp = node;
				node = parent;
				parent = tmp;
			}
			// RR
			leftRotate(tree, grandparent);
			grandparent->color = RED;
			parent->color = BLACK;
		}
	}
	tree->root->color = BLACK;
}

// 插入
void insertRBTree(RBTree* tree, keyType key) {
	// 1. 创建一个红黑树节点
	RBNode* node = createRBNode(key);
	// 2. 根据二叉搜索树的规则找到待插入点
	RBNode* cur = tree->root;
	RBNode* pre = NULL;
	while (cur) {
		pre = cur;
		if (key < cur->key) {
			cur = cur->left;
		}
		else if (key > cur->key) {
			cur = cur->right;
		}
		else {
			printf("key: %d is exist\n", key);
			return;
		}
	}
	// 3. 在对应位置上插入，若是根节点，更新tree
	node->parent = pre;
	if (pre) {
		if (key < pre->key) {
			pre->left = node;
		}
		else {
			pre->right = node;
		}
	}
	else {
		tree->root = node;
	}
	tree->count++;
	// 4. 修复红黑树
	insertFixUp(tree, node);
}

// 显示红黑树节点
void printRBTreeNode(RBNode* node, int parentKey, int dir) {
	if (node) {
		if (dir == 0) {
			printf("%2d[B] is root\n", node->key);
		}
		else {
			printf("%2d[%c] is %2d's %s\n", node->key,
				node->color == RED ? 'R' : 'B',
				parentKey, dir == 1 ? "right child" : "left child");
		}
		printRBTreeNode(node->left, node->key, -1);
		printRBTreeNode(node->right, node->key, 1);
	}
}

// 寻找节点
static RBNode* searchRBNode(RBTree* tree, keyType key) {
	RBNode* node = tree->root;
	while (node) {
		if (key < node->key) {
			node = node->left;
		} 
		else if (key > node->key) {
			node = node->right;
		}
		else {
			return node;
		}
	}
	printf("not found %d key\n", key);
	return NULL;
}

// 调整删除节点
static void deleteFixup(RBTree* tree, RBNode* x, RBNode* parent) {
	RBNode* w = NULL;
	// x不是根节点，并且x是黑色
	while (x != tree->root && (!x || x->color == BLACK)) {
		// x是父亲的左孩子
		if (parent->left == x) {
			w = parent->right;
			// case1: x的兄弟是红色
			if (w->color == RED) {
				// 1. 将兄弟节点设置为黑色
				w->color = BLACK;
				// 2. 将父亲节点设置为红色
				parent->color = RED;
				// 3. 左旋父亲节点
				leftRotate(tree, parent);
				// 4. 重新设置x的兄弟节点
				w = parent->right;
			}
			// case2: x的兄弟w是黑色，且w的孩子都是黑色
			if ((!w->left || w->left->color == BLACK) && (!w->right || w->right->color == BLACK)) {
				// 1. 兄弟节点变为红色
				w->color = RED;
				// 2. 修正父节点为当前节点
				x = parent;
				parent = parent->parent;
			}
			else {
				// case3：异向红，兄弟节点是黑色，左孩子是红色，右孩子是黑色
				if (!w->right || w->right->color == BLACK) {
					// 1. 左孩子变为黑色
					w->left->color = BLACK;
					// 2. 兄弟节点变为红色
					w->color = RED;
					// 3. 右旋父亲节点
					rightRotate(tree, w);
					// 4. 重新设置兄弟节点
					w = parent->right;
				}
				// case4: 同向红，x的兄弟节点是黑色，右孩子是红色，左孩子随意
				// 1. 兄弟的右孩子变为兄弟颜色
				w->right->color = w->color;
				// 2. 兄弟的颜色变为父亲的颜色
				w->color = parent->color;
				// 3。 将父亲节点变为黑色
				parent->color = BLACK;
				// 4. 左旋父亲节点
				leftRotate(tree, parent);
				x = tree->root;
				break;
			}
		}
		// x是父亲的右孩子
		else {
			w = parent->left;
			// case1: x的兄弟是红色
			if (w->color == RED) {
				// 1. 将兄弟节点设置为黑色
				w->color = BLACK;
				// 2. 将父亲节点设置为红色
				parent->color = RED;
				// 3. 右旋父亲节点
				rightRotate(tree, parent);
				// 4. 将重新设置兄弟节点
				w = parent->left;
			}
			// case2：x的兄弟是黑色，且兄弟节点的孩子都是黑色
			if ((!w->left || w->left->color == BLACK) && (!w->right || w->right->color == BLACK)) {
				// 1. 兄弟节点变为红色
				w->color = RED;
				// 2. 修正父节点为当前节点
				x = parent;
				parent = parent->parent;
			}
			else {
				// case3: 异向红，x的兄弟是黑色，且兄弟的右孩子是红色，左孩子是黑色
				if (!w->left || w->left->color == BLACK) {
					// 1. 右孩子变黑
					w->right->color = BLACK;
					// 2. 兄弟节点变红
					w->color = RED;
					// 3. 左旋兄弟节点
					leftRotate(tree, w);
					// 4. 重新设置兄弟节点
					w = parent->left;
				}
				// case4: 同向红，x的兄弟是黑色，且左孩子是红色，右孩子随意
				// 1. 兄弟的左孩子变为兄弟的颜色
				w->left->color = w->color;
				// 2. 兄弟节点的颜色变为父亲的颜色
				w->color = parent->color;
				// 3. 将父亲节点变为黑色
				parent->color = BLACK;
				// 4. 右旋父亲节点
				rightRotate(tree, parent);
				x = tree->root;
				break;
			}
		}
	}
	if (x) {
		x->color = BLACK;
	}
}

// 删除红黑树中的节点
static void deleteRBNode(RBTree* tree, RBNode* node) {
	RBNode* y;			// 真正删除的节点地址
	RBNode* x;			// 替换节点
	RBNode* parent;		// 替换节点为null后，无法找到父亲
	if (node->left == NULL || node->right == NULL) {
		y = node;
	}
	else {
		y = node->right;
		while (y->left) {
			y = y->left;
		}
	}
	// 真正删除的节点找到了，开始寻找替换节点
	if (y->left) {
		x = y->left;
	}
	else {
		x = y->right;
	}
	parent = y->parent;
	// 开始更新替换节点和原父节点的关系
	if (x) {
		x->parent = y->parent;
	}
	if (y->parent == NULL) {
		tree->root = x;
	}
	else {
		if (y->parent->left == y) {
			y->parent->left = x;
		}
		else {
			y->parent->right = x;
		}
	}
	// 更新左右孩子的根节点为后继节点的值，其他不变
	if (y != node) {
		node->key = y->key;
	}
	// 如果删除节点是黑色需要进行调整
	if (y->color == BLACK) {
		deleteFixup(tree, x, parent);
	}
	// 删除节点是红色，或者调整完，直接删除
	free(y);
	tree->count--;
}

// 删除红黑树节点
void deleteRBTree(RBTree* tree, keyType key) {
	RBNode* node = searchRBNode(tree, key);
	if (node == NULL) return;
	deleteRBNode(tree, node);
}

// 释放红黑树的节点
static void releaseRBNode(RBTree* tree, RBNode* node) {
	if (node) {
		releaseRBNode(tree, node->left);
		releaseRBNode(tree, node->right);
		free(node);
		tree->count--;
	}
}

// 释放红黑树
void releaseRBTree(RBTree* tree) {
	if (tree->root) {
		releaseRBNode(tree, tree->root);
	}
	printf("release: tree have %d node\n", tree->count);
}