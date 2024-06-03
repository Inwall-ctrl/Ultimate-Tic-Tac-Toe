#ifndef ULTIMATETTT_GAME_H
#define ULTIMATETTT_GAME_H

#endif //ULTIMATETTT_GAME_H

#include "board.h"
#include "ultimateboard.h"

#include "iostream"

class Game{
private:
    State current_state;
    UltimateBoard ult_board;
    Player current_player = PLAYER_X;
    char global_winner;
    int current_step;
    int next_mini_board;

    friend class current_player;
public:
    Game();
    void switch_player();
    void start_game();
    Player get_current_player();  // Getter for current_player
};