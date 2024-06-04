#include "ultimateboard.h"
#include "Core/board.h"

using namespace std;
// создание большого поля типа маленьких полей
UltimateBoard::UltimateBoard() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            boards[i][j] = Board();
        }
    }
}

bool UltimateBoard::add_mark(int mini_position, int cell_position, Player player){
    // проверка большого поля
    if (mini_position < 1 || mini_position > 9) {
        return false;
    }

    int row = (mini_position - 1) / 3; // Определяем строку
    int col = (mini_position - 1) % 3; // Определяем столбец

    return boards[row][col].add_mark(cell_position, player);
}

bool UltimateBoard::check_ultimate_winner(Player player) {
    for (int i = 0; i < 3; i++) {
        if (boards[i][0].check_winner() == player && boards[i][1].check_winner() == player && boards[i][2].check_winner() == player)
            return true;
        if (boards[0][i].check_winner() == player && boards[1][i].check_winner() == player && boards[2][i].check_winner() == player)
            return true;
    }
    if (boards[0][0].check_winner() == player && boards[1][1].check_winner() == player && boards[2][2].check_winner() == player)
        return true;
    if (boards[0][2].check_winner() == player && boards[1][1].check_winner() == player && boards[2][0].check_winner() == player)
        return true;
    return false;}

bool UltimateBoard::is_ultimate_full() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if(!boards[i][j].isFull()){
                return false;
            }
        }
    }
    return true;
}
