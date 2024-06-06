#ifndef ULTIMATETTT_ULTIMATEBOARD_H
#define ULTIMATETTT_ULTIMATEBOARD_H

#include "Board.h"

class UltimateBoard {
public: // Change from private to public
    Board boards[3][3];

public:
    UltimateBoard();
    void display() const;
    bool add_mark(int mini_position, int cell_position, Player player);
    bool check_ultimate_winner(Player player) const;
    bool isMiniBoardAvailable(int row, int col) const;
    bool is_ultimate_full() const;
};

#endif // ULTIMATETTT_ULTIMATEBOARD_H
