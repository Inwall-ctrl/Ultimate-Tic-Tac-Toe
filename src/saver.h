#ifndef ULTIMATETTT_SAVER_H
#define ULTIMATETTT_SAVER_H

#include <iostream>
#include "Core/board.h"
#include "Core/ultimateboard.h"
#include <vector>

using namespace std;


class Saver {
private:
    int current_game = -1;
    vector<Player> game_results; // Массив для хранения результатов игр
public:
    Saver(); // Конструктор
    void add_result(Player winner); // Метод для добавления нового результата
    vector<Player> get_results(); // Метод для получения сохраненных результатов};
};
#endif //ULTIMATETTT_SAVER_H
