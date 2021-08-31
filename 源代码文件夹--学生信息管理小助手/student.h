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
	char address[31]; //������15������
	char phonum[12]; //11λ�绰����
	char email[30];
	char clas[20];
	char sex[3];//һ�����������ֽ�
	float score;
	struct Student* next;
}Student,*List;

//�������������Ϊָ��ĵ�ַ�ģ��ں���ͷ���Ͳ���׸��

char mennu();//�˵�����

void sokoban();//��������Ϸ
void stu_failed(List *L);//ͳ�Ʋ�����ѧ������&����ƽ���ɼ�
void judge(struct Student *p);//�ж��û������Ƿ�Ϻ��淶

void stu_input(List *L);   //ѧ����Ϣ¼��
void stu_seek(List *L);    //ѧ����Ϣ��ѯ
void stu_browse(List *L);  //ѧ����Ϣ���
void stu_order(List *L);   //ѧ����Ϣ����
void stu_delete(List *L);  //ѧ����Ϣ��ɾ��
void stu_change(List *L);  //ѧ����Ϣ�޸�
void stu_insert(List *L);  //ѧ����Ϣ����

void time_now();//��ʾ��ǰϵͳ��ʱ��
void readfile(List *L);//���ļ��ж�ȡѧ����Ϣ�������

void save_into_file(List L);//��������ѧ����Ϣ���ļ�
#endif // STUDENT_H_INCLUDED


