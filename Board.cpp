#include "Core/board.h"

// Initialize the board with empty cells
Board::Board() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cells[i][j] = EMPTY;
        }
    }
}

// Add a mark to the board at the specified position
bool Board::add_mark(int position, Player player) {
    if (position < 1 || position > 9) {
        return false;
    }

    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    if (cells[row][col] != EMPTY) {
        return false;
    }

    cells[row][col] = player;
    return true;
}

// Get the mark at the specified position
Player Board::get_mark(int position) const {
    if (position < 1 || position > 9) {
        return EMPTY;
    }

    int row = (position - 1) / 3;
    int col = (position - 1) % 3;
    return cells[row][col];
}

// Check if there's a winner on the board
Player Board::check_winner() const {
    // Check rows
    for (int i = 0; i < 3; ++i) {
        if (cells[i][0] != EMPTY && cells[i][0] == cells[i][1] && cells[i][1] == cells[i][2]) {
            return cells[i][0];
        }
    }

    // Check columns
    for (int j = 0; j < 3; ++j) {
        if (cells[0][j] != EMPTY && cells[0][j] == cells[1][j] && cells[1][j] == cells[2][j]) {
            return cells[0][j];
        }
    }

    // Check diagonals
    if (cells[0][0] != EMPTY && cells[0][0] == cells[1][1] && cells[1][1] == cells[2][2]) {
        return cells[0][0];
    }
    if (cells[0][2] != EMPTY && cells[0][2] == cells[1][1] && cells[1][1] == cells[2][0]) {
        return cells[0][2];
    }

    // No winner found
    return EMPTY;
}

// Check if the board is full
bool Board::isFull() const {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (cells[i][j] == EMPTY) {
                return false;
            }
        }
    }
    return true;
}
