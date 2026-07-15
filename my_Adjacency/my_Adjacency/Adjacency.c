#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Adjacency.h"

// 创建
AGraph* createAGraph(int n) {
	AGraph* graph = malloc(sizeof(AGraph));
	if (graph == NULL) return NULL;
	graph->visited = malloc(sizeof(int) * n);
	graph->nodes = malloc(sizeof(ArcNode) * n);
	if (graph->nodes == NULL || graph->visited == NULL)
		return NULL;
	graph->edgeNum = 0;
	graph->nodeNum = n;

	memset(graph->nodes, 0, sizeof(ArcNode) * n);
	memset(graph->visited, 0, sizeof(int) * n);

	return graph;
}

// 初始化
void initAGraph(AGraph* graph, const char* shows[], int n, int directed) {
	graph->directed = directed;
	for (int i = 0; i < n; i++) {
		graph->nodes[i].number = i;
		graph->nodes[i].show = shows[i];
		graph->nodes[i].firstEdge = NULL;
	}
}

// 创建边
static ArcEdge* createEdge(int number, int w) {
	ArcEdge* edge = malloc(sizeof(ArcEdge));
	if (edge == NULL) return NULL;
	edge->next = NULL;
	edge->number = number;
	edge->weight = w;

	return edge;
}

// 添加边
void addAGraphEdge(AGraph* graph, int x, int y, int w) {
	if (x < 0 || x >= graph->nodeNum || y < 0 || y >= graph->nodeNum)
		return;

	// 头插法
	ArcEdge* edge = createEdge(y, w);
	edge->next = graph->nodes[x].firstEdge;
	graph->nodes[x].firstEdge = edge;
	graph->edgeNum++;

	// 如果是无向图
	if (graph->directed == 0) {
		edge = createEdge(x, w);
		edge->next = graph->nodes[y].firstEdge;
		graph->nodes[y].firstEdge = edge;
	 }
}

// 访问
static void visitedNode(ArcNode* node) {
	printf("%s\t", node->show);
}

// DFS
void DFSAGraphTravel(AGraph* graph, int v) {
	graph->visited[v] = 1;
	visitedNode(&graph->nodes[v]);

	// 辅助指针p
	ArcEdge* p = graph->nodes[v].firstEdge;
	while (p) {
		if (graph->visited[p->number] == 0) {
			DFSAGraphTravel(graph, p->number);
		}
		p = p->next;
	}
}

// 重置已访问数组
static void resetVisited(AGraph* graph) {
	memset(graph->visited, 0, sizeof(int) * graph->nodeNum);
}

// BFS
void BFSAGraphTravel(AGraph* graph, int v) {
	// 重置已访问数组
	resetVisited(graph);

	// 用队列实现模拟
	int* queue = malloc(sizeof(int) * graph->nodeNum);
	if (queue == NULL) return;
	int rear = 0;
	int front = 0;
	// 入队
	rear = (rear + 1) % graph->nodeNum;
	queue[rear] = v;
	graph->visited[v] = 1;
	int cur;

	while (rear != front) {
		front = (front + 1) % graph->nodeNum;
		cur = queue[front];
		visitedNode(&graph->nodes[cur]);

		ArcEdge* p = graph->nodes[cur].firstEdge;
		while (p) {
			if (graph->visited[p->number] == 0) {
				rear = (rear + 1) % graph->nodeNum;
				queue[rear] = p->number;
				graph->visited[p->number] = 1;
			}

			p = p->next;
		}
	}

	free(queue);
}

// 释放
void releaseAGraph(AGraph* graph) {
	if (graph == NULL) return;

	free(graph->visited);
	
	ArcEdge* tmp;
	ArcEdge* p;
	for (int i = 0; i < graph->nodeNum; i++) {
		p = graph->nodes[i].firstEdge;
		while (p) {
			tmp = p->next;
			free(p);
			p = tmp;
		}
	}
	free(graph->nodes);
	free(graph);
}