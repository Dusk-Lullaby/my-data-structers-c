#pragma once

// 边的结构
typedef struct arcEdge{
	int weight;		// 权重
	int number;		// 边的终点
	struct arcEdge* next;	// 下一条边
}ArcEdge;

// 顶点的结构
typedef struct {
	int number;			
	const char* show;		// 顶点的显示
	ArcEdge* firstEdge;		// 出度
}ArcNode;

// 邻接链表
typedef struct {
	ArcNode* nodes;		// 顶点数组
	int* visited;		// 已访问数组
	int nodeNum;		// 顶点个数
	int edgeNum;		// 边的个数
	int directed;		// 是否有向
}AGraph;


/*
	功能：创建邻接链表
	参数：顶点个数
	返回值：邻接链表
*/
AGraph* createAGraph(int n);

/*
	功能：初始化邻接链表
	参数：邻接表 顶点数组 数量 是否有向
	返回值：无
*/
void initAGraph(AGraph* graph, const char* shows[], int n, int directed);

/*
	功能：添加边
	参数：邻接表 起点 终点 权重
	返回值：无
*/
void addAGraphEdge(AGraph* graph, int x, int y, int w);

/*
	功能：深度优先搜索
	参数：邻接链表 从第几个顶点开始
	返回值：无
*/
void DFSAGraphTravel(AGraph* graph, int v);

/*
	功能：广度优先搜索
	参数：邻接链表 从第几个顶点开始
	返回值：无
*/
void BFSAGraphTravel(AGraph* graph, int v);

/*
	功能：释放邻接链表
	参数：链接链表
	返回值：无
*/
void releaseAGraph(AGraph* graph);