#include"Drew.h"

void DISPLAY_DESK() {

	initgraph(screenWidth, screenHigh);

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

void fnDrawSnakeBody(SnakeMap* map, SnakeRelevant* Data) {
	int xh = 0;
	int yh = 0;

	//清屏
	cleardevice();

	//铺底色
	setfillcolor(none);
	solidrectangle(MapBorderA_x, MapBorderA_y, MapBorderB_x, MapBorderB_y);

	for (int i = pmapW + 1; i < pmapS - pmapW; i++) {
		//跳过边界和空方快的绘画
		if (i % pmapW == 0 || i % pmapW == pmapW - 1 || map[i].Attributes == none)
			continue;
		//更新坐标
		xh = DrewStartPoint_x + (i % pmapW) * cellWidth;
		yh = DrewStartPoint_y + (i / pmapW) * cellWidth;
		//绘画食物
		if (i == Data->food) {
			setfillcolor(apple);
			solidrectangle(xh, yh, xh + cellWidth - cellGap, yh + cellWidth - cellGap);
			continue;
		}
		//绘画蛇头
		if (i == Data->head) {
			setfillcolor(LIGHTBLUE);
			solidrectangle(xh, yh, xh + cellWidth - cellGap, yh + cellWidth - cellGap);
			continue;
		}
		//蛇身
		if (i == Data->tail)
			setfillcolor(RED);
		else
			setfillcolor(SnakeBody);
		//突起结点以连接个个方块
		switch (map[i].Direction)
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

void fnOutputMessage(SnakeRelevant* Data, bool op)
{
	//黑边框
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 2);
	rectangle(MapBorderA_x, MapBorderA_y, MapBorderB_x, MapBorderB_y);

	setlinecolor(RED);
	line(outputMessageA_x, outputMessageAB_y, outputMessageB_x, outputMessageAB_y);

	setbkmode(TRANSPARENT);
	settextstyle(MessageWidth, MessageWidth / 2, L"微软雅黑");
	wchar_t str[50];
	if(op)
		swprintf_s(str, 
			L"score%3d|Dir%2d|step%3d|fxy%3d|txy%3d",
			(int)(100 * debuggingResults()),
			Data->tempdir,
			Data->stepNumber,
			CheakHtoTFSafety(Data->food, 0),
			CheakHtoTFSafety(Data->tail, 0)
		);
	else
		swprintf_s(str, 
			L"score:%3d|spe:%%%2d|fxy(%3d,%3d)",
			Data->score,
			(int)(PlayerSpeed - Data->speed) * 100 / PlayerSpeed,
			Data->x_FoodHead,
			Data->y_FoodHead
		);
	outtextxy(outputMessage__x, outputMessageAB_y - MessageWidth - 2, str);
}
