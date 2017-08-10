#include "CardGroup.h"
#include <algorithm>

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

CardGroup::CardGroup() {
        top = 0;
}

CardGroup::~CardGroup() {

}

void CardGroup::shuffle() {
        srand(time(0));
        for (int i = 0; i < cards.size(); i++) {
                int r = i + rand() % (cards.size() - i); // careful here!
                std::swap(cards[i], cards[r]);
        }
}

void CardGroup::print() const {
        for (int i = top; i<cards.size(); i++) {
                if(cards[i] != NULL) cards[i]->print();
                else printf("NULL");
                printf(" ");
        }
}

void CardGroup::add(Card * card) {
        this->cards.push_back(card);
}

Card * CardGroup::draw() {
        if(top >= this->cards.size()) return NULL;
        else return this->cards[top++];
}

void CardGroup::clear() {
        this->cards.clear();
        top = 0;
}

void CardGroup::deepClear() {
        for (int i = 0; i<cards.size(); i++) {
                if(cards[i]) delete cards[i];
        }
        clear();
}
