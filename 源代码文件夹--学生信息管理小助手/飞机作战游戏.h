#ifndef  _PLANE_
#define  _PLANE_
#include <stdio.h>
#include <windows.h>            //����Ƶ������أ�system(����)���� ,�ı�������ɫ����
#include <conio.h>              //_getch(),exit(0)��

int high, width;                //��ս����ĸߣ���

int plane_x, plane_y;           //�ɻ�����

int enomy_x, enomy_y;           //�о��ɻ�����

int bullet_x, bullet_y;         //�ӵ�����

int pscore;                      //�÷�

int pflag;                       //�ɻ��Ƿ�ײ��


void color(int c);                     //�趨������ɫ

void p_mennu();                          //��Ϸ��ʼǰ��ѡ�����
void explanation();                    //��Ϸ����˵��
void initial_data();                   //��ʼ��
void show();                           //��ӡ��Ϸͼ��

void plane_game();
void without_input();              //û������ʱ�ĸ���
void with_input();                 //������ʱ�ĸ��£�û������ʱ��ִ�в���
#endif


#ifndef _CURSOR_
#define _CURSOR_
void gotoxy(int x, int y);             //�ƶ����
void HideCursor();                     //���ع�꺯��
#endif

