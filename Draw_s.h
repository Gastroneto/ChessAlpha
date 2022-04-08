#pragma once
#include "square.h"
bool is_in(CPoint point, int z0 = 41, int z1 = 458);
CPoint get_place(CPoint point, int z0=41, int z1=458);
void paint_fig(CDC * dc, char fig, CPoint point, int z0=41, int z1=458); //���������� � ��������� ����
void draw_move(CDC * dc, square Square[][8], CPoint StartPoint, CPoint FinishPoint);
void draw_fig(CDC *dc, char fig, CPoint pt, int z0 = 41, int z1 = 458); //���������� � ��������� �����������
void show_moves(CDC *dc, CPoint turns[], int z0 = 41, int z1 = 458); //���������� �������, ���� ����� ������
