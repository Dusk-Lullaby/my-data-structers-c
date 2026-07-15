#pragma once

// HuffmanTree的节点结构，顺序存储每个元素的属性
typedef struct {
	int weight;		// 节点的权值
	int parent;		// 该节点的父亲编号，0表示根
	int lChild;		// 该节点的孩子编号
	int rChild;
}HuffmanNode, *HuffmanTree;

typedef char* HuffmanCode;

// 已知n个字符的权值表，根据这个表创建出对应的哈夫曼树空间
HuffmanTree createHuffmanTree(const int* w, int n);

// 释放哈夫曼树
void releaseHuffmanTree(HuffmanTree tree);

// 产生哈夫曼树编码
HuffmanCode* createHuffmanCode(HuffmanTree tree, int n);
