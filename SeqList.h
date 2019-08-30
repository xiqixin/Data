#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <assert.h>

#define MAX_SIZE 5

typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* array;
	size_t size;//顺序表中的有效信息
	size_t capacity;
}SeqList;
typedef struct SeqList SeqList;
//初始化
void SeqListInit(SeqList*s1, size_t capacity);

//尾插
void SeqListPushBack(SeqList* s1,SLDataType data);

//头插
void SeqListPushFront(SeqList* s1, SLDataType data);

//打印
void SeqListPrint(SeqList* s1);

//尾删
void SeqListPopBack(SeqList* s1);

//头删
void SeqListPopFront(SeqList* s1);

//扩容
void CheckCapacity(SeqList* s1);

//查找
int SeqListFind(SeqList* s1, SLDataType x);

//在pos位置下标位置插入数据
void SeqListInsert(SeqList* s1, size_t pos, SLDataType x);

//删除pos下标的数据
void SeqListErase(SeqList* s1, size_t pos);

//删除第一个遇到的x
void SeqListRemove(SeqList* s1, SLDataType x);

//删除所有遇到的x
void SeqListRmoveAll(SeqList* s1, SLDataType x);

//将pos位置的值修改为x
void SeqListModify(SeqList* s1, size_t pos, SLDataType x);

//冒泡排序
void SeqListBubbleSort(SeqList* s1);

//二分查找
int SeqListBinaryFind(SeqList* S1, SLDataType x);
