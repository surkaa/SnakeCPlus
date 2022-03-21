#include"snake.h"
int ManHaadun_x(int a, int b) {
	return a % pmapW - b % pmapW;
}

int ManHaadun_y(int a, int b) {
	return a / pmapW - b / pmapW;
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
			TrunSnake_byPlayer(result);
			break;
		}
	return result;
}

void MoveSnake_Head(SnakeMap* map, int* tempdir, int* head) {
	map[*head].dir = *tempdir;
	*head += *tempdir;
	map[*head].adr = SnakeBody;
}

void MoveSnake_Tail(SnakeMap* map, int* tail) {
	int temp = *tail;
	*tail += map[temp].dir;
	map[temp].adr = none;
	map[temp].dir = unkown;
}

int _condition(int head) {
	int result =
		8 * isSnakeBody(head + left) +
		4 * isSnakeBody(head + up) +
		2 * isSnakeBody(head + down) +
		1 * isSnakeBody(head + right);

	return result;
}

void SpeedSnake(bool op, SnakeRelevant* absnake) {
	//Ϊʹ��������ʱ�õ��ٶ� speed = 1 �����ϵ�� SpeedRelationship ����
	if(!op)
		absnake->speed = (initspeed * pow(2, -absnake->score * SpeedRelationship));
	Sleep((DWORD)absnake->speed);
}