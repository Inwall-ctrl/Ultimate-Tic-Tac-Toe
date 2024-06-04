#ifndef __Core__
#define __Core__

#include <cstdio>
#include "iostream"

enum Player {EMPTY, PLAYER_X, PLAYER_O};
enum State {START, PLAYER1, PLAYER2, END};

class Board {
private:
    Player cells[3][3];
public:
    Board();
    bool add_mark(int position, Player player);
    Player get_mark(int position);
    Player check_winner();
    bool isFull(); // Проверяет заполнена ли маленькая доска полностью
};

#endif
