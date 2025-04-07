#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Player.h"


class Game {
private:
    Board board;
    Player& player1;
    Player& player2;
    bool isPlayerOneTurn;

public:
    Game(Player& p1, Player& p2);
    void switchPlayer();
    Player& getCurrentPlayer();
    void play();
};

#endif