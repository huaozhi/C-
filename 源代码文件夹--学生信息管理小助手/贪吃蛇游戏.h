#ifndef EATINGSNAKE_H_INCLUDED
#define EATINGSNAKE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

struct food{
    int x;
    int y;
}FOOD;
struct snake
{
    int length;
    int speed;
    int x[100];
    int y[100];
}eats;

int firstshow();//首页面展示

void inticialm();  //初始化界面
void smove(); //按键操作移动蛇
void showfood();  //投放食物
int gameover();   //游戏结束(1是0否)
void setcolor(unsigned short r, unsigned short s); //设定显示颜色
int eatingsnake();

#endif // EATINGSNAKE_H_INCLUDED

#ifndef _CURSOR_
#define _CURSOR_
void gotoxy(int x, int y);             //移动光标
void HideCursor();                     //隐藏光标函数
#endif
