#include "student.h"
//��Դ�ļ�������������������޸ĵĺ�������˵���������ѯ���������������
extern int studentnum;

//�˵�����
char mennu()
{
    time_now();
	printf("**********ѧ����Ϣ����ϵͳ**********\n");
	printf("*       ��ǰϵͳ���� %d ��ѧ��      *\n", studentnum);
	printf("*                                  *\n");
	printf("*           0-ѧ����Ϣ���ļ�����   *\n");
	printf("*           1-ѧ����Ϣ¼��         *\n");
	printf("*           2-ѧ����Ϣ��ѯ         *\n");
	printf("*           3-ѧ����Ϣ���         *\n");
	printf("*           4-ѧ����Ϣ����         *\n");
	printf("*           5-ѧ����Ϣ��ɾ��       *\n");
	printf("*           6-ѧ����Ϣ���޸�       *\n");
	printf("*           7-ѧ����Ϣ������       *\n");
	printf("*           8-�˳�ϵͳ             *\n");
	printf("*           9-ˢ�µ�ǰҳ��         *\n");
	printf("*           @-�ɻ���ս��Ϸ         *\n");
	printf("*           #-��������Ϸ           *\n");
	printf("*           &-̰������Ϸ           *\n");
	printf("************************************\n");
	printf("��������Ҫ���еĲ�����Ӧ�ı�ţ�");
	char n[10];
    int lens = 0;

	while(1)
    {
        gets(n);
        lens = strlen(n);
        if(lens > 1)
            printf("�밴Ҫ������!\n");
        else{
            if(isdigit(n[0]) || n[0] == '&' || n[0] == '#' || n[0] == '@')
                break;
            else
                printf("�밴Ҫ������!\n");
        }
    }
	system("CLS");
	return n[0];

}

//��������ʾϵͳ��ǰʱ��ĺ��������ӡ����ǰʱ��������ա�ʱ����
void time_now()
{
    time_t t;
    struct tm* ltime;
    time (&t);//��ȡUnixʱ���
    ltime = localtime (&t);//תΪʱ��ṹ��
    printf ( "*********%d/%02d/%02d %02d:%02d:%02d********\n",ltime->tm_year+1900, ltime->tm_mon+1, ltime->tm_mday,
            ltime->tm_hour, ltime->tm_min, ltime->tm_sec);//������
}


//ͳ�Ʋ�����ѧ��������ѧ��ƽ���֣�����Ƿ��в������ѧ������������ʾ����
void stu_score(List *L)
{
	List q = (*L)->next;
	int count = 0;//����ͳ�Ʋ���������
	int stucou = 0;//��ʾѧ������
	double score_sum;//��ʾѧ���ɼ��ܺ�
	double score_ave = 0;//��ʾƽ���ɼ�
	while(q != NULL)
    {
        score_sum += q->score;//ѧ���ܳɼ�
        stucou++;//ѧ������
        if(q->score - 60 < 0)
            count++;
        q = q->next;
    }
    score_ave = score_sum/stucou;
    printf("ƽ����Ϊ%.2f", score_ave);
    if(count == 0)
        printf("��ȫ������\n\n");
    else
        printf("��������%d��\n\n", count);
}

