#pragma once

typedef int Element_t;

//DNode为节点结构
//DLinkHeader为头节点结构
typedef struct d_node {
	int val;
	struct d_node* next;
	struct d_node* prev;
}DNode_t, DLinkHeader_t;

/*
	功能： 初始化双向循环链表
	参数： 无
	返回值： 无
		双向循环链表的头建议是用户自己维护，表头放在栈上，放在全局变量
*/
void initDLink(DLinkHeader_t* header);

/*
	功能： 头插
	参数： 需要插入的链表 插入的元素
	返回值： 无
*/
void insertDLinkHeader(DLinkHeader_t* header, Element_t val);

/*
	功能： 尾插
	参数： 需要插入元素的链表 插入的元素
	返回值： 无
*/
void insertDLinkRear(DLinkHeader_t* header, Element_t val);

/*
	功能： 遍历打印
	参数： 需要操作的链表
	返回值： 无
*/
void showDLink(const DLinkHeader_t* header);

/*
	功能： 删除单个元素
	参数： 需要删除的链表 需要删除的元素
	返回值： 无
*/
void deleteDLinkElement(DLinkHeader_t* header, Element_t val);

/*
	功能： 删除全部元素
	参数： 需要删除的链表
	返回值： 无
*/
void deleteALLDLink(DLinkHeader_t* header);
