#pragma once
// 从邻接矩阵中初始化边集数组

// 定义一个边集结构 边集数组
typedef struct {
	int head;		// 头
	int end;		// 尾
	int weight;		// 权重
}EdgeSet;

// 使用邻接矩阵来表示无向图，再从邻接矩阵中初始化边集数组
#include "MatrixGraph.h"

/*
	功能：初始化边集数组
	参数：邻接矩阵 边集数组
	返回值：边的个数
*/
int initEdgeSet(MatrixGraph* graph, EdgeSet* edges);

/*
	功能：排序边集数组
	参数：边集数组 顶点个数
	返回值：无
*/
void sortEdgeSet(EdgeSet* edges, int num);

/*
	功能：kruskal
	参数：邻接矩阵 边集数组 边数 最短路径数组
	返回值：最短路径
*/
int kruskalMGraph(const MatrixGraph* graph, const EdgeSet* edges, int num, EdgeSet* result);
