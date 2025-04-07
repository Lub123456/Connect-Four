#ifndef BOARD_H
#define BOARD_H

#include <vector>


class Board {
private:
    static const int ROWS = 6;
    static const int COLUMNS = 7;
    std::vector<std::vector<char>> grid;

public:
    Board();

    const std::vector<std::vector<char>>& getGrid() const;
    void display() const;
    bool dropPiece(int col, char symbol);
    bool checkWin(char symbol) const;
    bool isFull() const;
};

#endif // BOARD_H
