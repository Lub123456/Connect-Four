#include "AIPlayer.h"
#include <iostream>
#include <cstdlib>
#include <ctime>


AIPlayer::AIPlayer(std::string name, char symbol) : Player(name, symbol) {
    std::srand(std::time(nullptr));  // Initialization of random generator
}

int AIPlayer::chooseColumn(const Board& board) const {

    const auto& grid = board.getGrid();
    std::vector<int> validColumns;

    for (int col = 0; col < 7; ++col) {
        if (grid[0][col] == ' ') {
            validColumns.push_back(col);
        }
    }

    int column = validColumns[std::rand() % validColumns.size()];
    std::cout << name << " (" << symbol << ") chooses column " << column + 1 << std::endl;
    return column;
}
