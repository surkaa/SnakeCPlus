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

void DrewSnake_Game_Interface() {
	setlinecolor(RED);
	setlinestyle(PS_SOLID, 3);
	rectangle(x0, y0, PixelSnakeWidth + x0,
		PixelSnakeHigh + y0);
	cleardevice();
}

void DrewSnake_SnakeMap(struct SnakeMap* map, struct SnakeRelevant* absnake) {
	int xh = 0;
	int yh = 0;
	for (int i = 0; i < s; i++) {
		//���������ɫ�滭����
		if (i == absnake->head)
			setfillcolor(LIGHTBLUE);
		else if (i == absnake->tail)
			setfillcolor(RED);
		else
			setfillcolor(map[i].adr);
		xh = x0 + (i % x) * mp;
		yh = y0 + (i / x) * mp;
		solidrectangle(xh, yh, xh + mp, yh + mp);
	}
}

void DrewSnake_Game_Information(struct SnakeMap* map, struct SnakeRelevant* absnake) {
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 2);
	rectangle(x0, y0, x0 + PixelSnakeWidth, y0 + PixelSnakeHigh);
	setlinecolor(CYAN);
	settextcolor(DARKGRAY);
	int x1 = x0 + 3 * mp * x / 10;
	int x2 = x0 + 7 * mp * x / 10;
	int y1 = 2 * y0 / 10;
	int y2 = 7 * y0 / 10;
	rectangle(x1, y1, x2, y2);
	absnake->x_FoodHead = ManHaadun_x(absnake->food, absnake->head);
	absnake->y_FoodHead = ManHaadun_y(absnake->head, absnake->food);
	absnake->condition =
		8 * isSnakeBody(map[absnake->head + left].adr) +
		4 * isSnakeBody(map[absnake->head + up].adr) +
		2 * isSnakeBody(map[absnake->head + down].adr) +
		1 * isSnakeBody(map[absnake->head + right].adr);
	setbkmode(TRANSPARENT);
	settextstyle(3 * y0 / 10, 0, L"����");
	wchar_t str[50];
	swprintf_s(str, L"�÷�:%3d|�ٶ�:%3.0f|ʳ������(%2d,%2d)|%X",
		absnake->score, absnake->speed, absnake->x_FoodHead, absnake->y_FoodHead, absnake->condition);
	outtextxy(x1 + 2, y1 + 4, str);
}

void DrewSanke_Speed(struct SnakeRelevant* absnake) {
	//Ϊʹ��������ʱ�õ��ٶ� speed = 1 �����ϵ�� k ����
	double k = pow(2, -absnake->score * log(absnake->init_speed) / log(2) / s);
	absnake->speed = absnake->init_speed * k;
	Sleep(absnake->speed);
}