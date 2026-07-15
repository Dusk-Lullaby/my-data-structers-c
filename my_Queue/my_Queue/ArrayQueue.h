#pragma once

typedef int Element_t;
#define MAXSIZE 5
typedef struct {
	Element_t data[MAXSIZE];
	int front;
	int rear;
}ArrayQueue_t;

/*
	功能： 创建顺序队列
	参数： 无
	返回值： 需要创建的顺序队列
*/
ArrayQueue_t* createArrayQueue();

/*
	功能： 释放顺序队列
	参数： 需要释放的顺序队列
	返回值： 无
*/
void releaseArrayQueue(ArrayQueue_t* queue);

/*
	功能： 入队
	参数： 队列 需要入队的元素
	返回值： 成功0 失败-1
*/
int enArrayQueue(ArrayQueue_t* Queue, Element_t element);

/*
	功能： 出队
	参数： 队列 需要出队的元素
	返回值： 成功0 失败-1
*/
int deArrayQueue(ArrayQueue_t* queue, Element_t* element);