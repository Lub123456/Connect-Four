#include "HumanPlayer.h"
#include <iostream>
#include <limits>


HumanPlayer::HumanPlayer(std::string name, char symbol) : Player(name, symbol) {}

int HumanPlayer::chooseColumn(const Board& board) const {
    int column;

    while (true) {
        std::cout << name << " (" << symbol << "), enter a column [1-7]: ";
        std::cin >> column;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Please enter an integer !\n";
        } else if (column < 1 || column > 7) {
            std::cout << "Please enter a valid column (from 1 to 7)\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return column - 1;
        }
    }
}
