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

int firstshow();//��ҳ��չʾ

void inticialm();  //��ʼ������
void smove(); //���������ƶ���
void showfood();  //Ͷ��ʳ��
int gameover();   //��Ϸ����(1��0��)
void setcolor(unsigned short r, unsigned short s); //�趨��ʾ��ɫ
int eatingsnake();

#endif // EATINGSNAKE_H_INCLUDED

#ifndef _CURSOR_
#define _CURSOR_
void gotoxy(int x, int y);             //�ƶ����
void HideCursor();                     //���ع�꺯��
#endif
