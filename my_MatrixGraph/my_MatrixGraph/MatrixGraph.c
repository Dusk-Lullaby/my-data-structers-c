#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MatrixGraph.h"

// 初始化
void initMatrixGraph(MatrixGraph* graph, const char* name[], int n, int directed, int weight) {
	graph->directed = directed;
	graph->vertexNum = n;
	graph->edgeNum = 0;
	memset(graph->edges, 0, sizeof(MatrixEdge) * n);
	memset(graph->vertexs, 0, sizeof(MatrixEdge) * n);

	for (int i = 0; i < n; i++) {
		// 对顶点进行初始化
		graph->vertexs[i].number = i;
		graph->vertexs[i].show = name[i];

		// 对边进行初始化
		for (int j = 0; j < n; j++) {
			graph->edges[i][j] = weight;
		}
	}
}

// 判断是否是边
static int isEdge(int weight) {
	if (weight > 0 && weight < INF)
		return 1;
	return 0;
}

// 增加
void addMatrixGraph(MatrixGraph* graph, int x, int y, int w) {
	if (x < 0 || x >= graph->vertexNum || y < 0 || y >= graph->vertexNum)
		return;
	if (!isEdge(w))
		return;

	graph->edges[x][y] = w;
	// 无向图
	if (graph->directed == 0) {
		graph->edges[y][x] = w;
	}
	graph->edgeNum++;
}

// 访问
void visitedMatrixGraph(MatrixVertex* vertex) {
	printf("%s\t", vertex->show);
}

// DFS已访问数组
static int DFSMatrixGraphVisited[MAX_VERTEX_NUM];

// DFS
void DFSMatrixGraphTravel(MatrixGraph* graph, int v) {
	visitedMatrixGraph(&graph->vertexs[v]);
	DFSMatrixGraphVisited[v] = 1;
	// 从v节点开始，找到一个边节点，再通过这个节点进行DFS
	for (int i = 0; i < graph->vertexNum; i++) {
		// 有边并且还没有访问
		if (DFSMatrixGraphVisited[i] == 0 && isEdge(graph->edges[v][i])) {
			DFSMatrixGraphTravel(graph, i);
		}
	}
}

// BFS已访问数组
static int BFSMatrixGraphVisited[MAX_VERTEX_NUM];

//BFS
void BFSMatrixGraphTravel(MatrixGraph* graph, int v) {
	// 临时队列
	int queue[MAX_VERTEX_NUM];
	int rear = 0;
	int front = 0;
	// 入队
	rear = (rear + 1) % MAX_VERTEX_NUM;
	queue[rear] = v;
	BFSMatrixGraphVisited[v] = 1;

	int cur;
	while (front != rear) {
		front = (front + 1) % MAX_VERTEX_NUM;
		cur = queue[front];
		visitedMatrixGraph(&graph->vertexs[cur]);
		for (int i = 0; i < graph->vertexNum; i++) {
			if (isEdge(graph->edges[cur][i]) && BFSMatrixGraphVisited[i] == 0) {
				rear = (rear + 1) % MAX_VERTEX_NUM;
				queue[rear] = i;
				BFSMatrixGraphVisited[i] = 1;
			}
		}
	}
}