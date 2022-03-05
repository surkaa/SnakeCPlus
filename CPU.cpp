#include"snake.h"
SnakeMap Map[ss];
SnakeRelevant absnake;
void InitGame() {
	int i;
	int n = 4;
	for (i = 0; i < ss; i++) {
		if (i <= xx || i % xx == 0 || i % xx == xx - 1 || i >= ss - xx)
			Map[i].adr = wall;
		else {
			Map[i].adr = i <= n + xx ? SnakeBody : none;
			Map[i].dir = i <= n + xx ? right : unkown;
		}
	}
	absnake.head = n + xx;
	absnake.tail = 1 + xx;
	absnake.score = -1;
	absnake.init_speed = absnake.speed = 10;
	absnake.tempdir = right;
	absnake.x_FoodHead = 0;
	absnake.y_FoodHead = 0;
	AddApple();
}

void AddApple() {
	absnake.food = 0;
	do
		absnake.food = rand() % ss;
	while (Map[absnake.food].adr != none);
	Map[absnake.food].adr = apple;
	absnake.score++;
	printf("\a");
}

void TrunSnake(bool isHuman_AI)
{
	if (isHuman_AI)
		absnake.tempdir = TrunSnake_byAlpha(Map, &absnake);
	else
		absnake.tempdir = TrunSnake_byPlayer(absnake.tempdir);
}

bool CheakSnakeSafety()
{
	int NextSquare = absnake.head + absnake.tempdir;
	if (Map[NextSquare].adr == none || Map[NextSquare].adr ==apple || NextSquare == absnake.tail)
		return true;

	return false;
}

void DrewSnake() {
	BeginBatchDraw();
	fnDrawSnakeBody(Map, &absnake);
	fnOutputMessage(Map, &absnake);
	EndBatchDraw();
	SpeedSnake(&absnake);
}

void MoveSnake() {
	if (Map[absnake.head + absnake.tempdir].adr != apple)
		MoveSnake_Tail(Map, &absnake.tail);
	else
		AddApple();
	MoveSnake_Head(Map, &absnake.tempdir, &absnake.head);
}
