#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void menu()
{
		printf("*****************************************\n");
		printf("-----------------------------------------\n");
		printf("-----------------------------------------\n");
		printf("-----1. * ����Ϸ *    0.* �˳���Ϸ *-----\n");
		printf("-----------------------------------------\n");
		printf("-----------------------------------------\n");
		printf("-----------------------------------------\n");
		printf("*****************************************\n");

}

int main()
{

	int intput=0;
	srand((unsigned int)time(NULL));
	system("color F0");//0 = ��ɫ 8 = ��ɫ1 = ��ɫ 9 = ����ɫ2 = ��ɫ A = ����ɫ = ����ɫ B = ��ǳ��ɫ5 = ��ɫ D = ����ɫ6 = ��ɫ E = ����ɫ7 = ��ɫ F = ����ɫ
    do
	{    
		menu();
		printf("��ѡ�� \n");
		scanf("%d",&intput);
		switch(intput)
		{
		case 0:
			printf("�˳��ɹ���\n");
			break;
		case 1:
			minegame();
			break;
		default:
			printf("û�����ѡ�������ѡ��\n");
		}
	}while(intput);
	system("pause");
	return 0;
}
