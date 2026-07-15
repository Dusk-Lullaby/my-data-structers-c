#include <stdio.h>
#include <stdlib.h>
#include "Prim.h"

int PrimMatrixGraph(const MatrixGraph* graph, int startV, EdgeSet* result) {
	// 权值cost
	int* cost = malloc(sizeof(int) * graph->nodeNum);
	// 激活点
	int* mark = malloc(sizeof(int) * graph->nodeNum);
	// 从哪个点开始访问
	int* visited = malloc(sizeof(int) * graph->nodeNum);
	if (cost == NULL || mark == NULL || visited == NULL) return 0;

	// 1. 更新第一个节点激活的状态
	for (int i = 0; i < graph->nodeNum; i++) {
		mark[i] = 0;
		cost[i] = graph->edges[startV][i];
		// 更新visit信息，说明从哪个节点开始访问i
		if (graph->edges[startV][i] < INF) {
			visited[i] = startV;
		}
	}
	mark[startV] = 1;

	int sum = 0;
	// 2. 动态激活节点，查找最小值，添加到result边集数组
	// 查找 n - 1 个最小生成树的边
	for (int i = 0; i < graph->nodeNum - 1; i++) {
		// 寻找最小值
		int min = INF;
		int k = 0;
		// 从权值数组里找到未激活顶点的最小值
		for (int j = 0; j < graph->nodeNum; j++) {
			if (mark[j] == 0 && cost[j] < min) {
				min = cost[j];
				k = j;
			}
		}

		// 激活最小值的节点
		mark[k] = 1;
		// 确定从哪个节点来
		result[i].begin = visited[k];
		result[i].end = k;
		result[i].weight = min;
		sum += min;

		// 激活的k号节点，它的边比之前的cost小
		for (int j = 0; j < graph->nodeNum; j++) {
			if (mark[j] == 0 && cost[j] > graph->edges[k][j]) {
				cost[j] = graph->edges[k][j];
				visited[j] = k;
			}
		}
	}

	free(cost);
	free(visited);
	free(mark);

	return sum;
}