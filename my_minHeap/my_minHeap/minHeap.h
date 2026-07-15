#pragma once 

typedef struct {
	int* data;				// 数据域
	int capacity;			// 最大容量
	int len;				// 约束堆的数据长度
}MinHeap;

MinHeap* createMinHeap(int n);

void insertMinHeap(MinHeap* heap, int e);

int extractMinHeap(MinHeap* heap);

void releaseMinHeap(MinHeap* heap);