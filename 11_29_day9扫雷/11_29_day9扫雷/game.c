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
	while(count)//�����Ҫ����ѭ�����棬�������!!!
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
void checkmine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col )//��ҿ�ʼɨ��
{
int x=0;
int y=0;
int geshu=0;
int ret=0;
int x1=0;
int y1=0;
while(geshu<row*col-LEI)//���׵Ĳ���
{
	printf("���������׵����꣺");
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
   printf("��ϲ�㣬�㱻ը���ˣ�\n");
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
    printf("������������\n");
}
if(geshu==row*col-LEI)
{
  printf("��ϲ��!���׳ɹ���\n");
  printfun(mine,ROW,COL);
}
}
void expandmine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col,int x,int y)//չ��һƬ������
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
	Initial(mine,ROWS,COLS,'0');//��ʼ������
	Initial(show,ROWS,COLS,'*');//��ʼ������
	printfun(mine,ROW,COL);//��ӡ����
	printfun(show,ROW,COL);
    arramine(mine,ROW,COL);//������
	printfun(mine,ROW,COL);
	checkmine(mine,show,ROW,COL);//�Ų���


}


