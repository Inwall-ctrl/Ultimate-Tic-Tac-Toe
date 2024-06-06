#include "UltimateBoard.h"

// Initialize the ultimate board with empty mini-boards
UltimateBoard::UltimateBoard() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            boards[i][j] = Board();
        }
    }
}

// Display the ultimate board
void UltimateBoard::display() const {
    for (int miniRow = 0; miniRow < 3; ++miniRow) {
        for (int cellRow = 0; cellRow < 3; ++cellRow) {
            for (int miniCol = 0; miniCol < 3; ++miniCol) {
                for (int cellCol = 0; cellCol < 3; ++cellCol) {
                    Player mark = boards[miniRow][miniCol].get_mark(cellRow * 3 + cellCol + 1);
                    char symbol = (mark == Player::PLAYER_X) ? 'X' : (mark == Player::PLAYER_O) ? 'O' : '-';
                    std::cout << symbol;
                    if (cellCol < 2) {
                        std::cout << ' ';
                    }
                }
                if (miniCol < 2) {
                    std::cout << " | ";
                }
            }
            std::cout << std::endl;
        }
        if (miniRow < 2) {
            std::cout << "---------------------" << std::endl;
        }
    }
}

// Add a mark to the ultimate board
bool UltimateBoard::add_mark(int mini_position, int cell_position, Player player) {
    if (mini_position < 1 || mini_position > 9) {
        return false;
    }

    int row = (mini_position - 1) / 3;
    int col = (mini_position - 1) % 3;

    return boards[row][col].add_mark(cell_position, player);
}

// Check if there's a winner on the ultimate board
bool UltimateBoard::check_ultimate_winner(Player player) const {
    for (int i = 0; i < 3; ++i) {
        if (boards[i][0].check_winner() == player && boards[i][1].check_winner() == player && boards[i][2].check_winner() == player)
            return true;
        if (boards[0][i].check_winner() == player && boards[1][i].check_winner() == player && boards[2][i].check_winner() == player)
            return true;
    }
    if (boards[0][0].check_winner() == player && boards[1][1].check_winner() == player && boards[2][2].check_winner() == player)
        return true;
    if (boards[0][2].check_winner() == player && boards[1][1].check_winner() == player && boards[2][0].check_winner() == player)
        return true;
    return false;
}

// Check if the ultimate board is full
bool UltimateBoard::is_ultimate_full() const {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (!boards[i][j].isFull()) {
                return false;
            }
        }
    }
    return true;
}

// Check if a mini-board is available for play
bool UltimateBoard::isMiniBoardAvailable(int row, int col) const {
    return !boards[row][col].isFull() && boards[row][col].check_winner() == Player::EMPTY;
}
