#include "game.h"
#include "Core/board.h"
#include "saver.h"

// Game constructor
Game::Game(){
    // Init assets
    textures["background"] = LoadTexture("../src/resource/background.png");
    textures["cross"] = LoadTexture("../src/resource/cross.png");
    textures["zero"] = LoadTexture("../src/resource/zero.png");
    textures["ttt"] = LoadTexture("../src/resource/ttt.png");
    textures["x_win"] = LoadTexture("../src/resource/x_win.png");
    textures["o_win"] = LoadTexture("../src/resource/o_win.png");
    textures["o_win"] = LoadTexture("../src/resource/o_win.png");
    textures["white-"] = LoadTexture("../src/resource/white-.png");
    textures["white_wert"] = LoadTexture("../src/resource/white_wert.png");
    textures["w_table"] = LoadTexture("../src/resource/w_table.png");
    textures["o_white"] = LoadTexture("../src/resource/o_white.png");
    textures["x_white"] = LoadTexture("../src/resource/x_white.png");



    InitAudioDevice();

    sounds["tron"] = LoadMusicStream("../src/resource/tron.ogg");
    SetMusicVolume(sounds["tron"], 0.5f);

    // Start playing music
    PlayMusicStream(sounds["tron"]);

    // Init Field
    board_gui = init_field();

    // Init states

    // Function to make player move
    std::function<void()> move = [this](){
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            for (auto& button : board_gui) {
                if (button.IsClicked()){
                    int mini = (button.Id - 1) % 9 + 1;
                    int cell = (button.Id - 1) / 9 + 1;

                    if(current_block != cell && current_block != -1){
                        state.change(current_player == PLAYER_X ? "PlayerXMove" : "PlayerOMove");
                        return;
                    }

                    if(board.add_mark(cell, mini, current_player)){
                        current_block = mini;
                        button.SetImage(current_player == PLAYER_X ? textures["cross"] : textures["zero"]);
                        state.change(current_player == PLAYER_X ? "PlayerOMove" : "PlayerXMove");
                        return;
                    }
                }
            }
        }

        if(this->board.check_ultimate_winner(PLAYER_X) || this->board.check_ultimate_winner(PLAYER_O)){
            state.change("End");
        }
    };

    // Function to make active buttons for next move
    std::function<void()> setButtons = [this](){
        if(this->board.check_cell_winner(current_block) != EMPTY) {
            current_block = -1;
        }

        for (auto &button: board_gui) {
            if(current_block != -1){
                int start = (current_block - 1) * 9 + 1;
                int end = start + 8;

                button.SetActive(false);
                for (int i = start; i <= end; i++) {
                    if (button.Id == i) {
                        button.SetActive(true);
                    }
                }
            } else {
                button.SetActive(true);
            }
        }
    };

    // Start state
    State Start;
    Start.enter = [this]() {
        title = "Start";
        this->current_block = -1;
    };
    Start.update = [this]() {
        this->state.change("PlayerXMove");
    };
    Start.exit = []() {};

    // Player X move
    State PlayerXMove;
    PlayerXMove.enter = [this](){
        title = "X Move";
        this->current_player = PLAYER_X;
    };
    PlayerXMove.update = move;
    PlayerXMove.exit = setButtons;

    // Player O move
    State PlayerOMove;
    PlayerOMove.enter = [this]() {
        title = "O Move";
        this->current_player = PLAYER_O;
    };
    PlayerOMove.update = move;
    PlayerOMove.exit = setButtons;

    // End state
    State End;

    End.enter = [this]() {
        if(this->board.check_ultimate_winner(PLAYER_X)){
            title = "Player X win!";
            saver.add_result(PLAYER_X);
        }
        if (this->board.check_ultimate_winner(PLAYER_O)){
            title = "Player O win!";
            saver.add_result(PLAYER_O);
        }
    };

    End.update = []() {};
    End.exit = []() {};

    state.register_state("Start", Start);
    state.register_state("PlayerXMove", PlayerXMove);
    state.register_state("PlayerOMove", PlayerOMove);
    state.register_state("End", End);

    state.change("Start");
}

// init_field inits field of buttons
vector<Button> Game::init_field() {
    std::vector<Button> buttons;

    int blockSize = 3;
    int buttonWidth = 45;
    int buttonHeight = 50;
    int startX = 220;
    int startY = 150;
    int gapBetweenBlocks = 20;

    int id = 0;
    for (int blockY = 0; blockY < blockSize; blockY++) {
        for (int blockX = 0; blockX < blockSize; blockX++) {
            for (int buttonY = 0; buttonY < blockSize; buttonY++) {
                for (int buttonX = 0; buttonX < blockSize; buttonX++) {
                    id++;
                    int posX = startX + (buttonX * buttonWidth) + (blockX * (blockSize * buttonWidth + gapBetweenBlocks));
                    int posY = startY + (buttonY * buttonHeight) + (blockY * (blockSize * buttonHeight + gapBetweenBlocks));

                    buttons.push_back(Button({
                                                     static_cast<float>(posX),
                                                     static_cast<float>(posY),
                                                     static_cast<float>(buttonWidth),
                                                     static_cast<float>(buttonHeight)
                    }, id));
                }
            }
        }
    }

    return buttons;
}

