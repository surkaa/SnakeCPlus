#include"snake.h"

char SELECT() {

	char result = _getch();
	cleardevice();

	return result;
}

void DEBUGAlpha(bool op) {
	int i = 0;
	double ageCompleteness = 0;
	while (i++ < 3000) {
		InitGame();
		while (CheakSnakeSafety()) {
			MoveSnake();
			TrunSnake(true, op);
		}
		ageCompleteness += completeness();
		printf("\n\tNo.%-4d %%%3.1lf", i, 100 * completeness());
		if (i % 10 == 0) {
			//print();
			printf("\n\n\tAge: %%%4.2lf", ageCompleteness / i * 100);
			if (op) {
				DrewSnake(1);
				Sleep(1000);
				if (_kbhit())
					system("pause");
			}
		}
	}
	printf("\n\n\n\n\tAge: %%%4.2lf", ageCompleteness / (i - 1) * 100);
	system("pause");
}

void SnakeGame(bool isHuman_AI) {

	InitGame();
	while (CheakSnakeSafety())
	{
		MoveSnake();
		DrewSnake(isHuman_AI);
		TrunSnake(isHuman_AI, 1);
	}
	DrewSnake(isHuman_AI);
	system("pause");
}

void HELP() {

}