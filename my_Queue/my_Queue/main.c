#include <stdio.h>
#include "ArrayQueue.h"
#include "LinkQueue.h"

void test01() {
	ArrayQueue_t* queue = createArrayQueue();
	for (int i = 0; i < 5; i++) {
		enArrayQueue(queue, 100 + i);
	}
	Element_t e;
	while (deArrayQueue(queue, &e) == 0) {
		printf("%d\t", e);
	}
	printf("\n");
	releaseArrayQueue(queue);
}

void test02() {
	LinkQueue_t* queue = createLinkQueue();
	for (int i = 0; i < 5; i++) {
		enLinkQueue(queue, i + 100);
	}
	value_t val;
	while (deLinkQueue(queue, &val) == 0) {
		printf("%d\t", val);
	}
	releaseLinkQueue(queue);
}

int main() {
	test01();
	test02();
	return 0;
}