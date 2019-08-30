#define _CRT_SECURE_NO_WARNINGS
#include "seqlist.h"

void SeqListInit(SeqList*s1, size_t capacity)
{
	assert(s1!= NULL);
	s1->array = (SLDataType*)malloc(capacity * sizeof(SLDataType));//申请空间
	if (s1->array == NULL)
	{
		printf("申请失败");
		return;
	}
	s1->capacity = capacity;
	s1->size = 0;
}

//尾插
void SeqListPushBack(SeqList* s1,SLDataType data)
{
	assert(s1 != NULL);
	//检查扩容
	CheckCapacity(s1);
	s1->array[s1->size] = data;
	s1->size++;
}

//头插
void SeqListPushFront(SeqList* s1, SLDataType data)
{
	assert(s1 != NULL);
	//检查扩容
	CheckCapacity(s1);
	for (int i = s1->size - 1; i >= 0; i--)
	{
		s1->array[i + 1] = s1->array[i];
	}
	s1->array[0] = data;
	s1->size++;
}

//打印
void SeqListPrint(SeqList* s1)
{
	assert(s1 != NULL);
	for (unsigned int i = 0; i < s1->size; i++)
	{
		printf("%d ", s1->array[i]);
	}
	printf("\n");
}

//尾删
void SeqListPopBack(SeqList* s1)
{
	assert(s1 != NULL);
	if (s1->size == 0)
	{
		printf("顺序表里没有数据");
			return;
	}
	s1->size--;
}

//头删
void SeqListPopFront(SeqList* s1)
{
	assert(s1 != NULL);
	assert(s1->size > 0);
	for (unsigned int i = 0; i < s1->size; i++)
	{
		s1->array[i] = s1->array[i + 1];
	}
	s1->size--;
}

//检查是否扩容
void CheckCapacity(SeqList* s1)
{
	assert(s1 != NULL);
	//边界条件是s1->size和s1->capacity相等时需要扩容
	if (s1->size == s1->capacity)
	{
		s1->capacity *= 2;//将容量扩大为原来的两倍
		SLDataType* new_array = (SLDataType*)malloc(s1->capacity * sizeof(SLDataType));//开辟新的空间
		memcpy(new_array, s1->array, s1->size * sizeof(SLDataType));//将以前的数据搬到新空间
		if (s1->array == NULL)
		{
			printf("申请失败");
			return;
		}
		free(s1->array);//释放原来的空间
		s1->array = new_array;//将新空间指针指向s1->array
		printf("扩容成功！\n");
	}
	return;
}

int SeqListFind(SeqList* s1, SLDataType x)
{
	//查找
	assert(s1 != NULL);
	size_t i;
	for (i = 0; i < s1->size; i++)
	{
		if (x == s1->array[i])
		{
			return i;//找到了，返回下标
		}
	}
	return -1;//没找到
}

//在pos位置插入x
void SeqListInsert(SeqList* s1, size_t pos, SLDataType x)
{
	assert(s1 != NULL);
	if (pos<0 || pos>s1->size)
	{
		printf("输入位置错误！！！\n");
		return;
	}
	else if (pos == s1->size)
	{
		//此时是尾插
		SeqListPushBack(s1,x);
	}
	else
	{
		size_t i;
		for (i = s1->size - 1; i >= pos; i--)
		{
			s1->array[i + 1] = s1->array[i];
		}
		s1->array[pos] = x;
		s1->size++;
	}
}

//删除pos下标的数据
void SeqListErase(SeqList* s1, size_t pos)
{
	assert(s1 != NULL);
	if (pos >= s1->size)
	{
		printf("输入位置错误！！！\n");
		return;
	}
	else
	{
		size_t i;
		for (i = pos; i < s1->size; i++)
		{
			s1->array[i] = s1->array[i + 1];
		}
		s1->size--;
	}
}

//删除第一个遇到的x
void SeqListRemove(SeqList* s1, SLDataType x)
{
	assert(s1 != NULL);
	for (size_t i = 0; i < s1->size; i++)
	{
		if (x == s1->array[i])
		{
			SeqListErase(s1, i);
			return;
		}
	}
	printf("该顺序表中没有%d",x);
}

//删除所有遇到的x
void SeqListRmoveAll(SeqList* s1, SLDataType x)
{
	assert(s1 != NULL);
	size_t i;
	for(i = 0;i < s1->size; i++)
	{
		if (x == s1->array[i])
		{
			SeqListErase(s1, i);//删除遇到的x----删除之后下一个位置的数据把当前位置覆盖
			i--;//下标先往前走，再在循环中往后走，保证每一个位置都被遍历
		}
	}

}

//将pos位置的值修改为x
void SeqListModify(SeqList* s1, size_t pos, SLDataType x)
{
	assert(s1 != NULL);
	assert(pos >= 0 && pos < s1->size);
	s1->array[pos] = x;
}

//冒泡排序
void SeqListBubbleSort(SeqList* s1)
{
	assert(s1 != NULL);
	size_t i, j;
	SLDataType tmp;
	for (i = 0; i < s1->size;i++)
	{
		for (j = 0; j < s1->size-i-1; j++)
		{
			if (s1->array[j] > s1->array[j + 1])
			{
				tmp = s1->array[j];
				s1->array[j] = s1->array[j + 1];
				s1->array[j + 1] = tmp;
			}
		}
	}
}

//二分查找
int SeqListBinaryFind(SeqList* s1, SLDataType x)
{
	assert(s1 != NULL);
	size_t left = 0;
	size_t right = s1->size - 1;
	while (left <= right)
	{
		size_t mid = (size_t)(left + (right-left) / 2);
		if (x < s1->array[mid])
		{
			right = mid - 1;
		}
		else if (x > s1->array[mid])
		{
			left = mid + 1;
		}
		else
		{ 
			return mid; 
		}
	}
	return -1;
}
