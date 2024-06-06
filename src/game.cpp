#include "game.h"
#include "Core/board.h"

Game::Game(){
    // Init assets
    textures["background"] = LoadTexture("../src/resource/background.png");
    textures["cross"] = LoadTexture("../src/resource/cross.png");
    textures["zero"] = LoadTexture("../src/resource/zero.png");

    // Init Field
    board_gui = init_field();

    // Init states
    State Start;
    Start.enter = [this]() {
        title = "Start";
        this->current_block = -1;
    };
    Start.update = [this]() {
        this->state.change("PlayerXMove");
    };
    Start.exit = []() {};

    State PlayerXMove;
    PlayerXMove.enter = [this]() {
        title = "X Move";
    };

    // Player X move
    PlayerXMove.update = [this]() {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            for (auto& button : board_gui) {
                if (button.IsClicked()){
                    int mini = (button.Id - 1) % 9 + 1;
                    int cell = (button.Id - 1) / 9 + 1;

                    if(current_block != cell && current_block != -1){
                        this->state.change("PlayerXMove");
                        return;
                    }

                    if(board.add_mark(mini, cell, PLAYER_X) && board.check_ultimate_winner(EMPTY)){
                        current_block = mini;

                        button.SetImage(textures["cross"]);
                        this->state.change("PlayerOMove");
                        return;
                    }
                }
            }

            if(board.is_ultimate_full() || !board.check_ultimate_winner(EMPTY)){
                this->state.change("End");
            }
        }
    };
    PlayerXMove.exit = []() {};

    // Player O move
    State PlayerOMove;
    PlayerOMove.enter = [this]() {
        title = "O Move";
    };
    PlayerOMove.update = [this]() {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            for (auto& button : board_gui) {
                if (button.IsClicked()){
                    int mini = (button.Id - 1) % 9 + 1;
                    int cell = (button.Id - 1) / 9 + 1;

                    if(current_block != cell && current_block != -1){
                        this->state.change("PlayerOMove");
                        return;
                    }

                    if(board.add_mark(mini, cell, PLAYER_O) && board.check_ultimate_winner(EMPTY)){
                        current_block = mini;

                        button.SetImage(textures["zero"]);
                        this->state.change("PlayerXMove");
                        return;
                    }
                }
            }

            if(board.is_ultimate_full() || !board.check_ultimate_winner(EMPTY)){
                this->state.change("End");
            }
        }
    };
    PlayerOMove.exit = []() {};

    State End;
    End.enter = [this]() {
        title = "END";
    };
    End.update = []() {};
    End.exit = []() {};

    state.register_state("Start", Start);
    state.register_state("PlayerXMove", PlayerXMove);
    state.register_state("PlayerOMove", PlayerOMove);
    state.register_state("End", End);

    state.change("Start");
}

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

void Game::Update(){
    int start = (current_block - 1) * 9 + 1;
    int end = start + 8;

    // Update all buttons
    for (auto &button: board_gui) {
        if(current_block != -1){
            button.SetActive(false);
            for (int i = start; i <= end; i++) {
                if (button.Id == i) {
                    button.SetActive(true);
                }
            }
        }

        button.Update();
    }

    state.update();
}

void Game::Draw(){
    // Draw background
    DrawTexture(textures["background"], 0, 0, WHITE);
    // Draw title
    DrawText(title, 10, 10, 20, WHITE);
    // Draw all buttons
    for (auto& button : board_gui) {
        button.Draw();
    }
}


