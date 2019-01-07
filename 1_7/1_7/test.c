#define _CRT_SECURE_NO_WARNINGS 1
//判断某数是否是2的n次方

# include<stdio.h>
# include<stdlib.h>
void two_pow(int num)
	{

	   if((num&(num-1))==0)
		   printf("%d是2的次方数！\n",num);
	   else
		   printf("%d不是2的次方数！\n",num);
	}
int main()
{
  int n=0;
  scanf("%d",&n);
  two_pow(n);

  system("pause");
   return 0;
}

