#include <stdio.h>
#include <stdlib.h>
#include "MatrixGraph.h"

/*
	1. 初始化有向图， 没有路径的节点的节点dist更新为INF
	2. 将激活start编号到其他各个节点的路径进行更新，再更新path
	3. 循环，将所有节点都激活
		每激活一个节点，从原点开始到这个激活点，是目前认为的最优解，再最优解的情况下，增加相关的边，会不会影响其他未激活点的距离
		一旦发现更小值，更新path
*/
void DijkstraMatrixGraph(const MatrixGraph* graph, int start, int dist[], int path[]) {
	// 节点访问记录
	int* mark = malloc(sizeof(int) * graph->nodeNum);
	if (mark == NULL || dist == NULL) return;
	
	// 激活start后，更新dist表，path中的start编号设置为-1，作为路径打印时的结束标准
	for (int i = 0; i < graph->nodeNum; i++) {
		dist[i] = graph->edges[start][i];
		mark[i] = 0;
		if (dist[i] < INF) {
			path[i] = start;
		}
		else {
			path[i] = INF;
		}
	}
	mark[start] = 1;
	path[start] = -1;

	// 从dist里查找最小值
	// 除了start，还需要激活的点
	for (int i = 0; i < graph->nodeNum - 1; i++) {
		int min = INF;
		int tmpIndex = 0;
		// 从未激活节点中，找到一个源点到其的最短距离
		for (int j = 0; j < graph->nodeNum; j++) {
			if (mark[j] == 0 && dist[j] < min) {
				min = dist[j];
				tmpIndex = j;
			}
		}

		mark[tmpIndex] = 1;

		// 以刚刚激活的节点，更新源点到其他顶点的距离
		for (int j = 0; j < graph->nodeNum; j++) {
			if (mark[j] == 0 && dist[j] > graph->edges[tmpIndex][j] + dist[tmpIndex]) {
				dist[j] = graph->edges[tmpIndex][j] + dist[tmpIndex];
				path[j] = tmpIndex;
			}
		}
	}

	free(mark);
}

void showShortPath(const int path[], int num, int pos) {
	int* stack = malloc(sizeof(int) * num);
	if (stack == NULL) return;
	int top = -1;

	while (path[pos] != -1) {
		stack[++top] = pos;
		pos = path[pos];
	}

	stack[++top] = pos;

	while (top != -1) {
		printf("%d\t", stack[top--]);
	}
	printf("\n");
}