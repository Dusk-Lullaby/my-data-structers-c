#include <stdio.h>
#include <stdlib.h>
#include "crossLinkGraph.h"

// 创建
CrossGraph* createCrossGraph(int n) {
	CrossGraph* graph = malloc(sizeof(CrossGraph));
	if (graph == NULL) return NULL;
	graph->nodes = malloc(sizeof(ArcVertex) * n);
	if (graph->nodes == NULL) {
		free(graph);
		return NULL;
	}
	graph->vertexNum = n;
	graph->edegNum = 0;

	return graph;
}

// 初始化
void initCrossGraph(CrossGraph* graph, int num, char* names[]) {
	for (int i = 0; i < num; i++) {
		graph->nodes[i].show = names[i];
		graph->nodes[i].number = i;
		graph->nodes[i].firstIn = NULL;
		graph->nodes[i].firstOut = NULL;
	}
}

// 添加
void addArcBox(CrossGraph* graph, int head, int tail, int w) {
	ArcBox* box = malloc(sizeof(ArcBox));
	if (box == NULL) return;
	box->head = head;
	box->tail = tail;
	box->weight = w;

	// 头插
	box->headNext = graph->nodes[head].firstIn;
	graph->nodes[head].firstIn = box;
	box->tailNext = graph->nodes[tail].firstOut;
	graph->nodes[tail].firstOut = box;

	graph->edegNum++;
}

// 入度
int inDegreeVertex(CrossGraph* graph, int num) {
	int count = 0;
	ArcBox* box = graph->nodes[num].firstIn;
	while (box) {
		box = box->headNext;
		count++;
	}

	return count;
}

// 出度
int outDegreeVertex(CrossGraph* graph, int num) {
	int count = 0;
	ArcBox* box = graph->nodes[num].firstOut;
	while (box) {
		box = box->tailNext;
		count++;
	}

	return count;
}

// 释放
void releaseCrossGraph(CrossGraph* graph) {
	if (graph == NULL) return;
	for (int i = 0; i < graph->vertexNum; i++) {
		ArcBox* p = graph->nodes[i].firstOut;
		while (p) {
			ArcBox* tmp = p->tailNext;
			free(p);
			p = tmp;
		}
	}

	free(graph->nodes);
	free(graph);
}