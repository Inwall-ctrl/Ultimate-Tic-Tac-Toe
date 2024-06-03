#include "Core/board.h"

using namespace std;

Board::Board() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cells[i][j] = EMPTY;
        }
    }
}

bool Board::add_mark(int position, Player player){
    if (position < 1 || position > 9) {
        return false;
    }

    int row = (position - 1) / 3; // Определяем строку
    int col = (position - 1) % 3; // Определяем столбец

    if(cells[row][col] != EMPTY){
        return false;
    }

    cells[row][col] = player;
    return true;
}

// get_mark returns mark at position
Player Board::get_mark(int position){
    if (position < 1 || position > 9) {
        return EMPTY;
    }

    int row = (position - 1) / 3;
    int col = (position - 1) % 3;
    return cells[row][col];
}

Player Board::check_winner() {
    // Проверка по строкам
    for (int i = 0; i < 3; ++i) {
        if (cells[i][0] != EMPTY && cells[i][0] == cells[i][1] && cells[i][1] == cells[i][2]) {
            return cells[i][0];
        }
    }

    // Проверка по столбцам
    for (int j = 0; j < 3; ++j) {
        if (cells[0][j] != EMPTY && cells[0][j] == cells[1][j] && cells[1][j] == cells[2][j]) {
            return cells[0][j];
        }
    }

    // Проверка по диагоналям
    if (cells[0][0] != EMPTY && cells[0][0] == cells[1][1] && cells[1][1] == cells[2][2]) {
        return cells[0][0];
    }
    if (cells[0][2] != EMPTY && cells[0][2] == cells[1][1] && cells[1][1] == cells[2][0]) {
        return cells[0][2];
    }

    // Если ни одно из условий не выполнено, значит победителя нет
    return EMPTY;
}

bool Board::isFull() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (cells[i][j] == EMPTY) {
                return false;
            }
        }
    }
    return true;
}
