#include "menu.h"
#include "Scene/scene.h"
#include "Scene/manager.h"

enum {MainGame, AiGame};

Menu::Menu(SceneManager *sceneManager) : Scene(sceneManager) {
    textures["background"] = LoadTexture("../src/resource/background.png");
    textures["1vs1"] = LoadTexture("../src/resource/1vs1.png");
    textures["1vsai"] = LoadTexture("../src/resource/1vsai.png");

    Button btn1 = Button({100, 200, 300, 300}, MainGame);
    btn1.SetImage(textures["1vs1"]);
    Button btn2 = Button({500, 200, 300, 300}, AiGame);
    btn2.SetImage(textures["1vsai"]);

    buttons.push_back(btn1);
    buttons.push_back(btn2);
}

void Menu::Update() {
    // Update all buttons
    for (auto &button: buttons) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            if (button.IsClicked() && button.Id == MainGame){
                sceneManager->RequestSwitchTo("Game");
            }
            if (button.IsClicked() && button.Id == AiGame){
                sceneManager->RequestSwitchTo("AiGame");
            }
        }
        button.Update();
    }
}

void Menu::Draw() {
    // Draw background
    DrawTexture(textures["background"], 0, 0, WHITE);

    // Draw all buttons
    for (auto &button: buttons) {
        button.Draw();
    }
}
