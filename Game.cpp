#include "Game.h"
#include "UltimateBoard.h"
#include "MinimaxAI.h"
#include <vector>

// Constructor to initialize the game
Game::Game() : current_state(PLAYER1), current_player(PLAYER_X), global_winner('-'), current_step(0), next_mini_board_row(-1), next_mini_board_col(-1), game_mode(1) {}

// Function to switch between players
void Game::switch_player() {
    current_player = (current_player == PLAYER_X) ? PLAYER_O : PLAYER_X;
}

// Function to set the game mode
void Game::set_mode(int mode) {
    game_mode = mode;
}

// Function to get available moves in a specific mini-board
std::vector<int> Game::get_available_moves(int mini_board_row, int mini_board_col) {
    std::vector<int> available_moves;
    for (int i = 1; i <= 9; ++i) {
        if (ult_board.boards[mini_board_row][mini_board_col].get_mark(i) == EMPTY) {
            available_moves.push_back(i);
        }
    }
    return available_moves;
}

// Function to handle AI moves
void Game::make_ai_move() {
    std::pair<int, int> best_move = MinimaxAI::find_best_move(ult_board.boards[next_mini_board_row][next_mini_board_col], current_player);
    int mini_position = next_mini_board_row * 3 + next_mini_board_col + 1;
    int cell_position = best_move.first * 3 + best_move.second + 1;
    ult_board.add_mark(mini_position, cell_position, current_player);
    next_mini_board_row = best_move.first;
    next_mini_board_col = best_move.second;
}
// Function to start and manage the game
void Game::start_game() {
    bool initial_turn = true;

    while (true) {
        ult_board.display();

        if (current_state == END) {
            std::cout << "Game over! ";
            if (global_winner == 'X' || global_winner == 'O') {
                std::cout << "Player " << global_winner << " wins!" << std::endl;
            } else {
                std::cout << "It's a tie!" << std::endl;
            }
            break;
        }

        if (initial_turn) {
            if (game_mode == 2 || (game_mode == 3 && current_player == PLAYER_O)) {
                make_ai_move();
                initial_turn = false;
                continue;
            }

            std::cout << "Player " << (current_player == PLAYER_X ? 'X' : 'O') << ", enter mini board position (1-9): ";
            int mini_position;
            std::cin >> mini_position;

            if (mini_position < 1 || mini_position > 9) {
                std::cout << "Invalid mini board position! Try again." << std::endl;
                continue;
            }

            next_mini_board_row = (mini_position - 1) / 3;
            next_mini_board_col = (mini_position - 1) % 3;

            if (!ult_board.isMiniBoardAvailable(next_mini_board_row, next_mini_board_col)) {
                std::cout << "Selected mini board is not available! Try again." << std::endl;
                continue;
            }

            initial_turn = false;
        }

        if (game_mode == 2 || (game_mode == 3 && current_player == PLAYER_O)) {
            make_ai_move();
        } else {
            std::cout << "Player " << (current_player == PLAYER_X ? 'X' : 'O') << ", enter cell position (1-9) in mini-board (" 
                      << (next_mini_board_row + 1) << ", " << (next_mini_board_col + 1) << "): ";
            int cell_position;
            std::cin >> cell_position;

            if (cell_position < 1 || cell_position > 9) {
                std::cout << "Invalid cell position! Try again." << std::endl;
                continue;
            }

            int cellRow = (cell_position - 1) / 3;
            int cellCol = (cell_position - 1) % 3;
            int mini_position = next_mini_board_row * 3 + next_mini_board_col + 1;
            int absolute_cell_position = cellRow * 3 + cellCol + 1;

            if (!ult_board.add_mark(mini_position, absolute_cell_position, current_player)) {
                std::cout << "Invalid move! Try again." << std::endl;
                continue;
            }

            next_mini_board_row = cellRow;
            next_mini_board_col = cellCol;
        }

        if (ult_board.check_ultimate_winner(current_player)) {
            ult_board.display();
            global_winner = (current_player == PLAYER_X) ? 'X' : 'O';
            current_state = END;
            continue;
        }

        if (ult_board.is_ultimate_full()) {
            ult_board.display();
            global_winner = '-';
            current_state = END;
            continue;
        }

        if (!ult_board.isMiniBoardAvailable(next_mini_board_row, next_mini_board_col)) {
            initial_turn = true;
        }

        switch_player();
    }
}
