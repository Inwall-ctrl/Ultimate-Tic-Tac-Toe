#ifndef ULTIMATETTT_MENU_H
#define ULTIMATETTT_MENU_H

#include <map>
#include "Scene/scene.h"
#include "button.h"

class Menu : public Scene {
private:
    std::map<std::string, Texture2D> textures;
    vector<Button> buttons;
public:
    Menu(SceneManager* sceneManager);
    void Update() override;
    void Draw() override;
};


#endif //ULTIMATETTT_MENU_H
