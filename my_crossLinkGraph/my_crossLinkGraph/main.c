#include <stdio.h>
#include <stdlib.h>
#include "crossLinkGraph.h"

void setupGraph(CrossGraph* graph) {
	char* nodeNames[] = { "V0", "V1", "V2", "V3" };
	initCrossGraph(graph, sizeof(nodeNames) / sizeof(nodeNames[0]), nodeNames);

	// (β -> ͷ)
	addArcBox(graph, 3, 0, 1);
	addArcBox(graph, 0, 1, 1);
	addArcBox(graph, 0, 2, 1);
	addArcBox(graph, 2, 1, 1);
	addArcBox(graph, 1, 2, 1);
}

int main() {
	int n = 4;
	CrossGraph* graph = createCrossGraph(n);
	if (graph == NULL) return -1;
	setupGraph(graph);

	printf("V0 inDegree: %d\n", inDegreeVertex(graph, 0));
	printf("V0 outDegree: %d\n", outDegreeVertex(graph, 0));
	printf("graph edge number : %d\n", graph->edegNum);

	releaseCrossGraph(graph);

	return 0;
}