#include "CardGame.h"

CardGame::CardGame() {
        q = NULL;
        dealer = NULL;
        isInit = false;
}

CardGame::~CardGame() {
        this->cards.deepClear();
        this->players.deepClear();
        if(q) delete q;
        if(dealer) delete dealer;
}

CardGroup * CardGame::getCardDeck() {
        return &(this->cards);
}

PlayerRing * CardGame::getPlayers() {
        return &(this->players);
}

bool CardGame::init(){
        if(isInit) return false;
        isInit = true;
        q = new EventQueue("main_queue");
        return true;
}

// void CardGame::addPlayer(Player* player) {
//         players.add(player);
// }

// void CardGame::addDealer(Dealer* d) {
//         if(this->dealer) delete this->dealer;
//         this->dealer = d;
// }
