#include "贪吃蛇游戏.h"
#define HEIGHT 26
#define WEIGHT 78

int f = 0;
int eatsscore = 0;//玩家得分
int d = 2;
int eatingsnake()
{
    int i;
    i=firstshow();
    if(!i)
    {
        system("cls");
        printf("                贪吃蛇游戏规则\n");
        printf("1.按键盘的方向键控制蛇的移动，使蛇吃到圆点形状的食物\n");
        printf("2.按键盘的空格键控制蛇的停顿，使蛇可以停顿和移动\n");
        printf("3.吃到一个食物加100分，并产生铃响声\n");
        printf("4.撞到墙壁，或者吃到蛇自身游戏都将结束\n");
        printf("5.游戏结束后，会出现总得分，按两次回车回到菜单\n");
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
            printf("游戏结束!欢迎下次再来！");
            gotoxy(WEIGHT/2+1,HEIGHT/2+2);
            printf("玩家总分：%d分",eatsscore);
            getch();
            break;
        }
    }
    getch();
    system("cls");
    return 0;
}

void setcolor(unsigned short r, unsigned short s)//r前色，s背景色
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
        printf("■");
        gotoxy(i,HEIGHT);
        printf("■");
    }

    for(i=1;i<HEIGHT;i++)
    {
        setcolor(6,0);
        gotoxy(0,i);
        printf("■");
        gotoxy(WEIGHT,i);
        printf("■");
    }

    while(1)
    {
        srand((unsigned)time(NULL));
        FOOD.x=rand()%(WEIGHT-4)+2;
        FOOD.y=rand()%(HEIGHT-2)+1;//在框中随机产生那个一个点的坐标，并产生该点

        if(FOOD.x%2 == 0)
            break;
    }
    setcolor(4,0);
    gotoxy(FOOD.x,FOOD.y);
    printf("●");
    eats.length = 3;//蛇De身长
    eats.speed=350;  //蛇移动速度
    eats.x[0]=WEIGHT/2+1; //蛇头横坐标要为偶数
    eats.y[0]=HEIGHT/2;    //蛇头纵坐标
    setcolor(9, 0);  //设定打印颜色为淡蓝字黑底

    gotoxy(eats.x[0], eats.y[0]);
    printf("■");
    for(i=1;i<eats.length;i++)
    {
        eats.x[i]=eats.x[i-1]+2;
        eats.y[i]=eats.y[i-1];
        gotoxy(eats.x[i],eats.y[i]);
        printf("■");  //打印蛇身
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
        if(k==224)//对应→四种
        {
            k=getch();
            if(k==72&&d!=2)
                d=1;  //72为向上方向键
            if(k==80&&d!=1)
                d=2;  //80为向下
            if(k==75&&d!=4)
                d=3;  //75为向左
            if(k==77&&d!=3)
                d=4;  //77为向右
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
    for(i = eats.length - 1; i > 0; i--)  //从蛇尾起每节存储前一节坐标值（蛇头除外）
    {
        eats.x[i]=eats.x[i-1];
        eats.y[i]=eats.y[i-1];
    }
    switch(d)
    {
        case 1: eats.y[0]-=1; break;   //d=1向上移动
        case 2: eats.y[0]+=1; break;   //d=2向下移动
        case 3: eats.x[0]-=2; break;   //d=3向左移动
        case 4: eats.x[0]+=2; break;   //d=4向右移动
    }
    setcolor(9, 0);
    gotoxy(eats.x[0], eats.y[0]);
    printf("■");
    if(eats.x[0] == FOOD.x && eats.y[0] == FOOD.y)  //如吃到食物则执行以下操作
    {
        printf("\007");//\007响铃
        eats.length++;
        eatsscore += 100;
        eats.speed -= 5;
        f = 1;
    }
    else
        f = 0;  //没吃到食物Flag的值为0

    if(eats.speed<150)
        eats.speed += 5;  //作弊码，不让速度无限加快
}

void showfood()
{
    if(f == 1)  //如吃到食物才执行以下操作，生成另一个食物
    {
        while (1)
        {
            int i,n= 1;
            srand((unsigned)time(NULL));       //启动随机数发生器srand( ),接下产生食物坐标值
            FOOD.x = rand()%(WEIGHT - 4) + 2;  //产生在游戏框范围内的一个x坐标值
            FOOD.y = rand()%(HEIGHT - 2) + 1;  //产生在游戏框范围内的一个y坐标值
            for(i = 0; i < eats.length; i++)   //随机生成的食物不能在蛇的身体上
            {
                if(FOOD.x == eats.x[i] &&FOOD.y == eats.y[i])
                {
                    n = 0;
                    break;
                }
            }
            if (n && FOOD.x%2 == 0)
                break;                          //n不为0且横坐标为偶数，则食物坐标取值成功

         }

        setcolor(12, 0);

        gotoxy(FOOD.x,FOOD.y); printf("●");  //光标到取得的坐标处打印食物
    }

    return;
}

int gameover()              //判断游戏是否结束
{
    int  i;
    setcolor(7, 0);
    gotoxy(2,HEIGHT+1);
    printf("暂停键：space.");  //以下打印一些其它信息
    gotoxy(2,HEIGHT+2);
    printf("游戏得分：%d",eatsscore);
    if (eats.x[0] == 0 || eats.x[0] == WEIGHT)
        return 1;  //蛇头触碰左右边界
    if (eats.y[0] == 0 || eats.y[0] == HEIGHT)
        return 1;  //蛇头触碰上下边界

    for (i = 1; i < eats.length; i++)
    {
        if (eats.x[0] == eats.x[i] && eats.y[0] == eats.y[i])
            return 1;
    } //蛇吃到自身
    return 0;  //没碰到边界及自身时就返回0
}
int firstshow()
{
    int i;
    printf("********************************************\n");
    printf("***********欢迎来到贪吃蛇的王国*************\n");
    printf("**********准备好迎接你的挑战了吗************\n");
    printf("********************************************\n\n");

    printf("*******0--是的，我已信心满满迎接挑战*************\n");
    printf("*******1--没有，我还要再准备再去应战*************\n");
    printf("请输入:");

    scanf("%d",&i);

    return i;
}
