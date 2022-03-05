#pragma once
#ifndef _SKANE_H
#define _SNAKE_H

#include<easyx.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<math.h>

//Snake Game
#define x					50	
#define s					1500
#define xx					(x + 2)
#define ss					(s + 2 * (xx + s / x))
#define mp					15
#define x0					30
#define y0					50
#define pw					(2 * x0 + xx * mp)
#define ph					(2 * y0 + (ss / xx) * mp)
#define x1					3 * pw / 10
#define x2					7 * pw / 10
#define y					4 * y0 / 5
#define setWidth			2 * y0 / 5
#define theMapBorder_x1		x0 + mp
#define theMapBorder_y1		y0 + mp
#define theMapBorder_x2		x0 + xx * mp - mp
#define theMapBorder_y2		y0 + ss / xx * mp - mp

//Snake Dircetion
#define unkown		0
#define left		-1
#define up			-xx
#define down		xx
#define right		1

//Snakebody
#define apple				YELLOW
#define SnakeBody			BROWN
#define none				LIGHTGRAY
#define wall				BLACK

struct SnakeMap
{
	int adr;
	int dir;
};

struct SnakeRelevant
{
	int head;
	int tail;
	int food;
	int score;
	int init_speed;
	int tempdir;
	int condition;
	int x_FoodHead;
	int y_FoodHead;
	float speed;
};

//Desk
char SELECT();
void DEBUGAlpha();
void SnakeGame(bool);
void HELP();

//Drew
void DISPLAY_DESK();
void fnDrawSnakeBody(struct SnakeMap* map, struct SnakeRelevant* absnake);
void fnOutputMessage(struct SnakeMap* map, struct SnakeRelevant* absnake);

//CPU
void InitGame();
void AddApple();
void TrunSnake(bool isHuman_AI);
bool CheakSnakeSafety();
void DrewSnake();
void MoveSnake();

//Al
int TrunSnake_byAlpha(struct SnakeMap* map, struct SnakeRelevant* absnake);
int planA(struct SnakeMap* map, struct SnakeRelevant* absnake, int now_dir);
int NoDie(struct SnakeMap* map, struct SnakeRelevant* absnake, int now_dir);

//Tools
int isSnakeBody(int op);
int ManHaadun_x(int a, int b);
int ManHaadun_y(int a, int b);
int TrunSnake_byPlayer(int dir);
void MoveSnake_Head(struct SnakeMap* map, int* tempdir, int* head);
void MoveSnake_Tail(struct SnakeMap* map, int* tail);
int _condition(struct SnakeMap* map, int head);
void SpeedSnake(struct SnakeRelevant* absnake);

#endif // !_SKANE_H
