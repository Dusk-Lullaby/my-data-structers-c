#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "minHeap.h"

MinHeap* createMinHeap(int n) {
	MinHeap* heap = malloc(sizeof(MinHeap));
	if (heap == NULL) return NULL;
	heap->data = malloc(sizeof(int) * (n + 1));
	if (heap->data == NULL) {
		free(heap->data);
		return NULL;
	}
	heap->len = 0;
	heap->capacity = n;
	memset(heap->data, 0, sizeof(int) * (n + 1));
	return heap;
}

static void siftUp(MinHeap* heap, int k) {
	while (k > 1 && heap->data[k] < heap->data[k / 2]) {
		int tmp = heap->data[k];
		heap->data[k] = heap->data[k / 2];
		heap->data[k / 2] = tmp;
		k /= 2;
	}
}

void insertMinHeap(MinHeap* heap, int e) {
	if (heap->len >= heap->capacity) {
		printf("Heap Full\n");
	}
	// ÔÚÄ©¶Ë²åÈëÔªËØ
	heap->data[++heap->len] = e;
	siftUp(heap, heap->len);
}

static void siftDown(MinHeap* heap, int k) {
	while (2 * k <= heap->len) {
		int index = 2 * k;
		if (2 * k + 1 <= heap->len && heap->data[index + 1] < heap->data[index]) {
			index = 2 * k + 1;
		}
		if (heap->data[index] > heap->data[k]) {
			break;
		}
		int tmp = heap->data[index];
		heap->data[index] = heap->data[k];
		heap->data[k] = tmp;
		k = index;
	}
}

int extractMinHeap(MinHeap* heap) {
	int ret = heap->data[1];
	heap->data[1] = heap->data[heap->len--];
	siftDown(heap, 1);
	return ret;
}

void releaseMinHeap(MinHeap* heap) {
	if (heap == NULL) return;
	if (heap->data) {
		free(heap->data);
		heap->data = NULL;
	}
	free(heap);
}
