#include"snake.h"
int TrunSnake_byAlpha(struct SnakeMap* map, struct SnakeRelevant* absnake) {
	int result = absnake->tempdir;



	return result;
}

void Refresh_Cost(struct SnakeMap* map, int food, int next, int Nowcost) {
	int cTSPHd[5] = { unkown,left,up,down,right };
	int safety[5] = { 0,next % x == 0,next < x,next > s - x,next % x == x - 1 };
	for (int i = 1; i < 5; i++)
		if (!safety[i]) {
			int NextAround = next + cTSPHd[i];
			if (!map[NextAround].op)
				map[NextAround].cost = Nowcost + 1 +
				(int)fabs(ManHaadun_x(food, NextAround)) + (int)fabs(ManHaadun_y(food, NextAround));
		}
}

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