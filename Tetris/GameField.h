#pragma once

#include "Constants.h"


//GameField
//--------------------------------------------------------------
class GameField
{
public:
	GameField();

	bool isRowFull(int row);
	void clearRow(int row);
	void clearLines();
	void placeTetromino(const Tetromino &t);

	int getCell(int x, int y) const;
	int(&getField())[M][N];

private:
	int field[M][N];
};
//--------------------------------------------------------------
