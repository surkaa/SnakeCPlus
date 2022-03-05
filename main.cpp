/************************************
 * 游戏：AI贪吃蛇
 * 作者：Sur_kaa<suralcarywn@qq.com>
 * 编译环境：visual studio 2022
 * 最后修改：2022年3月5日
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