#pragma once

typedef int Element_t;

#define MAXSIZE 5
typedef struct {
	Element_t data[MAXSIZE];
	int top;
}ArrayStack_t;

/*
	功能： 创建顺序栈
	参数： 无
	返回值： 创建的顺序栈
*/
ArrayStack_t* createArrayStack();

/*
	功能： 压栈
	参数： 需要压栈的顺序栈 需要压入的元素
	返回值： 成功0 失败-1
*/
int pushArrayStack(ArrayStack_t* stack, Element_t e);

/*
	功能： 出栈
	参数： 需要出栈的顺序栈 出栈的元素
	返回值： 成功0 失败-1
*/
int popArrayStack(ArrayStack_t* stack, Element_t* e);

/*
	功能： 释放顺序栈
	参数： 需要释放的顺序表
	返回值： 无
*/
void releaseArrayStack(ArrayStack_t* stack);