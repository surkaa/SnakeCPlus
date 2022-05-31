#include"snake.h"
int ManHaadun_x(int a, int b) {
	return a % pmapW - b % pmapW;
}

int ManHaadun_y(int a, int b) {
	return a / pmapW - b / pmapW;
}

int TrunSnake_byPlayer(int Direction) {
	int result = Direction;
	if (_kbhit())
		switch (_getch())
		{
		case 77:case'a':case'A':case'3':
			if (Direction != right)
				result = left;
			break;
		case 72:case'w':case'W':case'1':
			if (Direction != down)
				result = up;
			break;
		case 80:case's':case'S':case'2':
			if (Direction != up)
				result = down;
			break;
		case 75:case'd':case'D':case'4':
			if (Direction != left)
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
	map[*head].Direction = *tempdir;
	*head += *tempdir;
	map[*head].Attributes = SnakeBody;
}

void MoveSnake_Tail(SnakeMap* map, int* tail) {
	int temp = *tail;
	*tail += map[temp].Direction;
	map[temp].Attributes = none;
	map[temp].Direction = unkown;
}

int getSquareSafetyFactor(int head) {
	int result =
		8 * isSnakeBody(head + left) +
		4 * isSnakeBody(head + up) +
		2 * isSnakeBody(head + down) +
		1 * isSnakeBody(head + right);

	return result;
}

void SpeedSnake(bool op, SnakeRelevant* Data) {
	if (op)
		Data->speed = AISpeed;
	else
//		为使分数达满时得到速度 speed = 1 计算得系数 SpeedRelationship 如下
		Data->speed = (int)(PlayerSpeed * pow(2, -Data->score * SpeedRelationship));
	Sleep((DWORD)Data->speed);
}
