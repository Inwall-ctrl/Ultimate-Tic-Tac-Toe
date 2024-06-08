#include "saver.h"
#include <vector>
#include "Core/board.h"

Saver::Saver() {
    game_results.push_back(EMPTY);
    game_results.push_back(EMPTY);
    game_results.push_back(EMPTY);
}

void Saver::add_result(Player winner) {
    current_game=(current_game+1)%3;
    if (game_results.size() <= 3) {
        game_results[current_game] = winner;
    }
}

vector<Player> Saver::get_results(){
    return game_results;
}


