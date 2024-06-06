#ifndef MINIMAX_AI_H
#define MINIMAX_AI_H

#include "Board.h"
#include <vector>

class MinimaxAI {
public:
    static std::pair<int, int> find_best_move(const Board& board, Player player);
private:
    static int minimax(Board board, Player player, int depth, bool maximizingPlayer);
};

#endif // MINIMAX_AI_H
