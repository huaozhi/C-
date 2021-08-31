#include "student.h"
//��Դ�ļ��������Ҫֱ�Ӷ���������޸ĵĺ����������������޸ĺ��������뺯����ɾ������
extern int studentnum;

//������������,�������Ϊָ��ĵ�ַ�����õĺ����а�ѧ������ĺ��������ɼ�����ĺ�������ǰһ�����ĺ���
void stu_order(List *L)
{
	if(*L == NULL || (*L)->next == NULL)
	{
		printf("ѧ����ϢΪ�գ�\n���س����������˵���\n");
		getchar();
		getchar();
		system("CLS");
		return;
	}
	List find_before(List head, List p);

	void order_num(List *);
	void order_sco(List *);
	int n;
	printf("1-��ѧ������\n2-���ɼ���������\n");
	printf("��ѡ������ʽ��");

    while(scanf("%d", &n))
    {
    	if(n != 1 && n != 2)
    		printf("�������룬����������\n");
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
	printf("�Ѱ�Ҫ���������\n");
	printf("���س����������˵�\n");
	getchar();
	system("CLS");
}

//�ҵ���ǰ����ǰһ����㣬��Ҫ��������ͷָ���ָ��ǰ����ָ��
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

//��ѧ����Ϣ��ѧ���ɵ͵��߽�������
void order_num(List *L)
{
	List pHead, pEnd, p, q, q_bef;
	int minnum;
	pHead = pEnd = (List)malloc(sizeof(struct Student));
	pHead->next = NULL;
	while((*L)->next != NULL) //��ԭ�����ǿ�����
	{
		minnum = (*L)->next->num; //��ʼ�õ�һ�������Ϊ�ݶ�����Сѧ�ŵĽ��
		q = p = (*L)->next;      //p��������Ѱ�ң�q������ǵ�ǰ��Сѧ�ŵĽ�㣬�����ϸ���
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

		q_bef->next = q->next;  //���ҵ�����Сѧ�ŵĽ��q��ԭ�����޳�
		pEnd->next = q;      //�� q�ӵ�������ĺ���
		q->next = NULL;
		pEnd = q;             //��������������һ�����
	}
	(*L)->next = pHead->next;
	free(pHead); //�ͷŶ���Ľ��
}

//��ѧ����Ϣ���ɼ���������
void order_sco(List *L)  //����ԭ����order_num()����
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

//������ѧ����Ϣ��ɾ������
void stu_delete(List *L)
{
    if(*L == NULL || (*L)->next == NULL)
	{
		printf("ѧ����ϢΪ�գ�\n���س����������˵���\n");
		getchar();
		getchar();
		system("CLS");
		return;
	}
	int n;
	printf("������Ҫɾ����ѧ����Ϣ������");
	scanf("%d", &n);
	while(n > studentnum)
	{
		printf("ɾ����������������������������\n");
		scanf("%d", &n);
	}
	studentnum = studentnum - n;
	while(n--)
	{
		int ns;
		printf("1-����ѧ��   2-��������  ��ѡ��");
		while(scanf("%d", &ns))
		{
			if(ns == 1 || ns == 2)
			    break;
			else
			    printf("�밴Ҫ��ѡ��\n");
		}
		List p, q;
		switch(ns)
		{
			case 1:
			    {}
				int stu_n;
				printf("�������ѧ����ѧ�ţ�");
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
					printf("δ�ҵ���ѧ����\n");
					break;
				}
				q = p->next;  //qָ���ѧ����㣬pָ��q��ǰһ��ѧ�����
				p->next = q->next;
				free(q);
				break;
			case 2:
			    {}
				char stu_na[20];
			    printf("�������ѧ����������");
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
					printf("δ�ҵ���ѧ����\n");
					break;
				}
				List q = p->next;
				p->next = q->next;
				free(q);
				break;
		}

	}
	getchar();
    printf("ɾ����ϣ����س����������˵�\n");
    getchar();
    system("CLS");
}

