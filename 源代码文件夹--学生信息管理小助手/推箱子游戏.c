#include "student.h"

void PrintMap();//��ӡ��ͼ
void MoveUp();//�����������ƶ�
void MoveDown();//�����������ƶ�
void MoveLeft();//�����������ƶ�
void MoveRight();//�����������ƶ�

int map[8][8] =
{
    {3,3,3,0,0,0,0,0},
    {3,0,4,3,0,3,0,0},
    {3,0,0,0,3,4,3,0},
    {0,3,1,0,0,0,3,0},
    {0,3,0,2,0,1,0,3},
    {0,3,0,1,0,0,3,0},
    {0,3,3,3,4,3,3,0},
    {0,0,0,0,3,0,0,0}
};//�����ͼ����;����0��ʾ�հ�,1��ʾ����,2��ʾ��,3��ʾǽ,4��ʾĿ���

int boxnum = 3;//��ǰ��ͼ�����ӵ���Ŀ;��ȷ��
int px = 4, py = 3;//���ڵ�ǰ��ͼ��ĳ�ʼ����λ��;��ȷ��


void sokoban()
{
    char input;//�û�������ַ�;����Ϸ����wasd�������������������ƶ�
    if(boxnum == 0)
    {
        printf("���Ѿ�ͨ���˱���Ϸ~\n���س������ز˵�\n");
        getchar();
		getchar();
		system("CLS");
		return;

    }
    else
    {
        while(1)
        {
            system("CLS");
            printf("��ʹ��wasd�����������������ƶ���\n");
            PrintMap();//��ÿ�ƶ�һ����Ҫ���»滭��ͼ
            if(!boxnum)
                break;
            else
            {
                input = getch();//�ӿ���̨��ȡһ���ַ�
                switch(input)
                {
                case 'w':
                    MoveUp();
                    break;
                case 's':
                    MoveDown();
                    break;
                case 'a':
                    MoveLeft();
                    break;
                case 'd':
                    MoveRight();
                    break;
                default:
                    break;
                }
            }
        }
    }
    printf("��ϲͨ����Ϸ!\n���س����ص����˵�\n");
    getchar();
    getchar();
    system("CLS");
}

void PrintMap()
{
    int i, j;
    for(i = 0; i < 8; i++)
    {
        for(j = 0; j < 8; j++)
        {
            switch(map[i][j])
            {
            case 0:
                printf("  ");
                break;
            case 1:
                printf("��");//����
                break;
            case 2:
                printf("��");//��
                break;
            case 3:
                printf("��");//ǽ
                break;
            case 4:
                printf("��");//Ŀ�ĵ�
                break;
            default:
                break;
            }

        }
        printf("\n");
    }
}

void MoveLeft()//�������ƶ�
{
    switch(map[px][py-1])
    {
    case 0://�˵�����ǿհ�
        map[px][py] = 0;//����ԭ����λ������Ϊ�հף�������
        map[px][py-1] = 2;//�˵��������Ϊ��
        py--;//���˵���������˸���
        break;
    case 1://�˵���������ӣ�������
        if(map[px][py-2] == 0)//���ӵ�����ǿյ�
        {
            map[px][py-2] = 1;//���ӣ�����������ǰ����һ��
            map[px][py-1] = 2;
            map[px][py] = 0;
            py--;
        }
        else if(map[px][py-2] == 4)//���ӵ������Ŀ�ĵ�
        {
            map[px][py-2] = 0;//��ʱ���Ӻ�Ŀ�ĵصķ��Ŷ���ʧ
            map[px][py-1] = 2;
            map[px][py] = 0;//�˱�����λ��Ҳ�ǿո���Ϊǰ����
            boxnum--;//������Ŀ��һ
            py--;
        }
        break;
    case 3://�˵������ǽ���˲��ᶯ
        break;
    case 4://�˵������Ŀ�ĵأ��涨��ʱ��Ҳ�����ж�
        break;
    default:
        break;
    }
}

