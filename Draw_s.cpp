#include "stdafx.h"
#include "Draw_s.h"
bool is_in(CPoint point, int z0, int z1)
{
	if (((point.y < z1-1) && (point.x < z1-1)) && ((point.y > z0) && (point.x > z0)))
		return TRUE;
	return FALSE;
}
CPoint get_place(CPoint point, int z0, int z1) {
	int size = (z1 - z0) / 8; //52 - каждое поле делится на 52*52 пикселя.
	CPoint pt;
	int y = point.y;
	int x = point.x;
	int number = (y - z0) / size;
	int letter = (x - z0) / size;
	pt.x = letter;
	pt.y = number;
	return pt;
}
void paint_fig(CDC * dc, char fig, CPoint point, int z0, int z1) //нарисовать фигуру в указанном поле.
{
	CPoint pt;
	pt.y = z0 + point.y*(z1 - z0) / 8;
	pt.x = z0 + point.x*(z1 - z0) / 8;
	draw_fig(dc, fig, pt,  z0,  z1);
}

void draw_move(CDC * dc, square Square[][8], CPoint StartPoint, CPoint FinishPoint)
{
	paint_fig(dc, ' ', StartPoint); //рисуем в старом месте
	paint_fig(dc, ' ', FinishPoint); //стираем в новом месте
	paint_fig(dc, Square[FinishPoint.y][FinishPoint.x].fig, FinishPoint); //рисуем в новом месте
}

