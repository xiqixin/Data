#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//数据类型
typedef int DLDataType;
 
//结点类型
typedef struct DListNode
{
	DLDataType val;
	struct  DListNode* next;
	struct  DListNode* prev;
}DLListNode;

//双向链表类型
typedef struct
{
	DListNode* head;
}DList;


//生成结点
DListNode* BuyNode(DLDataType val)
{
	DListNode* node = (DListNode*)malloc(sizeof(DLDataType));
	assert(node);

	node->val = val;
	node->prev = node->next = NULL;

	return node;

}
//初始化
void DListInit(DList* dlist)
{
	DListNode* head=BuyNode(0);
	//头节点中的val一般没有实际意义
	head->next = head;
	head->prev = head;

	dlist->head = head;
}

//清空
void DListclear(DList* dlist)
{
	DListNode *cur, *next;

	for (cur = dlist->head->next; cur != NULL; cur = next)
	{
		next = cur->next;
		free(cur);
	}
	dlist->head->next =dlist->head;
	dlist->head->prev = dlist->head;
}

//销毁，连头结点也没有
void DListDestroy(DList* dlist)
{
	DListclear(dlist);
	free(dlist->head);
	dlist->head = NULL;
}

//在pos结点前面插入
void DListInsert(DListNode* pos, DLDataType val)
{
	DListNode* node = BuyNode(val);

	node->next = pos;
	node->prev = pos->prev;
	pos->prev->next = node;
	pos->prev = node;
}

//头插
void DListPushFront(DList* dlist, DLDataType val)
{
	DListInsert(dlist->head->next, val);
#if 0
	DListNode* node = BuyNode(val);

	node->next = dlist->head->next;
	node->prev = dlist->head;
	dlist->head->next->prev = node;
	dlist->head->next = node;
#endif
}

//尾插
void DListPushBack(DList* dlist, DLDataType val)
{ 
	DListInsert(dlist->head, val);
#if 0
	//申请结点
	DListNode* node = BuyNode(val);

    //这是双向循环链表
	node->next = dlist->head;
	node->prev = dlist->head->prev;
	dlist->head->prev->next = node;
	dlist->head->prev = node;
#endif	
}

//打印
void DListPrintByHead(DListNode* head)
{
	DListNode* cur;
	//注意循环条件
	for (cur = head->next; cur != head; cur = cur->next)
	{
		printf("%d->", cur->val);
	}
	printf("\n");
}


//查找   找到返回地址，找不到返回空
DListNode* DListFind(DList* dlist,DLDataType val)
{
	DListNode* cur;
	for (cur = dlist->head->next; cur != dlist->head; cur = cur->next)
	{
		if (val == cur->val)
		{
			return cur;
		}
	}
	return NULL;
}

//删除pos结点
//pos不是头结点
void  DListErase(DListNode* pos)
{
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
}

//头删
void DListPopFront(DList* dlist)
{
	assert(dlist->head->next != NULL);
	DListErase(dlist->head->next);
}
//尾删
void DListPopBack(DList* dlist)
{
	assert(dlist->head->next != dilst->head);
	DListErase(dlist->head->prev);
}
