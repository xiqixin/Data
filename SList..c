#define _CRT_SECURE_NO_WARNINGS
#include "SList.h"


//初始化
void SListInit(SList* list)
{
	assert(list != NULL);
	list->first = NULL;
}

//销毁
void SListDestroy(SList* list)
{
	SListNode* next,*cur;
	for (cur = list->first; cur != NULL; cur = next)
	{
		next = cur->next;
		free(cur);
	}
	list->first = NULL;
}

SListNode* BuySListNode(SLDataType data)
{
	SListNode* node = (SListNode*)malloc(sizeof(SListNode));
	assert(node != NULL);
	node->data = data;
	node->next = NULL;

	return node;
}

//头插
void SListPushFront(SList* list, SLDataType data)
{
	assert(list != NULL);
	
	SListNode* node = BuySListNode(data);

	node->next = list->first;
	list->first = node;
}

//头删
void SListPopFront(SList* list)
{
	assert(list != NULL);
	assert(list->first != NULL);

	SListNode * old_first = list->first;
	list->first = list->first->next;
	free(old_first);
}

//尾插
void SListPushBack(SList* list, SLDataType data)
{
	assert(list != NULL);
	if (list->first == NULL)
	{
		//链表为空
		SListPushFront(list, data);
		return;
	}
	//链表中有结点
	SListNode* cur;
	//找最后一个结点cur
	for (cur = list->first; cur->next != NULL; cur = cur->next)
	{
	}
	SListNode* node = BuySListNode(data);
	cur->next= node;
}

//尾删
void  SListPopBack(SList* list)
{
	assert(list != NULL);
	assert(list->first != NULL);        //0个结点
	if (list->first->next == NULL)      //一个结点
	{
		//相当于头删
		SListPopFront(list);
		return;
	}
	//两个及以上的结点
	SListNode* cur;
	//找倒数第二个结点cur
	for (cur = list->first; cur->next->next!= NULL; cur = cur->next)
	{
	}
	free(cur->next);
	cur->next = NULL;
}

//查找
SListNode * SListFind(SList *list, SLDataType data)
{
	assert(list != NULL);
	assert(list->first != NULL);
	SListNode* cur;
	for (cur = list->first; cur != NULL; cur = cur->next)
	{
		if (data == cur->data)
		{
			return cur;
		}
	}

	return NULL;
}

//在pos位置后面插入新结点
void SListInsertAfter(SListNode* pos, SLDataType data)
{
	SListNode* node= BuySListNode(data);
	node->next = pos->next;
	pos->next = node;
}


//删除pos后面的一个结点（pos不是最后一个结点）
void SListEraseAfter(SListNode* pos)
{
	SListNode* next = pos->next->next;
	free(pos->next);
	pos->next = next;
}
//删除第一个遇到的data
void SListRemove(SList *list, SLDataType data)
{
	assert(list != NULL);
	assert(list->first != NULL);

	SListNode* cur = list->first;
	SListNode* prev = NULL;

	while (cur != NULL && cur->data != data)
	{
		prev = cur;
		cur = cur->next;
	}

	if (cur == NULL)
	{
		//没找到
		return;
	}
	else if (prev == NULL)
	{
		//当cur！=NULL 和 prev=NULL 同时满足
		//即cur->data == data
		//第一个就是data 所以是头删
		SListPopFront(list);
		return;
	}
	else
	{
		prev->next = cur->next;
		free(cur);
	}
	
}

//打印
void SListPrint(SList *list)
{
	SListNode* cur = list->first;
	for (; cur != NULL; cur = cur->next)
	{
		printf("%d->", cur->data);
	}
	printf("NULL\n");
}
