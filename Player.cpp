#include "Player.h"
#include <iostream>


Player::Player(const std::string& name, char symbol) : name(name), symbol(symbol) {}

char Player::getSymbol() const {
    return symbol;
}

std::string Player::getName() const {
    return name;
}
