#include "stdafx.h"
#include "moves.h"



void Get_turns(CPoint pt, square Square[][8], CPoint turns[])
{
	int append = 0;
	char number = pt.y;
	char letter = pt.x;
	switch (Square[number][letter].fig) {
	case 'P': //����� �����
		append = 0;
		if (Square[number - 1][letter].color_of_fig == empty && number > 0) {
			turns[append].y = (number - 1);
			turns[append].x = letter;
			append++; //��� �� ���� �����
			if (number == 6 && Square[number - 2][letter].color_of_fig == empty) {
				turns[append].y = number - 2;
				turns[append].x = letter;
				append++; //��� �� ��� �����
			}
		}
		if (letter > 0 && Square[number - 1][letter - 1].color_of_fig == black) {
			turns[append].y = number - 1;
			turns[append].x = letter - 1;
			append++; // �������� �����
		}
		if (letter < 7 && Square[number - 1][letter + 1].color_of_fig == black) {
			turns[append].y = number - 1;
			turns[append].x = letter + 1;
			append++; // �������� ������
		}
		break;
	case 'p': //������ �����
		append = 0;
		if (Square[number + 1][letter].color_of_fig == empty && number < 7) {
			turns[append].y = (number + 1);
			turns[append].x = letter;
			append++; //��� �� ���� �����
			if (number == 1 && Square[number + 2][letter].color_of_fig == empty) {
				turns[append].y = number + 2;
				turns[append].x = letter;
				append++; //��� �� ��� �����
			}
		}
		if (letter > 0 && Square[number + 1][letter - 1].color_of_fig == white) {
			turns[append].y = number + 1;
			turns[append].x = letter - 1;
			append++; // �������� �����
		}
		if (letter < 7 && Square[number + 1][letter + 1].color_of_fig == white) {
			turns[append].y = number + 1;
			turns[append].x = letter + 1;
			append++; // �������� ������
		}
		break;
	case 'H': //����� ����
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
	case 'h': //����� �������
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
	case 'c': //����� ����
		append = 0;
		for(int y=-1; y<=1; y++)//������, ����
			for(int x=-1; x<=1; x++)//����� � ������
				if ((x != y) && (x == 0 || y == 0))//����-�� �� �������� � �� ����� �����
					for (int move = 1; move < 8; move++) {  //�������� �� �������:
						int y_ = y*move + number; //��������������� ������ �� Y: �������� �� ������ + ���� ����������
						int x_ = x*move + letter;//��������������� ������ �� X: �������� �� ���� + ���� ����������
						if((0<=y_ && y_<=7)&&(0<=x_ && x_<=7)) //���� ������ � ����, ��:
							
							if (Square[y_][x_].color_of_fig != black) { //���� �� ��� ����- ����� ����
								turns[append].y = y_;
								turns[append].x = x_;
								append++;
							}
							if (Square[y_][x_].color_of_fig != empty) //���� �� ������, �� ������ �� ��� � ���� �����������
									break;
							
					}
		break;
	case 'C': //����� �����
		append = 0;
		for (int y = -1; y <= 1; y++)//������, ����
			for (int x = -1; x <= 1; x++)//����� � ������
				if ((x != y) && (x == 0 || y == 0))//����-�� �� �������� � �� ����� �����
					for (int move = 1; move < 8; move++) {  //�������� �� �������:
						int y_ = y*move + number; //��������������� ������ �� Y: �������� �� ������ + ���� ����������
						int x_ = x*move + letter;//��������������� ������ �� X: �������� �� ���� + ���� ����������
						if ((0 <= y_ && y_ <= 7) && (0 <= x_ && x_ <= 7)) //���� ������ � ����, ��:

							if (Square[y_][x_].color_of_fig != white) { //���� �� ��� ����- ����� ����
								turns[append].y = y_;
								turns[append].x = x_;
								append++;
							}
						if (Square[y_][x_].color_of_fig != empty) //���� �� ������, �� ������ �� ��� � ���� �����������
							break;

					}
		break;
	case'o'://���� ���������
		append = 0;
		for (int y = -1; y <= 1; y+=2)//������, ����
			for (int x = -1; x <= 1; x+=2)//����� � ������
					for (int move = 1; move < 8; move++) {  //�������� �� �������:
						int y_ = y*move + number; //��������������� ������ �� Y: �������� �� ������ + ���� ����������
						int x_ = x*move + letter;//��������������� ������ �� X: �������� �� ���� + ���� ����������
						if ((0 <= y_ && y_ <= 7) && (0 <= x_ && x_ <= 7)) //���� ������ � ����, ��:

							if (Square[y_][x_].color_of_fig != black) { //���� �� ��� ����- ����� ����
								turns[append].y = y_;
								turns[append].x = x_;
								append++;
							}
						if (Square[y_][x_].color_of_fig != empty) //���� �� ������, �� ������ �� ��� � ���� �����������
							break;

					}
		break;
	case'O'://���� �������
		append = 0;
		for (int y = -1; y <= 1; y += 2)//������, ����
			for (int x = -1; x <= 1; x += 2)//����� � ������
				for (int move = 1; move < 8; move++) {  //�������� �� �������:
					int y_ = y*move + number; //��������������� ������ �� Y: �������� �� ������ + ���� ����������
					int x_ = x*move + letter;//��������������� ������ �� X: �������� �� ���� + ���� ����������
					if ((0 <= y_ && y_ <= 7) && (0 <= x_ && x_ <= 7)) //���� ������ � ����, ��:

						if (Square[y_][x_].color_of_fig != white) { //���� �� ��� ����- ����� ����
							turns[append].y = y_;
							turns[append].x = x_;
							append++;
						}
					if (Square[y_][x_].color_of_fig != empty) //���� �� ������, �� ������ �� ��� � ���� �����������
						break;

				}
		break;
	case'q'://�������� ����
		append = 0;
		for (int y = -1; y <= 1; ++y)//������, ����
			for (int x = -1; x <= 1; ++x)//����� � ������
				if ((x != 0 || y != 0))//����-�� �� �������� � �� ����� �����
				for (int move = 1; move < 8; move++) {  //�������� �� �������:
					int y_ = y*move + number; //��������������� ������ �� Y: �������� �� ������ + ���� ����������
					int x_ = x*move + letter;//��������������� ������ �� X: �������� �� ���� + ���� ����������
					if ((0 <= y_ && y_ <= 7) && (0 <= x_ && x_ <= 7)) //���� ������ � ����, ��:

						if (Square[y_][x_].color_of_fig != black) { //���� �� ��� ����- ����� ����
							turns[append].y = y_;
							turns[append].x = x_;
							append++;
						}
					if (Square[y_][x_].color_of_fig != empty) //���� �� ������, �� ������ �� ��� � ���� �����������
						break;

				}
		break;
	case'Q'://������� ��������
		append = 0;
		for (int y = -1; y <= 1; ++y)//������, ����
			for (int x = -1; x <= 1; ++x)//����� � ������
				if ((x != 0 || y != 0))//����-�� �� �������� � �� ����� �����
					for (int move = 1; move < 8; move++) {  //�������� �� �������:
						int y_ = y*move + number; //��������������� ������ �� Y: �������� �� ������ + ���� ����������
						int x_ = x*move + letter;//��������������� ������ �� X: �������� �� ���� + ���� ����������
						if ((0 <= y_ && y_ <= 7) && (0 <= x_ && x_ <= 7)) //���� ������ � ����, ��:

							if (Square[y_][x_].color_of_fig != white) { //���� �� ��� ����- ����� ����
								turns[append].y = y_;
								turns[append].x = x_;
								append++;
							}
						if (Square[y_][x_].color_of_fig != empty) //���� �� ������, �� ������ �� ��� � ���� �����������
							break;

					}
		break;
	case'k'://������ ����
		append = 0;
		for (int y = -1; y <= 1; ++y)//������, ����
			for (int x = -1; x <= 1; ++x)//����� � ������
				if ((x != 0 || y != 0)){//����-�� �� �������� � �� ����� �����
						int y_ = y + number; //��������������� ������ �� Y: �������� �� ������ + ���� ����������
						int x_ = x + letter;//��������������� ������ �� X: �������� �� ���� + ���� ����������
						if ((0 <= y_ && y_ <= 7) && (0 <= x_ && x_ <= 7)) //���� ������ � ����, ��:
							if (Square[y_][x_].color_of_fig != black) { //���� �� ��� ����- ����� ����
								turns[append].y = y_;
								turns[append].x = x_;
								append++;
							}
					}
		break;
	case'K'://������ ������
		append = 0;
		for (int y = -1; y <= 1; ++y)//������, ����
			for (int x = -1; x <= 1; ++x)//����� � ������
				if ((x != 0 || y != 0)) {//����-�� �� �������� � �� ����� �����
					int y_ = y + number; //��������������� ������ �� Y: �������� �� ������ + ���� ����������
					int x_ = x + letter;//��������������� ������ �� X: �������� �� ���� + ���� ����������
					if ((0 <= y_ && y_ <= 7) && (0 <= x_ && x_ <= 7)) //���� ������ � ����, ��:
						if (Square[y_][x_].color_of_fig != white) { //���� �� ��� ����- ����� ����
							turns[append].y = y_;
							turns[append].x = x_;
							append++;
						}
				}
		break;
	}
}
