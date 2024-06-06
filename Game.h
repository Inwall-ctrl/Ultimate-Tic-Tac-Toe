#ifndef ULTIMATETTT_GAME_H
#define ULTIMATETTT_GAME_H

#include "Board.h"
#include "UltimateBoard.h"
#include <iostream>
#include <vector>

class Game {
private:
    State current_state;
    UltimateBoard ult_board;
    Player current_player;
    char global_winner;
    int current_step;
    int next_mini_board_row;
    int next_mini_board_col;
    int game_mode;

public:
    Game();
    void switch_player();
    void start_game();
    void set_mode(int mode);
    void make_ai_move();
    std::vector<int> get_available_moves(int mini_board_row, int mini_board_col);
};

#endif // ULTIMATETTT_GAME_H
