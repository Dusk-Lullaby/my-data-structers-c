#include <stdio.h>
#include "ArrayStack.h"
#include "LinkStack.h"

void test01() {
	ArrayStack_t* stack = createArrayStack();
	for (int i = 0; i < 6; i++) {
		pushArrayStack(stack, i);
	}
	Element_t e;
	for (int i = 0; i < 6; i++) {
		popArrayStack(stack, &e);
	}
	releaseArrayStack(stack);
}

void test02() {
	LinkStack_t* stack = createLinkStack();
	pushLinkStack(stack, 82);
	Element_t e = 100;
	popLinkStack(stack, &e);
	printf("%d\n", e);
	popLinkStack(stack, &e);
	releaseLinkStack(stack);
}

int main() {
	test01();
	test02();

	return 0;
}