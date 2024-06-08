//
// Created by Pluzhnikov Mark on 2024/6/8.
//

#include "saver.h"
#include <vector>

Saver::Saver() {
    // Инициализация массива результатов
    game_results.reserve(3); // Зарезервируем место для трех результатов
}

void Saver::add_result(Player winner) {
    if (game_results.size() < 3) {
        game_results.push_back(winner);
    }
}

vector<Player> Saver::get_results(){
    return game_results;
}


