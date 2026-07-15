#include <stdio.h>
#include <stdlib.h>
#include "quickFind.h"

//创建
QuickFindSet* createQuickFindSet(int n) {
	QuickFindSet* setQF = malloc(sizeof(QuickFindSet));
	if (setQF == NULL) return NULL;
	setQF->data = malloc(sizeof(Element_t) * n);
	setQF->groupID = malloc(sizeof(int) * n);
	setQF->n = n;
	if (setQF->data == NULL || setQF->groupID == NULL) return NULL;

	return setQF;
}

//释放
void releaseQuickFindSet(QuickFindSet* setQF) {
	if (setQF == NULL) return;
	free(setQF->data);
	free(setQF->groupID);
	free(setQF);
}

//初始化
void initQuickFindSet(QuickFindSet* setQF, Element_t* data, int n) {
	if (setQF == NULL || data == NULL) return;
	for (int i = 0; i < n; i++) {
		setQF->data[i] = data[i];
		setQF->groupID[i] = data[i];
	}
}

//查找索引
static int findIndex(QuickFindSet* setQF, Element_t e) {
	for (int i = 0; i < setQF->n; i++) {
		if (setQF->data[i] == e) {
			return i;
		}
	}

	return -1;
}

//查找
int findQuickFindSet(QuickFindSet* setQF, Element_t a, Element_t b) {
	if (setQF == NULL) return 0;
	int aIndex = findIndex(setQF, a);
	int bIndex = findIndex(setQF, b);
	if (aIndex == -1 || bIndex == -1) return 0;
	return setQF->groupID[aIndex] == setQF->groupID[bIndex];
}

//合并
void unionQuickFindSet(QuickFindSet* setQF, Element_t a, Element_t b) {
	int aIndex = findIndex(setQF, a);
	int bIndex = findIndex(setQF, b);
	if (aIndex == -1 || bIndex == -1) return;
	//备份需要变化的组ID
	int gID = setQF->groupID[bIndex];
	for (int i = 0; i < setQF->n; i++) {
		if (setQF->groupID[i] == gID) {
			setQF->groupID[i] = setQF->groupID[aIndex];
		}
	}
}