void draw_fig(CDC *dc,char fig,CPoint pt, int z0, int z1)
{
	// rgb(143, 36, 38) красное поле
	// rgb(255, 251, 219) белое поле
	// rgb(0, 0, 255) синeе 
	//RGB(171, 143, 97) бежевое поле
	// красные фигуры 166, 30, 46
	dc->SelectObject(CreatePen(PS_SOLID, 1, RGB(0, 0, 0))); //Чёрные фигуры
	if (fig < 'a') {
		dc->SelectObject(CreatePen(PS_SOLID, 1, RGB(232, 109, 60))); //белые фигуры  (f 232, 109, 60 )
	}
	int add_x = pt.x;
	int add_y = pt.y;

	switch ((fig | ' '))
	{
	case ' ':
		if (((pt.x - z0) / 52 + (pt.y - z0) / 52) & 1) //== 1
		//if (((pt.x - z0) / 52 + (pt.y - z0) / 52) % 2 == 1)
			dc->SelectObject(CreatePen(PS_SOLID, 1, RGB(168, 168, 167))); //чёрное поле
		else
			dc->SelectObject(CreatePen(PS_SOLID, 1, RGB(255, 253, 235))); // белое поле (f 255, 253, 235
	
			
		for (int i = 0; i < 52; i++) {
			dc->MoveTo(add_x, add_y + i);
			dc->LineTo(add_x + 52, add_y + i);
		}
		break;
	case 'q': //королева
		dc->MoveTo(add_x + 25, add_y + 8);
		dc->LineTo(add_x + 25, add_y + 8);

		dc->MoveTo(add_x + 24, add_y + 9);
		dc->LineTo(add_x + 26, add_y + 9);

		dc->MoveTo(add_x + 23, add_y + 10);
		dc->LineTo(add_x + 27, add_y + 10);

		dc->MoveTo(add_x + 24, add_y + 11);
		dc->LineTo(add_x + 26, add_y + 11);

		dc->MoveTo(add_x + 25, add_y + 12);
		dc->LineTo(add_x + 25, add_y + 12); //шар сверху

		dc->MoveTo(add_x + 21, add_y + 13);
		dc->LineTo(add_x + 29, add_y + 13);

		dc->MoveTo(add_x + 21, add_y + 14);
		dc->LineTo(add_x + 29, add_y + 14);

		dc->MoveTo(add_x + 22, add_y + 15);
		dc->LineTo(add_x + 28, add_y + 15);

		dc->MoveTo(add_x + 22, add_y + 16);
		dc->LineTo(add_x + 28, add_y + 16);

		dc->MoveTo(add_x + 23, add_y + 17);
		dc->LineTo(add_x + 27, add_y + 17);

		dc->MoveTo(add_x + 23, add_y + 18);
		dc->LineTo(add_x + 27, add_y + 18); //подставка

		dc->MoveTo(add_x + 21, add_y + 19);
		dc->LineTo(add_x + 29, add_y + 19);

		dc->MoveTo(add_x + 19, add_y + 20);
		dc->LineTo(add_x + 31, add_y + 20);

		dc->MoveTo(add_x + 19, add_y + 21);
		dc->LineTo(add_x + 31, add_y + 21);

		dc->MoveTo(add_x + 19, add_y + 22);
		dc->LineTo(add_x + 31, add_y + 22); //юбочка

		dc->MoveTo(add_x + 23, add_y + 23);
		dc->LineTo(add_x + 27, add_y + 23);

		dc->MoveTo(add_x + 23, add_y + 24);
		dc->LineTo(add_x + 27, add_y + 24);

		dc->MoveTo(add_x + 23, add_y + 25);
		dc->LineTo(add_x + 27, add_y + 25);

		dc->MoveTo(add_x + 23, add_y + 26);
		dc->LineTo(add_x + 27, add_y + 26);

		dc->MoveTo(add_x + 22, add_y + 27);
		dc->LineTo(add_x + 28, add_y + 27);

		dc->MoveTo(add_x + 22, add_y + 28);
		dc->LineTo(add_x + 28, add_y + 28);

		dc->MoveTo(add_x + 22, add_y + 29);
		dc->LineTo(add_x + 28, add_y + 29);

		dc->MoveTo(add_x + 22, add_y + 30);
		dc->LineTo(add_x + 28, add_y + 30);

		dc->MoveTo(add_x + 22, add_y + 31);
		dc->LineTo(add_x + 28, add_y + 31);

		dc->MoveTo(add_x + 22, add_y + 32);
		dc->LineTo(add_x + 28, add_y + 32);

		dc->MoveTo(add_x + 22, add_y + 33);
		dc->LineTo(add_x + 28, add_y + 33);

		dc->MoveTo(add_x + 21, add_y + 34);
		dc->LineTo(add_x + 29, add_y + 34);

		dc->MoveTo(add_x + 21, add_y + 35);
		dc->LineTo(add_x + 29, add_y + 35);

		dc->MoveTo(add_x + 21, add_y + 36);
		dc->LineTo(add_x + 29, add_y + 36); //колонна

		dc->MoveTo(add_x + 20, add_y + 37);
		dc->LineTo(add_x + 30, add_y + 37);

		dc->MoveTo(add_x + 19, add_y + 38);
		dc->LineTo(add_x + 31, add_y + 38);

		dc->MoveTo(add_x + 18, add_y + 39);
		dc->LineTo(add_x + 32, add_y + 39);

		dc->MoveTo(add_x + 17, add_y + 40);
		dc->LineTo(add_x + 33, add_y + 40);

		dc->MoveTo(add_x + 17, add_y + 41);
		dc->LineTo(add_x + 33, add_y + 41);

		dc->MoveTo(add_x + 17, add_y + 42);
		dc->LineTo(add_x + 33, add_y + 42); //ноги
		break;
	case 'k': //король

		dc->MoveTo(add_x + 23, add_y + 7);
		dc->LineTo(add_x + 27, add_y + 7);

		dc->MoveTo(add_x + 23, add_y + 8);
		dc->LineTo(add_x + 27, add_y + 8);

		dc->MoveTo(add_x + 21, add_y + 9);
		dc->LineTo(add_x + 29, add_y + 9);

		dc->MoveTo(add_x + 21, add_y + 10);
		dc->LineTo(add_x + 29, add_y + 10);

		dc->MoveTo(add_x + 23, add_y + 11);
		dc->LineTo(add_x + 27, add_y + 11);

		dc->MoveTo(add_x + 23, add_y + 12);
		dc->LineTo(add_x + 27, add_y + 12);  //крест

		dc->MoveTo(add_x + 21, add_y + 13);
		dc->LineTo(add_x + 29, add_y + 13);

		dc->MoveTo(add_x + 21, add_y + 14);
		dc->LineTo(add_x + 29, add_y + 14);

		dc->MoveTo(add_x + 22, add_y + 15);
		dc->LineTo(add_x + 28, add_y + 15);

		dc->MoveTo(add_x + 22, add_y + 16);
		dc->LineTo(add_x + 28, add_y + 16);

		dc->MoveTo(add_x + 23, add_y + 17);
		dc->LineTo(add_x + 27, add_y + 17);

		dc->MoveTo(add_x + 23, add_y + 18);
		dc->LineTo(add_x + 27, add_y + 18); //подставка

		dc->MoveTo(add_x + 22, add_y + 19);
		dc->LineTo(add_x + 28, add_y + 19);

		dc->MoveTo(add_x + 21, add_y + 20);
		dc->LineTo(add_x + 29, add_y + 20);

		dc->MoveTo(add_x + 20, add_y + 21);
		dc->LineTo(add_x + 30, add_y + 21);

		dc->MoveTo(add_x + 19, add_y + 22);
		dc->LineTo(add_x + 31, add_y + 22); //юбочка

		dc->MoveTo(add_x + 23, add_y + 23);
		dc->LineTo(add_x + 27, add_y + 23);

		dc->MoveTo(add_x + 23, add_y + 24);
		dc->LineTo(add_x + 27, add_y + 24);

		dc->MoveTo(add_x + 23, add_y + 25);
		dc->LineTo(add_x + 27, add_y + 25);

		dc->MoveTo(add_x + 23, add_y + 26);
		dc->LineTo(add_x + 27, add_y + 26);

		dc->MoveTo(add_x + 22, add_y + 27);
		dc->LineTo(add_x + 28, add_y + 27);

		dc->MoveTo(add_x + 22, add_y + 28);
		dc->LineTo(add_x + 28, add_y + 28);

		dc->MoveTo(add_x + 22, add_y + 29);
		dc->LineTo(add_x + 28, add_y + 29);

		dc->MoveTo(add_x + 22, add_y + 30);
		dc->LineTo(add_x + 28, add_y + 30);

		dc->MoveTo(add_x + 22, add_y + 31);
		dc->LineTo(add_x + 28, add_y + 31);

		dc->MoveTo(add_x + 22, add_y + 32);
		dc->LineTo(add_x + 28, add_y + 32);

		dc->MoveTo(add_x + 22, add_y + 33);
		dc->LineTo(add_x + 28, add_y + 33);

		dc->MoveTo(add_x + 21, add_y + 34);
		dc->LineTo(add_x + 29, add_y + 34);

		dc->MoveTo(add_x + 21, add_y + 35);
		dc->LineTo(add_x + 29, add_y + 35);

		dc->MoveTo(add_x + 21, add_y + 36);
		dc->LineTo(add_x + 29, add_y + 36); //колонна

		dc->MoveTo(add_x + 20, add_y + 37);
		dc->LineTo(add_x + 30, add_y + 37);

		dc->MoveTo(add_x + 19, add_y + 38);
		dc->LineTo(add_x + 31, add_y + 38);

		dc->MoveTo(add_x + 18, add_y + 39);
		dc->LineTo(add_x + 32, add_y + 39);

		dc->MoveTo(add_x + 17, add_y + 40);
		dc->LineTo(add_x + 33, add_y + 40);

		dc->MoveTo(add_x + 17, add_y + 41);
		dc->LineTo(add_x + 33, add_y + 41);

		dc->MoveTo(add_x + 17, add_y + 42);
		dc->LineTo(add_x + 33, add_y + 42); //ноги

		break;
	case 'h': //конь 
		dc->MoveTo(add_x + 24, add_y + 6);
		dc->LineTo(add_x + 24, add_y + 6);

		dc->MoveTo(add_x + 24, add_y + 7);
		dc->LineTo(add_x + 25, add_y + 7);

		dc->MoveTo(add_x + 24, add_y + 8);
		dc->LineTo(add_x + 26, add_y + 8);

		dc->MoveTo(add_x + 23, add_y + 9);
		dc->LineTo(add_x + 28, add_y + 9);

		dc->MoveTo(add_x + 22, add_y + 10);
		dc->LineTo(add_x + 30, add_y + 10);

		dc->MoveTo(add_x + 22, add_y + 11);
		dc->LineTo(add_x + 30, add_y + 11);

		dc->MoveTo(add_x + 21, add_y + 12);
		dc->LineTo(add_x + 31, add_y + 12);  

		dc->MoveTo(add_x + 21, add_y + 13);
		dc->LineTo(add_x + 33, add_y + 13);

		dc->MoveTo(add_x + 20, add_y + 14);
		dc->LineTo(add_x + 34, add_y + 14);

		dc->MoveTo(add_x + 20, add_y + 15);
		dc->LineTo(add_x + 35, add_y + 15);

		dc->MoveTo(add_x + 20, add_y + 16);
		dc->LineTo(add_x + 34, add_y + 16);

		dc->MoveTo(add_x + 19, add_y + 17);
		dc->LineTo(add_x + 27, add_y + 17);

		dc->MoveTo(add_x + 32, add_y + 17);
		dc->LineTo(add_x + 34, add_y + 17);

		dc->MoveTo(add_x + 19, add_y + 18);
		dc->LineTo(add_x + 28, add_y + 18); 

		dc->MoveTo(add_x + 33, add_y + 18);
		dc->LineTo(add_x + 34, add_y + 18); //голова

		dc->MoveTo(add_x + 19, add_y + 19);
		dc->LineTo(add_x + 28, add_y + 19);

		dc->MoveTo(add_x + 19, add_y + 20);
		dc->LineTo(add_x + 29, add_y + 20);

		dc->MoveTo(add_x + 19, add_y + 21);
		dc->LineTo(add_x + 30, add_y + 21);

		dc->MoveTo(add_x + 19, add_y + 22);
		dc->LineTo(add_x + 30, add_y + 22);

		dc->MoveTo(add_x + 19, add_y + 23);
		dc->LineTo(add_x + 31, add_y + 23);

		dc->MoveTo(add_x + 19, add_y + 24);
		dc->LineTo(add_x + 32, add_y + 24);

		dc->MoveTo(add_x + 19, add_y + 25);
		dc->LineTo(add_x + 32, add_y + 25);

		dc->MoveTo(add_x + 19, add_y + 26);
		dc->LineTo(add_x + 33, add_y + 26);

		dc->MoveTo(add_x + 19, add_y + 27);
		dc->LineTo(add_x + 33, add_y + 27);

		dc->MoveTo(add_x + 19, add_y + 28);
		dc->LineTo(add_x + 34, add_y + 28); // шея 

		dc->MoveTo(add_x + 19, add_y + 29);
		dc->LineTo(add_x + 34, add_y + 29);

		dc->MoveTo(add_x + 18, add_y + 30);
		dc->LineTo(add_x + 35, add_y + 30);

		dc->MoveTo(add_x + 18, add_y + 31);
		dc->LineTo(add_x + 35, add_y + 31);

		dc->MoveTo(add_x + 17, add_y + 32);
		dc->LineTo(add_x + 35, add_y + 32);

		dc->MoveTo(add_x + 17, add_y + 33);
		dc->LineTo(add_x + 35, add_y + 33);

		dc->MoveTo(add_x + 16, add_y + 34);
		dc->LineTo(add_x + 35, add_y + 34);

		dc->MoveTo(add_x + 18, add_y + 35);
		dc->LineTo(add_x + 34, add_y + 35);

		dc->MoveTo(add_x + 18, add_y + 36);
		dc->LineTo(add_x + 33, add_y + 36);

		dc->MoveTo(add_x + 16, add_y + 37);
		dc->LineTo(add_x + 35, add_y + 37);

		dc->MoveTo(add_x + 17, add_y + 38);
		dc->LineTo(add_x + 34, add_y + 38);

		dc->MoveTo(add_x + 17, add_y + 39);
		dc->LineTo(add_x + 34, add_y + 39);

		dc->MoveTo(add_x + 16, add_y + 40);
		dc->LineTo(add_x + 35, add_y + 40);

		dc->MoveTo(add_x + 16, add_y + 41);
		dc->LineTo(add_x + 35, add_y + 41);

		dc->MoveTo(add_x + 16, add_y + 42);
		dc->LineTo(add_x + 35, add_y + 42);//основа

	case 'p': //пешка


		dc->MoveTo(add_x + 25, add_y + 15);
		dc->LineTo(add_x + 26, add_y + 15);

		dc->MoveTo(add_x + 23, add_y + 16);
		dc->LineTo(add_x + 28, add_y + 16);

		dc->MoveTo(add_x + 23, add_y + 17);
		dc->LineTo(add_x + 28, add_y + 17);

		dc->MoveTo(add_x + 22, add_y + 18);
		dc->LineTo(add_x + 29, add_y + 18); 

		dc->MoveTo(add_x + 22, add_y + 19);
		dc->LineTo(add_x + 29, add_y + 19);

		dc->MoveTo(add_x + 23, add_y + 20);
		dc->LineTo(add_x + 28, add_y + 20);

		dc->MoveTo(add_x + 23, add_y + 21);
		dc->LineTo(add_x + 28, add_y + 21);

		dc->MoveTo(add_x + 25, add_y + 22);
		dc->LineTo(add_x + 26, add_y + 22); //шарик

		dc->MoveTo(add_x + 22, add_y + 23);
		dc->LineTo(add_x + 29, add_y + 23);

		dc->MoveTo(add_x + 22, add_y + 24);
		dc->LineTo(add_x + 29, add_y + 24); //шарф

		dc->MoveTo(add_x + 24, add_y + 25);
		dc->LineTo(add_x + 27, add_y + 25);

		dc->MoveTo(add_x + 24, add_y + 26);
		dc->LineTo(add_x + 27, add_y + 26);

		dc->MoveTo(add_x + 23, add_y + 27);
		dc->LineTo(add_x + 28, add_y + 27);

		dc->MoveTo(add_x + 23, add_y + 28);
		dc->LineTo(add_x + 28, add_y + 28);

		dc->MoveTo(add_x + 23, add_y + 29);
		dc->LineTo(add_x + 28, add_y + 29);

		dc->MoveTo(add_x + 22, add_y + 30);
		dc->LineTo(add_x + 29, add_y + 30);

		dc->MoveTo(add_x + 22, add_y + 31);
		dc->LineTo(add_x + 29, add_y + 31);

		dc->MoveTo(add_x + 22, add_y + 32);
		dc->LineTo(add_x + 29, add_y + 32); //шея

		dc->MoveTo(add_x + 21, add_y + 33);
		dc->LineTo(add_x + 30, add_y + 33);

		dc->MoveTo(add_x + 20, add_y + 34);
		dc->LineTo(add_x + 31, add_y + 34); //

		dc->MoveTo(add_x + 20, add_y + 35);
		dc->LineTo(add_x + 31, add_y + 35);

		dc->MoveTo(add_x + 20, add_y + 36);
		dc->LineTo(add_x + 31, add_y + 36); //колонна

		dc->MoveTo(add_x + 20, add_y + 37);
		dc->LineTo(add_x + 31, add_y + 37);

		dc->MoveTo(add_x + 20, add_y + 38);
		dc->LineTo(add_x + 31, add_y + 38); //подставка

		dc->MoveTo(add_x + 19, add_y + 39);
		dc->LineTo(add_x + 32, add_y + 39);

		dc->MoveTo(add_x + 18, add_y + 40);
		dc->LineTo(add_x + 33, add_y + 40);

		dc->MoveTo(add_x + 18, add_y + 41);
		dc->LineTo(add_x + 33, add_y + 41);

		dc->MoveTo(add_x + 18, add_y + 42);
		dc->LineTo(add_x + 33, add_y + 42); //ноги

		break;
	case 'c':

		dc->MoveTo(add_x + 21, add_y + 13);
		dc->LineTo(add_x + 29, add_y + 13);

		dc->MoveTo(add_x + 21, add_y + 14);
		dc->LineTo(add_x + 29, add_y + 14);

		dc->MoveTo(add_x + 22, add_y + 15);
		dc->LineTo(add_x + 28, add_y + 15);

		dc->MoveTo(add_x + 22, add_y + 16);
		dc->LineTo(add_x + 28, add_y + 16);

		dc->MoveTo(add_x + 23, add_y + 17);
		dc->LineTo(add_x + 27, add_y + 17);

		dc->MoveTo(add_x + 23, add_y + 18);
		dc->LineTo(add_x + 27, add_y + 18); //подставка

		dc->MoveTo(add_x + 23, add_y + 19);
		dc->LineTo(add_x + 27, add_y + 19);

		dc->MoveTo(add_x + 23, add_y + 20);
		dc->LineTo(add_x + 27, add_y + 20);

		dc->MoveTo(add_x + 23, add_y + 21);
		dc->LineTo(add_x + 27, add_y + 21);

		dc->MoveTo(add_x + 23, add_y + 22);
		dc->LineTo(add_x + 27, add_y + 22); //юбочка

		dc->MoveTo(add_x + 23, add_y + 23);
		dc->LineTo(add_x + 27, add_y + 23);

		dc->MoveTo(add_x + 23, add_y + 24);
		dc->LineTo(add_x + 27, add_y + 24);

		dc->MoveTo(add_x + 23, add_y + 25);
		dc->LineTo(add_x + 27, add_y + 25);

		dc->MoveTo(add_x + 23, add_y + 26);
		dc->LineTo(add_x + 27, add_y + 26);

		dc->MoveTo(add_x + 22, add_y + 27);
		dc->LineTo(add_x + 28, add_y + 27);

		dc->MoveTo(add_x + 22, add_y + 28);
		dc->LineTo(add_x + 28, add_y + 28);

		dc->MoveTo(add_x + 22, add_y + 29);
		dc->LineTo(add_x + 28, add_y + 29);

		dc->MoveTo(add_x + 22, add_y + 30);
		dc->LineTo(add_x + 28, add_y + 30);

		dc->MoveTo(add_x + 22, add_y + 31);
		dc->LineTo(add_x + 28, add_y + 31);

		dc->MoveTo(add_x + 22, add_y + 32);
		dc->LineTo(add_x + 28, add_y + 32);

		dc->MoveTo(add_x + 22, add_y + 33);
		dc->LineTo(add_x + 28, add_y + 33);

		dc->MoveTo(add_x + 21, add_y + 34);
		dc->LineTo(add_x + 29, add_y + 34);

		dc->MoveTo(add_x + 21, add_y + 35);
		dc->LineTo(add_x + 29, add_y + 35);

		dc->MoveTo(add_x + 21, add_y + 36);
		dc->LineTo(add_x + 29, add_y + 36); //колонна

		dc->MoveTo(add_x + 20, add_y + 37);
		dc->LineTo(add_x + 30, add_y + 37);

		dc->MoveTo(add_x + 19, add_y + 38);
		dc->LineTo(add_x + 31, add_y + 38);

		dc->MoveTo(add_x + 18, add_y + 39);
		dc->LineTo(add_x + 32, add_y + 39);

		dc->MoveTo(add_x + 17, add_y + 40);
		dc->LineTo(add_x + 33, add_y + 40);

		dc->MoveTo(add_x + 17, add_y + 41);
		dc->LineTo(add_x + 33, add_y + 41);

		dc->MoveTo(add_x + 17, add_y + 42);
		dc->LineTo(add_x + 33, add_y + 42); //ноги

		break;
	case 'o':

		dc->MoveTo(add_x + 22, add_y + 19);
		dc->LineTo(add_x + 28, add_y + 19);

		dc->MoveTo(add_x + 21, add_y + 20);
		dc->LineTo(add_x + 29, add_y + 20);

		dc->MoveTo(add_x + 20, add_y + 21);
		dc->LineTo(add_x + 30, add_y + 21);

		dc->MoveTo(add_x + 19, add_y + 22);
		dc->LineTo(add_x + 31, add_y + 22); //юбочка

		dc->MoveTo(add_x + 23, add_y + 23);
		dc->LineTo(add_x + 27, add_y + 23);

		dc->MoveTo(add_x + 23, add_y + 24);
		dc->LineTo(add_x + 27, add_y + 24);

		dc->MoveTo(add_x + 23, add_y + 25);
		dc->LineTo(add_x + 27, add_y + 25);

		dc->MoveTo(add_x + 23, add_y + 26);
		dc->LineTo(add_x + 27, add_y + 26);

		dc->MoveTo(add_x + 22, add_y + 27);
		dc->LineTo(add_x + 28, add_y + 27);

		dc->MoveTo(add_x + 22, add_y + 28);
		dc->LineTo(add_x + 28, add_y + 28);

		dc->MoveTo(add_x + 22, add_y + 29);
		dc->LineTo(add_x + 28, add_y + 29);

		dc->MoveTo(add_x + 22, add_y + 30);
		dc->LineTo(add_x + 28, add_y + 30);

		dc->MoveTo(add_x + 22, add_y + 31);
		dc->LineTo(add_x + 28, add_y + 31);

		dc->MoveTo(add_x + 22, add_y + 32);
		dc->LineTo(add_x + 28, add_y + 32);

		dc->MoveTo(add_x + 22, add_y + 33);
		dc->LineTo(add_x + 28, add_y + 33);

		dc->MoveTo(add_x + 21, add_y + 34);
		dc->LineTo(add_x + 29, add_y + 34);

		dc->MoveTo(add_x + 21, add_y + 35);
		dc->LineTo(add_x + 29, add_y + 35);

		dc->MoveTo(add_x + 21, add_y + 36);
		dc->LineTo(add_x + 29, add_y + 36); //колонна

		dc->MoveTo(add_x + 20, add_y + 37);
		dc->LineTo(add_x + 30, add_y + 37);

		dc->MoveTo(add_x + 19, add_y + 38);
		dc->LineTo(add_x + 31, add_y + 38);

		dc->MoveTo(add_x + 18, add_y + 39);
		dc->LineTo(add_x + 32, add_y + 39);

		dc->MoveTo(add_x + 17, add_y + 40);
		dc->LineTo(add_x + 33, add_y + 40);

		dc->MoveTo(add_x + 17, add_y + 41);
		dc->LineTo(add_x + 33, add_y + 41);

		dc->MoveTo(add_x + 17, add_y + 42);
		dc->LineTo(add_x + 33, add_y + 42); //ноги

		break;
	}
}

void show_moves(CDC * dc, CPoint turns[], int z0, int z1)
{
	dc->SelectObject(CreatePen(PS_SOLID, 1, RGB(17, 0, 255)));
	CPoint pt;
	int add_x;
	int add_y;
	for (int i = 0; i < 27; i++) {
		if (turns[i].x == 9)
			break;
		add_x = z0 + turns[i].x*(z1 - z0) / 8;
		add_y = z0 + turns[i].y*(z1 - z0) / 8;
		dc->MoveTo(add_x + 24, add_y + 26);
		dc->LineTo(add_x + 28, add_y + 26);
		dc->MoveTo(add_x + 25, add_y + 25);
		dc->LineTo(add_x + 27, add_y + 25);
		dc->MoveTo(add_x + 25, add_y + 27);
		dc->LineTo(add_x + 27, add_y + 27);
		dc->MoveTo(add_x + 26, add_y + 24);
		dc->LineTo(add_x + 26, add_y + 28);
	}


}
