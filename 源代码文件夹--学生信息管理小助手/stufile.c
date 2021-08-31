//stufile.c这一源文件里包括需要对文件进行操作的函数
#include "student.h"
extern int studentnum;
//以下是信息录入函数,并保存在文件里
void stu_input(List *L)
{
    printf("请输入需要录入信息的学生数：");
	int n;
	scanf("%d",&n);
	getchar();
	if(n == 0)
	{
		printf("本次操作取消，1秒后返回");
		Sleep(1000);
	    system("CLS");
		return;
	}
	List q = *L = (List)malloc(sizeof(struct Student));
	q->next = NULL;

	studentnum = n;
	while(n--)
	{
		List p = (List)malloc(sizeof(struct Student));
		p->next = NULL;
		judge(p);
		q->next = p;
		q = p;
		system("CLS");
	}
    //已经将学生信息以链表结构联系起来，接下来将链表内的学生信息存储到文件中
	List p1 = *L;
	p1 = p1->next;
	if(p1 == NULL)
	{
		printf("未输入信息！\n按回车键回到主菜单\n");
		getchar();
		getchar();
		system("CLS");
		return;
	}
    printf("信息输入完毕！\n");
	FILE *fp;

	if((fp = fopen("stu.txt", "w+")) == NULL)
	{
		printf("Can not open this file!\n");
		exit(1);
	}
	while(p1)
	{
		fwrite(p1, sizeof(Student), 1, fp);
		p1 = p1->next;
	}
	fclose(fp);
	printf("保存成功~\n");

	getchar();
	printf("已录入所有学生的信息\n");
	printf("按回车键回到主菜单\n");
	getchar();
	system("CLS");
}

//将文件中的信息存储在链表里
void readfile(List *L)
{
    List p, q;
    studentnum = 0;
    struct Student studen;
    List head = *L = (List)malloc(sizeof(struct Student));
    if(head != NULL)
        head->next = NULL;
    p = q = head;

    FILE *fp;
    if((fp = fopen("stu.txt", "r")) == NULL)
	{
		printf("Cant open this file!\n");
        exit(0);
	}
     while(!feof(fp))
    {
    	q = p;
    	fread(&studen, sizeof(struct Student), 1, fp);
        p = (List)malloc(sizeof(struct Student));
        p->num = studen.num;
        p->age = studen.age;
        p->birth= studen.birth;
        p->score = studen.score;
        strcpy(p->name, studen.name);
        strcpy(p->address, studen.address);
        strcpy(p->phonum, studen.phonum);
        strcpy(p->email, studen.email);
        strcpy(p->clas, studen.clas);
        strcpy(p->sex, studen.sex);
        q->next = p;
        studentnum++;
	}
	studentnum--;
	free(p);
	q->next = NULL;
    fclose(fp);
    printf("操作中....请稍后");
    getchar();
    printf("学生信息已载入！按回车键返回");
	getchar();
	system("CLS");

}

//从文件中读取学生信息组成链表
void save_into_file(List L)
{
	List p0;
	FILE *fp;
	if((fp = fopen("stu.txt", "w+")) == NULL)
	{
		printf("Can not open this file!\n");
		exit(1);
	}
	if(L == NULL || L->next == NULL)
	{
		fclose(fp);
		return;
	}

	p0 = L->next;
	while(p0)
	{
		fwrite(p0, sizeof(Student), 1, fp);
		p0 = p0->next;
	}
	fclose(fp);
	printf("保存成功~\n");
	printf("已将所有学生的信息存入文件中\n");
}
