#include"snake.h"
int TrunSnake_byAlpha(struct SnakeMap* map, struct SnakeRelevant* absnake) {
	int result = absnake->tempdir;

	result = planA(map, absnake, result);

	result = NoDie(map, absnake, result);

	return result;
}

int planA(struct SnakeMap* map, struct SnakeRelevant* absnake, int now_dir) {
	int result = now_dir;
	if (absnake->y_FoodHead == 0)
		result = absnake->x_FoodHead > 0 ? right : left;
	if (absnake->x_FoodHead == 0)
		result = absnake->y_FoodHead > 0 ? up : down;
	return result;
		}

int NoDie(struct SnakeMap* map, struct SnakeRelevant* absnake, int now_dir) {

	switch(absnake->condition)
	{
	case 1: 
		now_dir = right;
		break;
	case 2: 
		now_dir = down;
		break;
	case 4: 
		now_dir = up;
		break;
	case 6:
		now_dir = absnake->y_FoodHead ? up : down;
		break;
	case 8: 
		now_dir = left;
		break;
	case 9:
		now_dir = absnake->x_FoodHead ? right : left;
		break;
}
	return now_dir;

int ReturnTheMinCost(struct SnakeMap* map) {
	int min = s;
	int result = 0;
	for (int i = 0; i < s; i++)
		if (map[i].op && min > map[i].cost) {
			int temp = min;
			min = map[i].cost;
			map[i].cost = temp;
			result = i;
		}
	return result;
}