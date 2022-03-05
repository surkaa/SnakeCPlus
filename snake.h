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
#define s					1500
#define x					50
#define mp					15
#define x0					45
#define y0					50
#define pw					2 * x0 + x * mp
#define ph					2 * y0 + (s / x) * mp
#define PixelSnakeWidth		x * mp
#define PixelSnakeHigh		(s / x) * mp

//Snake Dircetion
#define unkown				0
#define left				-1
#define up					-x
#define down				x
#define right				1

//Snakebody
#define apple				YELLOW
#define SnakeBody			BROWN
#define none				LIGHTGRAY


struct SnakeMap
{
	int adr;
	int dir;
	int op;			//op: 0未访问  1边界已访问  -1已访问
	int cost;
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
void DrewSnake_Game_Interface();
void DrewSnake_SnakeMap(struct SnakeMap* map, struct SnakeRelevant* absnake);
void DrewSnake_Game_Information(struct SnakeMap* map, struct SnakeRelevant* absnake);
void DrewSanke_Speed(struct SnakeRelevant* absnake);

//SnakeCPU
void InitGame();
void AddApple();
void TrunSnake(bool isHuman_AI);
bool CheakSnakeSafety();
void DrewSnake();
void MoveSnake();

//AlphaSnake
int TrunSnake_byAlpha(struct SnakeMap* map, struct SnakeRelevant* absnake);
void Refresh_Cost(struct SnakeMap* map, int head, int next, int Nowcost);
int ReturnTheMinCost(struct SnakeMap* map);

//Tools
int isSnakeBody(int op);
int ManHaadun_x(int a, int b);
int ManHaadun_y(int a, int b);
int TrunSnake_byPlayer(int dir);
void MoveSnake_Head(struct SnakeMap* map, int* tempdir, int* head);
void MoveSnake_Tail(struct SnakeMap* map, int* tail);

#endif // !_SKANE_H
