#ifndef ULTIMATETTT_BOARD_H
#define ULTIMATETTT_BOARD_H

enum Player {EMPTY, PLAYER_X, PLAYER_O};

class Board {
private:
    Player cells[3][3];
public:
    Board();
    bool add_mark(int position, Player player);
    Player get_mark(int position);
    Player check_winner();
    bool isFull();



    int minimax(Player player, int depth, bool maximizing_player);
    int find_best_move(Player player);

    int evaluate_board(Player player);

    int evaluate_small_board(int small_board_index, Player player);

    bool isEmpty();
};

#endif
