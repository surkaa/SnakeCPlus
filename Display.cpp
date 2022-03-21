#include"snake.h"

void DISPLAY_DESK() {

	initgraph(screenWidth, screenHigh, 1);

	setbkcolor(WHITE);
	cleardevice();

	settextcolor(0xFFFF00);
	settextstyle(70, 35, L"����");
	outtextxy(110, 70, L"̰");
	outtextxy(386, 70, L"��");
	outtextxy(660, 70, L"��");

	settextcolor(0xAAAA00);
	settextstyle(40, 0, L"����");
	outtextxy(290, 220, L"A  ��ʼ��Ϸ");
	outtextxy(290, 300, L"B  �۲�ģʽ");
	outtextxy(290, 380, L"C  ��Ϸ����");

}

void fnDrawSnakeBody(SnakeMap* map, SnakeRelevant* absnake) {
	int xh = 0;
	int yh = 0;

	//����
	cleardevice();

	//�̵�ɫ
	setfillcolor(none);
	solidrectangle(MapBorderA_x, MapBorderA_y, MapBorderB_x, MapBorderB_y);

	for (int i = pmapW + 1; i < pmapS - pmapW; i++) {
		//�����߽�Ϳշ���Ļ滭
		if (i % pmapW == 0 || i % pmapW == pmapW - 1 || map[i].adr == none)
			continue;
		//��������
		xh = DrewStartPoint_x + (i % pmapW) * cellWidth;
		yh = DrewStartPoint_y + (i / pmapW) * cellWidth;
		//�滭ʳ��
		if (i == absnake->food) {
			setfillcolor(apple);
			solidrectangle(xh, yh, xh + cellWidth - cellGap, yh + cellWidth - cellGap);
			continue;
		}
		//�滭��ͷ
		if (i == absnake->head) {
			setfillcolor(LIGHTBLUE);
			solidrectangle(xh, yh, xh + cellWidth - cellGap, yh + cellWidth - cellGap);
			continue;
		}
		//����
		if (i == absnake->tail)
			setfillcolor(RED);
		else
			setfillcolor(SnakeBody);
		//ͻ���������Ӹ�������
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
	//�ڱ߿�
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 2);
	rectangle(MapBorderA_x, MapBorderA_y, MapBorderB_x, MapBorderB_y);

	setlinecolor(RED);
	line(outputMessageA_x, outputMessageAB_y, outputMessageB_x, outputMessageAB_y);

	setbkmode(TRANSPARENT);
	settextstyle(MessageWidth, MessageWidth / 2, L"΢���ź�");
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
