#ifndef CARD_GAME_CARDGROUP
#define CARD_GAME_CARDGROUP

#include <vector>
#include <algorithm>

#include "Card.h"

// CardGroup has an abstract set of cards.
// CardDeck has a concrete set of cards.
class CardGroup {
protected:
std::vector<Card*> cards;
int top;
public:
CardGroup();
~CardGroup();
void add(Card * card);
template <typename Comparator>
void sort(const Comparator c) {
        std::sort(this->cards.begin() + top, cards.end(), c);
}
void shuffle();
void print() const;
void clear();
void deepClear();
Card * draw();
};

#endif /* end of include guard: CARD_GAME_CARDGROUP */
