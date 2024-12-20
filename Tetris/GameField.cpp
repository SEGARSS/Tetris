#include "GameField.h"

// �����������: ������������� ������� ����
GameField::GameField() {
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            field[i][j] = 0;
}

// ��������� ��������� �� ����
void GameField::placeTetromino(const Tetromino& tetromino) {
    for (int i = 0; i < 4; i++) {
        int x = tetromino.blocks[i].x;
        int y = tetromino.blocks[i].y;
        field[y][x] = tetromino.color;
    }
}

// ������� ����������� �����
void GameField::clearLines() {
    for (int i = M - 1; i >= 0; i--) {
        if (isRowFull(i)) {
            clearRow(i);
            // �������� ����� ����
            for (int k = i; k > 0; k--)
                for (int j = 0; j < N; j++)
                    field[k][j] = field[k - 1][j];
            for (int j = 0; j < N; j++)
                field[0][j] = 0;
            i++; // ��������� ������� ������ �����
        }
    }
}

// ��������, ��������� �� ������
bool GameField::isRowFull(int row) {
    for (int j = 0; j < N; j++) {
        if (field[row][j] == 0) {
            return false;
        }
    }
    return true;
}

// ������� ���������� ������
void GameField::clearRow(int row) {
    for (int j = 0; j < N; j++) {
        field[row][j] = 0;
    }
}

// ��������� �������� ������ ����
int GameField::getCell(int x, int y) const {
    if (x < 0 || x >= N || y < 0 || y >= M)
        return 0;
    return field[y][x];
}

// ���������� ������ �� ������ �������� ����
int (&GameField::getField())[M][N] {
    return field;
}