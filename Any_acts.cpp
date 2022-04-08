#include "stdafx.h"
#include "Any_acts.h"
#include "Figure.h"
#include "moves.h"
void set_start_pos(square square[][8])
{
	Figure fig;  //�������� �� c, K, q � ��
	for (int i = 0; i<8; i++) {
		square[1][i].set_fig(fig.pawn(black), black);
		square[6][i].set_fig(fig.pawn(white), white);
	}
	square[0][0].set_fig(fig.castle(black), black);
	square[0][7].set_fig(fig.castle(black), black);
	square[7][0].set_fig(fig.castle(white), white);
	square[7][7].set_fig(fig.castle(white), white);
	square[0][1].set_fig(fig.horse(black), black);
	square[0][6].set_fig(fig.horse(black), black);
	square[7][6].set_fig(fig.horse(white), white);
	square[7][1].set_fig(fig.horse(white), white);
	square[0][2].set_fig(fig.officer(black), black);
	square[0][5].set_fig(fig.officer(black), black);
	square[7][2].set_fig(fig.officer(white), white);
	square[7][5].set_fig(fig.officer(white), white);
	square[0][3].set_fig(fig.queen(black), black);
	square[0][4].set_fig(fig.king(black), black);
	square[7][3].set_fig(fig.queen(white), white);
	square[7][4].set_fig(fig.king(white), white);
	for (int i = 2; i < 6; i++)
		for (int j = 0; j < 8; j++)
			square[i][j].set_fig();
	
}

void move(square Square[][8],  CPoint StartPoint, CPoint FinishPoint)
{
	Square[FinishPoint.y][FinishPoint.x].set_fig(Square[StartPoint.y][StartPoint.x].fig, Square[StartPoint.y][StartPoint.x].color_of_fig);
	if ((Square[FinishPoint.y][FinishPoint.x].fig == 'p') && (FinishPoint.y == 7))
		Square[FinishPoint.y][FinishPoint.x].fig = 'q';
	else if ((Square[FinishPoint.y][FinishPoint.x].fig == 'P') && (FinishPoint.y == 0))
		Square[FinishPoint.y][FinishPoint.x].fig = 'Q';
	Square[StartPoint.y][StartPoint.x].set_fig();
}

int get_price(square Square[][8], int color) //���������� ����
{
	int summ=0;
	char border1;
	char border2;
	if (color == 1) {
		border1 = 'A';
		border2 = 'Z';
	}
	else {
		border1 = 'a';
		border2 = 'z';
	}
	for(int number = 0; number<8; number ++)
		for (int letter = 0; letter < 8; letter++) {
			char fig = Square[number][letter].fig;
			if ((fig > border1) && (fig < border2)) {
				switch (fig)
				{
				case 'p':
					summ += 100;
					break;
				case 'P':
					summ += 100;
					break;
				case 'h':
					summ += 288;
					break;

				case 'H':
					summ += 288;
					break;
				case 'c':
					summ += 480;
					break;
				case 'C':
					summ += 480;
					break;
				case 'Q':
					summ += 1077;
					break;
				case 'q':
					summ += 1077;
					break;
				case 'O':
					summ += 345;
					break;
				case 'o':
					summ += 345;
					break;
				case 'K':
					summ += 20000; 
					break;
				case 'k':
					summ += 20000;
					break;
				default:
					break;
				}
			}
		}
	return summ;
}

int get_figs(square Square[][8], CPoint fig[], int color)
{
	char border1;
	char border2;
	if (color == white) {
		border1 = 'A';
		border2 = 'Z';
	}
	else {
		border1 = 'a';
		border2 = 'z';
	}
	int count = 0;
	for (int j = 0; j < 8; j++) {
		for (int i = 0; i < 8; i++) {
			char figure = Square[j][i].fig;//���� ������
			if ((figure < border2) && (figure > border1)) {
				fig[count] = { i,j };
				count++;
			}
				
		}
	}
	fig[count] = { 9,9 };
	return 0;
}

bool can_we_move(CPoint pt, CPoint turns[])
{
	for (int i = 0; i < 27; i++) {
		if (turns[i] == pt)
			return true;
		if (turns[i].x == 9)
			return false;
	}
	return false;
}

