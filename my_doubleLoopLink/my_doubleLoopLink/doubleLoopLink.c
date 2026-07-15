#include <stdio.h>
#include <stdlib.h>
#include "doubleLoopLink.h"

/*初始化*/
void initDLink(DLinkHeader_t* header) {
	header->next = header;
	header->prev = header;
}

/*
	功能： 插入
	参数： 前驱节点 新节点 后继节点
	返回值： 无
*/
static void addDNode(DNode_t* prev, DNode_t* new_node, DNode_t* next) {
	next->prev = new_node;
	new_node->next = next;
	new_node->prev = prev;
	prev->next = new_node;
}

/*头插*/
void insertDLinkHeader(DLinkHeader_t* header, Element_t val) {
	//创建节点
	DNode_t* new_node = malloc(sizeof(DNode_t));
	if (new_node == NULL) return;
	new_node->val = val;
	//插入
	addDNode(header, new_node, header->next);
}

/*尾插*/
void insertDLinkRear(DLinkHeader_t* header, Element_t val) {
	//创建节点
	DNode_t* new_node = malloc(sizeof(DNode_t));
	if (new_node == NULL) return;
	new_node->val = val;
	//插入
	addDNode(header->prev, new_node, header);
}

/*遍历打印*/
void showDLink(const DLinkHeader_t* header) {
	//创建辅助指针p
	DNode_t* p = header->next;
	int cnt = 0;
	while (p != header) {
		printf("%d\t", p->val);
		p = p->next;
		cnt++;
	}
	printf("\nthis link have %d node\n", cnt);
}

/*
	功能： 删除
	参数： 前驱节点 后继节点
	返回值： 无
*/
static deleteDNode(DNode_t* prev, DNode_t* next) {
	prev->next = next;
	next->prev = prev;
}

/*删除单个元素*/
void deleteDLinkElement(DLinkHeader_t* header, Element_t val) {
	//辅助指针p
	DNode_t* p = header->next;
	//查找
	while (p != header && p->val != val) {
		p = p->next;
	}
	//查找失败
	if (p == header) {
		printf("not found value\n");
		return;
	}
	//删除
	deleteDNode(p->prev, p->next);
	free(p);
}

/*删除全部元素*/
void deleteALLDLink(DLinkHeader_t* header) {
	//辅助指针
	DNode_t* p = header->next;
	while (p != header) {
		deleteDNode(header, p->next);
		free(p);
		p = header->next;
	}
}