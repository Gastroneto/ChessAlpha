#include "stdafx.h"
#include "Any_acts.h"
#include "Figure.h"
#include "moves.h"
void set_start_pos(square square[][8])
{
	Figure fig;  //заменить на c, K, q и тп
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

int get_price(square Square[][8], int color) //Доработать веса
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
			char figure = Square[j][i].fig;//наша фигура
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
	CPoint figures[3][64]; //фигуры, которыми можем ходить
	CPoint turns[3][64]; //поля, куда будем ходить
	CPoint m_moves[3][2]; //непосредственно сами ходы
	square m_figure[3][2]; // фигуры для возврата в исконное состояние.
	int  th_price;;
	int i[3]; //счётчик фигур
	int j[3]; //счётчик ходов фигур
	int price_3 = -10000, price_2 = 10000, price_1 = -10000;

	reset_CP_array(figures[0]); //обнуляем массив с фигурами
	get_figs(Square, figures[0], black); // получаем фигуры для первого хода
	i[0] = 0; //обнуляем первый счётчик фигур
	while (figures[0][i[0]].x != 9) { //пока фигура имеет смысл

		m_moves[0][0] = figures[0][i[0]]; //откуда ходим
		m_figure[0][0] = Square[m_moves[0][0].y][m_moves[0][0].x]; //запоминаем начальную позицию

		reset_CP_array(turns[0]); //сбрасываем ходы первой фигуры
		Get_turns(m_moves[0][0], Square, turns[0]); //получаем ходы 
		j[0] = 0; //обнуляем первый счётчик ходов
		while (turns[0][j[0]].x != 9) { //пока ход имеет смысл

			m_moves[0][1] = turns[0][j[0]]; //ходим туда
			m_figure[0][1] = Square[m_moves[0][1].y][m_moves[0][1].x]; //запоминаем куда сделали первый ход

			move(Square, m_moves[0][0], m_moves[0][1]); //делаем сам ход

			//##########	1 Ход		###########

			reset_CP_array(figures[1]); //обнуляем фигуры после первого хода
			get_figs(Square, figures[1], white); //получаем ходы соперника
			i[1] = 0;//обнуляем второй счётчик фигур
			price_2 = 10000;
			while (figures[1][i[1]].x != 9) { //пока фигура имеет смысл
				m_moves[1][0] = figures[1][i[1]]; //откуда ходим
				m_figure[1][0] = Square[m_moves[1][0].y][m_moves[1][0].x]; //запоминаем начальную позицию

				reset_CP_array(turns[1]); //сбрасываем ходы второй фигуры
				Get_turns(m_moves[1][0], Square, turns[1]); //получаем ходы 
				j[1] = 0; //обнуляем второй счётчик ходов

				while (turns[1][j[1]].x != 9) { //пока ход имеет смысл

					m_moves[1][1] = turns[1][j[1]]; //ходим туда
					m_figure[1][1] = Square[m_moves[1][1].y][m_moves[1][1].x]; //запоминаем куда сделали первый ход

					move(Square, m_moves[1][0], m_moves[1][1]); //делаем сам ход

					//############ 2 ход ###########

					reset_CP_array(figures[2]); //обнуляем массив с фигурами
					get_figs(Square, figures[2], black); // получаем фигуры для третьего хода
					i[2] = 0; //обнуляем третий счётчик фигур
					price_3 = -10000;
					while (figures[2][i[2]].x != 9) { //пока фигура имеет смысл

						m_moves[2][0] = figures[2][i[2]]; //откуда ходим
						m_figure[2][0] = Square[m_moves[2][0].y][m_moves[2][0].x]; //запоминаем начальную позицию

						reset_CP_array(turns[2]); //сбрасываем ходы первой фигуры
						Get_turns(m_moves[2][0], Square, turns[2]); //получаем ходы 
						j[2] = 0; //обнуляем третий счётчик ходов
						while (turns[2][j[2]].x != 9) { //пока ход имеет смысл

							m_moves[2][1] = turns[2][j[2]]; //ходим туда
							m_figure[2][1] = Square[m_moves[2][1].y][m_moves[2][1].x]; //запоминаем куда сделали третий ход

							move(Square, m_moves[2][0], m_moves[2][1]); //делаем сам ход
							//############ 3 ход ###########
							th_price = get_price(Square, black);
							th_price= th_price -get_price(Square, white); //получаем оценку позиции
							if (th_price > price_3)
								price_3 = th_price; //находим лучший ход
							Square[m_moves[2][0].y][m_moves[2][0].x] = m_figure[2][0];
							Square[m_moves[2][1].y][m_moves[2][1].x] = m_figure[2][1]; //возвращаем на предыдущие позиции
							j[2]++;
						}
						i[2]++;
					}
					if (price_3 < price_2) //находим худший из лучших (сопернику выгодно, иметь худшую для нас- лучшую для него позицию)
						price_2 = price_3;
					Square[m_moves[1][0].y][m_moves[1][0].x] = m_figure[1][0]; //возвращаем на позиции до второго хода
					Square[m_moves[1][1].y][m_moves[1][1].x] = m_figure[1][1];
					j[1]++;
				}
				i[1]++;
			}
			if (price_2 > price_1) {
				price_1 = price_2; //находим лучшее из того, что выберет соперник
				turn[0] = m_moves[0][0];
				turn[1] = m_moves[0][1]; //запоминаем ходы. - (наш ход)
			}
			Square[m_moves[0][0].y][m_moves[0][0].x] = m_figure[0][0]; //возвращаем на позиции до первого хода
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
