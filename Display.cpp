#include"snake.h"

void DISPLAY_DESK() {

	initgraph(screenWidth, screenHigh, 1);

	setbkcolor(WHITE);
	cleardevice();

	settextcolor(0xFFFF00);
	settextstyle(70, 35, L"楷体");
	outtextxy(110, 70, L"贪");
	outtextxy(386, 70, L"吃");
	outtextxy(660, 70, L"蛇");

	settextcolor(0xAAAA00);
	settextstyle(40, 0, L"楷体");
	outtextxy(290, 220, L"A  开始游戏");
	outtextxy(290, 300, L"B  观察模式");
	outtextxy(290, 380, L"C  游戏帮助");

}

void fnDrawSnakeBody(SnakeMap* map, SnakeRelevant* absnake) {
	int xh = 0;
	int yh = 0;

	//清屏
	cleardevice();

	//铺底色
	setfillcolor(none);
	solidrectangle(MapBorderA_x, MapBorderA_y, MapBorderB_x, MapBorderB_y);

	for (int i = pmapW + 1; i < pmapS - pmapW; i++) {
		//跳过边界和空方快的绘画
		if (i % pmapW == 0 || i % pmapW == pmapW - 1 || map[i].adr == none)
			continue;
		//更新坐标
		xh = DrewStartPoint_x + (i % pmapW) * cellWidth;
		yh = DrewStartPoint_y + (i / pmapW) * cellWidth;
		//绘画食物
		if (i == absnake->food) {
			setfillcolor(apple);
			solidrectangle(xh, yh, xh + cellWidth - cellGap, yh + cellWidth - cellGap);
			continue;
		}
		//绘画蛇头
		if (i == absnake->head) {
			setfillcolor(LIGHTBLUE);
			solidrectangle(xh, yh, xh + cellWidth - cellGap, yh + cellWidth - cellGap);
			continue;
		}
		//蛇身
		if (i == absnake->tail)
			setfillcolor(RED);
		else
			setfillcolor(SnakeBody);
		//突起结点以连接个个方块
		switch (map[i].dir)
		{
		case left:
			solidrectangle(xh - cellGap, yh, xh + cellWidth - cellGap, yh + cellWidth - cellGap);
			break;
		case up:
			solidrectangle(xh, yh - cellGap, xh + cellWidth - cellGap, yh + cellWidth - cellGap);
			break;
		case right:
			solidrectangle(xh, yh, xh + cellWidth, yh + cellWidth - cellGap);
			break;
		case down:
			solidrectangle(xh, yh, xh + cellWidth - cellGap, yh + cellWidth);
			break;
		case unkown:
			solidrectangle(xh, yh, xh + cellWidth - cellGap, yh + cellWidth - cellGap);
			break;
		}
	}

}

void fnOutputMessage(SnakeMap* map, SnakeRelevant* absnake)
{
	//黑边框
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 2);
	rectangle(MapBorderA_x, MapBorderA_y, MapBorderB_x, MapBorderB_y);

	setlinecolor(RED);
	line(outputMessageA_x, outputMessageAB_y, outputMessageB_x, outputMessageAB_y);

	setbkmode(TRANSPARENT);
	settextstyle(MessageWidth, MessageWidth / 2, L"微软雅黑");
	wchar_t str[80];
	swprintf_s(str, 
		L"score:%3d|step:%3d|fxy(%3d,%3d,%1d)|txy(%3d,%3d,%1d)|spe:%%%2.0lf",
		absnake->score,
		absnake->stepNumber,
		absnake->x_FoodHead,
		absnake->y_FoodHead,
		CheakHtoTFSafety(absnake->food, 0),
		absnake->x_TailHead,
		absnake->y_TailHead,
		CheakHtoTFSafety(absnake->tail, 0),
		(initspeed - absnake->speed) * 100 / initspeed);
	outtextxy(outputMessage__x, outputMessageAB_y - MessageWidth - cellGap, str);
}
