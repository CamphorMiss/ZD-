#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void menu()
{
		printf("*****************************************\n");
		printf("-----------------------------------------\n");
		printf("-----------------------------------------\n");
		printf("-----1. * 玩游戏 *    0.* 退出游戏 *-----\n");
		printf("-----------------------------------------\n");
		printf("-----------------------------------------\n");
		printf("-----------------------------------------\n");
		printf("*****************************************\n");

}

int main()
{

	int intput=0;
	srand((unsigned int)time(NULL));
	system("color F0");//0 = 黑色 8 = 灰色1 = 蓝色 9 = 淡蓝色2 = 绿色 A = 淡绿色 = 湖蓝色 B = 淡浅绿色5 = 紫色 D = 淡紫色6 = 黄色 E = 淡黄色7 = 白色 F = 亮白色
    do
	{    
		menu();
		printf("请选择： \n");
		scanf("%d",&intput);
		switch(intput)
		{
		case 0:
			printf("退出成功！\n");
			break;
		case 1:
			minegame();
			break;
		default:
			printf("没有这个选项，请重新选择！\n");
		}
	}while(intput);
	system("pause");
	return 0;
}