// Update updates all objects
void Game::Update(){
    // Update all buttons
    for (auto &button: board_gui) {
        button.Update();
    }

    state.update();

    UpdateMusicStream(sounds["tron"]);


}

// Draw draws all objects
void Game::Draw(){
    // Draw background
    DrawTexture(textures["background"], 0, 0, WHITE);
    // Draw title
    DrawText(title, 10, 10, 20, WHITE);
    // Draw all buttons
    for (auto& button : board_gui) {
        button.Draw();
    }
    DrawTexture(textures["ttt"], 150, 10, WHITE);

    //row horizontal
    for (int i = 1; i <= 2; ++i) {
        int col = (i - 1) / 3;
        int row = (i - 1) % 3;
    }
    // row horizontal
    DrawTexture(textures["white-"], 220, 200, WHITE);
    DrawTexture(textures["white-"], 375, 200, WHITE);
    DrawTexture(textures["white-"], 530, 200, WHITE);
    DrawTexture(textures["white-"], 220, 250, WHITE);
    DrawTexture(textures["white-"], 375, 250, WHITE);
    DrawTexture(textures["white-"], 530, 250, WHITE);

    DrawTexture(textures["white-"], 220, 370, WHITE);
    DrawTexture(textures["white-"], 375, 370, WHITE);
    DrawTexture(textures["white-"], 530, 370, WHITE);
    DrawTexture(textures["white-"], 220, 420, WHITE);
    DrawTexture(textures["white-"], 375, 420, WHITE);
    DrawTexture(textures["white-"], 530, 420, WHITE);

    DrawTexture(textures["white-"], 220, 540, WHITE);
    DrawTexture(textures["white-"], 375, 540, WHITE);
    DrawTexture(textures["white-"], 530, 540, WHITE);
    DrawTexture(textures["white-"], 220, 590, WHITE);
    DrawTexture(textures["white-"], 375, 590, WHITE);
    DrawTexture(textures["white-"], 530, 590, WHITE);

    //wert line
    DrawTexture(textures["white_wert"], 264, 150, WHITE);
    DrawTexture(textures["white_wert"], 309, 150, WHITE);
    DrawTexture(textures["white_wert"], 419, 150, WHITE);
    DrawTexture(textures["white_wert"], 464, 150, WHITE);
    DrawTexture(textures["white_wert"], 574, 150, WHITE);
    DrawTexture(textures["white_wert"], 619, 150, WHITE);

    DrawTexture(textures["white_wert"], 264, 320, WHITE);
    DrawTexture(textures["white_wert"], 309, 320, WHITE);
    DrawTexture(textures["white_wert"], 419, 320, WHITE);
    DrawTexture(textures["white_wert"], 464, 320, WHITE);
    DrawTexture(textures["white_wert"], 574, 320, WHITE);
    DrawTexture(textures["white_wert"], 619, 320, WHITE);

    DrawTexture(textures["white_wert"], 264, 490, WHITE);
    DrawTexture(textures["white_wert"], 309, 490, WHITE);
    DrawTexture(textures["white_wert"], 419, 490, WHITE);
    DrawTexture(textures["white_wert"], 464, 490, WHITE);
    DrawTexture(textures["white_wert"], 574, 490, WHITE);
    DrawTexture(textures["white_wert"], 619, 490, WHITE);



    DrawTexture(textures["w_table"], 30, 670, WHITE);
    //cell1 = 30 705
    //cell2 = 97 705
    //cell3 = 166 705
//    DrawTexture(textures["o_white"], 30, 705, WHITE);
//    DrawTexture(textures["o_white"], 97, 705, WHITE);
//    DrawTexture(textures["o_white"], 166, 705, WHITE);
    if(saver.get_results()[0] == PLAYER_X){
        DrawTexture(textures["x_white"], 30, 705, WHITE);
    }
    if(saver.get_results()[0] == PLAYER_O){
        DrawTexture(textures["o_white"], 30, 705, WHITE);
    }






    for (int i = 1; i <= 9; ++i) {
        int col = (i - 1) / 3;
        int row = (i - 1) % 3;
        if(board.check_cell_winner(i) == PLAYER_X){
            DrawTexture(textures["x_win"], 220+(row*155), 150+(col*170), WHITE);
        }
        if(board.check_cell_winner(i) == PLAYER_O){
            DrawTexture(textures["o_win"], 220+(row*155), 150+(col*170), WHITE);
        }
    }








}


