#include <stdio.h>
#include <stdlib.h>
#include "MatrixGraph.h"

void setupMatrixGraph(MatrixGraph* graph) {
	const char* nodeNames[] = { "V1", "V2", "V3", "V4",
							"V5", "V6", "V7", "V8" };
	initMatrixGraph(graph, nodeNames, sizeof(nodeNames) / sizeof(nodeNames[0]), 0, 0);

	addMatrixGraph(graph, 0, 1, 1);
	addMatrixGraph(graph, 0, 2, 1);
	addMatrixGraph(graph, 1, 3, 1);
	addMatrixGraph(graph, 1, 4, 1);
	addMatrixGraph(graph, 3, 7, 1);
	addMatrixGraph(graph, 4, 7, 1);
	addMatrixGraph(graph, 2, 5, 1);
	addMatrixGraph(graph, 2, 6, 1);
	addMatrixGraph(graph, 5, 6, 1);
}

int main() {
	MatrixGraph graph;
	setupMatrixGraph(&graph);

	printf("deep:\n");
	DFSMatrixGraphTravel(&graph, 0);

	printf("\nwide:\n");
	BFSMatrixGraphTravel(&graph, 0);

	printf("\nedges: %d\n", graph.edgeNum);

	return 0;
}