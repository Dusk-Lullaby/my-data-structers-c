#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include "HuffmanTree.h"

static void seleteNode(HuffmanTree tree, int n, int* s1, int* s2) {
	if (tree == NULL) return;

	int min = 0;
	// 获取最小编号
	for (int i = 1; i <= n; i++) {
		if (tree[i].parent == 0) {
			min = i;
			break;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (tree[i].parent == 0 && tree[i].weight < tree[min].weight) {
			min = i;
		}
	}
	*s1 = min;

	// 获取第二小的编号
	for (int i = 1; i <= n; i++) {
		if (tree[i].parent == 0 && i != *s1) {
			min = i;
			break;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (tree[i].parent == 0 && i != *s1 && tree[i].weight < tree[min].weight)
			min = i;
	}
	*s2 = min;
}

HuffmanTree createHuffmanTree(const int* w, int n) {
	int m = 2 * n - 1;
	
	// 申请2n个节点
	// 如果正常从下标 0 开始存储有效节点，那么放在 0 号位置的节点就是一个实际存在的有效节点。
	// 此时，如果检查到某个节点的 parent == 0，程序在逻辑上将无法区分：
	HuffmanTree tree = malloc(sizeof(HuffmanNode) * (m + 1));
	if (tree == NULL) return NULL;

	// 初始化 1 ~ 2n - 1 个节点
	for (int i = 1; i <= m; i++) {
		tree[i].weight = tree[i].parent = tree[i].lChild = tree[i].rChild = 0;
	}
	
	// 设置初始化值
	for (int i = 1; i <= n; i++) {
		tree[i].weight = w[i - 1];
	}

	int s1, s2;			// 选取当前节点表，权值最小的两个
	for (int i = n + 1; i <= m; i++) {
		// [1...i-1]范围内，父节点为0的约束下，寻找两个最小值
		seleteNode(tree, i - 1, &s1, &s2);
		// 将这两个最小值，组合到第i个位置上
		tree[i].lChild = s1;
		tree[i].rChild = s2;
		tree[i].weight = tree[s1].weight + tree[s2].weight;
		tree[s1].parent = tree[s2].parent = i;
	}

	return tree;
}

void releaseHuffmanTree(HuffmanTree tree) {
	if (tree) {
		free(tree);
	}
}

HuffmanCode* createHuffmanCode(HuffmanTree tree, int n) {
	// 开辟一个存放哈夫曼编码的数组
	HuffmanCode* codes = malloc(sizeof(HuffmanCode) * n);
	// 开辟一个临时空间，来存放每个节点的哈夫曼编码
	char* temp = malloc(sizeof(char) * n);
	if (codes == NULL || temp == NULL) return NULL;
	// 初始化
	memset(codes, 0, sizeof(HuffmanCode) * n);

	int start;		// 用来临时空间进行编码的起始位置，从后往前开始编码
	int p;			// 存放当前节点的父节点信息
	int pos;		// 正在编码的位置

	for (int i = 1; i <= n; i++) {
		// 树的最大高度是n - 1
		start = n - 1;
		// 由于编码是从后往前，并且有'\0'，因此temp数组可以直接进行覆盖
		temp[start] = '\0';
		pos = i;
		p = tree[pos].parent;

		while (p) {
			start--;
			// 左0右1
			temp[start] = tree[p].lChild == pos ? '0' : '1';
			pos = p;
			p = tree[pos].parent;
		}
		// 将临时空间的值拷贝给正式空间
		codes[i - 1] = malloc(sizeof(char) * (n - start));
		strcpy(codes[i - 1], &temp[start]);
	}

	free(temp);
	return codes;
}