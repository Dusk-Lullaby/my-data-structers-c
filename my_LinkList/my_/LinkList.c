#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"



LinkList_t* createLinkList() {
	//创建表头
	LinkList_t* link_table = malloc(sizeof(LinkList_t));
	//判断是否创建成功
	if (link_table == NULL) {
		printf("link_table malloc failed\n");
		return NULL;
	}

	//初始化
	link_table->count = 0;
	link_table->head.next = NULL;
	link_table->head.value = 0;

	return link_table;
}

int insertLinkListHead(LinkList_t* link_table, Element value) {
	//判断链表是否存在
	if (link_table == NULL) return -1;
	//p就是添加元素的前驱
	node_t* p = &link_table->head;
	//创建新节点
	node_t* new_node = malloc(sizeof(node_t));
	if (new_node == NULL) return -1;
	//头插
	new_node->value = value;
	new_node->next = p->next;
	p->next = new_node;
	link_table->count++;

	return 0;
}

void showLinkList(const LinkList_t* link_table) {
	printf("LinkList have %d node\n", link_table->count);
	//创建辅助指针
	node_t* p = link_table->head.next;
	while (p) {
		printf("%d\t", p->value);
		//指针后移
		p = p->next;
	}
	printf("\n");
}

int deleteLinkListElement(LinkList_t* link_table, Element value) {
	//辅助指针指向value的前驱节点
	node_t* p = &link_table->head;
	//寻找value
	while (p->next && p->next->value != value) {
		p = p->next;
	}
	//如果没找到value
	if (p->next == NULL) {
		printf("error\n");
		return -1;
	}
	//删除
	node_t* tmp = p->next;
	p->next = tmp->next;
	free(tmp);

	link_table->count--;
	
	return 0;
}

int insertLinkListPos(LinkList_t* link_table, int pos, Element value) {
	//索引合法性
	if (pos < 0 || pos > link_table->count) {
		printf("pos is invalid\n");
		return -1;
	}
	int index = 0;
	node_t* p = &link_table->head;
	//当index == pos - 1时，p为前驱节点
	while (p && index <= pos - 1) {
		p = p->next;
		index++;
	}
	if (p == NULL) return -1;
	//创建新节点
	node_t* new_node = malloc(sizeof(node_t));
	if (new_node == NULL) {
		printf("new_node malloc failed\n");
		return -1;
	}
	//插入
	new_node->value = value;
	new_node->next = p->next;
	p->next = new_node;
	link_table->count++;

	return 0;
}

void releaseLinkList(LinkList_t* link_table) {
	if (link_table) {
		//创建指针p指向前驱节点
		node_t* p = &link_table->head;
		//临时指针
		node_t* tmp;
		while (p->next) {
			tmp = p->next;
			p->next = tmp->next;
			free(tmp);
			link_table->count--;
		}
		printf("LinkTable have %d node\n", link_table->count);
		//释放表头
		free(link_table);
	}
}
