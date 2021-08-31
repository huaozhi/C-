//stufile.c��һԴ�ļ��������Ҫ���ļ����в����ĺ���
#include "student.h"
extern int studentnum;
//��������Ϣ¼�뺯��,���������ļ���
void stu_input(List *L)
{
    printf("��������Ҫ¼����Ϣ��ѧ������");
	int n;
	scanf("%d",&n);
	getchar();
	if(n == 0)
	{
		printf("���β���ȡ����1��󷵻�");
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
    //�Ѿ���ѧ����Ϣ������ṹ��ϵ�������������������ڵ�ѧ����Ϣ�洢���ļ���
	List p1 = *L;
	p1 = p1->next;
	if(p1 == NULL)
	{
		printf("δ������Ϣ��\n���س����ص����˵�\n");
		getchar();
		getchar();
		system("CLS");
		return;
	}
    printf("��Ϣ������ϣ�\n");
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
	printf("����ɹ�~\n");

	getchar();
	printf("��¼������ѧ������Ϣ\n");
	printf("���س����ص����˵�\n");
	getchar();
	system("CLS");
}

//���ļ��е���Ϣ�洢��������
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
    printf("������....���Ժ�");
    getchar();
    printf("ѧ����Ϣ�����룡���س�������");
	getchar();
	system("CLS");

}

//���ļ��ж�ȡѧ����Ϣ�������
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
	printf("����ɹ�~\n");
	printf("�ѽ�����ѧ������Ϣ�����ļ���\n");
}
