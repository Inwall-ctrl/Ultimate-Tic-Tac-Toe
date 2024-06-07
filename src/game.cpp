#include "game.h"
#include "Core/board.h"

// Game constructor
Game::Game(){
    // Init assets
    textures["background"] = LoadTexture("../src/resource/background.png");
    textures["cross"] = LoadTexture("../src/resource/cross.png");
    textures["zero"] = LoadTexture("../src/resource/zero.png");

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
        }
        if (this->board.check_ultimate_winner(PLAYER_O)){
            title = "Player O win!";
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
}


