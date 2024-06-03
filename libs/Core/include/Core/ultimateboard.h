#ifndef ULTIMATETTT_ULTIMATEBOARD_H
#define ULTIMATETTT_ULTIMATEBOARD_H

#include "board.h"
#include "iostream"

class UltimateBoard{
private:
    Board boards[3][3]; // Contains an array of 3x3 objects of the Board class
//    Board board_winner;

public:
    void display();
    UltimateBoard(); // initialization of mini-boards (places small boards in a large one-ultimate)
    bool add_mark(int mini_position, int cell_position, Player player);
    bool check_ultimate_winner(Player player); // Checking for winnings
    bool is_ultimate_full(); // Checking if the board is full

};



#endif //ULTIMATETTT_ULTIMATEBOARD_H
