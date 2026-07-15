#include <stdio.h>
#include <stdlib.h>
#include "Joseph.h"

void initJoseph(Joseph_t* game, int number) {
	//创建节点
	for (int i = 1; i <= number; i++) {
		node_t* node = malloc(sizeof(node_t));
		if (node == NULL) return;
		node->number = i;
		//第一个节点
		if (game->head == NULL) {
			game->head = node;
			game->tail = node;
		}
		//添加节点
		else {
			game->tail->next = node;
			game->tail = node;
		}
		game->tail->next = game->head;
	}
}

void showJoseph(const Joseph_t* game) {
	node_t* p = game->head;
	do {
		printf("%d ", p->number);
		p = p->next;
	} while (p != game->head);
	printf("\n");
}

void startJoseph(Joseph_t* game, int kill) {
	//指向需要杀的人
	node_t* cur = game->head;
	//辅助指针，指向前驱
	node_t* pre = game->tail;
	//遍历， 直到只剩下一个人
	while (cur->next != cur) {
		//报数
		for (int i = 1; i < kill; i++) {
			pre = cur;
			cur = cur->next;
		}
		//杀人
		pre->next = cur->next;
		free(cur);
		//cur指针后移
		cur = pre->next;
	}
	printf("win is %d\n", cur->number);
}