#include <stdio.h>
#include "LinkList.h"

void test01(void) {
	LinkList_t* link_table = createLinkList();
	for (int i = 0; i < 10; i++) {
		insertLinkListHead(link_table, 100 + i);
	}
	showLinkList(link_table);
	printf("-------------\n");
	deleteLinkListElement(link_table, 100);
	deleteLinkListElement(link_table, 109);
	showLinkList(link_table);
	printf("-------------\n");
	insertLinkListPos(link_table, 0, 82);
	insertLinkListPos(link_table, 8, 802);
	showLinkList(link_table);
	printf("----------------\n");
	releaseLinkList(link_table);
}

int main() {
	test01();

	return 0;
}