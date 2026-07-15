#pragma once

typedef int value_t;

//节点结构
typedef struct _node {
	value_t val;
	struct _node* next;
}node_t;

typedef struct {
	int count;
	node_t* top;
}LinkStack_t;

/*
	功能： 创建链栈
	参数： 无
	返回值： 创建的链表
*/
LinkStack_t* createLinkStack();

/*
	功能： 压栈
	参数： 需要压栈的链栈 需要压入的元素
	返回值： 成功0 失败-1
*/
int pushLinkStack(LinkStack_t* stack, value_t val);

/*
	功能： 弹栈
	参数： 需要弹栈的链栈 弹出的元素
	返回值： 成功0 失败-1
*/
int popLinkStack(LinkStack_t* stack, value_t* val);

/*
	功能： 释放链栈
	参数： 无
	返回值： 无
*/
void releaseLinkStack(LinkStack_t* stack);