void MoveRight()//�������ƶ�
{
    switch(map[px][py+1])
    {
    case 0://�˵��Ҹ��ǿհ�
        map[px][py] = 0;//����ԭ����λ������Ϊ�հף�������
        map[px][py+1] = 2;//�˵��Ҹ�����Ϊ��
        py++;//���˵���������˸���
        break;
    case 1://�˵��Ҹ������ӣ�������
        if(map[px][py+2] == 0)//���ӵ��Ҹ��ǿյ�
        {
            map[px][py+2] = 1;//���ӣ�����������ǰ����һ��
            map[px][py+1] = 2;
            map[px][py] = 0;
            py++;
        }
        else if(map[px][py+2] == 4)//���ӵ��Ҹ���Ŀ�ĵ�
        {
            map[px][py+2] = 0;//��ʱ���Ӻ�Ŀ�ĵصķ��Ŷ���ʧ
            map[px][py+1] = 2;
            map[px][py] = 0;//�˱�����λ��Ҳ�ǿո���Ϊǰ����
            boxnum--;//������Ŀ��һ
            py++;
        }
        break;
    case 3://�˵��Ҹ���ǽ���˲��ᶯ
        break;
    case 4://�˵��Ҹ���Ŀ�ĵأ��涨��ʱ��Ҳ�����ж�
        break;
    default:
        break;
    }
}

void MoveUp()//�������ƶ�
{
    switch(map[px-1][py])
    {
    case 0://�˵��ϸ��ǿհ�
        map[px][py] = 0;//����ԭ����λ������Ϊ�հף�������
        map[px-1][py] = 2;//�˵��ϸ�����Ϊ��
        px--;//���˵���������˸���
        break;
    case 1://�˵��ϸ������ӣ�������
        if(map[px-2][py] == 0)//���ӵ��ϸ��ǿյ�
        {
            map[px-2][py] = 1;//���ӣ�����������ǰ����һ��
            map[px-1][py] = 2;
            map[px][py] = 0;
            px--;
        }
        else if(map[px-2][py] == 4)//���ӵ��ϸ���Ŀ�ĵ�
        {
            map[px-2][py] = 0;//��ʱ���Ӻ�Ŀ�ĵصķ��Ŷ���ʧ
            map[px-1][py] = 2;
            map[px][py] = 0;//�˱�����λ��Ҳ�ǿո���Ϊǰ����
            boxnum--;//������Ŀ��һ
            px--;
        }
        break;
    case 3://�˵��ϸ���ǽ���˲��ᶯ
        break;
    case 4://�˵��ϸ���Ŀ�ĵأ��涨��ʱ��Ҳ�����ж�
        break;
    default:
        break;
    }
}

void MoveDown()//�������ƶ�
{
    switch(map[px+1][py])
    {
    case 0://�˵��¸��ǿհ�
        map[px][py] = 0;//����ԭ����λ������Ϊ�հף�������
        map[px+1][py] = 2;//�˵��¸�����Ϊ��
        px++;//���˵���������˸���
        break;
    case 1://�˵��¸������ӣ�������
        if(map[px+2][py] == 0)//���ӵ��¸��ǿյ�
        {
            map[px+2][py] = 1;//���ӣ�����������ǰ����һ��
            map[px+1][py] = 2;
            map[px][py] = 0;
            px++;
        }
        else if(map[px+2][py] == 4)//���ӵ��¸���Ŀ�ĵ�
        {
            map[px+2][py] = 0;//��ʱ���Ӻ�Ŀ�ĵصķ��Ŷ���ʧ
            map[px+1][py] = 2;
            map[px][py] = 0;//�˱�����λ��Ҳ�ǿո���Ϊǰ����
            boxnum--;//������Ŀ��һ
            px++;
        }
        break;
    case 3://�˵��¸���ǽ���˲��ᶯ
        break;
    case 4://�˵��¸���Ŀ�ĵأ��涨��ʱ��Ҳ�����ж�
        break;
    default:
        break;
    }
}
