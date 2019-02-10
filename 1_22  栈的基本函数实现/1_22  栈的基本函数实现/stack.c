#define _CRT_SECURE_NO_WARNINGS 1

#include "stack.h"
void StackInit(Stack* ps)
{
	assert(ps);
   ps->_a=(STDataType*)malloc(sizeof(STDataType)*3);
   if(NULL==ps->_a)
   {
	   perror(ps->_a);
	   return;
   }
   ps->_capacity=3;
   ps->_top=0;
}
void StackDestory(Stack* ps)
{
   assert(ps);
   ps->_capacity=0;
   ps->_top=0;
   free(ps->_a);
   ps->_a=NULL;
   printf("销毁栈成功！\n");


}
void CheckCapacity(Stack* ps)
{

	STDataType*ret=NULL;
	int newcapa=0;
	assert(ps);
	newcapa=2*(ps->_capacity);
	
		//增容
		ret=(STDataType*)malloc(sizeof(STDataType)*newcapa);
		if(ret==NULL)
		{
			assert(0);
			return;

		}
		else
		{
			memcpy(ret,ps->_a,sizeof(STDataType)*ps->_top);
			
			free(ps->_a);
			ps->_a=ret;
			ps->_capacity=newcapa;
		}

	
}
void StackPush(Stack* ps, STDataType x)//栈顶插入一个元素
{
	assert(ps);
	if(ps->_top==ps->_capacity)
	{
          CheckCapacity(ps);
	}
	
	ps->_a[ps->_top]=x;
	ps->_top+=1;

}
void StackPop(Stack* ps)//栈顶删除一个元素
{
	assert(ps);
	ps->_top--;
}
STDataType StackTop(Stack* ps)//取出栈顶的元素
{
   assert(ps);
   return ps->_a[ps->_top-1];
}
int StackEmpty(Stack* ps)//清空栈
{
	assert(ps);
	ps->_top=0;
	printf("清空栈成功！\n");
	return ps->_top;

}
int StackSize(Stack* ps)//求栈里面的元素个数
{
   assert(ps);
   return ps->_top;
}
void PrintStack(Stack* ps)
{
	int i=0;
	assert(ps);
	if(ps->_top==0)
	{
		return;
	}
	else
	{
		for(i=0;i<ps->_top;i++)
		{
			printf("%d ",ps->_a[i]);
		}
		printf("\n");
	}
}

void TestStack()
{
	Stack p;
	StackInit(&p);
	
	StackPush(&p,1);
	StackPush(&p,2);
	StackPush(&p,3);
	StackPush(&p,4);
	StackPush(&p,5);
    PrintStack(&p);
	StackPop(&p);
	PrintStack(&p);

   printf("栈顶的元素是：%d\n",StackTop(&p));
   printf("栈里面一共有%d个元素\n",StackSize(&p));
	StackEmpty(&p);
	
	StackDestory(&p);
}
