#pragma once
#ifndef _SKANE_H
#define _SNAKE_H

#include<easyx.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<math.h>

//Init Msp
//#define mapSize	        1500		//蛇活动的格数(1500)
//#define mapWidth          50			//蛇活动的宽度(50)
#define mapSize	            1500		//蛇活动的格数
#define mapWidth            50			//蛇活动的宽度
#define cellWidth			20			//蛇身的宽度
#define cellGap				3			//蛇身之间的间隙
#define initlong			2			//蛇的初始长度
#define PlayerSpeed			80			//玩家的屏幕刷新速度
#define AISpeed			    0			//机器的屏幕刷新速度
#define DrewStartPoint_x	30			//蛇图绘画起始点X
#define DrewStartPoint_y	50			//蛇图绘画起始点Y

#define SpeedRelationship	(log(PlayerSpeed) / log(2) / mapSize)
#define mapHigh	            (mapSize / mapWidth)									
#define pmapW               (mapWidth + 2)
#define pmapH               (mapHigh + 2)
#define pmapS		        (pmapW * pmapH)


//Dircetion
#define unkown				0
#define left				-1
#define up					-pmapW
#define down				pmapW
#define right				1

//SNAKE.Attributes
#define apple				YELLOW
#define SnakeBody			BROWN
#define none				LIGHTGRAY
#define wall				BLACK

struct SnakeMap
{
	int Attributes;
	int Direction;
	int Number;
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
	int stepNumber;
	int speed;
};

//Desk
char SELECT();											//采集信息
void DEBUGAlpha(bool);									//调试游戏
void GameStart(bool);									//开始游戏
void HELP();											//游戏帮助

//Display
void DISPLAY_DESK();									//描绘桌面
void fnDrawSnakeBody(SnakeMap*, SnakeRelevant*);		//绘画蛇身
void fnOutputMessage(SnakeRelevant*, bool);				//输出信息

//CPU
void InitMsp();											//地图初始化
void AddApple();										//生成食物
void TrunSnake(bool, bool);								//蛇的转向
bool CheakSnakeSafety();								//检查此方向是否通行
int isSnakeBody(int);									//是否能让蛇通行
int CheakHtoTFSafety(int, int);							//检查某方向能否连通某地点
bool fnNextCheck(int);								    //检查下一步
void fnAroundCheak(int, int);					        //检查下一步的周围
void fnDisplaySnake(bool);								//绘图
void fnRefresh();										//更新数据
void MoveSnake();										//移动蛇
double debuggingResults();								//返回此次调试成绩

//Al
int TrunSnake_byAlpha(SnakeMap*, SnakeRelevant*);		//通过机器转向
int fnFarthestToTheSnakeFood_A(SnakeRelevant*);			//远离食物方案A
int fnFarthestToTheSnakeFood_B(SnakeRelevant*);			//远离食物方案B
int fnFarthestToTheSnakeTail(SnakeRelevant*);			//远离蛇尾方案


//Tools
int ManHaadun_x(int, int);								//两点竖直距离
int ManHaadun_y(int, int);								//两点水平距离
int TrunSnake_byPlayer(int);							//通过玩家转向
void MoveSnake_Head(SnakeMap*, int*, int*);				//移动蛇头
void MoveSnake_Tail(SnakeMap*, int*);					//移动蛇尾
int getSquareSafetyFactor(int);							//获取方块周边通行率
void SpeedSnake(bool, SnakeRelevant*);					//截停

#endif // !_SKANE_H
