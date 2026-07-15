#include <stdio.h>
#include <stdlib.h>
#include "swapSort.h"

static swap(int* table, int index1, int index2) {
	int temp = table[index1];
	table[index1] = table[index2];
	table[index2] = temp;
}

void bubbleSort1(int* table, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (table[j] > table[j + 1])
				swap(table, j, j + 1);
		}
	}
}

void bubbleSort2(int* table, int n) {
	for (int i = 0; i < n; i++) {
		int flag = 1;
		for (int j = 0; j < n - 1 - i; j++) {
			if (table[j] > table[j + 1]) {
				swap(table, j, j + 1);
				flag = 0;
			}
		}
		if (flag) return;
	}
}

void bubbleSort3(int* table, int n) {
	// newIndex 用于记录每轮遍历中最后一次发生交换的元素下标
	int newIndex;

	do {
		// 每次遍历前初始化为 0。
		// 如果整轮遍历都没有触发交换，newIndex 会保持为 0，从而终止循环（说明数组已有序）。
		newIndex = 0;
		// 遍历当前需要排序的区间 [0, n-1)
		for (int i = 0; i < n - 1; i++) {
			// 如果相邻元素逆序，则进行交换
			if (table[i] > table[i + 1]) {
				swap(table, i, i + 1);
				// 记录最后一次交换的位置。
				// 因为 i+1 之后的元素没有再发生交换，说明它们已经处于正确且有序的位置。
				newIndex = i + 1;
			}
		}
		// 将下一轮的遍历终点 n 更新为最后一次交换的位置。
		// 这直接略过了尾部已经排好序的部分，减少了不必要的比较。
		n = newIndex;
	} while (newIndex != 0); // 当 newIndex 为 0 时，说明没有发生任何交换，排序完成。
}

static int partitionDouble(int* table, int start, int end) {
	swap(table, start, rand() % (end - start + 1) + start);
	int pivot = table[start];
	int left = start;
	int right = end;
	while (left < right) {
		while (left < right && table[right] >= pivot) {
			right--;
		}
		while (left < right && table[left] <= pivot) {
			left++;
		}
		if (left < right) {
			swap(table, left, right);
		}
	}
	swap(table, start, left);
	return left;
}

static void quickSortTable1(int* table, int start, int end) {
	if (start >= end) {
		return;
	}
	int pivotIndex = partitionDouble(table, start, end);
	quickSortTable1(table, 0, pivotIndex - 1);
	quickSortTable1(table, pivotIndex + 1, end);
}

void quickSort1(int* table, int n) {
	quickSortTable1(table, 0, n - 1);
}

static int partitionSingle(int* table, int start, int end) {
	swap(table, start, rand() % (end - start + 1) + start);
	int pivot = table[start];
	int mark = start;
	for (int i = start + 1; i <= end; i++) {
		if (pivot > table[i]) {
			mark++;
			swap(table, mark, i);
		}
	}
	swap(table, start, mark);
	return mark;
}

static void quickSortTable2(int* table, int start, int end) {
	if (start >= end) {
		return;
	}
	int pivotIndex = partitionSingle(table, start, end);
	quickSortTable2(table, 0, pivotIndex - 1);
	quickSortTable2(table, pivotIndex + 1, end);

}

void quickSort2(int* table, int n) {
	quickSortTable2(table, 0, n - 1);
}