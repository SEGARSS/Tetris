#include "Tetromino.h"


//Tetromino
//---------------------------------------------------------------
Tetromino::Tetromino() // Конструктор: создаёт случайное тетромино
{
	static int figures[7][4] =
	{
		1, 3, 5, 7, // I
		2, 4, 5, 7, // S
		3, 5, 4, 6, // Z
		3, 5, 4, 7, // T
		2, 3, 5, 7, // L
		3, 5, 7, 6, // J
		2, 3, 4, 5  // O
	};

	int n = rand() % 7;

	for (int i = 0; i < 4; i++)
	{
		blocks[i].x = figures[n][i] % 2;
		blocks[i].y = figures[n][i] / 2;
	}

	color = 1 + rand() % 7; // Случайный цвет
}
//---------------------------------------------------------------
void Tetromino::rotate() // Поворот тетромино
{
	sf::Vector2i center = blocks[1]; // Центр вращения

	for (int i = 0; i < 4; i++)
	{
		int x = blocks[i].y - center.y;
		int y = blocks[i].x - center.x;
		blocks[i].x = center.x - x;
		blocks[i].y = center.y - y;
	}
}
//---------------------------------------------------------------
void Tetromino::move(int dx, int dy) // Перемещение тетромино
{
	for (int i = 0; i < 4; i++)
	{
		blocks[i].x += dx;
		blocks[i].y += dy;
	}
}
//---------------------------------------------------------------
bool Tetromino::checkBounds(const int field[M][N]) // Проверка границ и столкновений
{
	for (int i = 0; i < 4; i++)
	{
		int x = blocks[i].x;
		int y = blocks[i].y;

		if (x < 0 || x >= N || y >= M || field[y][x])
			return false;
	}

	return true;
}
//---------------------------------------------------------------


