#ifndef ULTIMATETTT_BOARD_H
#define ULTIMATETTT_BOARD_H

enum Player {EMPTY, PLAYER_X, PLAYER_O};
enum StateEn {START, PLAYER1, PLAYER2, END};

class Board {
private:
    Player cells[3][3];
public:
    Board();
    void clear();
    bool add_mark(int position, Player player);
    Player get_mark(int position);
    Player check_winner();
    bool isFull(); // Проверяет заполнена ли маленькая доска полностью
};

#endif
