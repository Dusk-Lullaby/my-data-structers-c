#pragma once
#include "common.h"

typedef struct {
	Element_t* data;
	int n;
	int* parent;	//父节点的编号
	int* size;		//存放对应元素作为根节点时，表示元素的个数
} QuickUnionSet;

typedef struct _node{
	int index;
	struct _node* parent;
} SetNode;

/*
	功能：创建并查集
	参数：元素的个数
	返回值：无
*/
QuickUnionSet* createQuickUnionSet(int n);

/*
	功能：释放并查集
	参数：并查集
	返回值：无
*/
void releaseQuickUnionSet(QuickUnionSet* setQU);

/*
	功能：初始化并查集
	参数：并查集 数据数组 元素个数
	返回值：无
*/
void initQuickUnionSet(QuickUnionSet* setQU, Element_t* data, int n);

/*
	功能：查找
	参数：并查集 元素a 元素b
	返回值：0失败 1成功
*/
int findQuickUnionSet(QuickUnionSet* setQU, Element_t a, Element_t b);

/*
	功能：合并
	参数：并查集 元素a 元素b
	返回值：无
*/
void unionQuickUnionSet(QuickUnionSet* setQU, Element_t a, Element_t b);