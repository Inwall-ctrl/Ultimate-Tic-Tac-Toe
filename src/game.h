#ifndef ULTIMATETTT_GAME_H
#define ULTIMATETTT_GAME_H

#include <iostream>
#include "FSM/FSM.h"
#include "Core/ultimateboard.h"
#include "button.h"

class Game {
private:
    std::map<std::string, Texture2D> textures;
    std::map<std::string, Music> sounds;
    vector<Button> board_gui;
    char *title;

    FSM state;
    UltimateBoard board;
    int current_block;
    Player current_player;

    static vector<Button> init_field();
public:
    Game();
    void Update();
    void Draw();
};

#endif
