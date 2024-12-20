#pragma once

#include "Constants.h"


//Tetromino
//------------------------------------------------------------------
class Tetromino
{
public:
	Tetromino();	

	sf::Vector2i blocks[4];
	void rotate();
	void move(int dx, int dy);
	bool checkBounds(const int field[M][N]);

	
	int color;

private:
	
};
//------------------------------------------------------------------