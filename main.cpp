/************************************
 * ��Ϸ��AḬ����
 * ���ߣ�Sur_kaa<suralcarywn@qq.com>
 * ���뻷����visual studio 2022
 * ����޸ģ�2022��3��5��
 ************************************/
#include"snake.h"
int main()
{
	srand((unsigned int)time(NULL));
	DISPLAY_DESK();
	switch (SELECT())
	{
	case '0':
		DEBUGAlpha();
		break;
	case'a':case'A':case'1':
		SnakeGame(false);
		break;
	case'b':case'B':case'2':
		SnakeGame(true);
		break;
	case'c':case'C':case'3':
		HELP();
		break;
	}
	closegraph();
	return 0;
}