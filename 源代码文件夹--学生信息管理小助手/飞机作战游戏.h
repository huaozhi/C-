#ifndef  _PLANE_
#define  _PLANE_
#include <stdio.h>
#include <windows.h>            //光标移到与隐藏，system(“”)函数 ,改变字体颜色函数
#include <conio.h>              //_getch(),exit(0)等

int high, width;                //作战区域的高，宽

int plane_x, plane_y;           //飞机坐标

int enomy_x, enomy_y;           //敌军飞机坐标

int bullet_x, bullet_y;         //子弹坐标

int pscore;                      //得分

int pflag;                       //飞机是否撞毁


void color(int c);                     //设定文字颜色

void p_mennu();                          //游戏开始前的选择界面
void explanation();                    //游戏操作说明
void initial_data();                   //初始化
void show();                           //打印游戏图画

void plane_game();
void without_input();              //没有输入时的更新
void with_input();                 //有输入时的更新，没有输入时不执行操作
#endif


#ifndef _CURSOR_
#define _CURSOR_
void gotoxy(int x, int y);             //移动光标
void HideCursor();                     //隐藏光标函数
#endif