int get_bot_turn(square Square[][8], CPoint turn[], int color)
{
	CPoint figures[3][64]; //������, �������� ����� ������
	CPoint turns[3][64]; //����, ���� ����� ������
	CPoint m_moves[3][2]; //��������������� ���� ����
	square m_figure[3][2]; // ������ ��� �������� � �������� ���������.
	int  th_price;;
	int i[3]; //������� �����
	int j[3]; //������� ����� �����
	int price_3 = -10000, price_2 = 10000, price_1 = -10000;

	reset_CP_array(figures[0]); //�������� ������ � ��������
	get_figs(Square, figures[0], black); // �������� ������ ��� ������� ����
	i[0] = 0; //�������� ������ ������� �����
	while (figures[0][i[0]].x != 9) { //���� ������ ����� �����

		m_moves[0][0] = figures[0][i[0]]; //������ �����
		m_figure[0][0] = Square[m_moves[0][0].y][m_moves[0][0].x]; //���������� ��������� �������

		reset_CP_array(turns[0]); //���������� ���� ������ ������
		Get_turns(m_moves[0][0], Square, turns[0]); //�������� ���� 
		j[0] = 0; //�������� ������ ������� �����
		while (turns[0][j[0]].x != 9) { //���� ��� ����� �����

			m_moves[0][1] = turns[0][j[0]]; //����� ����
			m_figure[0][1] = Square[m_moves[0][1].y][m_moves[0][1].x]; //���������� ���� ������� ������ ���

			move(Square, m_moves[0][0], m_moves[0][1]); //������ ��� ���

			//##########	1 ���		###########

			reset_CP_array(figures[1]); //�������� ������ ����� ������� ����
			get_figs(Square, figures[1], white); //�������� ���� ���������
			i[1] = 0;//�������� ������ ������� �����
			price_2 = 10000;
			while (figures[1][i[1]].x != 9) { //���� ������ ����� �����
				m_moves[1][0] = figures[1][i[1]]; //������ �����
				m_figure[1][0] = Square[m_moves[1][0].y][m_moves[1][0].x]; //���������� ��������� �������

				reset_CP_array(turns[1]); //���������� ���� ������ ������
				Get_turns(m_moves[1][0], Square, turns[1]); //�������� ���� 
				j[1] = 0; //�������� ������ ������� �����

				while (turns[1][j[1]].x != 9) { //���� ��� ����� �����

					m_moves[1][1] = turns[1][j[1]]; //����� ����
					m_figure[1][1] = Square[m_moves[1][1].y][m_moves[1][1].x]; //���������� ���� ������� ������ ���

					move(Square, m_moves[1][0], m_moves[1][1]); //������ ��� ���

					//############ 2 ��� ###########

					reset_CP_array(figures[2]); //�������� ������ � ��������
					get_figs(Square, figures[2], black); // �������� ������ ��� �������� ����
					i[2] = 0; //�������� ������ ������� �����
					price_3 = -10000;
					while (figures[2][i[2]].x != 9) { //���� ������ ����� �����

						m_moves[2][0] = figures[2][i[2]]; //������ �����
						m_figure[2][0] = Square[m_moves[2][0].y][m_moves[2][0].x]; //���������� ��������� �������

						reset_CP_array(turns[2]); //���������� ���� ������ ������
						Get_turns(m_moves[2][0], Square, turns[2]); //�������� ���� 
						j[2] = 0; //�������� ������ ������� �����
						while (turns[2][j[2]].x != 9) { //���� ��� ����� �����

							m_moves[2][1] = turns[2][j[2]]; //����� ����
							m_figure[2][1] = Square[m_moves[2][1].y][m_moves[2][1].x]; //���������� ���� ������� ������ ���

							move(Square, m_moves[2][0], m_moves[2][1]); //������ ��� ���
							//############ 3 ��� ###########
							th_price = get_price(Square, black);
							th_price= th_price -get_price(Square, white); //�������� ������ �������
							if (th_price > price_3)
								price_3 = th_price; //������� ������ ���
							Square[m_moves[2][0].y][m_moves[2][0].x] = m_figure[2][0];
							Square[m_moves[2][1].y][m_moves[2][1].x] = m_figure[2][1]; //���������� �� ���������� �������
							j[2]++;
						}
						i[2]++;
					}
					if (price_3 < price_2) //������� ������ �� ������ (��������� �������, ����� ������ ��� ���- ������ ��� ���� �������)
						price_2 = price_3;
					Square[m_moves[1][0].y][m_moves[1][0].x] = m_figure[1][0]; //���������� �� ������� �� ������� ����
					Square[m_moves[1][1].y][m_moves[1][1].x] = m_figure[1][1];
					j[1]++;
				}
				i[1]++;
			}
			if (price_2 > price_1) {
				price_1 = price_2; //������� ������ �� ����, ��� ������� ��������
				turn[0] = m_moves[0][0];
				turn[1] = m_moves[0][1]; //���������� ����. - (��� ���)
			}
			Square[m_moves[0][0].y][m_moves[0][0].x] = m_figure[0][0]; //���������� �� ������� �� ������� ����
			Square[m_moves[0][1].y][m_moves[0][1].x] = m_figure[0][1];
			j[0]++;
		}
		i[0]++;
	}
	return price_1;
}

int reset_CP_array(CPoint turn[], int size)
{
	for (int i = 0; i < size; i++) {
		turn[i] = { 9,9 };
	}
	return 0;
}
