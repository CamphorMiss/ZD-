#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void Initial(char mine[ROWS][COLS],int rows,int cols,char s)
{
memset(&mine[0][0],s,rows*cols*sizeof(char));
}
void printfun(char mine[ROWS][COLS],int row,int col)
{
int i=0;
int j=0;
printf("~~~~~~~~~~~~~~~~~~\n");
for(j=0;j<=col;j++)
	{
		printf("%d ",j);

}
printf("\n");
for(i=1;i<=row;i++)
{ 
	printf("%d ",i);
    for(j=1;j<=col;j++)
	{
		
	printf("%c ",mine[i][j]);
	}
printf("\n");
}
}
void arramine(char mine[ROWS][COLS],int row,int col)
{
	int count=LEI;
	int x=0;
	int y=0;
	while(count)//随机数要放在循环里面，否则出错!!!
	{
		x=rand()%row+1;
		y=rand()%col+1;
		if(mine[x][y]=='0')
		{
			 mine[x][y]='1';
			count--;
		}
	}
}
int sidemine(char mine[ROWS][COLS],int x,int y)
{
return mine[x-1][y-1]+
mine[x][y-1]+
mine[x+1][y-1]+
mine[x+1][y]+
mine[x+1][y+1]+
mine[x][y+1]+
mine[x-1][y+1]+
mine[x-1][y]-8*'0';

}
void checkmine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col )//玩家开始扫雷
{
int x=0;
int y=0;
int geshu=0;
int ret=0;
int x1=0;
int y1=0;
while(geshu<row*col-LEI)//非雷的部分
{
	printf("请输入排雷的坐标：");
scanf("%d%d",&x,&y);
if(1<=x&&x<=row&&1<=y&&y<=col)
{

	if(mine[x][y]=='1'&&ret==0)
	{
		mine[x][y]='0';
		while(1)
	{
		x1=rand()%row+1;
		y1=rand()%col+1;
		if(mine[x1][y1]=='0')
		{
			 mine[x1][y1]='1';
            printfun(mine,ROW,COL);
			 ret=1;
			 break;
		}
		} 
	}
   if(mine[x][y]=='1'&&ret==0)
   {
   printf("恭喜你，你被炸死了！\n");
   printfun(mine,ROW,COL);
   break;
   
   }
	else
	{
	int count=sidemine(mine,x,y);
	show[x][y]=count+'0';
    expandmine(mine,show,row,col,x,y);
	printfun(show,row,col);
	geshu++;
	}
}
else
    printf("输入坐标有误！\n");
}
if(geshu==row*col-LEI)
{
  printf("恭喜你!排雷成功！\n");
  printfun(mine,ROW,COL);
}
}
void expandmine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col,int x,int y)//展开一片的那种
{
	int temp=sidemine(mine,x,y);
    if(temp==0)
	      {
			show[x][y]=' ';
			if(x>0&&y-1>0&&show[x][y-1]=='*')
				expandmine(mine,show,row,col,x,y-1);
			if(x-1>0&&y-1>0&&show[x-1][y-1]=='*')
				expandmine(mine,show,row,col,x-1,y-1);
			if(x-1>0&&y>0&&show[x-1][y]=='*')
				expandmine(mine,show,row,col,x-1,y);
			if(x-1>0&&y+1>0&&show[x-1][y+1]=='*')
				expandmine(mine,show,row,col,x-1,y+1);
			if(x>0&&y+1>0&&show[x][y+1]=='*')
				expandmine(mine,show,row,col,x,y+1);
			if(x+1>0&&y+1>0&&show[x+1][y+1]=='*')
				expandmine(mine,show,row,col,x+1,y+1);
			if(x+1>0&&y>0&&show[x+1][y]=='*')
				expandmine(mine,show,row,col,x+1,y);
			if(x+1>0&&y-1>0&&show[x+1][y-1]=='*')
				expandmine(mine,show,row,col,x+1,y-1);
			
	    }
	else
	{
	   show[x][y]=temp+'0';
	}

}

void minegame()
{
	char mine[ROWS][COLS]={0};
	char show[ROWS][COLS]={0};
	Initial(mine,ROWS,COLS,'0');//初始化数组
	Initial(show,ROWS,COLS,'*');//初始化数组
	printfun(mine,ROW,COL);//打印数组
	printfun(show,ROW,COL);
    arramine(mine,ROW,COL);//布置雷
	printfun(mine,ROW,COL);
	checkmine(mine,show,ROW,COL);//排查雷


}


