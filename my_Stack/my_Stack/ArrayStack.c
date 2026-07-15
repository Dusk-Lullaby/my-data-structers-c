#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayStack.h"

/*创建*/
ArrayStack_t* createArrayStack() {
	//创建
	ArrayStack_t* stack = malloc(sizeof(ArrayStack_t));
	if (stack == NULL) {
		printf("malloc failed\n");
		return NULL;
	}

	//初始化
	memset(stack->data, 0, sizeof(stack->data));
	stack->top = -1;

	return stack;
}

/*压栈*/
int pushArrayStack(ArrayStack_t* stack, Element_t e) {
	//判断overFlow
	if (stack->top >= MAXSIZE - 1) {
		printf("overFlow\n");
		return -1;
	}

	//push
	stack->data[++stack->top] = e;

	return 0;
}

/*出栈*/
int popArrayStack(ArrayStack_t* stack, Element_t* e) {
	//underFlow
	if (stack->top < 0) {
		printf("underFlow\n");
		return -1;
	}

	//pop
	Element_t tmp = stack->data[stack->top--];
	if (e) {
		*e = tmp;
	}

	return 0;
}

/*释放*/
void releaseArrayStack(ArrayStack_t* stack) {
	if (stack) {
		free(stack);
	}
}