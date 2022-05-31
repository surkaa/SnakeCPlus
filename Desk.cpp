#include"snake.h"

char SELECT() {

	char result = _getch();
	cleardevice();

	return result;
}

void DEBUGAlpha(bool op) {
	int i = 0;
	double agedebuggingResults = 0;
	while (i++ < 100) {
		InitMsp();
		while (CheakSnakeSafety()) {
			MoveSnake();
			TrunSnake(true, op);
		}
		agedebuggingResults += debuggingResults();
		printf("\n\tNo.%-4d %%%3.1lf", i, 100 * debuggingResults());
		if (i % 5 == 0) {
			//print();
			printf("\n\n\tAge: %%%4.2lf", agedebuggingResults / i * 100);
			if (op) {
				fnDisplaySnake(1);
				Sleep(500);
				if (_kbhit())
					system("pause");
			}
		}
	}
	printf("\n\n\n\n\tAge: %%%4.2lf", agedebuggingResults / (i - 1) * 100);
	system("pause");
}

void GameStart(bool isHuman_AI) {

	InitMsp();
	while (CheakSnakeSafety())
	{
		MoveSnake();
		fnDisplaySnake(isHuman_AI);
		TrunSnake(isHuman_AI, 1);
	}
	fnDisplaySnake(isHuman_AI);
	system("pause");
}

void HELP() {

}
