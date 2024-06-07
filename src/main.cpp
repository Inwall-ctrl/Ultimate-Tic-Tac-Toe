#include "raylib.h"
#include <memory>
#include "button.h"
#include "game.h"
#include "Scene/manager.h"
#include "menu.h"
#include "aigame.h"


int main(){
	InitWindow(900, 800, "TTT");
    InitAudioDevice();

    SceneManager sceneManager;

    sceneManager.AddScene("MainMenu", std::make_shared<Menu>(&sceneManager));
    sceneManager.AddScene("Game", std::make_shared<Game>(&sceneManager));
    sceneManager.AddScene("AiGame", std::make_shared<AiGame>(&sceneManager));

    sceneManager.SwitchTo("MainMenu");

	SetTargetFPS(60);
	while (!WindowShouldClose()) {
        sceneManager.UpdateCurrentScene();

        BeginDrawing();
		ClearBackground(RAYWHITE);

        sceneManager.DrawCurrentScene();

        EndDrawing();
	}

	CloseWindow();

	return 0;
}

