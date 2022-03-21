#include"snake.h"
SnakeMap Map[pmapS];
SnakeRelevant absnake;
int op;
int Dir[4] = { left,right,up,down };
void InitGame() {
	for (int i = 0; i < pmapS; i++) {
		if (i <= pmapW || i % pmapW == 0 || (i + 1) % pmapW == 0 || i >= pmapS - pmapW) {
			Map[i].adr = SnakeBody;
			Map[i].dir = unkown;
		}
		else {
			Map[i].adr = i <= initlong + pmapW ? SnakeBody : none;
			Map[i].dir = i <= initlong + pmapW ? right : unkown;
		}
	}
	absnake.head = initlong + pmapW;
	absnake.tail = 1 + pmapW;
	absnake.score = -1;
	absnake.speed = initspeed;
	absnake.tempdir = right;
	absnake.x_FoodHead = 0;
	absnake.y_FoodHead = 0;
	AddApple();
}

void AddApple() {
	absnake.stepNumber = 0;
	absnake.food = 0;
	do
		absnake.food = rand() % pmapS;
	while (Map[absnake.food].adr != none);
	Map[absnake.food].adr = apple;
	absnake.score++;
	//printf("\a");
}

void TrunSnake(bool isHuman_AI, bool isD)
{
	if (isHuman_AI) {
		if (isD && _kbhit())
			system("pause");
		absnake.tempdir = TrunSnake_byAlpha(Map, &absnake);
	}
	else
		absnake.tempdir = TrunSnake_byPlayer(absnake.tempdir);
}

bool CheakSnakeSafety()
{
	bool su = false;
	for (int i = 0; i < pmapS; i++)
		if (Map[i].adr == none) {
			su = true;
			break;
		}
	if (absnake.stepNumber > 2 * pmapS)
		return false;
	int Next = absnake.head + absnake.tempdir;
	if (su && (Map[Next].adr == none || Next == absnake.food || Next == absnake.tail))
		return true;

	return false;
}

int CheakHtoTFSafety(int end, int dir)
{
	int nway = 1;
	op = false;
	for (int i = 0; i < pmapS; i++) {
		if (Map[i].adr == SnakeBody)
			Map[i].way = -1;
		else
			Map[i].way = 0;
		if (i == end)
			Map[i].way = -2;
		else if (i == absnake.head + dir && (!dir || Map[i].adr != SnakeBody))
			Map[i].way = nway;
	}
	while (1)
		if (update(++nway))
			break;
	return op;
}

bool update(int n)
{
	int record = 1;
	for (int i = 0; i < pmapS; i++)
		if (Map[i].way == (n - 1)) {
			around(i, n);
			record = 0;
		}
	return record;
}

void around(int num, int nway) {
	for (int i = 0; i < 4; i++) {
		if (Map[num + Dir[i]].way == -2) {
			op = nway;
			break;
		}
		if (Map[num + Dir[i]].way == 0)
			Map[num + Dir[i]].way = nway;
	}
}

void DrewSnake(bool op) {
	BeginBatchDraw();
	fnDrawSnakeBody(Map, &absnake);
	fnOutputMessage(Map, &absnake);
	EndBatchDraw();
	SpeedSnake(op, &absnake);
}

void MoveSnake() {
	if (Map[absnake.head + absnake.tempdir].adr != apple) {
		MoveSnake_Tail(Map, &absnake.tail);
		absnake.stepNumber++;
	}
	else
		AddApple();
	MoveSnake_Head(Map, &absnake.tempdir, &absnake.head);

	fnRefresh();
}

void fnRefresh()
{
	absnake.x_FoodHead = ManHaadun_x(absnake.food, absnake.head);
	absnake.y_FoodHead = ManHaadun_y(absnake.head, absnake.food);
	absnake.x_TailHead = ManHaadun_x(absnake.tail, absnake.head);
	absnake.y_TailHead = ManHaadun_y(absnake.head, absnake.tail);
	absnake.condition = _condition(absnake.head);
}

double completeness() {
	return (absnake.score + initlong + 1) / (float)mapSize;
}

int isSnakeBody(int op)
{
	return (Map[op].adr == none || op == absnake.food || op == absnake.tail) ? 1 : 0;
}