#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Board.h"


class Player {
protected:
    std::string name;
    char symbol;

public:
    Player(const std::string& name, char symbol);

    char getSymbol() const;
    std::string getName() const;

    virtual int chooseColumn(const Board& board) const = 0;
};

#endif
