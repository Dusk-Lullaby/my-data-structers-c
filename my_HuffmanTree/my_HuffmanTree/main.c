#include <stdio.h>
#include <stdlib.h>
#include "HuffmanTree.h"

int main() {
	int w[] = { 5, 29, 7, 8, 14, 23, 3, 11 };
	char show[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
	int n = sizeof(w) / sizeof(w[0]);
	int m = 2 * n - 1;
	HuffmanTree tree = createHuffmanTree(w, n);
	if (tree == NULL) {
		return -1;
	}

	for (int i = 1; i <= m; i++) {
		printf("%d\t%d\t%d\t%d\n", tree[i].weight, tree[i].parent, tree[i].lChild, tree[i].rChild);
	}

	HuffmanCode* code = createHuffmanCode(tree, n);
	for (int i = 0; i < n; i++) {
		printf("%c : %s\n", show[i], code[i]);
	}

	releaseHuffmanTree(tree);

	return 0;
}