#include "Game.h"
#include <iostream>

int main() {
    int choice;

    std::cout << "Select game mode:" << std::endl;
    std::cout << "1. Player vs Player" << std::endl;
    std::cout << "2. AI vs AI" << std::endl;
    std::cout << "3. Player vs AI" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    if (choice < 1 || choice > 3) {
        std::cout << "Invalid choice! Exiting." << std::endl;
        return 1;
    }

    Game game;
    game.set_mode(choice);
    game.start_game();
    return 0;
}
