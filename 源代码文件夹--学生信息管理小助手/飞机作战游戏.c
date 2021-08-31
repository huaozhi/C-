#include "飞机作战游戏.h"

void gotoxy(int x, int y)  //移动光标
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void color(int n)  //设置文字颜色
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), n);
}

void HideCursor() //隐藏光标
{
	CONSOLE_CURSOR_INFO cursor_info = {1, 0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void p_mennu() //游戏开始前的选择界面
{
	int n;
    gotoxy(37, 10);
	color(1);  //蓝色
	printf("飞 机 作 战");
	color(15); //白色
	gotoxy(17, 20);
	printf("1.开始游戏");
	gotoxy(63, 20);
	printf("2.操作说明");
	color(5);  //紫色
	gotoxy(32, 25);
	printf("请输入你的选择（1~2）：");
	color(7);  //白色
	scanf("%d", &n);
	switch(n)
	{
		case 1:
			system("CLS");
			break;
		case 2:
			system("CLS");
			explanation();
			break;
		default:
			color(12);  //淡红色
			gotoxy(32, 26);
		    printf("请输入正确选择（1~2）！");
		    getch();
		    system("CLS");
		    p_mennu(); //清屏后递归调用mennu()
	}
}
void initial_data() //数据初始化
{
	width = 60;
	high = 30;
	pflag = 0; //飞机未撞毁
	pscore = 0;
	plane_x = 22;  //x指第几行，y第几列，与getxy(x, y)的坐标相反
	plane_y = 30;
	enomy_x = 1;
	enomy_y = 2;
	bullet_x = 0;
	bullet_y = plane_y;
}
void explanation()           //游戏操作说明
{
	int i, j;
	color(6); //黄色
	for(i = 3; i < 27; i++)  //打印周框
	{
		for(j = 15; j < 65; j++)
		{
			gotoxy(j, i);
			if(i == 3 || i == 26 || j == 15 || j == 64)
			{
				printf("=");
			}
		}
	}
	color(15); //亮白色
	gotoxy(36, 3);
	printf("游戏操作说明");
	color(2); //绿色
	gotoxy(25, 8);
	printf("*按W S A D分别控制飞机上下左右移动");
	color(5); //紫色
	gotoxy(25, 13);
	printf("*按空格键可以向上发射炮弹");
	color(1); //蓝色
	gotoxy(25, 18);
	printf("*飞行过程不能与敌机相撞");
	color(13); //淡紫色
	gotoxy(25, 23);
	printf("每次击中敌机得5分，祝您游戏愉快！");
	color(12); //淡红色
	gotoxy(30, 24);
	printf("按任意键键键返回****");
	_getch();
	system("CLS");
	p_mennu();  //递归
}
void show()                   //打印游戏画面
{
	int i, j;

	for(i = 0; i < high; i++)
	{
		for(j = 0; j < width; j++)
		{
			if(i == plane_x && j == plane_y)
			    printf("^");           //飞机
			else if(i == enomy_x && j == enomy_y)
				printf("#");           //敌机
			else if(i == bullet_x && j == bullet_y)
			    printf("|");           //子弹
			else if(i == 0 || i == high-1 || j == 0 || j == width-1)
			    printf("=");           //上下边界
			else
			    printf(" ");
		}
		printf("\n");
	}

	color(1);
	printf("WSAD移动飞机，空格发射~");  //在作战区域下侧打印战绩
	color(11);
	printf("祝您游戏愉快！");
	gotoxy(65, 8);
	color(1);
	printf("战 绩");
	gotoxy(62, 10);
	color(3);
	printf("击中敌机数为%d", pscore);  //在作战区域下侧打印战绩
	color(12);
	gotoxy(62, 12);
	printf("总得分：%d", pscore*5);
}



void without_input()   //没有键盘输入是对子弹和敌机位置的更新，以及检测飞机是否撞毁
{
	if(bullet_x > 0)
	    bullet_x--;  //让子弹向上射击
	static int speed;  //声明静态变量speed = 0， 使得敌机运行速度是子弹和飞机的1/20
	if(speed < 20)
	    speed++;
	else
	{
		if(enomy_x < high-1)
		    enomy_x++;
		else
		{
			enomy_y = rand()%(width-2)+1;
			enomy_x = 0;
		}
		speed = 0;
	}
	if(bullet_x == enomy_x && bullet_y == enomy_y)  //子弹击中敌机
	{
		pscore++;
		bullet_x = -1;
		bullet_y = plane_y;
		enomy_x = 1;
		enomy_y = rand()%(width-2)+1;
	}
	if(plane_x == enomy_x && plane_y == enomy_y)
	    pflag = 1;   //飞机挂了
}


void with_input()      //有键盘输入时对飞机位置和子弹位置的更新
{
    char c = getch();
    switch(c)
    {
    	case 'w':
    		if(plane_x > 1)
    		    plane_x--;
    	    break;
    	case 's':
    		if(plane_x < high-2)
    		    plane_x++;
    	    break;
    	case 'a':
    		if(plane_y > 1)
    		    plane_y--;
    		break;
    	case 'd':
    		if(plane_y < width-2)
    		    plane_y++;
    		break;
    	case ' ':
    		bullet_x = plane_x-1;
    		bullet_y = plane_y;
    		break;
    	default:
    		break;
	}
}
void plane_game()
{
	system("mode con cols=80 lines=32");            //设置控制台的宽高
	SetConsoleTitle("飞机作战游戏");                //设置窗口标题
	p_mennu();                                       //开始时的菜单
	initial_data();                                //初始化坐标数据等
	HideCursor();                                  //隐藏光标

	while(1)
	{
		gotoxy(0,0);
		show();
		if(pflag) //飞机撞毁
		{
			system("CLS");
			printf("游戏结束!\n最后得分：%d", pscore*5);
			break;  //跳出循环
		}
		without_input();  //没有输入时的更新，包括子弹飞行和敌机游走
		if(kbhit())       //如果有键盘输入
		{
			with_input();
		}
	}
	Sleep(1000);
	system("CLS");
	color(15);
	return ;
}
