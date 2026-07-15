#pragma once

typedef int Element;

//节点的申明
typedef struct node {
	Element value;
	struct node* next;
}node_t;

//表头的申明
typedef struct {
	node_t head;
	int count;
}LinkList_t;

/*
	功能： 链表的创建
	参数： 无
	返回值： 创建之后的链表
*/
LinkList_t* createLinkList();

/*
	功能： 链表的释放
	参数： 无
	返回值： 无
*/
void releaseLinkList(LinkList_t* link_table);

/*
	功能： 头插
	参数： 需要插入的链表 需要插入的元素
	返回值： 0成功 -1失败
*/
int insertLinkListHead(LinkList_t* link_table, Element value);

/*
	功能： 任意位置插入元素
	参数： 需要插入的链表 需要插入的位置索引 需要插入元素
	返回值： 成功0 失败-1
*/
int insertLinkListPos(LinkList_t* link_table, int pos, Element value);

/*
	功能： 打印链表信息
	参数： 需要打印的链表
	返回值： 无
*/
void showLinkList(const LinkList_t* link_table);

/*
	功能： 删去链表中的元素
	参数： 需要删去元素的链表 删去的元素
	返回值： 0成功 -1失败
*/
int deleteLinkListElement(LinkList_t* link_table, Element value);

