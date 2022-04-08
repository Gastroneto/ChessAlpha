#pragma once
#pragma once
//White=1, Empty =0, Black = 2
class Figure
{
public:
	Figure();
	~Figure();
	char pawn(char color);
	char horse(char color);
	char king(char color);
	char queen(char color);
	char officer(char color);
	char castle(char color);
private:

};


