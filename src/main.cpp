// Ultimate TTT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<iostream>
#include "raylib.h"
#include<vector>
#include "button.h"
#include "game.h"


int main(){
	InitWindow(900, 800, "TTT");

    Game game;

	SetTargetFPS(60);
	while (!WindowShouldClose()) {
        game.Update();

        BeginDrawing();
		ClearBackground(RAYWHITE);

        game.Draw();

        EndDrawing();
	}

	CloseWindow();

	return 0;
}

