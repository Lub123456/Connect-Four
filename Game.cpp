#include "Game.h"
#include <iostream>


Game::Game(Player& p1, Player& p2) : player1(p1), player2(p2), isPlayerOneTurn(true) {}

void Game::switchPlayer() {
    isPlayerOneTurn = !isPlayerOneTurn;
}

Player& Game::getCurrentPlayer() {
    return isPlayerOneTurn ? player1 : player2;
}

void Game::play() {
    while (!board.isFull()) {
        board.display();
        int col;

        do {
            col = getCurrentPlayer().chooseColumn(board);
        } while (!board.dropPiece(col, getCurrentPlayer().getSymbol()));

        if (board.checkWin(getCurrentPlayer().getSymbol())) {
            board.display();
            std::cout << "\n" << getCurrentPlayer().getName() << " (" << getCurrentPlayer().getSymbol() << ") wins!" << std::endl;
            return;
        }

        switchPlayer();
    }

    std::cout << "It's a draw!" << std::endl;
}
