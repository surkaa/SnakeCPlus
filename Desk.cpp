#include"snake.h"

char SELECT() {

	char result = _getch();
	cleardevice();

	return result;
}

void DEBUGAlpha() {

}

void SnakeGame(bool isHuman_AI) {

	InitGame();
	while (CheakSnakeSafety())
	{
		MoveSnake();
		DrewSnake();
		TrunSnake(isHuman_AI);
	}
}

void HELP() {

}