#ifndef EVAL_MOVE_H
#define EVAL_MOVE_H

#include "Board.h"

class EvalMove {
public:
    /**
     * @brief Evaluates the entire board for a given player.
     * @param board The current game board.
     * @param player The player for whom to evaluate the board.
     * @return The evaluation score of the board position.
     */
    static int evaluate_board(const Board& board, Player player);

private:
    /**
     * @brief Evaluates a small 3x3 board within the larger board.
     * @param board The current game board.
     * @param small_board_index The index of the small board to evaluate.
     * @param player The player for whom to evaluate the board.
     * @return The evaluation score of the small board.
     */
    static int evaluate_small_board(const Board& board, int small_board_index, Player player);
};

#endif // EVAL_MOVE_H
