#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "topological.h"

static void visitNode(ArcNode* node) {
	if (node == NULL) return;
	printf("%s\t", node->show);
}

int TopologicalSort(AGraph* graph) {
	// 申请入度数组
	int* inDegree = malloc(sizeof(int) * graph->nodeNum);
	if (inDegree == NULL) return -1;
	memset(inDegree, 0, sizeof(int) * graph->nodeNum);

	// 将入度加入数组
	for (int i = 0; i < graph->nodeNum; i++) {
		if (graph->nodes[i].firstEdge) {
			ArcEdge* edge = graph->nodes[i].firstEdge;
			while (edge) {
				inDegree[edge->number]++;
				edge = edge->next;
			}
		}
	}

	// 申请栈
	int top = -1;
	int* stack = malloc(sizeof(int) * graph->nodeNum);
	if (stack == NULL) {
		free(inDegree);
		return -1;
	}
	// 将入度为0的值都加入栈中
	for (int i = 0; i < graph->nodeNum; i++) {
		if (inDegree[i] == 0) {
			stack[++top] = i;
		}
	}

	int count = 0;
	while (top != -1) {
		int index = stack[top--];
		count++;
		visitNode(&graph->nodes[index]);
		ArcEdge* edge = graph->nodes[index].firstEdge;
		while (edge) {
			inDegree[edge->number]--;
			if (inDegree[edge->number] == 0) {
				stack[++top] = edge->number;
			}
			edge = edge->next;
		}
	}

	free(stack);
	free(inDegree);

	if (count == graph->nodeNum) {
		return 1;
	}
	else {
		return 0;
	}
}