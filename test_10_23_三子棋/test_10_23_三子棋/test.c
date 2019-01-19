#include<stdio.h>
#include<stdlib.h>
void _printf()
{
printf("***************************************\n");
printf("***************************************\n");
printf("***********     1.play   **************\n");
printf("***********     0.exit   **************\n");
printf("***************************************\n");
printf("***************************************\n");

}
int main()
{
	int num;
    _printf();
	printf("«Î—°‘Ò£∫\n");
	scanf("%d",&num);
   switch(num)
   {
   case 0:
	   break;
   case 1:
	   game();
	   break;
   default:
	   printf(" ‰»Î¥ÌŒÛ£°\n");
	   break;
   
   }
   
   system("pause");
   return 0;
}