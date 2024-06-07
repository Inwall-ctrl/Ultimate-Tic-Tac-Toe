#include "menu.h"
#include "Scene/scene.h"
#include "Scene/manager.h"

enum {MainGame, AiGame};

Menu::Menu(SceneManager *sceneManager) : Scene(sceneManager) {
    textures["background"] = LoadTexture("../src/resource/background.png");

    buttons.push_back(Button({100, 100, 50, 50}, MainGame));
    buttons.push_back(Button({160, 100, 50, 50}, AiGame));
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
