#include <stdio.h>
#include <stdlib.h>

typedef int Element;

// 闭区间查找[0 ... n - 1]
int BinarySearchV1(const Element* table, int n, Element target) {
	int left = 0;
	int right = n - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (table[mid] == target) {
			return mid;
		}
		else if (table[mid] < target) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	return -1;
}

// 开区间查找[0 ... n)
int BinarySearchV2(const Element* table, int n, Element target) {
	int left = 0;
	int right = n;
	while (left < right) {
		int mid = left + (right - left) / 2;
		if (table[mid] == target) {
			return mid;
		}
		else if (table[mid] < target) {
			left = mid + 1;
		}
		else {
			right = mid;
		}
	}

	return -1;
}

int main() {
	int n = 10;
	Element* table = malloc(sizeof(Element) * 10);
	if (table == NULL) return -1;

	for (int i = 0; i < n; i++) {
		table[i] = 90 + i;
		printf("%d\t", table[i]);
	}
	printf("\n");

	for (int i = 0; i < n; i++) {
		int index = BinarySearchV1(table, n, table[i]);
		printf("%d\t", index);
	}
	printf("\n");
	for (int i = 0; i < n; i++) {
		int index = BinarySearchV2(table, n, table[i]);
		printf("%d\t", index);
	}
	printf("\n");
}