#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define H 3
#define S 3


 void meu_printf()
 {
 printf("************************************");
 printf("**********  1.开始游戏   ***********");
 printf("**********  0.结束游戏   ***********");
 printf("************************************");

 }
 void arr_printf(char arr[H][S])
 {
 int i,j;
 for(i=0;i<H;i++)
 {
    for(j=0;j<S;j++)
	{
	    arr[i][j]=' ';
	}
  }

void chess_printf(char arr[H][S])
{
int i;
for(i=0;i<H;i++)
{
    printf("%c|%c|%c\n",arr[i][0],arr[i][1],arr[i][2]);
    if(i<2)
		printf("--|--|--");
	printf("\n");
}
}
void player_chess(char arr[H][S])
{
int x,y;
printf("输入棋子的坐标：\n");
scanf("%d %d",&x,&y);
x--;
y--;
while(1)
{
if(arr[x][y]==' ')
{
   arr[x][y]='X';
   break;
}
else
{
	printf("此位置已有棋子，请重新选择！\n");
	continue;
}
}
}
int check_full(char arr[H][S])
{
int i,j;
for(i=0;i<H;i++)
{
  for(j=0;j<S;j++)
  {
  if(arr[i][j]==' ')
	  return 0;
  }
}
return 1;
}

void computer_chess(char arr[H][S])
{
 srand((unsigned)time(NULL));
 int x=0,y=0;
 while(1){
 srand((unsigned)time(NULL));
 x=rand()%3;
 y=rand()%3;
 if(arr[x][y]==' ')
 {
   arr[x][y]='o';
   break;
 }
 else
 {
	 if(check_full(arr)==0)
      continue;
	 else
		 break;
 }
 }
}
char check_win(char arr[H][S])
{
    int i = 0;
    int ret = 0;

    for (i = 0; i < H; i++)
    {
        if ((arr[i][0] == arr[i][1]) && (arr[i][2] == arr[i][1]))
        {
            return arr[i][0];
        }
    }
    for (i = 0; i < S; i++)
    {
        if ((arr[0][i] == arr[1][i]) && (arr[2][i] == arr[1][i]))
        {
            return arr[0][i];
        }
    }
    if ((arr[0][0] == arr[1][1]) && (arr[1][1] == arr[2][2]))
    {
        return arr[0][0];
    }
    if ((arr[0][2] == arr[1][1]) && (arr[1][1] == arr[2][0]))
    {
        return arr[2][0];
    }
    ret = check_full(arr);
    if (ret == 1)
    {
        return 'q';
    }
    return ' ';
}


int main()
{
  
  int n=1;
  int ret;
  char arr[H][S];
  
  while(n){
   meu_printf();
   scanf("%d",&n); 
  switch(n)
  {
  case 1:
	  {
	  arr_printf(arr[H][S]);
	  do{
	   chess_printf(arr[H][S]);
	     player_chess(arr);
     
      if(chess_win(arr)!=' ')
	     {
	          ret=check_win(arr[H][S]);
	          break;
	      }
                computer_chess(arr);
                ret = check_win(arr);
	  }while(ret==' ')
		  chess_printf(arr);
	      if(ret=='X')
			  printf("恭喜！你赢了！\n");
		  else if(ret=='O')
			  printf("电脑赢！\n");
		  else if(ret=='q')
			  printf("平局！！！\n");
  }
	  break;
    
  case 0:
	  break;
  }

  }

    system("pause");
	return 0;
}