#include "�ɻ���ս��Ϸ.h"

void gotoxy(int x, int y)  //�ƶ����
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void color(int n)  //����������ɫ
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), n);
}

void HideCursor() //���ع��
{
	CONSOLE_CURSOR_INFO cursor_info = {1, 0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void p_mennu() //��Ϸ��ʼǰ��ѡ�����
{
	int n;
    gotoxy(37, 10);
	color(1);  //��ɫ
	printf("�� �� �� ս");
	color(15); //��ɫ
	gotoxy(17, 20);
	printf("1.��ʼ��Ϸ");
	gotoxy(63, 20);
	printf("2.����˵��");
	color(5);  //��ɫ
	gotoxy(32, 25);
	printf("���������ѡ��1~2����");
	color(7);  //��ɫ
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
			color(12);  //����ɫ
			gotoxy(32, 26);
		    printf("��������ȷѡ��1~2����");
		    getch();
		    system("CLS");
		    p_mennu(); //������ݹ����mennu()
	}
}
void initial_data() //���ݳ�ʼ��
{
	width = 60;
	high = 30;
	pflag = 0; //�ɻ�δײ��
	pscore = 0;
	plane_x = 22;  //xָ�ڼ��У�y�ڼ��У���getxy(x, y)�������෴
	plane_y = 30;
	enomy_x = 1;
	enomy_y = 2;
	bullet_x = 0;
	bullet_y = plane_y;
}
void explanation()           //��Ϸ����˵��
{
	int i, j;
	color(6); //��ɫ
	for(i = 3; i < 27; i++)  //��ӡ�ܿ�
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
	color(15); //����ɫ
	gotoxy(36, 3);
	printf("��Ϸ����˵��");
	color(2); //��ɫ
	gotoxy(25, 8);
	printf("*��W S A D�ֱ���Ʒɻ����������ƶ�");
	color(5); //��ɫ
	gotoxy(25, 13);
	printf("*���ո���������Ϸ����ڵ�");
	color(1); //��ɫ
	gotoxy(25, 18);
	printf("*���й��̲�����л���ײ");
	color(13); //����ɫ
	gotoxy(25, 23);
	printf("ÿ�λ��ел���5�֣�ף����Ϸ��죡");
	color(12); //����ɫ
	gotoxy(30, 24);
	printf("���������������****");
	_getch();
	system("CLS");
	p_mennu();  //�ݹ�
}
void show()                   //��ӡ��Ϸ����
{
	int i, j;

	for(i = 0; i < high; i++)
	{
		for(j = 0; j < width; j++)
		{
			if(i == plane_x && j == plane_y)
			    printf("^");           //�ɻ�
			else if(i == enomy_x && j == enomy_y)
				printf("#");           //�л�
			else if(i == bullet_x && j == bullet_y)
			    printf("|");           //�ӵ�
			else if(i == 0 || i == high-1 || j == 0 || j == width-1)
			    printf("=");           //���±߽�
			else
			    printf(" ");
		}
		printf("\n");
	}

	color(1);
	printf("WSAD�ƶ��ɻ����ո���~");  //����ս�����²��ӡս��
	color(11);
	printf("ף����Ϸ��죡");
	gotoxy(65, 8);
	color(1);
	printf("ս ��");
	gotoxy(62, 10);
	color(3);
	printf("���ел���Ϊ%d", pscore);  //����ս�����²��ӡս��
	color(12);
	gotoxy(62, 12);
	printf("�ܵ÷֣�%d", pscore*5);
}



void without_input()   //û�м��������Ƕ��ӵ��͵л�λ�õĸ��£��Լ����ɻ��Ƿ�ײ��
{
	if(bullet_x > 0)
	    bullet_x--;  //���ӵ��������
	static int speed;  //������̬����speed = 0�� ʹ�õл������ٶ����ӵ��ͷɻ���1/20
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
	if(bullet_x == enomy_x && bullet_y == enomy_y)  //�ӵ����ел�
	{
		pscore++;
		bullet_x = -1;
		bullet_y = plane_y;
		enomy_x = 1;
		enomy_y = rand()%(width-2)+1;
	}
	if(plane_x == enomy_x && plane_y == enomy_y)
	    pflag = 1;   //�ɻ�����
}


void with_input()      //�м�������ʱ�Էɻ�λ�ú��ӵ�λ�õĸ���
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
	system("mode con cols=80 lines=32");            //���ÿ���̨�Ŀ��
	SetConsoleTitle("�ɻ���ս��Ϸ");                //���ô��ڱ���
	p_mennu();                                       //��ʼʱ�Ĳ˵�
	initial_data();                                //��ʼ���������ݵ�
	HideCursor();                                  //���ع��

	while(1)
	{
		gotoxy(0,0);
		show();
		if(pflag) //�ɻ�ײ��
		{
			system("CLS");
			printf("��Ϸ����!\n���÷֣�%d", pscore*5);
			break;  //����ѭ��
		}
		without_input();  //û������ʱ�ĸ��£������ӵ����к͵л�����
		if(kbhit())       //����м�������
		{
			with_input();
		}
	}
	Sleep(1000);
	system("CLS");
	color(15);
	return ;
}
