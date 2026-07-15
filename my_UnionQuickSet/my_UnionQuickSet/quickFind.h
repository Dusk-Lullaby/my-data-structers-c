#pragma once
#include "common.h"
/*
	QuickFind方法：每个元素都有一个编号，只要编号一样，就认为是一个集团的人
	合并时，把另外一个团伙的人的老大改为这个团伙的老大
*/

typedef struct {
	Element_t* data;	//存放具体数据，利用对应的索引建立元素关系，维护只维护索引
	int n;				//并查集元素的个数
	int* groupID;		//每个元素的组ID
}QuickFindSet;

/*
	功能：创建并查集
	参数：元素的个数
	返回值：并查集
*/
QuickFindSet* createQuickFindSet(int n);

/*
	功能：释放并查集
	参数：并查集
	返回值：无
*/
void releaseQuickFindSet(QuickFindSet* setQF);

/*
	功能：初始化并查集
	参数：并查集 元素数组 元素个数
	返回值：无
*/
void initQuickFindSet(QuickFindSet* setQF, Element_t* data, int n);

/*
	功能：查找两个元素是否在同一组
	参数：并查集 元素a 元素b
	返回值：0失败 1成功
*/
int findQuickFindSet(QuickFindSet* setQF, Element_t a, Element_t b);

/*
	功能：合并
	参数：并查集 元素a 元素b
	返回值：无
*/
void unionQuickFindSet(QuickFindSet* setQF, Element_t a, Element_t b);