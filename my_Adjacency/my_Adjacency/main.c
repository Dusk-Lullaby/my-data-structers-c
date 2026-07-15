#include <stdio.h>
#include <stdlib.h>
#include "Adjacency.h"

void setupGraph(AGraph* graph) {
	const char* nodeNames[] = { "A", "B", "C", "D", "E" };
	initAGraph(graph, nodeNames, sizeof(nodeNames) / sizeof(nodeNames[0]), 1);
	addAGraphEdge(graph, 0, 3, 1);
	addAGraphEdge(graph, 0, 2, 1);
	addAGraphEdge(graph, 0, 1, 1);
	addAGraphEdge(graph, 2, 3, 1);
	addAGraphEdge(graph, 3, 4, 1);
}

int main() {
	int n = 5;
	AGraph* graph = createAGraph(n);
	setupGraph(graph);
	DFSAGraphTravel(graph, 0);
	printf("\n");
	BFSAGraphTravel(graph, 0);

	releaseAGraph(graph);

	return 0;
}