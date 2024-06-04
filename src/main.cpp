// Ultimate TTT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<iostream>
#include "raylib.h"
#include<vector>

class Button{
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
int main()
{
	InitWindow(900, 800, "TTT");
	SetWindowState(FLAG_VSYNC_HINT);

	Texture2D texture = LoadTexture("resource/background.png");
	Texture2D cross = LoadTexture("resource/crosss.png");
	Texture2D zero = LoadTexture("resource/zero.png");

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

	for(auto& button : buttons) {
		button.AddImage(cross);
		button.AddImage(zero);
	}
	
	SetTargetFPS(60);
	

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(RAYWHITE);

		// Draw the background texture
		DrawTexture(texture, 0, 0, WHITE);
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

	// Unload the texture when done
	UnloadTexture(texture);
	CloseWindow();

	return 0;
}

