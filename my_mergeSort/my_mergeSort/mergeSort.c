#include <stdio.h>
#include <stdlib.h>
#include "mergemod.h"

// [left,right]闭区间内，实现排序，[left, mid][mid + 1, right]
static void merge(int* table, int left, int right, int mid) {
	// 计算左表包含的个数
	int n1 = mid - left + 1;
	// 计算右表包含的个数
	int n2 = right - mid - 1 + 1;
	// 额外分配数据缓存 aux1 aux2作为临时空间
	int* aux1 = malloc(sizeof(int) * n1);
	int* aux2 = malloc(sizeof(int) * n2);
	if (n1 == NULL || n2 == NULL) return;
	// 填充空间
	for (int i = 0; i < n1; i++) {
		aux1[i] = table[left + i];
	}
	for (int i = 0; i < n2; i++) {
		aux2[i] = table[mid + 1 + i];
	}
	// 对已经有序的aux1 和 aux2进行归并
	int i = 0;		// i指向aux1待查找的位置
	int j = 0;		// j指向aux2待查找的位置
	while (i < n1 && j < n2) {
		if (aux1[i] <= aux2[j]) {
			table[left + i + j] = aux1[i++];
		}
		else {
			table[left + i + j] = aux2[j++];
		}
	}
	// 循环退出条件是aux1或者aux2其中一个全部查找完，需要将未查找的继续查找
	while (i < n1) {
		table[left + i + j] = aux1[i++];
	}
	while (j < n2) {
		table[left + i + j] = aux2[j++];
	}

	free(aux1);
	free(aux2);
}

static void mergeLoop(int* table, int left, int right) {
	if (left >= right) return;
	int mid = (left + right) / 2;
	mergeLoop(table, left, mid);
	mergeLoop(table, mid + 1, right);
	// 拆分结束开始合并
	merge(table, left, right, mid);
}

void mergeSort(int* table, int n) {
	mergeLoop(table, 0, n - 1);
}