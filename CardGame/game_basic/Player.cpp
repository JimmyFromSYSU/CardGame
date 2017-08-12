#include "Player.h"

Player::Player(int id, std::string name){
        this->id = id;
        this->name=name;
}

Player::Player() {
}


Player::~Player(){
}

std::string Player::getName() const {
        return this->name;
}

int Player::getID() const {
        return this->id;
}

void Player::addCard(Card * card) {
        this->cards.add(card);
}

void Player::addCards(CardGroup g) {
        this->cards.add(g);
}

void Player::eraseCard(Card * card) {
        this->cards.erase(card);
}

void Player::eraseCards(CardGroup g) {
        this->cards.erase(g);
}

bool Player::existCards(CardGroup g) const {
        return this->cards.exist(g);
}

bool Player::existCard(Card * card) const {
        return this->cards.exist(card);
}

void Player::printCards() const {
        this->cards.print();
}
