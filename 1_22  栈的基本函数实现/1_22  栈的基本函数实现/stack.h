#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include <assert.h>
#include <string.h>



// 动态增长的栈
typedef int STDataType;

typedef struct Stack
{
	STDataType* _a;
	int _top; // 栈顶
	int _capacity; // 容量
}Stack;
void StackInit(Stack* ps);
void StackDestory(Stack* ps);
void StackPush(Stack* ps, STDataType x);
void StackPop(Stack* ps);
STDataType StackTop(Stack* ps);
int StackEmpty(Stack* ps);
int StackSize(Stack* ps);
void TestStack();
void CheckCapacity(Stack* ps);
void PrintStack(Stack* ps);



