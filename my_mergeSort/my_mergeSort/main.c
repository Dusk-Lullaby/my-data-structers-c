#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mergeSort.h"

int main() {
	srand((unsigned int)time(NULL));
	int n = 10;
	int* table = malloc(sizeof(int) * n);
	if (table == NULL) return;
	for (int i = 0; i < n; i++) {
		int e = rand() % 100 + 1;
		printf("%d\t", e);
		table[i] = e;
	}
	printf("\n");

	mergeSort(table, n);
	for (int i = 0; i < n; i++) {
		printf("%d\t", table[i]);
	}
	printf("\n");
	free(table);

	return 0;
}