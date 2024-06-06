// Ultimate TTT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<iostream>
#include "raylib.h"
#include<vector>
#include<cstdio>

class Button {
private:
	Rectangle bound;
	int imageIndex; // Index of the currently displayed image (-1 means no image)
	std::vector<Texture2D> images;
	bool click; // Flag to indicate whether the button has been clicked

public:
	Button(Rectangle _bounds) : bound(_bounds), imageIndex(-1), click(false) {}

	void Draw() const {
		DrawRectangleRec(bound, GRAY); // Change color when clicked
		//DrawText("Click me", static_cast<int>(bound.x) + 10, static_cast<int>(bound.y) + 10, 20, WHITE);
		if (click && imageIndex != -1) {
			DrawTexture(images[imageIndex], static_cast<int>(bound.x), static_cast<int>(bound.y), WHITE);
		}
	}

	bool IsClicked(Vector2 mousePosition) {
		if (!click && CheckCollisionPointRec(mousePosition, bound)) {
			imageIndex = (imageIndex + 1) % images.size(); // Cycle through images
			click = true; // Set clicked to true
			return true;
		}
		return false;
	}

	void AddImage(Texture2D image) {
		images.push_back(image);
	}

	bool IsClicked() const {
		return click;
	}
};





void DrawBut(Rectangle lim, Color color, Color tcolor, int fontSize, const char* text) {
	//Font font = LoadFont("resource/classicarcade.ttf");
	DrawRectangleRec(lim, color);
	DrawText(text, static_cast<int>(lim.x) + 10, static_cast<int>(lim.y) + 10, 20, tcolor);

}

