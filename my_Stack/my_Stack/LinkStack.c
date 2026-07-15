#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkStack.h"

/*create*/
LinkStack_t* createLinkStack() {
	//创建链栈头
	LinkStack_t* stack = malloc(sizeof(LinkStack_t));
	if (stack == NULL) {
		printf("malloc failed\n");
	}

	//初始化
	stack->count = 0;
	stack->top = NULL;

	return stack;
}

/*push*/
int pushLinkStack(LinkStack_t* stack, value_t val) {
	//创建节点
	node_t* node = malloc(sizeof(node_t));
	if (node == NULL) {
		printf("malloc failed\n");
		return -1;
	}

	//push
	node->val = val;
	node->next = stack->top;
	stack->top = node;
	stack->count++;

	return 0;
}

/*pop*/
int popLinkStack(LinkStack_t* stack, value_t* val) {
	//underFlow
	if (stack->count <= 0) {
		printf("underFlow\n");
		return -1;
	}

	//pop
	node_t* tmp = stack->top;
	stack->top = stack->top->next;
	if (val) {
		*val = tmp->val;
	}
	free(tmp);
	stack->count--;

	return 0;
}

/*release*/
void releaseLinkStack(LinkStack_t* stack) {
	//临时指针
	node_t* tmp;
	while (stack && stack->top != NULL) {
		tmp = stack -> top;
		stack->top = stack->top->next;
		free(tmp);
		stack->count--;
	}

	//释放链栈头
	free(stack);
}