#include"snake.h"

int isSnakeBody(int op)
{
	return op == none || op == apple ? true : false;
}

int ManHaadun_x(int a, int b) {
	return a % xx - b % xx;
}

int ManHaadun_y(int a, int b) {
	return a / xx - b / xx;
}

int TrunSnake_byPlayer(int dir) {
	int result = dir;
	if (_kbhit())
		switch (_getch())
		{
		case 77:case'a':case'A':case'3':
			if (dir != right)
				result = left;
			break;
		case 72:case'w':case'W':case'1':
			if (dir != down)
				result = up;
			break;
		case 80:case's':case'S':case'2':
			if (dir != up)
				result = down;
			break;
		case 75:case'd':case'D':case'4':
			if (dir != left)
				result = right;
			break;
		default:
			system("pause");
			break;
		}
	return result;
}

void MoveSnake_Head(struct SnakeMap* map, int* tempdir, int* head) {
	map[*head].dir = *tempdir;
	*head += *tempdir;
	map[*head].adr = SnakeBody;
}

void MoveSnake_Tail(struct SnakeMap* map, int* tail) {
	int temp = *tail;
	*tail += map[temp].dir;
	map[temp].adr = none;
	map[temp].dir = unkown;
}

int _condition(struct SnakeMap* map, int head) {
	int result = 
		8 * isSnakeBody(map[head + left].adr) +
		4 * isSnakeBody(map[head + up].adr) +
		2 * isSnakeBody(map[head + down].adr) +
		1 * isSnakeBody(map[head + right].adr);
	
	return result;
}

void SpeedSnake(struct SnakeRelevant* absnake) {
	//为使分数达满时得到速度 speed = 1 计算得系数 k 如下
	double k = pow(2, -absnake->score * log(absnake->init_speed) / log(2) / s);
	absnake->speed = absnake->init_speed * k;
	Sleep(absnake->speed);
}