#include <stdio.h>
#include <stdlib.h>
#include "Prim.h"

void setupMatrixGraph(MatrixGraph* graph, int edgeValue) {
	char* names[] = { "A", "B", "C", "D", "E", "F", "G" };
	initGraph(graph, names, sizeof(names) / sizeof(names[0]), 0, edgeValue);
	addMatrixGraph(graph, 0, 1, 12);
	addMatrixGraph(graph, 0, 5, 16);
	addMatrixGraph(graph, 0, 6, 14);
	addMatrixGraph(graph, 1, 2, 10);
	addMatrixGraph(graph, 1, 5, 7);
	addMatrixGraph(graph, 2, 3, 3);
	addMatrixGraph(graph, 2, 4, 5);
	addMatrixGraph(graph, 2, 5, 6);
	addMatrixGraph(graph, 3, 4, 4);
	addMatrixGraph(graph, 4, 5, 2);
	addMatrixGraph(graph, 4, 6, 8);
	addMatrixGraph(graph, 5, 6, 9);
}

void test01() {
	MatrixGraph* graph = malloc(sizeof(MatrixGraph));
	if (graph == NULL) return;
	setupMatrixGraph(graph, INF);

	EdgeSet* result = malloc(sizeof(EdgeSet) * (graph->nodeNum) - 1);
	if (result == NULL) return;

	int sumWeight = PrimMatrixGraph(graph, 0, result);
	printf("Prim weight = %d\n", sumWeight);
	for (int i = 0; i < graph->nodeNum - 1; i++) {
		printf("edge %d: [%s] --- [%d] --- [%s]\n", i + 1,
			graph->vex[result[i].begin].show, result[i].weight, graph->vex[result[i].end].show);
	}

	free(result);
	free(graph);
}

int main() {
	test01();
}