//�����ǲ�ѯ�������ṩ���ֲ�ѯ��ʽ����ӡѧ����Ϣ
void stu_seek(List *L)
{
	if(*L == NULL || (*L)->next == NULL)
	{
		printf("ѧ����ϢΪ�գ�\n���س����������˵�!\n");
		getchar();
		getchar();
		system("CLS");
		return;
	}
    printf("*************��ѡ���ѯ��ʽ*************\n");
    printf("************1.��ѧ��ѧ�Ų�ѯ************\n");
    printf("************2.��ѧ��������ѯ************\n");
    printf("************3.�������˵�****************\n");
    printf("----------------------------------------\n");
    int ennum, n, i = 1;//��ʾ��������ֺ�Ҫ��ѯ��ѧ������&�����õı���i
    while(scanf("%d", &ennum))
    {
    	if(ennum >= 1 && ennum <= 3)
    	    break;
    	else
    	    printf("�밴Ҫ�����룡\n");
	}

    List p = (*L)->next;  //�Ӵ�ĵ�һ��ѧ����Ϣ��ʼ
    List p_temp = p;
    char sname[20];
    int snum;    //��ʾ�����ѧ��ѧ��

    switch(ennum)
    {
    case 1:
        printf("������Ҫ��ѯ��ѧ����:");
        scanf("%d", &n);
        while(i <= n)
        {
            printf("������Ҫ��ѯ�ĵ�%d��ѧ����ѧ��:", i);
            scanf("%d", &snum);
            p = p_temp;
            while(p){
                if(p->num == snum)
                    break;
                p = p->next;
            }
            if(p == NULL)
			{
				printf("�Ҳ�����ѧ�������β�ѯʧ��\n");
				i++;
				continue;
			}
            printf("��ѧ����Ϣ����\n");
            printf("| ѧ�� |   ����   |����|  ����������  |         ��ַ         |    �绰     |       E-mail       |  �༶  |�Ա�|ѧ�ּ���|\n");            printf("| %d |%8s  | %d ", p->num, p->name, p->age);
            printf("|%6d/%02d/%02d  | %20s ", p->birth.year, p->birth.month, p->birth.day, p->address);
            printf("| %11s | %18s |  %4s  | %s |  %.2f |\n", p->phonum, p->email, p->clas, p->sex, p->score);
            i++;
        }
        getchar();
        printf("���س����������˵�\n");
        getchar();
        system("CLS");
        break;
    case 2:
        printf("������Ҫ��ѯ��ѧ����:");
        scanf("%d", &n);
        while(i <= n)
        {
            printf("������Ҫ��ѯ�ĵ�%d��ѧ��������:", i);
            scanf("%s", sname);
            p = p_temp;
            while(p){
                if(strcmp(p->name, sname) == 0)
                    break;
                p = p->next;
            }
            if(p == NULL)
			{
				printf("�Ҳ�����ѧ�������β�ѯʧ��\n");
				i++;
				continue;
			}
            printf("��ѧ����Ϣ����\n");
            printf("| ѧ�� |   ����   |����|  ����������  |         ��ַ         |    �绰     |       E-mail       |  �༶  |�Ա�|ѧ�ּ���|\n");
            printf("| %d |%8s  | %d ", p->num, p->name, p->age);
            printf("|%6d/%02d/%02d  | %20s ", p->birth.year, p->birth.month, p->birth.day, p->address);
            printf("| %11s | %18s |  %4s  | %s |  %.2f |\n", p->phonum, p->email, p->clas, p->sex, p->score);
            i++;
        }
        getchar();
        printf("���س����������˵�\n");
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


//�����������������ѧ����Ϣ��һ����ʽ��ӡ
void stu_browse(List *L)
{
	if(*L == NULL || (*L)->next == NULL)
	{
		printf("ѧ����ϢΪ�գ�\n���س����������˵���\n");
		getchar();
		getchar();
		system("CLS");
		return;
	}

	List p = (*L)->next;
	printf("��ѧ����Ϣ����\n");
    printf("| ѧ�� |   ����   |����|  ����������  |         ��ַ         |    �绰     |       E-mail       |  �༶  |�Ա�|ѧ�ּ���|\n");
	while(p)
	{
        printf("| %d |%8s  | %d ", p->num, p->name, p->age);
        printf("|%6d/%02d/%02d  | %20s ", p->birth.year, p->birth.month, p->birth.day, p->address);
        printf("| %11s | %18s |  %4s  | %s | %6.2f |\n", p->phonum, p->email, p->clas, p->sex, p->score);
        p = p->next;
	}
	stu_score(L);
	getchar();
	printf("���س����������˵�\n");
	getchar();
	system("CLS");
}
