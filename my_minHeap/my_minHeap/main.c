#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "minHeap.h"

int main() {
	srand((unsigned)time(NULL));
	int n = 10;
	MinHeap* table = createMinHeap(n);
	for (int i = 0; i < n; i++) {
		int e = rand() % 100 + 1;
		printf("%d\t", e);
		insertMinHeap(table, e);
	}
	printf("\n");

	for (int i = 0; i < n; i++) {
		printf("%d\t", extractMinHeap(table));
	}
	printf("\n");

	releaseMinHeap(table);
}