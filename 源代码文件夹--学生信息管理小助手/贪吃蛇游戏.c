#include "̰������Ϸ.h"
#define HEIGHT 26
#define WEIGHT 78

int f = 0;
int eatsscore = 0;//��ҵ÷�
int d = 2;
int eatingsnake()
{
    int i;
    i=firstshow();
    if(!i)
    {
        system("cls");
        printf("                ̰������Ϸ����\n");
        printf("1.�����̵ķ���������ߵ��ƶ���ʹ�߳Ե�Բ����״��ʳ��\n");
        printf("2.�����̵Ŀո�������ߵ�ͣ�٣�ʹ�߿���ͣ�ٺ��ƶ�\n");
        printf("3.�Ե�һ��ʳ���100�֣�������������\n");
        printf("4.ײ��ǽ�ڣ����߳Ե���������Ϸ��������\n");
        printf("5.��Ϸ�����󣬻�����ܵ÷֣������λس��ص��˵�\n");
        getch();
    }
    else
    {
        system("cls");
        return 0;
    }

    system("cls");

    inticialm();
    while(1)
    {
        Sleep(eats.speed);
        smove();
        showfood();
        if(gameover())
        {
            system("cls");
            gotoxy(WEIGHT/2+1,HEIGHT/2);
            printf("��Ϸ����!��ӭ�´�������");
            gotoxy(WEIGHT/2+1,HEIGHT/2+2);
            printf("����ܷ֣�%d��",eatsscore);
            getch();
            break;
        }
    }
    getch();
    system("cls");
    return 0;
}

void setcolor(unsigned short r, unsigned short s)//rǰɫ��s����ɫ
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, r + s * 0x10);
}
void inticialm()
{
    int i;
    gotoxy(0,0);
    HideCursor();

    for(i=0;i<=WEIGHT;i+=2)
    {
        setcolor(6,0);
        gotoxy(i,0);
        printf("��");
        gotoxy(i,HEIGHT);
        printf("��");
    }

    for(i=1;i<HEIGHT;i++)
    {
        setcolor(6,0);
        gotoxy(0,i);
        printf("��");
        gotoxy(WEIGHT,i);
        printf("��");
    }

    while(1)
    {
        srand((unsigned)time(NULL));
        FOOD.x=rand()%(WEIGHT-4)+2;
        FOOD.y=rand()%(HEIGHT-2)+1;//�ڿ�����������Ǹ�һ��������꣬�������õ�

        if(FOOD.x%2 == 0)
            break;
    }
    setcolor(4,0);
    gotoxy(FOOD.x,FOOD.y);
    printf("��");
    eats.length = 3;//��De��
    eats.speed=350;  //���ƶ��ٶ�
    eats.x[0]=WEIGHT/2+1; //��ͷ������ҪΪż��
    eats.y[0]=HEIGHT/2;    //��ͷ������
    setcolor(9, 0);  //�趨��ӡ��ɫΪ�����ֺڵ�

    gotoxy(eats.x[0], eats.y[0]);
    printf("��");
    for(i=1;i<eats.length;i++)
    {
        eats.x[i]=eats.x[i-1]+2;
        eats.y[i]=eats.y[i-1];
        gotoxy(eats.x[i],eats.y[i]);
        printf("��");  //��ӡ����
    }
    setcolor(7,0);

    return;
}

void smove()
{
    int k,i;
    if(kbhit())
    {
        k=getch();
        if(k==224)//��Ӧ������
        {
            k=getch();
            if(k==72&&d!=2)
                d=1;  //72Ϊ���Ϸ����
            if(k==80&&d!=1)
                d=2;  //80Ϊ����
            if(k==75&&d!=4)
                d=3;  //75Ϊ����
            if(k==77&&d!=3)
                d=4;  //77Ϊ����
        }
        if(k==32)
        {
            while(1)
                if((k=getch( ))==32)
                    break;
        }
    }
    if(f==0)
    {
        gotoxy(eats.x[eats.length-1],eats.y[eats.length-1]);
        printf("  ");
    }
    for(i = eats.length - 1; i > 0; i--)  //����β��ÿ�ڴ洢ǰһ������ֵ����ͷ���⣩
    {
        eats.x[i]=eats.x[i-1];
        eats.y[i]=eats.y[i-1];
    }
    switch(d)
    {
        case 1: eats.y[0]-=1; break;   //d=1�����ƶ�
        case 2: eats.y[0]+=1; break;   //d=2�����ƶ�
        case 3: eats.x[0]-=2; break;   //d=3�����ƶ�
        case 4: eats.x[0]+=2; break;   //d=4�����ƶ�
    }
    setcolor(9, 0);
    gotoxy(eats.x[0], eats.y[0]);
    printf("��");
    if(eats.x[0] == FOOD.x && eats.y[0] == FOOD.y)  //��Ե�ʳ����ִ�����²���
    {
        printf("\007");//\007����
        eats.length++;
        eatsscore += 100;
        eats.speed -= 5;
        f = 1;
    }
    else
        f = 0;  //û�Ե�ʳ��Flag��ֵΪ0

    if(eats.speed<150)
        eats.speed += 5;  //�����룬�����ٶ����޼ӿ�
}

void showfood()
{
    if(f == 1)  //��Ե�ʳ���ִ�����²�����������һ��ʳ��
    {
        while (1)
        {
            int i,n= 1;
            srand((unsigned)time(NULL));       //���������������srand( ),���²���ʳ������ֵ
            FOOD.x = rand()%(WEIGHT - 4) + 2;  //��������Ϸ��Χ�ڵ�һ��x����ֵ
            FOOD.y = rand()%(HEIGHT - 2) + 1;  //��������Ϸ��Χ�ڵ�һ��y����ֵ
            for(i = 0; i < eats.length; i++)   //������ɵ�ʳ�ﲻ�����ߵ�������
            {
                if(FOOD.x == eats.x[i] &&FOOD.y == eats.y[i])
                {
                    n = 0;
                    break;
                }
            }
            if (n && FOOD.x%2 == 0)
                break;                          //n��Ϊ0�Һ�����Ϊż������ʳ������ȡֵ�ɹ�

         }

        setcolor(12, 0);

        gotoxy(FOOD.x,FOOD.y); printf("��");  //��굽ȡ�õ����괦��ӡʳ��
    }

    return;
}

int gameover()              //�ж���Ϸ�Ƿ����
{
    int  i;
    setcolor(7, 0);
    gotoxy(2,HEIGHT+1);
    printf("��ͣ����space.");  //���´�ӡһЩ������Ϣ
    gotoxy(2,HEIGHT+2);
    printf("��Ϸ�÷֣�%d",eatsscore);
    if (eats.x[0] == 0 || eats.x[0] == WEIGHT)
        return 1;  //��ͷ�������ұ߽�
    if (eats.y[0] == 0 || eats.y[0] == HEIGHT)
        return 1;  //��ͷ�������±߽�

    for (i = 1; i < eats.length; i++)
    {
        if (eats.x[0] == eats.x[i] && eats.y[0] == eats.y[i])
            return 1;
    } //�߳Ե�����
    return 0;  //û�����߽缰����ʱ�ͷ���0
}
int firstshow()
{
    int i;
    printf("********************************************\n");
    printf("***********��ӭ����̰���ߵ�����*************\n");
    printf("**********׼����ӭ�������ս����************\n");
    printf("********************************************\n\n");

    printf("*******0--�ǵģ�������������ӭ����ս*************\n");
    printf("*******1--û�У��һ�Ҫ��׼����ȥӦս*************\n");
    printf("������:");

    scanf("%d",&i);

    return i;
}
