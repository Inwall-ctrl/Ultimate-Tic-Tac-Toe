#ifndef EVAL_MOVE_H
#define EVAL_MOVE_H

#include "Board.h"

class EvalMove {
public:
    static int evaluate_board(const Board& board, Player player);

private:
    static int evaluate_small_board(const Board& board, int small_board_index, Player player);
};

#endif // EVAL_MOVE_H
