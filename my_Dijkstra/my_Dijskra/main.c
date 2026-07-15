#include <stdio.h>
#include <stdlib.h>
#include "Dijkstra.h"

void setupMatrixGraph(MatrixGraph* graph, int edgeValue) {
	char* names[] = { "0", "1", "2", "3", "4", "5", "6" };
	initGraph(graph, names, sizeof(names) / sizeof(names[0]), 1, edgeValue);
	addMatrixGraph(graph, 0, 1, 4);
	addMatrixGraph(graph, 0, 2, 6);
	addMatrixGraph(graph, 0, 3, 6);
	addMatrixGraph(graph, 1, 4, 7);
	addMatrixGraph(graph, 1, 2, 1);
	addMatrixGraph(graph, 2, 4, 6);
	addMatrixGraph(graph, 2, 5, 4);
	addMatrixGraph(graph, 3, 2, 2);
	addMatrixGraph(graph, 3, 5, 5);
	addMatrixGraph(graph, 4, 6, 6);
	addMatrixGraph(graph, 5, 4, 1);
	addMatrixGraph(graph, 5, 6, 8);
}

int main() {
	MatrixGraph* graph = malloc(sizeof(MatrixGraph));
	setupMatrixGraph(graph, INF);
	if (graph == NULL) return;
	int* dist = malloc(sizeof(int) * graph->nodeNum);			// 存储 源点x到其他节点的最短路径
	int* path = malloc(sizeof(int) * graph->nodeNum);			// 存储源点到每个最短路径的前一个节点信息
	if (dist == NULL || path == NULL) {
		printf("malloc failed\n");
		return;
	}

	setupMatrixGraph(graph, INF);
	DijkstraMatrixGraph(graph, 0, dist, path);
	printf("0 node to 5 node\n");
	showShortPath(path, 10, 5);
	printf("0 node to 6 node\n");
	showShortPath(path, 10, 6);
}