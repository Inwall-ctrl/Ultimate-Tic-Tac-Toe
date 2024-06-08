#include <algorithm>
#include <ctime>
#include "Core/board.h"

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

void Board::clear(){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cells[i][j] = EMPTY;
        }
    }
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
constexpr int MAX_SCORE = 1000;
constexpr int MIN_SCORE = -1000;
constexpr int DRAW_SCORE = 0;

constexpr int WIN_SCORE = 100;
constexpr int LOSE_SCORE = -100;
constexpr int SMALL_BOARD_WIN_SCORE = 10;
constexpr int SMALL_BOARD_LOSE_SCORE = -10;

int Board::evaluate_board(Player player) {
    Player opponent = (player == PLAYER_X) ? PLAYER_O : PLAYER_X;

    int total_score = 0;

    // Evaluate each small board
    for (int i = 0; i < 9; ++i) {
        total_score += evaluate_small_board(i, player);
    }

    // Evaluate the overall board state
    int overall_win = check_winner();
    if (overall_win == player) {
        return WIN_SCORE;
    } else if (overall_win == opponent) {
        return LOSE_SCORE;
    }

    return total_score;
}

int Board::evaluate_small_board(int small_board_index, Player player) {
    Player opponent = (player == PLAYER_X) ? PLAYER_O : PLAYER_X;

    int start_index = small_board_index * 9;
    int small_board_score = 0;

    // Check rows, columns, and diagonals for potential wins or blocks
    const int win_conditions[8][3] = {
            {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Rows
            {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Columns
            {0, 4, 8}, {2, 4, 6}             // Diagonals
    };

    for (const auto& condition : win_conditions) {
        int count_player = 0;
        int count_opponent = 0;
        for (int i = 0; i < 3; ++i) {
            int mark = get_mark(start_index + condition[i]);
            if (mark == player) {
                ++count_player;
            } else if (mark == opponent) {
                ++count_opponent;
            }
        }

        if (count_player == 3) {
            return SMALL_BOARD_WIN_SCORE;
        } else if (count_opponent == 3) {
            return SMALL_BOARD_LOSE_SCORE;
        }

        // Heuristic: favor positions with potential to win
        if (count_player == 2 && count_opponent == 0) {
            small_board_score += 5;
        } else if (count_opponent == 2 && count_player == 0) {
            small_board_score -= 5;
        }
    }

    return small_board_score;
}

int Board::find_best_move(Player player) {
    // Сделать случайный первый ход
    if (isFull()) return -1; // Если доска полностью заполнена, нет доступных ходов
    if (isEmpty()) {
        srand(time(nullptr)); // Инициализация генератора случайных чисел
        int random_index;
        do {
            random_index = rand() % 9 + 1;
        } while (get_mark(random_index) != EMPTY); // Проверяем, что клетка пуста
        return random_index; // Возвращаем случайный первый ход
    }

    // Иначе, продолжаем с поиском лучшего хода по алгоритму минимакса
    int best_score = MIN_SCORE;
    int best_move = -1;

    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            int index = row * 9 + col + 1;
            if (get_mark(index) == EMPTY) {
                Board temp_board = *this; // Создаем копию текущей доски
                temp_board.add_mark(index, player);
                int score = temp_board.minimax(player, 0, false);
                if (score > best_score) {
                    best_score = score;
                    // Преобразуем индексы в значения от 1 до 9
                    best_move = index;
                }
            }
        }
    }

    return best_move;
}



int Board::minimax(Player player, int depth, bool maximizing_player) {
    Player opponent = (player == PLAYER_X) ? PLAYER_O : PLAYER_X;

    int score = evaluate_board( player);
    if (score == MAX_SCORE || score == MIN_SCORE || isFull()) {
        return score - depth; // Adjust score by depth to prefer faster wins
    }

    if (maximizing_player) {
        int best_score = MIN_SCORE;
        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                int index = row * 9 + col + 1;
                if (get_mark(index) == EMPTY) {
                    add_mark(index, player);
                    best_score = std::max(best_score, minimax(player, depth + 1, false));
                    add_mark(index, EMPTY); // Undo move
                }
            }
        }
        return best_score;
    } else {
        int best_score = MAX_SCORE;
        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                int index = row * 9 + col + 1;
                if (get_mark(index) == EMPTY) {
                    add_mark(index, opponent);
                    best_score = std::min(best_score, minimax(player, depth + 1, true));
                    add_mark(index, EMPTY); // Undo move
                }
            }
        }
        return best_score;
    }
}

bool Board::isEmpty() {
    for (int i = 1; i <= 9; ++i) {
        if (get_mark(i) != EMPTY) {
            return false; // Если хоть одна клетка не пуста, возвращаем false
        }
    }
    return true; // Если все клетки пусты, возвращаем true
}


