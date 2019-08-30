#define _CRT_SECURE_NO_WARNINGS
#pragma  once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SDataType;
//静态顺序表实现栈
#define MAX_LEN (100)

typedef struct
{
	SDataType arrar[MAX_LEN];
	int top;//栈顶
}Stack;

void StackInit(Stack* stack)
{
	stack->top = 0;
}

void StackDestroy(Stack* stack)
{
	stack->top = 0;
}

//增删该查

//只能从栈顶插入
void StackPush(Stack* stack, SDataType val)
{
	assert(stack);
	assert(stack->top < MAX_LEN);
	stack->arrar[stack->top] = val;
	stack->top++;
}

//只能从栈顶删除
void StackPop(Stack* stack)
{
	assert(stack);
	assert(stack->top > 0);
	stack->top--;
}

//返回栈顶元素
SDataType StackTop(Stack* stack)
{
	assert(stack);
	assert(stack->top > 0);
	return stack->arrar[stack->top - 1];
}
//判断是否为空
int StackEmpty(Stack* stack)
{
	return (stack->top == 0) ? 1 : 0;
}
int StackSize(Stack* stack)
{
	return stack->top;
}
