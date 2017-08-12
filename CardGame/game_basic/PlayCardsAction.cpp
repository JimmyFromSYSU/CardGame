#include "PlayCardsAction.h"

PlayCardsAction::PlayCardsAction(CardGroup cards) {
        this->cards = cards;
}

PlayCardsAction::~PlayCardsAction() {
}

std::string PlayCardsAction::getName() {
        return "PlayCardsAction";
}


void PlayCardsAction::playBy(Player* p) const {
        p->eraseCards(this->cards);
        printf("PlayCardsAction: %s play ", p->getName().c_str());
        this->cards.print();
        puts("");
}

void PlayCardsAction::inversePlayBy(Player* p) const {
        p->addCards(this->cards);
        printf("PlayCardsAction: %s withdraw ", p->getName().c_str());
        this->cards.print();
        puts("");
}

CardGroup PlayCardsAction::getCards() {
        return cards;
}
