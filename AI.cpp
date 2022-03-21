#include"snake.h"

//11.86  1500  50
//×ª½ÇÎÊÌâ

int TrunSnake_byAlpha(struct SnakeMap* map, struct SnakeRelevant* absnake) {
	int result = absnake->tempdir;
	int next = map[absnake->head + absnake->tempdir].dir;
	int x = absnake->x_FoodHead;
	int y = absnake->y_FoodHead;
	int z = x + y;
	if (y == 0)
		result = x > 0 ? right : left;
	if (x == 0)
		result = y > 0 ? up : down;

	absnake->tempdir = result;
	if (!CheakSnakeSafety())
		switch (absnake->condition)
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

	absnake->tempdir = result;
	if (CheakHtoTFSafety(absnake->food, 0)) {
		if (CheakHtoTFSafety(absnake->tail, absnake->tempdir))
			return result;
		else
			return fnAsFarAsThePathtoFood(absnake);
	}
	else
		return fnAsFarAsThePathtoTail_(absnake);
}

int fnAsFarAsThePathtoFood(SnakeRelevant* absnake)
{
	int result = 0;
	switch (absnake->condition)
	{
	case 1:
		result = right;
		break;
	case 2:
		result = down;
		break;
	case 3:
		result = absnake->tempdir == down ? right : down;
		break;
	case 4:
		result = up;
		break;
	case 5:
		result = absnake->tempdir == up ? right : up;
		break;
	case 6:
		result = absnake->tempdir == up ? down : up;
		break;
	case 7:
		if (absnake->tempdir == right)
			result = CheakHtoTFSafety(absnake->tail, up) ? up : down;
		else
			result = absnake->tempdir == up ? down : up;
		break;
	case 8:
		result = left;
		break;
	case 9:
		result = absnake->tempdir == left ? right : left;
		break;
	case 10:
		result = absnake->tempdir == left ? down : left;
		break;
	case 11:
		if (absnake->tempdir == down)
			result = CheakHtoTFSafety(absnake->tail, right) ? right : left;
		else
			result = absnake->tempdir == right ? left : right;
		break;
	case 12:
		result = absnake->tempdir == left ? up : left;
		break;
	case 13:
		if (absnake->tempdir == up)
			result = CheakHtoTFSafety(absnake->tail, left) ? left : right;
		else
			result = absnake->tempdir == left ? right : left;
		break;
	case 14:
		if (absnake->tempdir == left)
			result = CheakHtoTFSafety(absnake->tail, up) ? up : down;
		else
			result = absnake->tempdir == up ? down : up;
		break;
	}
	return result;
}

int fnAsFarAsThePathtoFood_(SnakeRelevant* absnake)
{
	int Dir[4] = { left,right,up,down };
	int result = absnake->tempdir;
	int max = 0;
	for (int i = 0; i < 4; i++) {
		if (CheakHtoTFSafety(absnake->food, Dir[i]) >= max) {
			max = CheakHtoTFSafety(absnake->food, Dir[i]);
			result = Dir[i];
		}
	}
	return result;
}

int fnAsFarAsThePathtoTail_(SnakeRelevant* absnake)
{
	int Dir[4] = { left,right,up,down };
	int result = absnake->tempdir;
	int max = 0;
	for (int i = 0; i < 4; i++) {
		if (CheakHtoTFSafety(absnake->tail, Dir[i]) >= max) {
			max = CheakHtoTFSafety(absnake->tail, Dir[i]);
			result = Dir[i];
		}
	}
	return result;
}
