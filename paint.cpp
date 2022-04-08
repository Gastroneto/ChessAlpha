#include "stdafx.h"
#include "paint.h"
#include "Figure.h"
using namespace std;




void set_start_pos(square square[][8])
{
	Figure fig;
	for(int i=0;i<8;i++){
		square[1][i].set_fig(fig.pawn(Black), Black);
		square[6][i].set_fig(fig.pawn(White),White);
	}
	square[0][0].set_fig(fig.castle(Black), Black);
	square[0][7].set_fig(fig.castle(Black), Black);
	square[7][0].set_fig(fig.castle(White), White);
	square[7][7].set_fig(fig.castle(White), White);
	square[0][1].set_fig(fig.horse(Black), Black);
	square[0][6].set_fig(fig.horse(Black), Black);
	square[7][6].set_fig(fig.horse(White), White);
	square[7][1].set_fig(fig.horse(White), White);
	square[0][2].set_fig(fig.officer(Black), Black);
	square[0][5].set_fig(fig.officer(Black), Black);
	square[7][2].set_fig(fig.officer(White), White);
	square[7][5].set_fig(fig.officer(White), White);
	square[0][3].set_fig(fig.queen(Black), Black);
	square[0][4].set_fig(fig.king(Black), Black);
	square[7][3].set_fig(fig.queen(White), White);
	square[7][4].set_fig(fig.king(White), White);
}
void paint_pos(square square[][8]) {
	for (int i = 0 /*строка*/; i < 8; i++) {
		for (int j = 0 /*столбец*/; j < 8; j++) {
			setsymb(j, i, square[i][j].fig);
		}
	}
}
