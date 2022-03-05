#include"snake.h"
SnakeMap Map[s];
SnakeRelevant absnake;
void InitGame() {
	int i;
	int n = 1;
	for (i = 0; i < s; i++) {
		Map[i].adr = i < n ? SnakeBody : none;
		Map[i].dir = i < n ? right : unkown;
		Map[i].op = 0;
		Map[i].cost = 0;
	}
	absnake.head = n - 1;
	absnake.tail = 0;
	absnake.score = -1;
	absnake.init_speed = absnake.speed = 120;
	absnake.tempdir = right;
	absnake.x_FoodHead = 0;
	absnake.y_FoodHead = 0;
	AddApple();
}

void AddApple() {
	absnake.food = 0;
	do
		absnake.food = rand() % s;
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
	switch (absnake.tempdir)
	{
	case left:
		if (absnake.head % x == 0)
			return false;
		break;
	case up:
		if (absnake.head < x)
			return false;
		break;
	case down:
		if (absnake.head >= s - x)
			return false;
		break;
	case right:
		if (absnake.head % x == x - 1)
			return false;
		break;
	}

	int NextSquare = absnake.head + absnake.tempdir;
	if (Map[NextSquare].adr == SnakeBody && NextSquare != absnake.tail)
		return false;

	return true;
}

void DrewSnake() {
	BeginBatchDraw();
	DrewSnake_Game_Interface();
	DrewSnake_SnakeMap(Map, &absnake);
	DrewSnake_Game_Information(Map, &absnake);
	EndBatchDraw();
	DrewSanke_Speed(&absnake);
}

void MoveSnake() {
	if (Map[absnake.head + absnake.tempdir].adr != apple)
		MoveSnake_Tail(Map, &absnake.tail);
	else
		AddApple();
	MoveSnake_Head(Map, &absnake.tempdir, &absnake.head);
}
