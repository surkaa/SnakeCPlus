#include"snake.h"

void DISPLAY_DESK() {

	initgraph(pw, ph, EW_DBLCLKS);

	setbkcolor(WHITE);
	cleardevice();

	settextcolor(0xFFFF00);
	settextstyle(70, 0, L"����");
	outtextxy(110, 70, L"̰");
	outtextxy(386, 70, L"��");
	outtextxy(660, 70, L"��");

	settextcolor(0xAAAA00);
	settextstyle(40, 0, L"����");
	outtextxy(290, 220, L"A  ��ʼ��Ϸ");
	outtextxy(290, 300, L"B  �۲�ģʽ");
	outtextxy(290, 380, L"C  ��Ϸ����");

}


void fnDrawSnakeBody(struct SnakeMap* map, struct SnakeRelevant* absnake) {
	//����
	cleardevice();
	int xh = 0;
	int yh = 0;
	for (int i = xx + 1; i < ss - xx; i++) {
		if (i % xx == 0 || i % xx == xx - 1)
			continue;
		//���������ɫ�滭����
		if (i == absnake->head)
			setfillcolor(LIGHTBLUE);
		else if (i == absnake->tail)
			setfillcolor(RED);
		else
			setfillcolor(map[i].adr);
		//��Ƿ������Ͻ�����
		xh = x0 + (i % xx) * mp;
		yh = y0 + (i / xx) * mp;
		solidrectangle(xh, yh, xh + mp, yh + mp);
	}

}

//���У���������������������������������������������
void fnOutputMessage(struct SnakeMap* map, struct SnakeRelevant* absnake) {

	//���ݸ���
	absnake->x_FoodHead = ManHaadun_x(absnake->food, absnake->head);
	absnake->y_FoodHead = ManHaadun_y(absnake->head, absnake->food);
	absnake->condition = _condition(map, absnake->head);

	//�ڱ߿�
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 2);
	rectangle(theMapBorder_x1, theMapBorder_y1, theMapBorder_x2, theMapBorder_y2);
	setlinecolor(RED);
	line(x1, y, x2, y);
	
	setbkmode(TRANSPARENT);
	settextstyle(setWidth, setWidth / 2, L"����");
	wchar_t str[33];
	swprintf_s(str, L"�÷�:%4d|�ٶ�:%3.0f|ʳ������(%2d,%2d)|%1X", absnake->score,
		absnake->speed, absnake->x_FoodHead, absnake->y_FoodHead, absnake->condition);
	outtextxy(x1, y - setWidth - 3, str);
}
