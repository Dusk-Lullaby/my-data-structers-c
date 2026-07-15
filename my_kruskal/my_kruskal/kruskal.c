#include <stdio.h>
#include <stdlib.h>
#include "kruskal.h"

// 初始化
int initEdgeSet(MatrixGraph* graph, EdgeSet* edges) {
	int sum = 0;
	for (int i = 0; i < graph->nodeNum; i++) {
		// 由于是无向图因此只需要考虑对角线之上的边
		for (int j = i; j < graph->nodeNum; j++) {
			// 是边
			if (graph->edges[i][j] > 0 && graph->edges[i][j] < INF) {
				edges[sum].head = i;
				edges[sum].end = j;
				edges[sum].weight = graph->edges[i][j];
				sum++;
			}
		}
	}

	return sum;
}

// 排序
void sortEdgeSet(EdgeSet* edges, int num) {
	for (int i = 0; i < num; i++) {
		for (int j = i + 1; j < num; j++) {
			if (edges[j].weight < edges[i].weight) {
				EdgeSet tmp = edges[i];
				edges[i] = edges[j];
				edges[j] = tmp;
			}
		}
	}
}

// 路径压缩寻找根节点
static int findRoot(int* uSet, int a) {
	// 父亲节点是自己本身时，则为根节点
	if (uSet[a] != a) {
		uSet[a] = findRoot(uSet, uSet[a]);
	}


	return uSet[a];
}

// kruskal
int kruskalMGraph(const MatrixGraph* graph, const EdgeSet* edges, int num, EdgeSet* result) {
	int* uSet = malloc(sizeof(int) * num);
	if (uSet == NULL) return 0;
	for (int i = 0; i < graph->nodeNum; i++) {
		uSet[i] = i;
	}

	int count = 0;
	int sum = 0;
	for (int i = 0; i < num; i++) {
		int a = findRoot(uSet, edges[i].head);
		int b = findRoot(uSet, edges[i].end);
		if (a == b) continue;
		uSet[a] = b;
		result[count].head = edges[i].head;
		result[count].end = edges[i].end;
		result[count].weight = edges[i].weight;
		sum += edges[i].weight;
		count++;
		if (count == graph->nodeNum - 1) break;
	}

	free(uSet);
	return sum;
}