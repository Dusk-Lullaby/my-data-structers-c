#include <stdio.h>
#include <stdlib.h>
#include "quickUnion.h"

//创建
QuickUnionSet* createQuickUnionSet(int n) {
	QuickUnionSet* setQU = malloc(sizeof(QuickUnionSet));
	if (setQU == NULL) return NULL;
	setQU->data = malloc(sizeof(Element_t) * n);
	setQU->n = n;
	setQU->parent = malloc(sizeof(int) * n);
	setQU->size = malloc(sizeof(int) * n);
	if (setQU->data == NULL || setQU->parent == NULL || setQU->size == NULL)
		return NULL;

	return setQU;
}

//释放
void releaseQuickUnionSet(QuickUnionSet* setQU) {
	if (setQU == NULL) return;
	free(setQU->data);
	free(setQU->parent);
	free(setQU->size);
	setQU->n = 0;
	free(setQU);
}

//初始化
void initQuickUnionSet(QuickUnionSet* setQU, Element_t* data, int n) {
	if (setQU == NULL || data == NULL) return;
	for (int i = 0; i < n; i++) {
		setQU->data[i] = data[i];
		setQU->parent[i] = i;
		setQU->size[i] = 1;
	}
}

//查找索引
static int findIndex(QuickUnionSet* setQU, Element_t e) {
	for (int i = 0; i < setQU->n; i++) {
		if (setQU->data[i] == e) {
			return i;
		}
	}
	return -1;
}

#if 0
//查找根
static int findRoot(QuickUnionSet* setQU, Element_t e) {
	int index = findIndex(setQU, e);
	if (index == -1) return -1;
	//当父节点是自己时，则为根节点
	while (index != setQU->parent[index]) {
		index = setQU->parent[index];
	}

	return index;
}
#else
//路径压缩

//压栈
static SetNode* pushStack(SetNode* stack, int index) {
	SetNode* node = malloc(sizeof(SetNode));
	if (node == NULL) return NULL;
	node->index = index;
	node->parent = stack;
	stack = node;

	return stack;
}

//弹栈
static SetNode* popStack(SetNode* stack, int* index) {
	if (stack == NULL) return NULL;
	*index = stack->index;
	SetNode* node = stack;
	stack = stack->parent;
	free(node);
	return stack;
}

//查找根
static int findRoot(QuickUnionSet* setQU, Element_t e) {
	if (setQU == NULL) return -1;
	int curIndex = findIndex(setQU, e);
	SetNode* path = NULL;
	//遍历e号节点的父节点路径
	while (setQU->parent[curIndex] != curIndex) {
		path = pushStack(path, curIndex);
		curIndex = setQU->parent[curIndex];
	}
	//出栈
	while (path) {
		int pos;
		path = popStack(path, &pos);
		setQU->parent[pos] = setQU->parent[curIndex];
	}
	free(path);

	return curIndex;
}

#endif
//查找
int findQuickUnionSet(QuickUnionSet* setQU, Element_t a, Element_t b) {
	if (setQU == NULL) return 0;
	int aRoot = findRoot(setQU, a);
	int bRoot = findRoot(setQU, b);

	if (aRoot == -1 || bRoot == -1) return 0;
	return aRoot == bRoot;
}

//合并
void unionQuickUnionSet(QuickUnionSet* setQU, Element_t a, Element_t b) {
	if (setQU == NULL) return;
	int aRoot = findRoot(setQU, a);
	int bRoot = findRoot(setQU, b);
	if (aRoot == -1 || bRoot == -1) return;
	if (setQU->size[aRoot] > setQU->size[bRoot]) {
		setQU->parent[bRoot] = setQU->parent[aRoot];
		setQU->size[aRoot] += setQU->size[bRoot];
	}
	else {
		setQU->parent[aRoot] = setQU->parent[bRoot];
		setQU->size[bRoot] += setQU->size[aRoot];
	}
}