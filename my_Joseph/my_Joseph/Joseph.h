#pragma once

//节点
typedef struct node {
	int number;
	struct node* next;
}node_t;

//约瑟夫环
typedef struct {
	node_t* head;
	node_t* tail;
}Joseph_t;

/*初始化*/
void initJoseph(Joseph_t* game, int count);

/*遍历打印*/
void showJoseph(const Joseph_t* game);

/*开始约瑟夫环游戏*/
void startJoseph(Joseph_t* game, int kill);