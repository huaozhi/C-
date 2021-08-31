#include "student.h"
//此源文件里包含需要直接对链表进行修改的函数，如排序函数，修改函数，插入函数，删除函数
extern int studentnum;

//以下是排序函数,输入参数为指针的地址，调用的函数有按学号排序的函数、按成绩排序的函数和找前一个结点的函数
void stu_order(List *L)
{
	if(*L == NULL || (*L)->next == NULL)
	{
		printf("学生信息为空！\n按回车键返回主菜单！\n");
		getchar();
		getchar();
		system("CLS");
		return;
	}
	List find_before(List head, List p);

	void order_num(List *);
	void order_sco(List *);
	int n;
	printf("1-按学号排序\n2-按成绩降序排序\n");
	printf("请选择排序方式：");

    while(scanf("%d", &n))
    {
    	if(n != 1 && n != 2)
    		printf("错误输入，请重新输入\n");
		else
		    break;
	}
	if(n == 1)
	{
		order_num(L);
	}
	else
	{
		order_sco(L);
	}
	getchar();
	printf("已按要求完成排序\n");
	printf("按回车键返回主菜单\n");
	getchar();
	system("CLS");
}

//找到当前结点的前一个结点，需要输入链表头指针和指向当前结点的指针
List find_before(List head, List p)
{
	if(p == NULL || head == NULL)
	    return NULL;
	List p_bef = head;
	while(p_bef)
	{
		if(p_bef->next == p)
			return p_bef;
		else
	    	p_bef = p_bef->next;
	}
	return NULL;
}

//将学生信息按学号由低到高进行排序
void order_num(List *L)
{
	List pHead, pEnd, p, q, q_bef;
	int minnum;
	pHead = pEnd = (List)malloc(sizeof(struct Student));
	pHead->next = NULL;
	while((*L)->next != NULL) //当原链表不是空链表
	{
		minnum = (*L)->next->num; //开始让第一个结点作为暂定的最小学号的结点
		q = p = (*L)->next;      //p用来遍历寻找，q用来标记当前最小学号的结点，并不断更新
		while(p->next != NULL)
		{
			if(p->next->num < minnum)
			{
				minnum = p->next->num;
				q = p->next;
			}
			p = p->next;
		}
		q_bef = find_before(*L, q);

		q_bef->next = q->next;  //将找到的最小学号的结点q从原链表剔除
		pEnd->next = q;      //将 q接到新链表的后面
		q->next = NULL;
		pEnd = q;             //更新新链表的最后一个结点
	}
	(*L)->next = pHead->next;
	free(pHead); //释放多余的结点
}

//将学生信息按成绩降序排序
void order_sco(List *L)  //代码原理于order_num()类似
{
	List pHead, pEnd, p, q, q_bef;
	int maxsco;
	pHead = pEnd = (List)malloc(sizeof(struct Student));
	pHead->next = NULL;
	while((*L)->next != NULL)
	{
		maxsco = (*L)->next->score;
		q = p = (*L)->next;
		while(p->next != NULL)
		{
			if(p->next->score > maxsco)
			{
				maxsco = p->next->score;
				q = p->next;
			}
			p = p->next;
		}
		q_bef = find_before(*L, q);
		q_bef->next = q->next;
		pEnd->next = q;
		q->next = NULL;
		pEnd = q;
	}
	(*L)->next = pHead->next;
	free(pHead);
}

//以下是学生信息的删除函数
void stu_delete(List *L)
{
    if(*L == NULL || (*L)->next == NULL)
	{
		printf("学生信息为空！\n按回车键返回主菜单！\n");
		getchar();
		getchar();
		system("CLS");
		return;
	}
	int n;
	printf("请输入要删除的学生信息个数：");
	scanf("%d", &n);
	while(n > studentnum)
	{
		printf("删除人数超过总人数，请重新输入\n");
		scanf("%d", &n);
	}
	studentnum = studentnum - n;
	while(n--)
	{
		int ns;
		printf("1-输入学号   2-输入姓名  请选择：");
		while(scanf("%d", &ns))
		{
			if(ns == 1 || ns == 2)
			    break;
			else
			    printf("请按要求选择！\n");
		}
		List p, q;
		switch(ns)
		{
			case 1:
			    {}
				int stu_n;
				printf("请输入该学生的学号：");
				scanf("%d", &stu_n);
				p = *L;
				while(p->next)
				{
				    if(p->next->num == stu_n)
					    break;
					p = p->next;
				}
				if(p->next == NULL)
				{
					printf("未找到该学生！\n");
					break;
				}
				q = p->next;  //q指向该学生结点，p指向q的前一个学生结点
				p->next = q->next;
				free(q);
				break;
			case 2:
			    {}
				char stu_na[20];
			    printf("请输入该学生的姓名：");
				scanf("%s", stu_na);
				List p = *L;
				while(p->next)
				{
					if(strcmp(stu_na, p->next->name) == 0)
					    break;
					p = p->next;
				}
				if(p->next == NULL)
				{
					printf("未找到该学生！\n");
					break;
				}
				List q = p->next;
				p->next = q->next;
				free(q);
				break;
		}

	}
	getchar();
    printf("删除完毕，按回车键返回主菜单\n");
    getchar();
    system("CLS");
}

