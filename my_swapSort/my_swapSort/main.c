#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "swapSort.h"

int* createTable(char name[], int n) {
	int* table = malloc(sizeof(int) * n);
	if (table == NULL) {
		return NULL;
	}
	printf("%s :\n", name);
	for (int i = 0; i < n; i++) {
		table[i] = rand() % 100 + 1;
		printf("%d\t", table[i]);
	}
	printf("\n");
	return table;
}

static void print(int* table, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d\t", table[i]);
	}
	printf("\n");
}

int main() {
	srand((unsigned int)time(NULL));
	int n = 10;
	int* bubbleTable1 = createTable("bubbleTable1", n);
	bubbleSort1(bubbleTable1, n);
	print(bubbleTable1, n);
	printf("\n");
	
	int* bubbleTable2 = createTable("bubbleTable2", n);
	bubbleSort2(bubbleTable2, n);
	print(bubbleTable2, n);
	printf("\n");
	
	int* bubbleTable3 = createTable("bubbleTable3", n);
	bubbleSort3(bubbleTable3, n);
	print(bubbleTable3, n);
	printf("\n");

	int* quickTable1 = createTable("quickTable1", n);
	quickSort1(quickTable1, n);
	print(quickTable1, n);
	printf("\n");

	int* quickTable2 = createTable("quickTable2", n);
	quickSort2(quickTable2, n);
	print(quickTable2, n);
	printf("\n");

}