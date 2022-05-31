/************************************
 * 游戏：AI贪吃蛇
 * 作者：Sur_kaa <suralcarywn@qq.com>
 * 编译环境：visual studio 2022
 * 最后修改：2022年5月31日
 ************************************/
#include"snake.h"
int main(void)
{
	srand((unsigned int)time(NULL));
	DISPLAY_DESK();
	switch (SELECT())
	{
	case'd':case'D':
		DEBUGAlpha(true);
		break;
	case's':case'S':
		DEBUGAlpha(false);
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
}