bool MenuBut(Rectangle lim) {
	return CheckCollisionPointRec(GetMouseDelta(), lim) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
}
int main()
{
	InitWindow(900, 800, "TTT");
	SetWindowState(FLAG_VSYNC_HINT);
	Texture2D texture = LoadTexture("resource/background.png");
	Texture2D cross = LoadTexture("resource/crosss.png");
	Texture2D zero = LoadTexture("resource/zero1.png");
	Texture2D utt = LoadTexture("resource/ttt.png");
	Texture2D single = LoadTexture("resource/single.png");
	Texture2D comp = LoadTexture("resource/comp.png");
	Texture2D well = LoadTexture("resource/WELL.png");

	std::vector<Button> buttons;
	//BLOCK-1
	buttons.push_back(Button({ 200,200, 45, 50 })); //1
	buttons.push_back(Button({ 250,200, 45, 50 })); //2
	buttons.push_back(Button({ 300,200, 45, 50 })); //3
	buttons.push_back(Button({ 200,255, 45, 50 })); //4
	buttons.push_back(Button({ 250,255, 45, 50 })); //5
	buttons.push_back(Button({ 300,255, 45, 50 })); //6
	buttons.push_back(Button({ 200,310, 45, 50 })); //7
	buttons.push_back(Button({ 250,310, 45, 50 })); //8
	buttons.push_back(Button({ 300,310, 45, 50 })); //9

	//BLOCK-2 
	buttons.push_back(Button({ 360,200, 45, 50 })); //1
	buttons.push_back(Button({ 410,200, 45, 50 })); //2
	buttons.push_back(Button({ 460,200, 45, 50 })); //3
	buttons.push_back(Button({ 360,255, 45, 50 })); //4
	buttons.push_back(Button({ 410,255, 45, 50 })); //5
	buttons.push_back(Button({ 460,255, 45, 50 })); //6
	buttons.push_back(Button({ 360,310, 45, 50 })); //7
	buttons.push_back(Button({ 410,310, 45, 50 })); //8
	buttons.push_back(Button({ 460,310, 45, 50 })); //9

	//BLOCK-3
	buttons.push_back(Button({ 520,200, 45, 50 })); //1
	buttons.push_back(Button({ 570,200, 45, 50 })); //2
	buttons.push_back(Button({ 620,200, 45, 50 })); //3
	buttons.push_back(Button({ 520,255, 45, 50 })); //4
	buttons.push_back(Button({ 570,255, 45, 50 })); //5
	buttons.push_back(Button({ 620,255, 45, 50 })); //6
	buttons.push_back(Button({ 520,310, 45, 50 })); //7
	buttons.push_back(Button({ 570,310, 45, 50 })); //8
	buttons.push_back(Button({ 620,310, 45, 50 })); //9

	//BLOCK-4
	buttons.push_back(Button({ 200,370, 45, 50 })); //1
	buttons.push_back(Button({ 250,370, 45, 50 })); //2
	buttons.push_back(Button({ 300,370, 45, 50 })); //3
	buttons.push_back(Button({ 200,425, 45, 50 })); //4
	buttons.push_back(Button({ 250,425, 45, 50 })); //5
	buttons.push_back(Button({ 300,425, 45, 50 })); //6
	buttons.push_back(Button({ 200,480, 45, 50 })); //7
	buttons.push_back(Button({ 250,480, 45, 50 })); //8
	buttons.push_back(Button({ 300,480, 45, 50 })); //9

	//BLOCK-5
	buttons.push_back(Button({ 360,370, 45, 50 })); //1
	buttons.push_back(Button({ 410,370, 45, 50 })); //2
	buttons.push_back(Button({ 460,370, 45, 50 })); //3
	buttons.push_back(Button({ 360,425, 45, 50 })); //4
	buttons.push_back(Button({ 410,425, 45, 50 })); //5
	buttons.push_back(Button({ 460,425, 45, 50 })); //6
	buttons.push_back(Button({ 360,480, 45, 50 })); //7
	buttons.push_back(Button({ 410,480, 45, 50 })); //8
	buttons.push_back(Button({ 460,480, 45, 50 })); //9

	//BLOCK-6
	buttons.push_back(Button({ 520,370, 45, 50 })); //1
	buttons.push_back(Button({ 570,370, 45, 50 })); //2
	buttons.push_back(Button({ 620,370, 45, 50 })); //3
	buttons.push_back(Button({ 520,425, 45, 50 })); //4
	buttons.push_back(Button({ 570,425, 45, 50 })); //5
	buttons.push_back(Button({ 620,425, 45, 50 })); //6
	buttons.push_back(Button({ 520,480, 45, 50 })); //7
	buttons.push_back(Button({ 570,480, 45, 50 })); //8
	buttons.push_back(Button({ 620,480, 45, 50 })); //9

	//BLOCK-7
	buttons.push_back(Button({ 200,540, 45, 50 })); //1
	buttons.push_back(Button({ 250,540, 45, 50 })); //2
	buttons.push_back(Button({ 300,540, 45, 50 })); //3
	buttons.push_back(Button({ 200,595, 45, 50 })); //4
	buttons.push_back(Button({ 250,595, 45, 50 })); //5
	buttons.push_back(Button({ 300,595, 45, 50 })); //6
	buttons.push_back(Button({ 200,650, 45, 50 })); //7
	buttons.push_back(Button({ 250,650, 45, 50 })); //8
	buttons.push_back(Button({ 300,650, 45, 50 })); //9

	//BLOCK-8
	buttons.push_back(Button({ 360,540, 45, 50 })); //1
	buttons.push_back(Button({ 410,540, 45, 50 })); //2
	buttons.push_back(Button({ 460,540, 45, 50 })); //3
	buttons.push_back(Button({ 360,595, 45, 50 })); //4
	buttons.push_back(Button({ 410,595, 45, 50 })); //5
	buttons.push_back(Button({ 460,595, 45, 50 })); //6
	buttons.push_back(Button({ 360,650, 45, 50 })); //7
	buttons.push_back(Button({ 410,650, 45, 50 })); //8
	buttons.push_back(Button({ 460,650, 45, 50 })); //9

	//BLOCK-9
	buttons.push_back(Button({ 520,540, 45, 50 })); //1
	buttons.push_back(Button({ 570,540, 45, 50 })); //2
	buttons.push_back(Button({ 620,540, 45, 50 })); //3
	buttons.push_back(Button({ 520,595, 45, 50 })); //4
	buttons.push_back(Button({ 570,595, 45, 50 })); //5
	buttons.push_back(Button({ 620,595, 45, 50 })); //6
	buttons.push_back(Button({ 520,650, 45, 50 })); //7
	buttons.push_back(Button({ 570,650, 45, 50 })); //8
	buttons.push_back(Button({ 620,650, 45, 50 })); //9

	for (auto& button : buttons) {
		button.AddImage(cross);
		button.AddImage(zero);
	}

	SetTargetFPS(60);

	bool welcomePage = true;

	
	
	while (!WindowShouldClose())
	{
		if (welcomePage) {
			BeginDrawing();
			ClearBackground(RAYWHITE);
			

			//DrawTexture(texture, 0, 0, WHITE);
			DrawTexture(well, 0, 0, WHITE);
			DrawTexture(utt, 160, 100, WHITE);
			
			Rectangle sins = { 104, 304, 278, 250 };
			Rectangle comps = { 504, 304, 282, 260 };
						
			DrawBut(sins, BLACK, WHITE, 60, "");
			DrawBut(comps, BLACK, WHITE, 60, "");

			DrawTexture(single, 100, 300, WHITE);
			DrawTexture(comp, 500, 300, WHITE);
			
			Rectangle enterb = { 105, 560, 280, 50 };
			DrawBut(enterb, WHITE, WHITE, 30, " ");
			Rectangle enter = { 100, 565, 280, 50 };
			DrawBut(enter, BLUE, WHITE, 20, "PRESS ENTER TO START");

			Rectangle shiftb = { 508, 570, 286, 50 };
			DrawBut(shiftb, WHITE, WHITE, 30, " ");
			Rectangle shift = { 504, 575, 285, 50 };
			DrawBut(shift, BLUE, WHITE, 20, "PRESS RSHIFT TO START");

			EndDrawing();

			if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_RIGHT_SHIFT)) {
				welcomePage = false;
				
			}

		}
		else {
			BeginDrawing();
			ClearBackground(RAYWHITE);

			// Draw the background texture
			DrawTexture(texture, 0, 0, WHITE);
			DrawTexture(utt, 120, 30, WHITE);

			DrawText("PLAYER-1", 40, 20,25, WHITE);
			DrawTexture(cross, 170, 10, WHITE);
			DrawText("PLAYER-2", 700, 30, 25, WHITE);
			DrawTexture(zero, 830, 20, WHITE);

			DrawRectangleLines(195, 195, 160, 170, WHITE);
			DrawRectangleLines(350, 195, 165, 170, WHITE);
			DrawRectangleLines(510, 195, 160, 170, WHITE);

			DrawRectangleLines(195, 365, 160, 170, WHITE);
			DrawRectangleLines(350, 365, 165, 170, WHITE);
			DrawRectangleLines(510, 365, 160, 170, WHITE);

			DrawRectangleLines(195, 535, 160, 170, WHITE);
			DrawRectangleLines(350, 535, 165, 170, WHITE);
			DrawRectangleLines(510, 535, 160, 170, WHITE);

			for (auto& button : buttons) {
				button.Draw();
			}

			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
				Vector2 mousePosition = GetMousePosition();
				for (auto& button : buttons) {
					button.IsClicked(mousePosition);
				}
			}
			EndDrawing();
			
		}

		
	}
		// Unload the texture when done
		UnloadTexture(texture);
		UnloadTexture(utt);
		UnloadTexture(single);
		UnloadTexture(comp);
		CloseWindow();

		return 0;
	}

