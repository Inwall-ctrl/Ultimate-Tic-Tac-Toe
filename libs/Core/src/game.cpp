#include "Core/game.h"
#include "Core/board.h"
#include "Core/ultimateboard.h"
#include "iostream"
using namespace std;

Game::Game(){

};

void Game::switch_player(){
    if(current_player == PLAYER_X){
        current_player = PLAYER_O;
    }
    if(current_player == PLAYER_O){
        current_player = PLAYER_X;
    }
}

Player Game::get_current_player() {
    return current_player;
}

void Game::start_game(){
    global_winner = EMPTY; // изначально пустой
    current_player = PLAYER_X; // он ходит первый
    next_mini_board = 0; // в зависимости от поставленного знака, значение будет меняться ->
    // -> служит для определения клетки в которой будет делать следующий код противник

    while ((global_winner == EMPTY) & (!ult_board.is_ultimate_full())){
        ult_board.display();
        cout << current_state; // когда писал, вроде был смысл. потом вернулся, забыл зачем. нужно ли?
        cout << "Please, Enter the number of cell, Mr " << current_player;
        cin >> current_step;
        if(ult_board.add_mark(current_step, next_mini_board, current_player)){
            if(ult_board.check_ultimate_winner(current_player)){
                global_winner = current_player;
            }else{
                switch_player();
                next_mini_board = current_step; // переопределяем главную клетку в которой будет ходить противник
            }
        }else{
            cout << "Impossible move < Try again" << endl;
        }

    }

    ult_board.display();
    if (global_winner != EMPTY) {
        cout << "Player " << (global_winner == PLAYER_X ? "X" : "O") << " wins!" << endl;
    } else {
        cout << "It's a tie!" << endl;
    }
}