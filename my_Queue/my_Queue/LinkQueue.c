#include <stdio.h>
#include <stdlib.h>
#include "LinkQueue.h"

/*创建*/
LinkQueue_t* createLinkQueue() {
	//开辟空间
	LinkQueue_t* queue = malloc(sizeof(LinkQueue_t));
	if (queue == NULL) {
		printf("malloc failed\n");
		return NULL;
	}
	//初始化
	queue->count = 0;
	queue->front = NULL;
	queue->rear = NULL;

	return queue;
}

/*入队*/
int enLinkQueue(LinkQueue_t* queue, value_t val) {
	//开辟空间
	node_t* node = malloc(sizeof(node_t));
	if (node == NULL) {
		printf("malloc failed\n");
		return -1;
	}
	//赋值
	node->next = NULL;
	node->val = val;
	//第一次入队
	if (queue->front == NULL) {
		queue->front = node;
		queue->rear = node;
	}
	//入队
	else {
		queue->rear->next = node;
		queue->rear = node;
	}
	queue->count++;

	return 0;
}

/*出队*/
int deLinkQueue(LinkQueue_t* queue, value_t* val) {
	if (queue == NULL) return -1;
	//判断队列是否为空
	if (queue->front == NULL) {
		printf("empty\n");
		return -1;
	}
	//出队
	node_t* tmp = queue->front;
	if (val) {
		*val = tmp->val;
	}
	queue->front = tmp->next;
	free(tmp);
	queue->count--;
	// 最后一个元素出队时，需要小心rear变为野指针
	if (queue->front == NULL) {
		queue->rear = NULL;
	}

	return 0;
}

/*释放*/
void releaseLinkQueue(LinkQueue_t* queue) {
	if (queue) {
		//临时指针
		node_t* tmp;
		while (queue->front) {
			tmp = queue->front;
			queue->front = tmp->next;
			free(tmp);
			queue->count--;
		}
		printf("queue have %d node\n", queue->count);
		free(queue);
	}
}