//以下是学生信息修改函数，由于需要对学生信息进行更新，调用了进行容错判断的函数
void stu_change(List *L)
{
	if(*L == NULL || (*L)->next == NULL)
	{
		printf("学生信息为空！\n按回车键返回主菜单！\n");
		getchar();
		getchar();
		system("CLS");
		return;
	}
	char na[20];
	int n1;
	printf("请输入要修改信息的学生的个数：");
	scanf("%d", &n1);
	while(n1 > studentnum)
	{
		printf("修改人数超过总人数，请重新输入\n");
		scanf("%d", &n1);
	}
	int temp = n1;
	system("CLS");
	while(n1--)
	{
	    printf("请输入要改变信息的第%d个学生的姓名：", temp-n1);
        scanf("%s", na);
	    List p = (*L)->next;
    	while(p)
    	{
	    	if(strcmp(na, p->name) == 0)
		    	break;
	       	p = p->next;
    	}
    	if(!p)
    	{
    		printf("未找到该学生！\n");
    	}
    	else
    	{
    	    printf("请对该学生的信息进行更新：\n");
    	    judge(p);

    	}
	}
	getchar();
	printf("信息全部修改完毕，按任意键返回主菜单\n");
	getchar();
	system("CLS");
}

//以下是学生信息增加函数，由于需要输入学生信息，调用了进行容错判断的函数
void stu_insert(List *L)
{
	if(*L == NULL || (*L)->next == NULL)
	{
		printf("学生信息为空！\n按回车键返回主菜单！\n");
		getchar();
		getchar();
		system("CLS");
		return;
	}
	int n;
	printf("输入需要增加的学生信息个数：");
	scanf("%d", &n);
	studentnum = studentnum + n;
	while(n--)
	{
		List p_new = (List)malloc(sizeof(struct Student));
		judge(p_new);

		p_new->next = (*L)->next;
		(*L)->next = p_new;
		system("CLS");
	}
	getchar();
	printf("学生信息插入成功\n");
	printf("按回车键键返回\n");
	getchar();
	system("CLS");
}

//判断用户输入是否合乎规范的函数，输入参数应为指向结构体变量的指针，是指针变量
void judge(struct Student *p)
{
    do{
        printf("输入学生学号：");//不能输入字母
        scanf("%d",&p->num);
        if(p->num - 10000 > 0 || p->num - 1000 < 0)
            printf("输入不合规范！学号必须为四位数字！\n");
    }while(p->num - 10000 > 0 || p->num - 1000 < 0);
    do{
        printf("输入学生姓名：");
        scanf("%s", p->name);
        if(strlen(p->name) > 8)
            printf("输入姓名过长！请重新输入！\n");
    }while(strlen(p->name) > 8);
    do{
        printf("输入学生年龄：");
        scanf("%d", &p->age);
        if(p->age - 100 > 0 || p->age -10 < 0)
            printf("输入不合规范！年龄必须为两位数！\n");
    }while(p->age - 100 > 0 || p->age -10 < 0);
    while(1){
        printf("输入学生生日(YYYY/MM/DD):");
        scanf("%d/%d/%d",&p->birth.year,&p->birth.month,&p->birth.day);
        if(p->birth.year < 1000 || p->birth.year > 10000 || p->birth.month > 12 || p->birth.year < 1 || p->birth.day > 31 || p->birth.day < 1)
            printf("输入有误！请仔细检查后重新输入\n");
        else
            break;
    }
    do{
        printf("输入学生地址：");
        scanf("%s",p->address);
        if(strlen(p->address) > 20)
            printf("输入地址过长！请重新输入！\n");
    }while(strlen(p->address) > 20);
    do{
        printf("输入学生电话：");
        scanf("%s",p->phonum);
        if(strlen(p->phonum) > 11)
            printf("输入电话号码不合规范！请重新输入！\n");
    }while(strlen(p->phonum) > 11);
    do{
        printf("输入学生邮箱：");
        scanf("%s",p->email);
        if(strlen(p->email) > 17)
            printf("输入邮箱过长！请重新输入！\n");
    }while(strlen(p->email) > 17);
    do{
        printf("输入学生班级：");
        scanf("%s",p->clas);
        if(strlen(p->clas) > 4)
            printf("输入班级不合规范！请重新输入！\n");
    }while(strlen(p->clas) > 4);
    do{
        printf("输入学生性别：");
        scanf("%s",p->sex);
        if(strcmp(p->sex, "男") != 0 && strcmp(p->sex,"女")!= 0)
            printf("输入不合规范！只能输入男女\n");
    }while(strcmp(p->sex, "男") != 0 && strcmp(p->sex,"女")!= 0);
    do{
        printf("输入学生平均学分绩点：");
        scanf("%f",&p->score);
        if(p->score < 0 || p->score > 100)
            printf("输入不合规范！请输入在0~100之间的数字\n");
    }while(p->score < 0 || p->score > 100);
}
