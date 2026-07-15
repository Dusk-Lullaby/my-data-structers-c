#include <stdio.h>
#include <stdlib.h>
#include "insertSort.h"

void insertSort1(int* table, int n) {
	for (int i = 1; i < n; i++) {
		// 如果后面的数比前面的数小
		if (table[i] < table[i - 1]) {
			// 存储需要插入的数据
			int tmp = table[i];
			// 用j的辅助变量找到待插入的位置
			int j = i - 1;
			while (j >= 0 && tmp < table[j]) {
				table[j + 1] = table[j];
				j--;
			}
			table[j + 1] = tmp;
		}
	}
}

void insertSort2(int* table, int n) {
	for (int i = 1; i < n; i++) {
		int tmp = table[i];
		int j;
		for (j = i; j > 0 && tmp < table[j - 1]; j--) {
			table[j] = table[j - 1];
		}
		table[j] = tmp;
	}
}

void shellSort(int* table, int n) {
	for (int gap = n / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < n; i++) {
			int tmp = table[i];
			int j;
			for (j = i; j >= gap && tmp < table[j - gap]; j -= gap) {
				table[j] = table[j - gap];
			}
			table[j] = tmp;
		}
	}
}