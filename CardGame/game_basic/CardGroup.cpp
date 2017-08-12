#include "CardGroup.h"
#include <algorithm>

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

CardGroup::CardGroup() {
        top = 0;
        _size = 0;
}

CardGroup::~CardGroup() {

}

int CardGroup::size() const {
        return _size;
}

void CardGroup::shuffle() {
        srand(time(0));
        for (int i = top; i < cards.size(); i++) {
                int r = i + rand() % (cards.size() - i); // careful here!
                std::swap(cards[i], cards[r]);
        }
}

void CardGroup::print() const {
        for (int i = top; i<cards.size(); i++) {
                if(cards[i] != NULL) cards[i]->print();
                printf(" ");
        }
}

void CardGroup::add(Card * card) {
        if(card) {
                this->cards.push_back(card);
                _size++;
        }
}

void CardGroup::add(CardGroup g) {
        Card * c = g.draw();
        while(c) {
                this->add(c);
                c = g.draw();
        }
}

void CardGroup::erase(Card * card) {
        if(card == NULL) return;
        for (int i = 0; i< this->cards.size(); i++) {
                if(card == cards[i]) {
                        cards[i] = NULL;
                        _size--;
                        return;
                }

        }
}

void CardGroup::erase(CardGroup g) {
        Card * c = g.draw();
        while(c) {
                this->erase(c);
                c = g.draw();
        }
}

bool CardGroup::exist(Card * card) const {
        if(card == NULL) return false;
        for (int i = 0; i< this->cards.size(); i++) {
                if(card == cards[i]) {
                        return true;
                }

        }
        return false;
}

bool CardGroup::exist(CardGroup g) const {
        Card * c = g.draw();
        while(c) {
                if(this->exist(c) == false) return false;
                c = g.draw();
        }
        return true;
}

Card * CardGroup::draw() {
        if(top >= this->cards.size()) return NULL;
        while(this->cards[top] == NULL) {
                top++;
                if(top >= this->cards.size()) return NULL;
        }
        _size--;
        return this->cards[top++];
}

CardGroup CardGroup::draw(int n) {
        CardGroup g;
        for(int i = 0; i<n; i++) {
                g.add(this->draw());
        }
        return g;
}

Card * CardGroup::first() const {
        if(top >= this->cards.size()) return NULL;
        int pos = top;
        while(this->cards[pos] == NULL) {
                pos++;
                if(pos >= this->cards.size()) return NULL;
        }
        return this->cards[pos];
}

Card * CardGroup::last() const {
        int pos = this->cards.size();
        if(top >= pos || pos < 0) return NULL;

        while(this->cards[pos] == NULL) {
                pos--;
                if(top >= pos || pos < 0) return NULL;
        }
        return this->cards[pos];
}

CardGroup CardGroup::first(int n) const {
        CardGroup g;
        if(top >= this->cards.size() || n <=0) return g;
        int pos = top;
        while(n--) {
                while(this->cards[pos] == NULL) {
                        pos++;
                        if(pos >= this->cards.size()) return g;
                }
                g.add(this->cards[pos]);
        }
        return g;
}

CardGroup CardGroup::last(int n) const {
        CardGroup g;
        int pos = this->cards.size();
        if(top >= pos || pos < 0 || n <=0) return g;
        while(n--) {
                while(this->cards[pos] == NULL) {
                        pos--;
                        if(top >= pos || pos < 0) return g;
                }
                g.add(this->cards[pos]);
        }
        return g;
}

void CardGroup::clear() {
        this->cards.clear();
        top = 0;
        _size=0;
}

void CardGroup::deepClear() {
        for (int i = 0; i<cards.size(); i++) {
                if(cards[i]) delete cards[i];
        }
        clear();
}
