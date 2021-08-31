#include "student.h"
//此源文件里包括不需对链表进行修改的函数，如菜单函数，查询函数，浏览函数等
extern int studentnum;

//菜单函数
char mennu()
{
    time_now();
	printf("**********学生信息管理系统**********\n");
	printf("*       当前系统共有 %d 名学生      *\n", studentnum);
	printf("*                                  *\n");
	printf("*           0-学生信息从文件载入   *\n");
	printf("*           1-学生信息录入         *\n");
	printf("*           2-学生信息查询         *\n");
	printf("*           3-学生信息浏览         *\n");
	printf("*           4-学生信息排序         *\n");
	printf("*           5-学生信息的删除       *\n");
	printf("*           6-学生信息的修改       *\n");
	printf("*           7-学生信息的增加       *\n");
	printf("*           8-退出系统             *\n");
	printf("*           9-刷新当前页面         *\n");
	printf("*           @-飞机作战游戏         *\n");
	printf("*           #-推箱子游戏           *\n");
	printf("*           &-贪吃蛇游戏           *\n");
	printf("************************************\n");
	printf("请输入你要进行的操作对应的编号：");
	char n[10];
    int lens = 0;

	while(1)
    {
        gets(n);
        lens = strlen(n);
        if(lens > 1)
            printf("请按要求输入!\n");
        else{
            if(isdigit(n[0]) || n[0] == '&' || n[0] == '#' || n[0] == '@')
                break;
            else
                printf("请按要求输入!\n");
        }
    }
	system("CLS");
	return n[0];

}

//以下是显示系统当前时间的函数，会打印出当前时间的年月日、时分秒
void time_now()
{
    time_t t;
    struct tm* ltime;
    time (&t);//获取Unix时间戳
    ltime = localtime (&t);//转为时间结构。
    printf ( "*********%d/%02d/%02d %02d:%02d:%02d********\n",ltime->tm_year+1900, ltime->tm_mon+1, ltime->tm_mday,
            ltime->tm_hour, ltime->tm_min, ltime->tm_sec);//输出结果
}


//统计不及格学生人数和学生平均分，输出是否有不及格的学生，若有则显示人数
void stu_score(List *L)
{
	List q = (*L)->next;
	int count = 0;//用于统计不及格人数
	int stucou = 0;//表示学生人数
	double score_sum;//表示学生成绩总和
	double score_ave = 0;//表示平均成绩
	while(q != NULL)
    {
        score_sum += q->score;//学生总成绩
        stucou++;//学生人数
        if(q->score - 60 < 0)
            count++;
        q = q->next;
    }
    score_ave = score_sum/stucou;
    printf("平均分为%.2f", score_ave);
    if(count == 0)
        printf("，全部及格！\n\n");
    else
        printf("，不及格%d人\n\n", count);
}

//以下是查询函数，提供两种查询方式并打印学生信息
void stu_seek(List *L)
{
	if(*L == NULL || (*L)->next == NULL)
	{
		printf("学生信息为空！\n按回车键返回主菜单!\n");
		getchar();
		getchar();
		system("CLS");
		return;
	}
    printf("*************请选择查询方式*************\n");
    printf("************1.按学生学号查询************\n");
    printf("************2.按学生姓名查询************\n");
    printf("************3.返回主菜单****************\n");
    printf("----------------------------------------\n");
    int ennum, n, i = 1;//表示输入的数字和要查询的学生人数&计数用的变量i
    while(scanf("%d", &ennum))
    {
    	if(ennum >= 1 && ennum <= 3)
    	    break;
    	else
    	    printf("请按要求输入！\n");
	}

    List p = (*L)->next;  //从存的第一个学生信息开始
    List p_temp = p;
    char sname[20];
    int snum;    //表示输入的学生学号

    switch(ennum)
    {
    case 1:
        printf("请输入要查询的学生数:");
        scanf("%d", &n);
        while(i <= n)
        {
            printf("请输入要查询的第%d个学生的学号:", i);
            scanf("%d", &snum);
            p = p_temp;
            while(p){
                if(p->num == snum)
                    break;
                p = p->next;
            }
            if(p == NULL)
			{
				printf("找不到该学生！本次查询失败\n");
				i++;
				continue;
			}
            printf("该学生信息如下\n");
            printf("| 学号 |   姓名   |年龄|  出生年月日  |         地址         |    电话     |       E-mail       |  班级  |性别|学分绩点|\n");            printf("| %d |%8s  | %d ", p->num, p->name, p->age);
            printf("|%6d/%02d/%02d  | %20s ", p->birth.year, p->birth.month, p->birth.day, p->address);
            printf("| %11s | %18s |  %4s  | %s |  %.2f |\n", p->phonum, p->email, p->clas, p->sex, p->score);
            i++;
        }
        getchar();
        printf("按回车键返回主菜单\n");
        getchar();
        system("CLS");
        break;
    case 2:
        printf("请输入要查询的学生数:");
        scanf("%d", &n);
        while(i <= n)
        {
            printf("请输入要查询的第%d个学生的姓名:", i);
            scanf("%s", sname);
            p = p_temp;
            while(p){
                if(strcmp(p->name, sname) == 0)
                    break;
                p = p->next;
            }
            if(p == NULL)
			{
				printf("找不到该学生！本次查询失败\n");
				i++;
				continue;
			}
            printf("该学生信息如下\n");
            printf("| 学号 |   姓名   |年龄|  出生年月日  |         地址         |    电话     |       E-mail       |  班级  |性别|学分绩点|\n");
            printf("| %d |%8s  | %d ", p->num, p->name, p->age);
            printf("|%6d/%02d/%02d  | %20s ", p->birth.year, p->birth.month, p->birth.day, p->address);
            printf("| %11s | %18s |  %4s  | %s |  %.2f |\n", p->phonum, p->email, p->clas, p->sex, p->score);
            i++;
        }
        getchar();
        printf("按回车键返回主菜单\n");
        getchar();
        system("CLS");
        break;
    case 3:
    	system("CLS");
    	break;
    default:
        system("CLS");
    }
}


//以下是浏览函数，将学生信息按一定格式打印
void stu_browse(List *L)
{
	if(*L == NULL || (*L)->next == NULL)
	{
		printf("学生信息为空！\n按回车键返回主菜单！\n");
		getchar();
		getchar();
		system("CLS");
		return;
	}

	List p = (*L)->next;
	printf("各学生信息如下\n");
    printf("| 学号 |   姓名   |年龄|  出生年月日  |         地址         |    电话     |       E-mail       |  班级  |性别|学分绩点|\n");
	while(p)
	{
        printf("| %d |%8s  | %d ", p->num, p->name, p->age);
        printf("|%6d/%02d/%02d  | %20s ", p->birth.year, p->birth.month, p->birth.day, p->address);
        printf("| %11s | %18s |  %4s  | %s | %6.2f |\n", p->phonum, p->email, p->clas, p->sex, p->score);
        p = p->next;
	}
	stu_score(L);
	getchar();
	printf("按回车键返回主菜单\n");
	getchar();
	system("CLS");
}
