#define _CRT_SECURE_NO_WARNINGS 1
//�ж�ĳ���Ƿ���2��n�η�

# include<stdio.h>
# include<stdlib.h>
void two_pow(int num)
	{

	   if((num&(num-1))==0)
		   printf("%d��2�Ĵη�����\n",num);
	   else
		   printf("%d����2�Ĵη�����\n",num);
	}
int main()
{
  int n=0;
  scanf("%d",&n);
  two_pow(n);

  system("pause");
   return 0;
}

