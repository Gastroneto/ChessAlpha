#include "stdafx.h"
#include "Figure.h"

Figure::Figure()
{
}


Figure::~Figure()
{
}


char Figure::pawn(char color)
{
	if (color == white) {
		return 'P';//♟
	}
	if (color == black) {
		return 'p'; //♙
	}
	return 'E';


}

char Figure::horse(char color)
{
	if (color == white)
		return 'H';//♞
	if (color == black)
		return 'h';//♘
	return 'E';
}

char Figure::king(char color)
{
	if (color == white)
		return 'K';//♚
	if (color == black)
		return 'k';//♔
	return 'E';
}

char Figure::queen(char color)
{
	if (color == white)
		return 'Q';//♛
	if (color == black)
		return 'q';//♕
	return 'E';
}

char Figure::officer(char color)
{
	if (color == white)
		return 'O';//♝
	if (color == black)
		return 'o';//♗
	return 'E';
}

char Figure::castle(char color)
{
	if (color == white)
		return 'C';//♜
	if (color == black)
		return 'c';//♖
	return 'E';
}