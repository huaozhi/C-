#include "student.h"
#include "�ɻ���ս��Ϸ.h"
#include "̰������Ϸ.h"
int studentnum; //��ǰѧ������

int main()
{
	SetConsoleTitle("ѧ����Ϣ����С����");
    List L = NULL;
	char a;
    studentnum = 0;
	while(1)
	{
    	a = mennu();

    	switch(a)
    	{
    		case '0':
    			readfile(&L);//���ļ��ж�ȡ���ݵ�����
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
					printf("�ɹ��˳�ϵͳ��");
					exit(0);
    		case '@':
    	        plane_game();
    	        getchar();
    	        system("mode con cols=122 lines=30");
    	        SetConsoleTitle("ѧ����Ϣ����С����");
    	        break;
            case '#':
            	SetConsoleTitle("��������Ϸ");
                sokoban();
                SetConsoleTitle("ѧ����Ϣ����С����");
		    	break;
			case '&':
				SetConsoleTitle("̰������Ϸ");
		        eatingsnake();
		        getchar();
		        SetConsoleTitle("ѧ����Ϣ����С����");
                break;
            default:
                break;
   	    }
   }
	return 0;
}
