#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


typedef int SLDataType;

typedef struct SListNode 
{
	SLDataType data;
	struct SListNode* next;
}SListNode;

typedef struct SList
{
	 SListNode* first;
}SList;

SList list;

//初始化
void SListInit(SList* list);

//销毁
void SListDestroy(SList* list);

//头插
void SListPushFront(SList* list, SLDataType data);

//头删
void SListPopFront(SList* list);

//尾插
void SListPushBack(SList* list, SLDataType data);

// 尾删
void SListPopBack(SList *list);

// 查找   NULL 表示没找到
SListNode* SListFind(SList *list, SLDataType data);

// 在 pos 这个结点后面插入新结点
void SListInsertAfter(SListNode *pos, SLDataType data);

// pos 不是最后一个结点
// 删除 pos 这个结点后面的结点
void SListEraseAfter(SListNode *pos);

// 删除第一个遇到的 data 结点
void SListRemove(SList *list, SLDataType data);


// 打印
void SListPrint(SList *list);
