#ifndef __CORE_H__
#define __CORE_H__

#include <iostream>

enum Player { EMPTY, PLAYER_X, PLAYER_O };
enum State { PLAYER1, PLAYER2, END };

class Board {
private:
    Player cells[3][3];
public:
    Board();
    bool add_mark(int position, Player player);
    Player get_mark(int position) const;
    Player check_winner() const;
    bool isFull() const;
};

#endif // __CORE_H__
