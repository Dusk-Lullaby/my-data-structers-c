#pragma once

// 弧结构
typedef struct arcBox {
	int head;		// 弧头
	int tail;		// 弧尾
	struct arcBox* headNext;	// 下一个弧头
	struct arcBox* tailNext;	// 下一个弧尾
	int weight;		// 权重
}ArcBox;

// 顶点结构
typedef struct {
	int number;
	char* show;
	ArcBox* firstIn;	// 第一个入度
	ArcBox* firstOut;	// 第一个出度
}ArcVertex;

// 十字链表结构
typedef struct {
	ArcVertex* nodes;
	int vertexNum;
	int edegNum;
}CrossGraph;

/*
	功能：创建十字链表
	参数：顶点的个数
	返回值：十字链表
*/
CrossGraph* createCrossGraph(int n);

/*
	功能：释放十字链表
	参数：十字链表
	返回值：无
*/
void releaseCrossGraph(CrossGraph* graph);

/*
	功能：初始化十字链表
	参数：十字链表 顶点个数 顶点数组
	返回值：无
*/
void initCrossGraph(CrossGraph* graph, int num, char* names[]);

/*
	功能：添加弧
	参数：十字链表 弧头 弧尾 权重
	返回值：无
*/
void addArcBox(CrossGraph* graph, int head, int tail, int weight);

/*
	功能：获取顶点的入度个数
	参数：十字链表 顶点位置
	返回值：入度
*/
int inDegreeVertex(CrossGraph* graph, int num);

/*
	功能：获取顶点的出度个数
	参数：十字链表 顶点位置
	返回值：出度
*/
int outDegreeVertex(CrossGraph* graph, int num);