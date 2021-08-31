#include "student.h"

void PrintMap();//打印地图
void MoveUp();//控制人向上移动
void MoveDown();//控制人向下移动
void MoveLeft();//控制人向左移动
void MoveRight();//控制人向右移动

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
};//定义地图数组;其中0表示空白,1表示箱子,2表示人,3表示墙,4表示目标地

int boxnum = 3;//当前地图里箱子的数目;已确定
int px = 4, py = 3;//人在当前地图里的初始坐标位置;已确定


void sokoban()
{
    char input;//用户输入的字符;本游戏采用wasd来控制人向上左下右移动
    if(boxnum == 0)
    {
        printf("您已经通过了本游戏~\n按回车键返回菜单\n");
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
            printf("请使用wasd键来进行上左下右移动！\n");
            PrintMap();//人每移动一步就要重新绘画地图
            if(!boxnum)
                break;
            else
            {
                input = getch();//从控制台读取一个字符
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
    printf("恭喜通过游戏!\n按回车键回到主菜单\n");
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
                printf("□");//箱子
                break;
            case 2:
                printf("♀");//人
                break;
            case 3:
                printf("■");//墙
                break;
            case 4:
                printf("☆");//目的地
                break;
            default:
                break;
            }

        }
        printf("\n");
    }
}

void MoveLeft()//人向左移动
{
    switch(map[px][py-1])
    {
    case 0://人的左格是空白
        map[px][py] = 0;//将人原来的位置设置为空白（人走了
        map[px][py-1] = 2;//人的左格设置为人
        py--;//对人的坐标进行了更新
        break;
    case 1://人的左格是箱子，可以推
        if(map[px][py-2] == 0)//箱子的左格是空的
        {
            map[px][py-2] = 1;//箱子，人依次向左前进了一格
            map[px][py-1] = 2;
            map[px][py] = 0;
            py--;
        }
        else if(map[px][py-2] == 4)//箱子的左格是目的地
        {
            map[px][py-2] = 0;//此时箱子和目的地的符号都消失
            map[px][py-1] = 2;
            map[px][py] = 0;//人本来的位置也是空格，因为前进了
            boxnum--;//箱子数目少一
            py--;
        }
        break;
    case 3://人的左格是墙，人不会动
        break;
    case 4://人的左格是目的地，规定这时人也不会行动
        break;
    default:
        break;
    }
}

void MoveRight()//人向右移动
{
    switch(map[px][py+1])
    {
    case 0://人的右格是空白
        map[px][py] = 0;//将人原来的位置设置为空白（人走了
        map[px][py+1] = 2;//人的右格设置为人
        py++;//对人的坐标进行了更新
        break;
    case 1://人的右格是箱子，可以推
        if(map[px][py+2] == 0)//箱子的右格是空的
        {
            map[px][py+2] = 1;//箱子，人依次向右前进了一格
            map[px][py+1] = 2;
            map[px][py] = 0;
            py++;
        }
        else if(map[px][py+2] == 4)//箱子的右格是目的地
        {
            map[px][py+2] = 0;//此时箱子和目的地的符号都消失
            map[px][py+1] = 2;
            map[px][py] = 0;//人本来的位置也是空格，因为前进了
            boxnum--;//箱子数目少一
            py++;
        }
        break;
    case 3://人的右格是墙，人不会动
        break;
    case 4://人的右格是目的地，规定这时人也不会行动
        break;
    default:
        break;
    }
}

void MoveUp()//人向上移动
{
    switch(map[px-1][py])
    {
    case 0://人的上格是空白
        map[px][py] = 0;//将人原来的位置设置为空白（人走了
        map[px-1][py] = 2;//人的上格设置为人
        px--;//对人的坐标进行了更新
        break;
    case 1://人的上格是箱子，可以推
        if(map[px-2][py] == 0)//箱子的上格是空的
        {
            map[px-2][py] = 1;//箱子，人依次向上前进了一格
            map[px-1][py] = 2;
            map[px][py] = 0;
            px--;
        }
        else if(map[px-2][py] == 4)//箱子的上格是目的地
        {
            map[px-2][py] = 0;//此时箱子和目的地的符号都消失
            map[px-1][py] = 2;
            map[px][py] = 0;//人本来的位置也是空格，因为前进了
            boxnum--;//箱子数目少一
            px--;
        }
        break;
    case 3://人的上格是墙，人不会动
        break;
    case 4://人的上格是目的地，规定这时人也不会行动
        break;
    default:
        break;
    }
}

void MoveDown()//人向下移动
{
    switch(map[px+1][py])
    {
    case 0://人的下格是空白
        map[px][py] = 0;//将人原来的位置设置为空白（人走了
        map[px+1][py] = 2;//人的下格设置为人
        px++;//对人的坐标进行了更新
        break;
    case 1://人的下格是箱子，可以推
        if(map[px+2][py] == 0)//箱子的下格是空的
        {
            map[px+2][py] = 1;//箱子，人依次向下前进了一格
            map[px+1][py] = 2;
            map[px][py] = 0;
            px++;
        }
        else if(map[px+2][py] == 4)//箱子的下格是目的地
        {
            map[px+2][py] = 0;//此时箱子和目的地的符号都消失
            map[px+1][py] = 2;
            map[px][py] = 0;//人本来的位置也是空格，因为前进了
            boxnum--;//箱子数目少一
            px++;
        }
        break;
    case 3://人的下格是墙，人不会动
        break;
    case 4://人的下格是目的地，规定这时人也不会行动
        break;
    default:
        break;
    }
}
