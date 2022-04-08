#pragma once
#include"square.h"
void set_start_pos(square square[][8]);
void move(square Square[][8], CPoint StartPoint, CPoint FinishPoint);
int get_price(square Square[][8], int color);
int get_figs(square Square[][8], CPoint fig[], int color);
bool can_we_move(CPoint pt, CPoint turns[]);
int get_bot_turn(square Square[][8], CPoint turn[], int color);
int reset_CP_array(CPoint turn[], int size=64); //обнуляем массив с позициями