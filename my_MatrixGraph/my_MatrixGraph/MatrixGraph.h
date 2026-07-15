#pragma once

#define MAX_VERTEX_NUM 10		// 节点最大数量
#define INF 1E4					// 无穷大

// 顶点结构
typedef struct {
	int number;			// 序号
	const char* show;	// 存储顶点表示的数据
}MatrixVertex;

// 边结构
typedef int MatrixEdge;

// 邻接表结构
typedef struct {
	MatrixVertex vertexs[MAX_VERTEX_NUM];				// 顶点数组	
	MatrixEdge edges[MAX_VERTEX_NUM][MAX_VERTEX_NUM];	// 二维边数组
	int vertexNum;		// 顶点个数
	int edgeNum;		// 边的个数
	int directed;		// 是否有向
}MatrixGraph;

/*
	功能：初始化邻接矩阵
	参数：邻接矩阵 顶点数组 顶点的个数 是否是有向图 边的情况
	返回值：邻接矩阵
*/
void initMatrixGraph(MatrixGraph* graph, const char* name[], int n, int directed, int weight);

/*
	功能：添加边
	参数：邻接矩阵 起点 终点 权重
	返回值：无
*/
void addMatrixGraph(MatrixGraph* graph, int x, int y, int w);

/*
	功能：深度优先搜索
	参数：邻接矩阵 第几个位置开始搜索
	返回值：无
*/
void DFSMatrixGraphTravel(MatrixGraph* graph, int v);

/*
	功能：广度优先搜索
	参数：邻接矩阵 从第几个位置开始搜索
	返回值：无
*/
void BFSMatrixGraphTravel(MatrixGraph* graph, int v);