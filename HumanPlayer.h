#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.h"


class HumanPlayer : public Player {
public:
    HumanPlayer(std::string name, char symbol);
    int chooseColumn(const Board& board) const override;
};


#endif

