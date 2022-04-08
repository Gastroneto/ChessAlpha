#include "stdafx.h"
#include "moves.h"



void Get_turns(CPoint pt, square Square[][8], CPoint turns[])
{
	int append = 0;
	char number = pt.y;
	char letter = pt.x;
	switch (Square[number][letter].fig) {
	case 'P': //белая пешка
		append = 0;
		if (Square[number - 1][letter].color_of_fig == empty && number > 0) {
			turns[append].y = (number - 1);
			turns[append].x = letter;
			append++; //ход на один вперёд
			if (number == 6 && Square[number - 2][letter].color_of_fig == empty) {
				turns[append].y = number - 2;
				turns[append].x = letter;
				append++; //ход на два вперёд
			}
		}
		if (letter > 0 && Square[number - 1][letter - 1].color_of_fig == black) {
			turns[append].y = number - 1;
			turns[append].x = letter - 1;
			append++; // съедание влево
		}
		if (letter < 7 && Square[number - 1][letter + 1].color_of_fig == black) {
			turns[append].y = number - 1;
			turns[append].x = letter + 1;
			append++; // съедание вправо
		}
		break;
	case 'p': //чёрная пешка
		append = 0;
		if (Square[number + 1][letter].color_of_fig == empty && number < 7) {
			turns[append].y = (number + 1);
			turns[append].x = letter;
			append++; //ход на один вперёд
			if (number == 1 && Square[number + 2][letter].color_of_fig == empty) {
				turns[append].y = number + 2;
				turns[append].x = letter;
				append++; //ход на два вперёд
			}
		}
		if (letter > 0 && Square[number + 1][letter - 1].color_of_fig == white) {
			turns[append].y = number + 1;
			turns[append].x = letter - 1;
			append++; // съедание влево
		}
		if (letter < 7 && Square[number + 1][letter + 1].color_of_fig == white) {
			turns[append].y = number + 1;
			turns[append].x = letter + 1;
			append++; // съедание вправо
		}
		break;
	case 'H': //белый пони
		append = 0;
		for (int y = -2; y < 3; y++) 
			for(int x = -2; x<3; x++)
				if(x!=0 && y!=0 && (x*x)*(y*y)==4)
					if (0<=number+y && number+y<=7 && 0<=letter+x && letter+x<8)
						if (Square[number + y][letter + x].color_of_fig != white) {
							turns[append].y = number + y;
							turns[append].x = letter + x;
							append++;
						}
		break;
	case 'h': //тёмная лошадка
		append = 0;
		for (int y = -2; y < 3; y++)
			for (int x = -2; x<3; x++)
				if (x != 0 && y != 0 && (x*x)*(y*y) == 4)
					if (0 <= number + y && number + y <= 7 && 0 <= letter + x && letter + x<8)
						if (Square[number + y][letter + x].color_of_fig != black) {
							turns[append].y = number + y;
							turns[append].x = letter + x;
							append++;
						}
		break;
	case 'c': //башня тьмы
		append = 0;
		for(int y=-1; y<=1; y++)//наверх, вниз
			for(int x=-1; x<=1; x++)//влево и вправо
				if ((x != y) && (x == 0 || y == 0))//куда-то не движемся и не стоим месте
					for (int move = 1; move < 8; move++) {  //движение на столько:
						int y_ = y*move + number; //рассматриваемая клетка по Y: движение по игрику + наша координата
						int x_ = x*move + letter;//рассматриваемая клетка по X: движение по иксу + наша координата
						if((0<=y_ && y_<=7)&&(0<=x_ && x_<=7)) //если клетка в поле, то:
							
							if (Square[y_][x_].color_of_fig != black) { //если не наш цвет- ходим туда
								turns[append].y = y_;
								turns[append].x = x_;
								append++;
							}
							if (Square[y_][x_].color_of_fig != empty) //если на фигуру, то больше не идём в этом направлении
									break;
							
					}
		break;
	case 'C': //башня света
		append = 0;
		for (int y = -1; y <= 1; y++)//наверх, вниз
			for (int x = -1; x <= 1; x++)//влево и вправо
				if ((x != y) && (x == 0 || y == 0))//куда-то не движемся и не стоим месте
					for (int move = 1; move < 8; move++) {  //движение на столько:
						int y_ = y*move + number; //рассматриваемая клетка по Y: движение по игрику + наша координата
						int x_ = x*move + letter;//рассматриваемая клетка по X: движение по иксу + наша координата
						if ((0 <= y_ && y_ <= 7) && (0 <= x_ && x_ <= 7)) //если клетка в поле, то:

							if (Square[y_][x_].color_of_fig != white) { //если не наш цвет- ходим туда
								turns[append].y = y_;
								turns[append].x = x_;
								append++;
							}
						if (Square[y_][x_].color_of_fig != empty) //если на фигуру, то больше не идём в этом направлении
							break;

					}
		break;
	case'o'://слон загорелый
		append = 0;
		for (int y = -1; y <= 1; y+=2)//наверх, вниз
			for (int x = -1; x <= 1; x+=2)//влево и вправо
					for (int move = 1; move < 8; move++) {  //движение на столько:
						int y_ = y*move + number; //рассматриваемая клетка по Y: движение по игрику + наша координата
						int x_ = x*move + letter;//рассматриваемая клетка по X: движение по иксу + наша координата
						if ((0 <= y_ && y_ <= 7) && (0 <= x_ && x_ <= 7)) //если клетка в поле, то:

							if (Square[y_][x_].color_of_fig != black) { //если не наш цвет- ходим туда
								turns[append].y = y_;
								turns[append].x = x_;
								append++;
							}
						if (Square[y_][x_].color_of_fig != empty) //если на фигуру, то больше не идём в этом направлении
							break;

					}
		break;
	case'O'://слон бледный
		append = 0;
		for (int y = -1; y <= 1; y += 2)//наверх, вниз
			for (int x = -1; x <= 1; x += 2)//влево и вправо
				for (int move = 1; move < 8; move++) {  //движение на столько:
					int y_ = y*move + number; //рассматриваемая клетка по Y: движение по игрику + наша координата
					int x_ = x*move + letter;//рассматриваемая клетка по X: движение по иксу + наша координата
					if ((0 <= y_ && y_ <= 7) && (0 <= x_ && x_ <= 7)) //если клетка в поле, то:

						if (Square[y_][x_].color_of_fig != white) { //если не наш цвет- ходим туда
							turns[append].y = y_;
							turns[append].x = x_;
							append++;
						}
					if (Square[y_][x_].color_of_fig != empty) //если на фигуру, то больше не идём в этом направлении
						break;

				}
		break;
	case'q'://королева тьмы
		append = 0;
		for (int y = -1; y <= 1; ++y)//наверх, вниз
			for (int x = -1; x <= 1; ++x)//влево и вправо
				if ((x != 0 || y != 0))//куда-то не движемся и не стоим месте
				for (int move = 1; move < 8; move++) {  //движение на столько:
					int y_ = y*move + number; //рассматриваемая клетка по Y: движение по игрику + наша координата
					int x_ = x*move + letter;//рассматриваемая клетка по X: движение по иксу + наша координата
					if ((0 <= y_ && y_ <= 7) && (0 <= x_ && x_ <= 7)) //если клетка в поле, то:

						if (Square[y_][x_].color_of_fig != black) { //если не наш цвет- ходим туда
							turns[append].y = y_;
							turns[append].x = x_;
							append++;
						}
					if (Square[y_][x_].color_of_fig != empty) //если на фигуру, то больше не идём в этом направлении
						break;

				}
		break;
	case'Q'://светлая королева
		append = 0;
		for (int y = -1; y <= 1; ++y)//наверх, вниз
			for (int x = -1; x <= 1; ++x)//влево и вправо
				if ((x != 0 || y != 0))//куда-то не движемся и не стоим месте
					for (int move = 1; move < 8; move++) {  //движение на столько:
						int y_ = y*move + number; //рассматриваемая клетка по Y: движение по игрику + наша координата
						int x_ = x*move + letter;//рассматриваемая клетка по X: движение по иксу + наша координата
						if ((0 <= y_ && y_ <= 7) && (0 <= x_ && x_ <= 7)) //если клетка в поле, то:

							if (Square[y_][x_].color_of_fig != white) { //если не наш цвет- ходим туда
								turns[append].y = y_;
								turns[append].x = x_;
								append++;
							}
						if (Square[y_][x_].color_of_fig != empty) //если на фигуру, то больше не идём в этом направлении
							break;

					}
		break;
	case'k'://Король тьмы
		append = 0;
		for (int y = -1; y <= 1; ++y)//наверх, вниз
			for (int x = -1; x <= 1; ++x)//влево и вправо
				if ((x != 0 || y != 0)){//куда-то не движемся и не стоим месте
						int y_ = y + number; //рассматриваемая клетка по Y: движение по игрику + наша координата
						int x_ = x + letter;//рассматриваемая клетка по X: движение по иксу + наша координата
						if ((0 <= y_ && y_ <= 7) && (0 <= x_ && x_ <= 7)) //если клетка в поле, то:
							if (Square[y_][x_].color_of_fig != black) { //если не наш цвет- ходим туда
								turns[append].y = y_;
								turns[append].x = x_;
								append++;
							}
					}
		break;
	case'K'://Добрый король
		append = 0;
		for (int y = -1; y <= 1; ++y)//наверх, вниз
			for (int x = -1; x <= 1; ++x)//влево и вправо
				if ((x != 0 || y != 0)) {//куда-то не движемся и не стоим месте
					int y_ = y + number; //рассматриваемая клетка по Y: движение по игрику + наша координата
					int x_ = x + letter;//рассматриваемая клетка по X: движение по иксу + наша координата
					if ((0 <= y_ && y_ <= 7) && (0 <= x_ && x_ <= 7)) //если клетка в поле, то:
						if (Square[y_][x_].color_of_fig != white) { //если не наш цвет- ходим туда
							turns[append].y = y_;
							turns[append].x = x_;
							append++;
						}
				}
		break;
	}
}
