#include "Player.h"

Player::Player(int id, std::string name){
        this->id = id;
        this->name=name;
}

std::string Player::getName() const {
        return this->name;
}

int Player::getID() const {
        return this->id;
}

Player::~Player(){
}

void Player::addCard(Card * card) {
        this->cards.add(card);
}

void Player::printCards() const {
        this->cards.print();
}
