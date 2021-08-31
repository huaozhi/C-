#include "student.h"
#include "飞机作战游戏.h"
#include "贪吃蛇游戏.h"
int studentnum; //当前学生人数

int main()
{
	SetConsoleTitle("学生信息管理小助手");
    List L = NULL;
	char a;
    studentnum = 0;
	while(1)
	{
    	a = mennu();

    	switch(a)
    	{
    		case '0':
    			readfile(&L);//从文件中读取数据到链表
    			break;
	    	case '1':
		    	stu_input(&L);
			    break;
	    	case '2':
		    	stu_seek(&L);
		    	break;
	    	case '3':
		    	stu_browse(&L);
		    	break;
	    	case '4':
	    		stu_order(&L);
		    	break;
			case '5':
			    stu_delete(&L);
			    break;
			case '6':
				stu_change(&L);
				break;
			case '7':
				stu_insert(&L);
				break;
    		case '8':
    		    	if(L != NULL)
    				{
	    			    save_into_file(L);
	    			    List q;
	    			    while(L)
	    			    {
	    			    	q = L;
	    			    	L = L->next;
	    			    	free(q);
						}
					}
					printf("成功退出系统！");
					exit(0);
    		case '@':
    	        plane_game();
    	        getchar();
    	        system("mode con cols=122 lines=30");
    	        SetConsoleTitle("学生信息管理小助手");
    	        break;
            case '#':
            	SetConsoleTitle("推箱子游戏");
                sokoban();
                SetConsoleTitle("学生信息管理小助手");
		    	break;
			case '&':
				SetConsoleTitle("贪吃蛇游戏");
		        eatingsnake();
		        getchar();
		        SetConsoleTitle("学生信息管理小助手");
                break;
            default:
                break;
   	    }
   }
	return 0;
}