//������ѧ����Ϣ�޸ĺ�����������Ҫ��ѧ����Ϣ���и��£������˽����ݴ��жϵĺ���
void stu_change(List *L)
{
	if(*L == NULL || (*L)->next == NULL)
	{
		printf("ѧ����ϢΪ�գ�\n���س����������˵���\n");
		getchar();
		getchar();
		system("CLS");
		return;
	}
	char na[20];
	int n1;
	printf("������Ҫ�޸���Ϣ��ѧ���ĸ�����");
	scanf("%d", &n1);
	while(n1 > studentnum)
	{
		printf("�޸���������������������������\n");
		scanf("%d", &n1);
	}
	int temp = n1;
	system("CLS");
	while(n1--)
	{
	    printf("������Ҫ�ı���Ϣ�ĵ�%d��ѧ����������", temp-n1);
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
    		printf("δ�ҵ���ѧ����\n");
    	}
    	else
    	{
    	    printf("��Ը�ѧ������Ϣ���и��£�\n");
    	    judge(p);

    	}
	}
	getchar();
	printf("��Ϣȫ���޸���ϣ���������������˵�\n");
	getchar();
	system("CLS");
}

//������ѧ����Ϣ���Ӻ�����������Ҫ����ѧ����Ϣ�������˽����ݴ��жϵĺ���
void stu_insert(List *L)
{
	if(*L == NULL || (*L)->next == NULL)
	{
		printf("ѧ����ϢΪ�գ�\n���س����������˵���\n");
		getchar();
		getchar();
		system("CLS");
		return;
	}
	int n;
	printf("������Ҫ���ӵ�ѧ����Ϣ������");
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
	printf("ѧ����Ϣ����ɹ�\n");
	printf("���س���������\n");
	getchar();
	system("CLS");
}

//�ж��û������Ƿ�Ϻ��淶�ĺ������������ӦΪָ��ṹ�������ָ�룬��ָ�����
void judge(struct Student *p)
{
    do{
        printf("����ѧ��ѧ�ţ�");//����������ĸ
        scanf("%d",&p->num);
        if(p->num - 10000 > 0 || p->num - 1000 < 0)
            printf("���벻�Ϲ淶��ѧ�ű���Ϊ��λ���֣�\n");
    }while(p->num - 10000 > 0 || p->num - 1000 < 0);
    do{
        printf("����ѧ��������");
        scanf("%s", p->name);
        if(strlen(p->name) > 8)
            printf("�����������������������룡\n");
    }while(strlen(p->name) > 8);
    do{
        printf("����ѧ�����䣺");
        scanf("%d", &p->age);
        if(p->age - 100 > 0 || p->age -10 < 0)
            printf("���벻�Ϲ淶���������Ϊ��λ����\n");
    }while(p->age - 100 > 0 || p->age -10 < 0);
    while(1){
        printf("����ѧ������(YYYY/MM/DD):");
        scanf("%d/%d/%d",&p->birth.year,&p->birth.month,&p->birth.day);
        if(p->birth.year < 1000 || p->birth.year > 10000 || p->birth.month > 12 || p->birth.year < 1 || p->birth.day > 31 || p->birth.day < 1)
            printf("������������ϸ������������\n");
        else
            break;
    }
    do{
        printf("����ѧ����ַ��");
        scanf("%s",p->address);
        if(strlen(p->address) > 20)
            printf("�����ַ���������������룡\n");
    }while(strlen(p->address) > 20);
    do{
        printf("����ѧ���绰��");
        scanf("%s",p->phonum);
        if(strlen(p->phonum) > 11)
            printf("����绰���벻�Ϲ淶�����������룡\n");
    }while(strlen(p->phonum) > 11);
    do{
        printf("����ѧ�����䣺");
        scanf("%s",p->email);
        if(strlen(p->email) > 17)
            printf("����������������������룡\n");
    }while(strlen(p->email) > 17);
    do{
        printf("����ѧ���༶��");
        scanf("%s",p->clas);
        if(strlen(p->clas) > 4)
            printf("����༶���Ϲ淶�����������룡\n");
    }while(strlen(p->clas) > 4);
    do{
        printf("����ѧ���Ա�");
        scanf("%s",p->sex);
        if(strcmp(p->sex, "��") != 0 && strcmp(p->sex,"Ů")!= 0)
            printf("���벻�Ϲ淶��ֻ��������Ů\n");
    }while(strcmp(p->sex, "��") != 0 && strcmp(p->sex,"Ů")!= 0);
    do{
        printf("����ѧ��ƽ��ѧ�ּ��㣺");
        scanf("%f",&p->score);
        if(p->score < 0 || p->score > 100)
            printf("���벻�Ϲ淶����������0~100֮�������\n");
    }while(p->score < 0 || p->score > 100);
}
