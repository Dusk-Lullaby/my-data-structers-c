#pragma once
#include "MatrixGraph.h"
// 定义一个边集结构 边集数组
typedef struct {
	int begin;		// 起点
	int end;		// 终点
	int weight;		// 权重
}EdgeSet;

int PrimMatrixGraph(const MatrixGraph* graph, int startV, EdgeSet* result);