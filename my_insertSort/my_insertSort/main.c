#include <stdio.h>
#include <stdlib.h>
#include "insertSort.h"

int main() {
	// 初始化随机数种子
	srand((unsigned int)time(NULL));
	int n = 10;
	int* table = malloc(sizeof(int) * n);
	int* table2 = malloc(sizeof(int) * n);
	int* table3 = malloc(sizeof(int) * n);
	if (table == NULL || table2 == NULL || table3 == NULL) return;
	for (int i = 0; i < n; i++) {
		table[i] = rand() % 100 + 1;
		printf("%d\t", table[i]);
	}
	insertSort1(table, n);
	printf("\n");
	for (int i = 0; i < n; i++) {
		printf("%d\t", table[i]);
	}
	printf("\n");

	for (int i = 0; i < n; i++) {
		table2[i] = rand() % 100 + 1;
		printf("%d\t", table2[i]);
	}
	insertSort2(table2, n);
	printf("\n");
	for (int i = 0; i < n; i++) {
		printf("%d\t", table2[i]);
	}
	printf("\n");

	for (int i = 0; i < n; i++) {
		table3[i] = rand() % 100 + 1;
		printf("%d\t", table3[i]);
	}
	shellSort(table3, n);
	printf("\n");
	for (int i = 0; i < n; i++) {
		printf("%d\t", table3[i]);
	}
	printf("\n");

	free(table);
	free(table2);
	free(table3);

	return 0;
}