#include"snake.h"
SnakeMap SNAKE[pmapS];
SnakeRelevant Data;
int op;
int Dir[4] = { left,right,up,down };
void InitMsp() {
	for (int i = 0; i < pmapS; i++) {
		if (i <= pmapW || i % pmapW == 0 || (i + 1) % pmapW == 0 || i >= pmapS - pmapW) {
			SNAKE[i].Attributes = SnakeBody;
			SNAKE[i].Direction = unkown;
		}
		else {
			SNAKE[i].Attributes = i <= initlong + pmapW ? SnakeBody : none;
			SNAKE[i].Direction = i <= initlong + pmapW ? right : unkown;
		}
	}
	Data.head = initlong + pmapW;
	Data.tail = 1 + pmapW;
	Data.score = -1;
	Data.speed = PlayerSpeed;
	Data.tempdir = right;
	Data.x_FoodHead = 0;
	Data.y_FoodHead = 0;
	AddApple();
}

void AddApple() {
	Data.stepNumber = 0;
	Data.food = 0;
	do
		Data.food = rand() % pmapS;
	while (SNAKE[Data.food].Attributes != none);
	SNAKE[Data.food].Attributes = apple;
	Data.score++;
	//printf("\a");
}

void TrunSnake(bool isHuman_AI, bool isD)
{
	if (isHuman_AI) {
		if (isD && _kbhit())
			system("pause");
		Data.tempdir = TrunSnake_byAlpha(SNAKE, &Data);
	}
	else
		Data.tempdir = TrunSnake_byPlayer(Data.tempdir);
}

bool CheakSnakeSafety()
{
	bool su = false;
	for (int i = 0; i < pmapS; i++)
		if (SNAKE[i].Attributes == none || SNAKE[i].Attributes == apple) {
			su = true;
			break;
		}
	if (Data.stepNumber > 2 * pmapS)
		return false;
	int Next = Data.head + Data.tempdir;
	if (su && (SNAKE[Next].Attributes == none || Next == Data.food || Next == Data.tail))
		return true;

	return false;
}

int CheakHtoTFSafety(int end, int Direction)
{
	int nway = 1;
	op = false;
	for (int i = 0; i < pmapS; i++) {
		if (SNAKE[i].Attributes == SnakeBody)
			SNAKE[i].Number = -1;
		else
			SNAKE[i].Number = 0;
		if (i == end)
			SNAKE[i].Number = -2;
		else if (i == Data.head + Direction && (!Direction || SNAKE[i].Attributes != SnakeBody))
			SNAKE[i].Number = nway;
	}
	while (1)
		if (fnNextCheck(++nway))
			break;
	return op;
}

bool fnNextCheck(int n)
{
	int record = 1;
	for (int i = 0; i < pmapS; i++)
		if (SNAKE[i].Number == (n - 1)) {
			fnAroundCheak(i, n);
			record = 0;
		}
	return record;
}

void fnAroundCheak(int num, int nway) {
	for (int i = 0; i < 4; i++) {
		if (SNAKE[num + Dir[i]].Number == -2) {
			op = nway;
			break;
		}
		if (SNAKE[num + Dir[i]].Number == 0)
			SNAKE[num + Dir[i]].Number = nway;
	}
}

void fnDisplaySnake(bool op) {
	BeginBatchDraw();
	fnDrawSnakeBody(SNAKE, &Data);
	fnOutputMessage(&Data, op);
	EndBatchDraw();
	SpeedSnake(op, &Data);
}

void MoveSnake() {
	if (SNAKE[Data.head + Data.tempdir].Attributes != apple) {
		MoveSnake_Tail(SNAKE, &Data.tail);
		Data.stepNumber++;
	}
	else
		AddApple();
	MoveSnake_Head(SNAKE, &Data.tempdir, &Data.head);

	fnRefresh();
}

void fnRefresh()
{
	Data.x_FoodHead = ManHaadun_x(Data.food, Data.head);
	Data.y_FoodHead = ManHaadun_y(Data.head, Data.food);
	Data.condition = getSquareSafetyFactor(Data.head);
}

double debuggingResults() {
	return (Data.score + initlong + 1) / (float)mapSize;
}

int isSnakeBody(int op)
{
	return (SNAKE[op].Attributes == none || op == Data.food || op == Data.tail) ? 1 : 0;
}
