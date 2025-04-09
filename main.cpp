#include <iostream>
#include <limits>

#include "Game.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"


int main() {
    std::cout << "Welcome to Connect Four!\n";

    int choice;
    bool playing = true;

    while (playing) {
        std::cout << "Do you want to play solo (1) or duo (2)? [Enter 1 or 2] : ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Please enter an integer !\n";
        } else if (choice != 1 && choice != 2) {
            std::cout << "Please enter 1 or 2\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            playing = false;
        }
    }

    if (choice == 1) {
        std::cout << "Enter your player's name : ";
        std::string playerName;
        std::cin >> playerName;
        HumanPlayer player1(playerName, 'O');
        std::cout << player1.getName() << ", you will be (O)\n";
        AIPlayer player2("Bot", 'X');
        Game game(player1, player2);
        game.play();

    } else {
        std::cout << "Enter the first player's name : ";
        std::string player1Name;
        std::cin >> player1Name;
        HumanPlayer player1(player1Name, 'O');
        std::cout << player1.getName() << ", you will be (O)\n";
        std::cout << "Enter the second player's name : ";
        std::string player2Name;
        std::cin >> player2Name;
        HumanPlayer player2(player2Name, 'X');
        std::cout << player2.getName() << ", you will be (X)\n";
        Game game(player1, player2);
        game.play();
    }

    return 0;
}
