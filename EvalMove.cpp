#include "EvalMove.h"

constexpr int WIN_SCORE = 100;
constexpr int LOSE_SCORE = -100;
constexpr int DRAW_SCORE = 0;
constexpr int SMALL_BOARD_WIN_SCORE = 10;
constexpr int SMALL_BOARD_LOSE_SCORE = -10;

int EvalMove::evaluate_board(const Board& board, Player player) {
    Player opponent = (player == PLAYER_X) ? PLAYER_O : PLAYER_X;

    int total_score = 0;

    // Evaluate each small board
    for (int i = 0; i < 9; ++i) {
        total_score += evaluate_small_board(board, i, player);
    }

    // Evaluate the overall board state
    int overall_win = board.check_winner();
    if (overall_win == player) {
        return WIN_SCORE;
    } else if (overall_win == opponent) {
        return LOSE_SCORE;
    }

    return total_score;
}

int EvalMove::evaluate_small_board(const Board& board, int small_board_index, Player player) {
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
            int mark = board.get_mark(start_index + condition[i]);
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
