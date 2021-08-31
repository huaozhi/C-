#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>

typedef struct birthday
{
	int year;
	int month;
	int day;
}Birthday;
typedef struct Student
{
    int num;
	char name[20];
	int age;
	Birthday birth;
	char address[31]; //不超过15个汉字
	char phonum[12]; //11位电话号码
	char email[30];
	char clas[20];
	char sex[3];//一个汉字两个字节
	float score;
	struct Student* next;
}Student,*List;

//函数的输入参数为指针的地址的，在函数头部就不再赘述

char mennu();//菜单函数

void sokoban();//推箱子游戏
void stu_failed(List *L);//统计不及格学生人数&计算平均成绩
void judge(struct Student *p);//判断用户输入是否合乎规范

void stu_input(List *L);   //学生信息录入
void stu_seek(List *L);    //学生信息查询
void stu_browse(List *L);  //学生信息浏览
void stu_order(List *L);   //学生信息排序
void stu_delete(List *L);  //学生信息的删除
void stu_change(List *L);  //学生信息修改
void stu_insert(List *L);  //学生信息插入

void time_now();//显示当前系统的时间
void readfile(List *L);//从文件中读取学生信息组成链表

void save_into_file(List L);//从链表保存学生信息到文件
#endif // STUDENT_H_INCLUDED


