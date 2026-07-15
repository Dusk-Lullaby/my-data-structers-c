#pragma once
#include "MatrixGraph.h"

void DijkstraMatrixGraph(const MatrixGraph* graph, int start, int dist[], int path[]);

void showShortPath(const int path[], int num, int pos);