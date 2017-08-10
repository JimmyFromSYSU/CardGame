#include "CardGame.h"

CardGame::CardGame() {
        q = NULL;
        dealer = NULL;
}

CardGame::~CardGame() {
        this->card_deck.deepClear();
        this->players.deepClear();
        if(q) delete q;
        if(dealer) delete dealer;
}

CardGroup * CardGame::getCardDeck() {
        return &(this->card_deck);
}

PlayerRing * CardGame::getPlayers() {
        return &(this->players);
}

void CardGame::init(){
        q = new EventQueue("main_queue");
}

void CardGame::run() {
}


void CardGame::addPlayer(Player* player) {
        players.add(player);
}

void CardGame::addDealer(Dealer* d) {
        if(this->dealer) this->dealer = NULL;
        this->dealer = d;
}
