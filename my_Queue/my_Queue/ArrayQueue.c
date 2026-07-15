#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayQueue.h"

/*创建*/
ArrayQueue_t* createArrayQueue() {
	//开辟空间
	ArrayQueue_t* queue = malloc(sizeof(ArrayQueue_t));
	if (queue == NULL) {
		printf("malloc failed\n");
		return NULL;
	}
	//初始化
	memset(queue, 0, sizeof(ArrayQueue_t));

	return queue;
}

/*入队*/
int enArrayQueue(ArrayQueue_t* queue, Element_t element) {
	//判断队列是否为满
	if (((queue->rear + 1) % MAXSIZE == queue->front)) {
		printf("full\n");
		return -1;
	}
	//入队
	//先入队再后移
	queue->data[queue->rear] = element;
	queue->rear = (queue->rear + 1) % MAXSIZE;

	return 0;
}

/*出队*/
int deArrayQueue(ArrayQueue_t* queue, Element_t* element) {
	//判断空
	if (queue->front == queue->rear) {
		printf("empty\n");
		return -1;
	}
	// 出队
	// 先出队再后移
	if (element) {
		*element = queue->data[queue->front];
	}
	queue->front = (queue->front + 1) % MAXSIZE;

	return 0;
}

/*释放*/
void releaseArrayQueue(ArrayQueue_t* queue) {
	if (queue) {
		free(queue);
	}
}