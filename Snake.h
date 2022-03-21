#pragma once
#ifndef _SKANE_H
#define _SNAKE_H

#include<easyx.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<math.h>

//Game
#define mapSize	            900
#define mapWidth            30
#define mapHigh	            (mapSize / mapWidth)
#define pmapW               (mapWidth + 2)
#define pmapH               (mapHigh + 2)
#define pmapS		        (pmapW * pmapH)
#define cellGap				3
#define cellWidth			25
#define initlong			15
#define initspeed			1

//Drew
#define DrewStartPoint_x	3
#define DrewStartPoint_y	50
#define screenWidth			(2 * DrewStartPoint_x + pmapW * cellWidth)
#define screenHigh			(2 * DrewStartPoint_y + pmapH * cellWidth)
#define outputMessageA_x	(3 * screenWidth / 10)
#define outputMessageB_x	(7 * screenWidth / 10)
#define outputMessage__x    ((outputMessageA_x + outputMessageB_x) / 2) - 230
#define outputMessageAB_y	(4 * DrewStartPoint_y / 5)
#define SpeedRelationship	(log(initspeed) / log(2) / mapSize)
#define MessageWidth		(DrewStartPoint_y / 2)
#define MapBorderA_x		(DrewStartPoint_x + cellWidth)
#define MapBorderA_y		(DrewStartPoint_y + cellWidth)
#define MapBorderB_x		(DrewStartPoint_x + pmapW * cellWidth - cellWidth - cellGap)
#define MapBorderB_y		(DrewStartPoint_y + pmapH * cellWidth - cellWidth - cellGap)

//Dircetion
#define unkown				0
#define left				-1
#define up					-pmapW
#define down				pmapW
#define right				1

//Map.adr
#define apple				YELLOW
#define SnakeBody			BROWN
#define none				LIGHTGRAY
#define wall				BLACK

struct SnakeMap
{
	int adr;
	int dir;
	int way;
};

struct SnakeRelevant
{
	int head;
	int tail;
	int food;
	int score;
	int tempdir;
	int condition;
	int x_FoodHead;
	int y_FoodHead;
	int x_TailHead;
	int y_TailHead;
	int stepNumber;
	double speed;
};

//Desk
char SELECT();
void DEBUGAlpha(bool);
void SnakeGame(bool);
void HELP();

//Drew
void DISPLAY_DESK();
void fnDrawSnakeBody(SnakeMap*, SnakeRelevant*);
void fnOutputMessage(SnakeMap*, SnakeRelevant*);

//CPU
void InitGame();
void AddApple();
void TrunSnake(bool, bool);
bool CheakSnakeSafety();
int isSnakeBody(int);
int CheakHtoTFSafety(int, int);
bool update(int n);
void around(int num, int nway);
void DrewSnake(bool);
void fnRefresh();
void MoveSnake();
void fnRefresh();
double completeness();

//Al
int TrunSnake_byAlpha(SnakeMap*, SnakeRelevant*);
int fnAsFarAsThePathtoFood(SnakeRelevant*);
int fnAsFarAsThePathtoFood_(SnakeRelevant*);
int fnAsFarAsThePathtoTail_(SnakeRelevant*);


//Tools
int ManHaadun_x(int, int);
int ManHaadun_y(int, int);
int TrunSnake_byPlayer(int);
void MoveSnake_Head(SnakeMap*, int*, int*);
void MoveSnake_Tail(SnakeMap*, int*);
int _condition(int);
void SpeedSnake(bool, SnakeRelevant*);

#endif // !_SKANE_H
