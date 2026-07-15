#pragma once

typedef int value_t;

typedef struct _node {
	value_t val;
	struct _node* next;
}node_t;

typedef struct {
	int count;
	node_t* front;
	node_t* rear;
}LinkQueue_t;

/*
	功能： 链式队列的创建
	参数： 无
	返回值： 创建的队列
*/
LinkQueue_t* createLinkQueue();

/*
	功能： 释放链式队列
	参数： 需要释放的队列
	返回值： 无
*/
void releaseLinkQueue(LinkQueue_t* queue);

/*
	功能： 入队
	参数： 队列 入队的元素
	返回值： 成功0 失败-1
*/
int enLinkQueue(LinkQueue_t* queue, value_t val);

/*
	功能： 出队
	参数： 队列 出队的元素
	返回值： 成功0 失败-1
*/
int deLinkQueue(LinkQueue_t* queue, value_t* val);