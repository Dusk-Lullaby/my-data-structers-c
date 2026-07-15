#include <stdio.h>
#include <stdlib.h>
#include "doubleLoopLink.h"

DLinkHeader_t header;

void testDoubleLoopLink() {
	initDLink(&header);
	for (int i = 0; i < 5; i++) {
		insertDLinkHeader(&header, 100 + i);
		insertDLinkRear(&header, 50 + i);
	}
	showDLink(&header);
	printf("---------------\n");
	deleteDLinkElement(&header, 50);
	deleteDLinkElement(&header, 104);
	showDLink(&header);
	printf("-----------------\n");
	deleteALLDLink(&header);
	showDLink(&header);
}

int main() {
	testDoubleLoopLink();

	return 0;
}