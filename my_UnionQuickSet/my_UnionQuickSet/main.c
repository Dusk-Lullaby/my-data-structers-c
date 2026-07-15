#include <stdio.h>
#include <stdlib.h>
#include "quickFind.h"
#include "quickUnion.h"


void test01() {
	int n = 9;
	Element_t data[9];
	for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
		data[i] = i;
	}
	QuickFindSet* setQF = createQuickFindSet(n);
	initQuickFindSet(setQF, data, n);

	unionQuickFindSet(setQF, 3, 4);
	unionQuickFindSet(setQF, 8, 0);
	unionQuickFindSet(setQF, 2, 3);
	unionQuickFindSet(setQF, 5, 6);
	if (findQuickFindSet(setQF, 0, 2)) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}
	if (findQuickFindSet(setQF, 2, 4)) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}

	unionQuickFindSet(setQF, 5, 1);
	unionQuickFindSet(setQF, 7, 3);
	unionQuickFindSet(setQF, 1, 6);
	unionQuickFindSet(setQF, 4, 8);
	if (findQuickFindSet(setQF, 0, 2)) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}
	if (findQuickFindSet(setQF, 2, 4)) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}

	releaseQuickFindSet(setQF);
}

void test02() {
	int n = 9;
	Element_t data[9];
	for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
		data[i] = i;
	}
	QuickUnionSet* setQU = createQuickUnionSet(n);
	initQuickUnionSet(setQU, data, n);

	unionQuickUnionSet(setQU, 8, 0);
	unionQuickUnionSet(setQU, 2, 3);
	unionQuickUnionSet(setQU, 3, 4);
	unionQuickUnionSet(setQU, 5, 6);
	if (findQuickUnionSet(setQU, 0, 2)) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}
	if (findQuickUnionSet(setQU, 2, 4)) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}

	unionQuickUnionSet(setQU, 5, 1);
	unionQuickUnionSet(setQU, 7, 3);
	unionQuickUnionSet(setQU, 1, 6);
	unionQuickUnionSet(setQU, 4, 8);
	if (findQuickUnionSet(setQU, 0, 2)) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}
	if (findQuickUnionSet(setQU, 2, 4)) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}

	releaseQuickUnionSet(setQU);
}


int main() {
	test01();
	test02();

	return 0;
}