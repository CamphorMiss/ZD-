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
   printf("����ջ�ɹ���\n");


}
void CheckCapacity(Stack* ps)
{

	STDataType*ret=NULL;
	int newcapa=0;
	assert(ps);
	newcapa=2*(ps->_capacity);
	
		//����
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
void StackPush(Stack* ps, STDataType x)//ջ������һ��Ԫ��
{
	assert(ps);
	if(ps->_top==ps->_capacity)
	{
          CheckCapacity(ps);
	}
	
	ps->_a[ps->_top]=x;
	ps->_top+=1;

}
void StackPop(Stack* ps)//ջ��ɾ��һ��Ԫ��
{
	assert(ps);
	ps->_top--;
}
STDataType StackTop(Stack* ps)//ȡ��ջ����Ԫ��
{
   assert(ps);
   return ps->_a[ps->_top-1];
}
int StackEmpty(Stack* ps)//���ջ
{
	assert(ps);
	ps->_top=0;
	printf("���ջ�ɹ���\n");
	return ps->_top;

}
int StackSize(Stack* ps)//��ջ�����Ԫ�ظ���
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

   printf("ջ����Ԫ���ǣ�%d\n",StackTop(&p));
   printf("ջ����һ����%d��Ԫ��\n",StackSize(&p));
	StackEmpty(&p);
	
	StackDestory(&p);
}
