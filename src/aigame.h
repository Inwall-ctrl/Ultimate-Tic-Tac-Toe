#ifndef ULTIMATETTT_AIGAME_H
#define ULTIMATETTT_AIGAME_H

#include <map>
#include <string>
#include "button.h"
#include "FSM/FSM.h"
#include "Core/ultimateboard.h"
#include "Scene/scene.h"

class AiGame : public Scene {
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
    explicit AiGame(SceneManager* sceneManager);
    void Update() override;
    void Draw() override;
};


#endif //ULTIMATETTT_AIGAME_H
