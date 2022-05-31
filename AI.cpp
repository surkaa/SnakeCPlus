#include"snake.h"

//11.86  1500  50
//转角问题

int TrunSnake_byAlpha(struct SnakeMap* map, struct SnakeRelevant* Data) {
	int result = Data->tempdir;
	int next = map[Data->head + Data->tempdir].Direction;
	int x = Data->x_FoodHead;
	int y = Data->y_FoodHead;
	int z = x + y;
	if (y == 0)
		result = x > 0 ? right : left;
	if (x == 0)
		result = y > 0 ? up : down;

	Data->tempdir = result;
	if (!CheakSnakeSafety())
		switch (Data->condition)
		{
		case 1:
			return right;
		case 2:
			return down;
		case 3:
			result = z > 0 ? right : down;
			break;
		case 4:
			return up;
		case 5:
			result = x > y ? right : up;
			break;
		case 6:
			result = y < 0 ? down : up;
			break;
		case 7:
			if (y > 0 && y > x)
				result = up;
			else if (y < 0 && z < 0)
				result = down;
			else
				result = right;
			break;
		case 8:
			return left;
		case 9:
			result = x > 0 ? right : left;
			break;
		case 10:
			result = x > y ? down : left;
			break;
		case 11:
			if (x > 0 && z > 0)
				result = right;
			else if (x < 0 && y > x)
				result = left;
			else
				result = down;
			break;
		case 12:
			result = z > 0 ? up : left;
			break;
		case 13:
			if (x > 0 && x > y)
				result = right;
			else if (x < 0 && z < 0)
				result = left;
			else
				result = up;
			break;
		case 14:
			if (y > 0 && z > 0)
				result = up;
			else if (y < 0 && x > y)
				result = down;
			else
				result = left;
			break;
		}

	Data->tempdir = result;
	if (CheakHtoTFSafety(Data->food, 0)) {
		if (CheakHtoTFSafety(Data->tail, Data->tempdir))
			return result;
		else
			return fnFarthestToTheSnakeFood_A(Data);
	}
	else
		return fnFarthestToTheSnakeTail(Data);
}

int fnFarthestToTheSnakeFood_A(SnakeRelevant* Data)
{
	int result = 0;
	switch (Data->condition)
	{
	case 1:
		result = right;
		break;
	case 2:
		result = down;
		break;
	case 3:
		result = Data->tempdir == down ? right : down;
		break;
	case 4:
		result = up;
		break;
	case 5:
		result = Data->tempdir == up ? right : up;
		break;
	case 6:
		result = Data->tempdir == up ? down : up;
		break;
	case 7:
		if (Data->tempdir == right)
			result = CheakHtoTFSafety(Data->tail, up) ? up : down;
		else
			result = Data->tempdir == up ? down : up;
		break;
	case 8:
		result = left;
		break;
	case 9:
		result = Data->tempdir == left ? right : left;
		break;
	case 10:
		result = Data->tempdir == left ? down : left;
		break;
	case 11:
		if (Data->tempdir == down)
			result = CheakHtoTFSafety(Data->tail, right) ? right : left;
		else
			result = Data->tempdir == right ? left : right;
		break;
	case 12:
		result = Data->tempdir == left ? up : left;
		break;
	case 13:
		if (Data->tempdir == up)
			result = CheakHtoTFSafety(Data->tail, left) ? left : right;
		else
			result = Data->tempdir == left ? right : left;
		break;
	case 14:
		if (Data->tempdir == left)
			result = CheakHtoTFSafety(Data->tail, up) ? up : down;
		else
			result = Data->tempdir == up ? down : up;
		break;
	}
	return result;
}

int fnFarthestToTheSnakeFood_B(SnakeRelevant* Data)
{
	int Dir[4] = { left,right,up,down };
	int result = Data->tempdir;
	int max = 0, temp = 0;
	for (int i = 0; i < 4; i++) {
		temp = CheakHtoTFSafety(Data->food, Dir[i]);
		if (temp >= max) {
			max = temp;
			result = Dir[i];
		}
	}
	return result;
}

int fnFarthestToTheSnakeTail(SnakeRelevant* Data)
{
	int Dir[4] = { left,right,up,down };
	int result = Data->tempdir;
	int max = 0, temp = 0;
	for (int i = 0; i < 4; i++) {
		temp = CheakHtoTFSafety(Data->tail, Dir[i]);
		if (temp >= max) {
			max = temp;
			result = Dir[i];
		}
	}
	return result;
}
