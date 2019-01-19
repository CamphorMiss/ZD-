#define _CRT_SECURE_NO_WARNINGS 1
#ifndef __GAME_H__
#define __GAME_H__
#define ROW 9
#define COL 9
#define LEI 10
#define ROWS ROW+2
#define COLS COL+2
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
void menu();
void minegame();
void Initial(char mine[ROWS][COLS],int rows,int cols,char s);
void arramine(char mine[ROWS][COLS],int row,int col);
void printfun(char mine[ROWS][COLS],int row,int col);
int sidemine(char mine[ROWS][COLS],int x,int y);
void checkmine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col);
void expandmine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col,int x,int y);//展开一片的那个东东




#endif//__GAME_H__

