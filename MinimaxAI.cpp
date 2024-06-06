#include "MinimaxAI.h"
#include "EvalMove.h"

constexpr int MAX_SCORE = 1000;
constexpr int MIN_SCORE = -1000;
constexpr int DRAW_SCORE = 0;

std::pair<int, int> MinimaxAI::find_best_move(const Board& board, Player player) {
    int best_score = MIN_SCORE;
    std::pair<int, int> best_move = {-1, -1};

    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            int index = row * 9 + col + 1;
            if (board.get_mark(index) == EMPTY) {
                Board temp_board = board;
                temp_board.add_mark(index, player);
                int score = minimax(temp_board, player, 0, false);
                if (score > best_score) {
                    best_score = score;
                    best_move = {row, col};
                }
            }
        }
    }

    return best_move;
}

int MinimaxAI::minimax(Board board, Player player, int depth, bool maximizing_player) {
    Player opponent = (player == PLAYER_X) ? PLAYER_O : PLAYER_X;

    int score = EvalMove::evaluate_board(board, player);
    if (score == MAX_SCORE || score == MIN_SCORE || board.isFull()) {
        return score - depth; // Adjust score by depth to prefer faster wins
    }

    if (maximizing_player) {
        int best_score = MIN_SCORE;
        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                int index = row * 9 + col + 1;
                if (board.get_mark(index) == EMPTY) {
                    board.add_mark(index, player);
                    best_score = std::max(best_score, minimax(board, player, depth + 1, false));
                    board.add_mark(index, EMPTY); // Undo move
                }
            }
        }
        return best_score;
    } else {
        int best_score = MAX_SCORE;
        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                int index = row * 9 + col + 1;
                if (board.get_mark(index) == EMPTY) {
                    board.add_mark(index, opponent);
                    best_score = std::min(best_score, minimax(board, player, depth + 1, true));
                    board.add_mark(index, EMPTY); // Undo move
                }
            }
        }
        return best_score;
    }
}
