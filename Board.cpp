#include "Board.h"
#include <iostream>


Board::Board() : grid(ROWS, std::vector<char>(COLUMNS, ' ')) {}


const std::vector<std::vector<char>>& Board::getGrid() const {
    return grid;
}

void Board::display() const {
    std::cout << "\n| 1 | 2 | 3 | 4 | 5 | 6 | 7 |\n";
    std::cout << "-----------------------------\n";
    for (const auto& row : grid) {
        for (char cell : row) {
            std::cout << "| " << cell << " ";
        }
        std::cout << "|\n";
    }
    std::cout << "-----------------------------\n";
}

bool Board::dropPiece(int col, char symbol) {
    if (col < 0 || col >= COLUMNS || grid[0][col] != ' ')
        //std::cout << "Please enter a valid column (from 1 to 7)\n";
        return false;

    for (int row = ROWS - 1; row >= 0; --row) {
        if (grid[row][col] == ' ') {
            grid[row][col] = symbol;
            return true;
        }
    }
    return false;
}

bool Board::isFull() const {
    for (const auto& cell : grid[0]) {
        if (cell == ' ') return false;
    }
    return true;
}

bool Board::checkWin(char symbol) const {
    // horizontal check
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLUMNS-3; ++col) {
            int count = 0;

            for (int i = 0; i < 4; ++i) {
                if (grid[row][col + i] == symbol) {
                    count += 1;
                } else {
                    break;
                }
            }

            if (count == 4) return true;
        }
    }

    // vertical ckeck
    for (int col = 0; col < COLUMNS; ++col) {
        for (int row = 0; row < ROWS-3; ++row) {
            int count = 0;

            for (int i = 0; i < 4; ++i) {
                if (grid[row + i][col] == symbol) {
                    count += 1;
                } else {
                    break;
                }
            }

            if (count == 4) return true;
        }
    }

    // first diagonal check
    for (int row = 0; row < ROWS-3; ++row) {
        for (int col = 0; col < COLUMNS-3; ++col) {
            int count = 0;

            for (int i = 0; i < 4; ++i) {
                if (grid[row + i][col + i] == symbol) {
                    count += 1;
                } else {
                    break;
                }
            }

            if (count == 4) return true;
        }
    }

    // second diagonal check
    for (int row = 3; row < ROWS; ++row) {
        for (int col = 0; col < COLUMNS-3; ++col) {
            int count = 0;

            for (int i = 0; i < 4; ++i) {
                if (grid[row - i][col + i] == symbol) {
                    count += 1;
                } else {
                    break;
                }
            }

            if (count == 4) return true;
        }
    }

    return false;
}
