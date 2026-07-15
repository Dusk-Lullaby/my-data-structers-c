#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "keyPath.h"

static void topological(AGraph* graph, int* ETV, int* LTV) {
	// 申请出度数组
	int* inDegree = malloc(sizeof(int) * graph->nodeNum);
	if (inDegree == NULL) return;
	memset(inDegree, 0, sizeof(int) * graph->nodeNum);
	// 将各个顶点的数组添加到数组中
	for (int i = 0; i < graph->nodeNum; i++) {
		// 存在边
		if (graph->nodes[i].firstEdge) {
			ArcEdge* edge = graph->nodes[i].firstEdge;
			// 遍历该节点的所有边
			while (edge) {
				inDegree[edge->number]++;
				edge = edge->next;
			}
		}
	}

	// 申请栈
	int* stack = malloc(sizeof(int) * graph->nodeNum);
	int top = -1;
	// 申请一个数组，用来存放拓扑排序的结果
	int* topo = malloc(sizeof(int) * graph->nodeNum);
	int index = -1;
	if (stack == NULL || topo == NULL) {
		free(inDegree);
		return;
	}

	// 寻找一个源点，将其放入栈
	for (int i = 0; i < graph->nodeNum; i++) {
		if (inDegree[i] == 0) {
			stack[++top] = i;
			break;
		}
	}

	// 不断弹栈，来进行排序
	int tmp;
	while (top != -1) {
		tmp = stack[top--];
		// 将弹出的顶点放入结果数组中
		topo[++index] = tmp;
		ArcEdge* edge = graph->nodes[tmp].firstEdge;
		while (edge) {
			if (--inDegree[edge->number] == 0) {
				stack[++top] = edge->number;
			}
			// 如果边起点的最早发生时间加上边的权值 大于 终点的最早发生时间
			// 那么更新终点的发生时间，取最大值
			// （终点的最大入度边是终点的最早发生时间）
			if (ETV[tmp] + edge->weight > ETV[edge->number]) {
				ETV[edge->number] = ETV[tmp] + edge->weight;
			}
			edge = edge->next;
		}
	}

	free(inDegree);
	free(stack);
	// 如果结果数组中元素的个数小于节点数，则代表有环
	if (++index < graph->nodeNum) {
		printf("have loop\n");
		return;
	}

	for (int i = 0; i < index; i++) {
		// 初始化，将所有节点的最晚发生时间设置为汇点的最早发生时间
		LTV[i] = ETV[tmp];
	}
	// 更新LTV
	for (int i = 0; i < graph->nodeNum; i++) {
		// 从终点向起点逆向推导
		ArcEdge* edge = graph->nodes[--index].firstEdge;
		while (edge) {
			// 最晚发生时间取最小值
			if (LTV[edge->number] - edge->weight < LTV[index]) {
				LTV[index] = LTV[edge->number] - edge->weight;
			}
			edge = edge->next;
		}
	}
}

static showPath(int* table, const char* names, int n) {
	printf("%s:\n", names);
	for (int i = 0; i < n; i++) {
		printf("%d\t", table[i]);
	}
	printf("\n");
}

void keyPath(AGraph* graph) {
	// 申请ETV和LTV
	int* ETV = malloc(sizeof(int) * graph->nodeNum);
	int* LTV = malloc(sizeof(int) * graph->nodeNum);
	if (ETV == NULL || LTV == NULL) return;
	memset(ETV, 0, sizeof(int) * graph->nodeNum);
	memset(LTV, 0, sizeof(int) * graph->nodeNum);
	// 通过拓扑排序来构建ETV和LTV
	topological(graph, ETV, LTV);
	showPath(ETV, "ETV", graph->nodeNum);
	showPath(LTV, "LTV", graph->nodeNum);

	// 计算ETE和LTE
	// ETE和起点的ETV相等
	// LTE等于终点的LTV减去边的权值
	for (int i = 0; i < graph->nodeNum; i++) {
		ArcEdge* edge = graph->nodes[i].firstEdge;
		while (edge) {
			if (ETV[i] == LTV[edge->number] - edge->weight) {
				printf("[%s] --- <%d> --- [%s]\n", graph->nodes[i].show, edge->weight, graph->nodes[edge->number].show);
			}
			edge = edge->next;
		}
	}

	free(ETV);
	free(LTV);
}