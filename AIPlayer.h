#ifndef AIPLAYER_H
#define AIPLAYER_H

#include "Player.h"
#include "Board.h"


class AIPlayer : public Player {
public:
    AIPlayer(std::string name, char symbol);
    int chooseColumn(const Board& board) const override;
};


#endif