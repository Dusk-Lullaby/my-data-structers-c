#include <stdio.h>
#include <stdlib.h>
#include "Joseph.h"

void test(void) {
	Joseph_t game = { NULL, NULL };
	initJoseph(&game, 41);
	showJoseph(&game);
	startJoseph(&game, 3);
}

int main() {
	test();

	return 0;
}