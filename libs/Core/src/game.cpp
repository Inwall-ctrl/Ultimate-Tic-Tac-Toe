#include "Core/game.h"
#include "Core/board.h"
#include "Core/ultimateboard.h"
#include "iostream"
using namespace std;

Game::Game(){

};

void Game::switch_player(){
    if(current_state == PLAYER_X){
        current_player = PLAYER_O;
    }
    if(current_state == PLAYER_O){
        current_player = PLAYER_X;
    }
}

Player Game::get_current_player() {
    return current_player;
}

void Game::set_current_player(Player player) {
    current_player = player;
}


void Game::start_game(){
    global_winner = EMPTY; // изначально пустой
    current_state = PLAYER1; // он ходит первый
    next_mini_board = 0; // в зависимости от поставленного знака, значение будет меняться ->
    // -> служит для определения клетки в которой будет делать следующий код противник
}
void Game::move(){
        switch (current_state) {
            case START:
                cout << "Player 1 enter the number of main cell: ";
                cin >> next_mini_board;
                current_state = PLAYER1;
                break;

            case PLAYER1:
                int pos1;
                cout << "Player 1 enter the number of position: ";
                cin >> pos1;
                if(!ult_board.add_mark(pos1, next_mini_board,PLAYER_X)){
                    cout << "we haven't this cell of its full, try again";
                    current_state = PLAYER1;
                    break;
                }
                cout << "Successful delivered";
                current_state = PLAYER2;
                if(ult_board.check_ultimate_winner(PLAYER_X)){
                    current_state = END;
                }
                break;

            case PLAYER2:
                int pos2;
                cout << "Player 1 enter the number of position: ";
                cin >> pos2;
                if(!ult_board.add_mark(pos2, next_mini_board, PLAYER_O)){
                    cout << "we haven't this cell of its full";
                    current_state = PLAYER2;
                    break;
                }
                next_mini_board = pos2;
                cout << "Successful delivered";
                current_state = PLAYER1;
                if(ult_board.check_ultimate_winner(PLAYER_O)){
                    current_state = END;
                }
                break;

            case END:
                cout << "The game has ended." << endl; // dont forget to create end moment for current_state(END)
                break;
        }


//
//    while ((global_winner == EMPTY) & (!ult_board.is_ultimate_full())){
//        ult_board.display();
//        cout << current_state; // когда писал, вроде был смысл. потом вернулся, забыл зачем. нужно ли?
//        cout << "Please, Enter the number of cell, Mr " << current_player;
//        cin >> current_step;
//        if(ult_board.add_mark(current_step, next_mini_board, current_player)){
//            if(ult_board.check_ultimate_winner(current_player)){
//                global_winner = current_player;
//            }else{
//                switch_player();
//                next_mini_board = current_step; // переопределяем главную клетку в которой будет ходить противник
//            }
//        }else{
//            cout << "Impossible move < Try again" << endl;
//        }
//
//    }
//
//    ult_board.display();
//    if (global_winner != EMPTY) {
//        cout << "Player " << (global_winner == PLAYER_X ? "X" : "O") << " wins!" << endl;
//    } else {
//        cout << "It's a tie!" << endl;
//    }
//
//    Player winner = ult_board.check_ultimate_winner();
//    if (winner != EMPTY) {
//        cout << "Player " << (winner == PLAYER_X ? "1" : "2") << " won!" << endl;
//        current_state = END;
//    }
//}
}