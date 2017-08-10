#include "PokerCardUtils.h"
#include "PokerCard.h"

void add54CardsTo(CardGroup& g) {
        PokerType simple_type[4] = {
                SPADE, HEART, CLUB, DIAMOND
        };

        PokerNumber simple_number[13] = {
                A, _2, _3, _4,
                _5, _6, _7, _8,
                _9, _10, J, Q,
                K
        };

        // Add 52 Normal Cards
        for ( int t = 0; t < 4; t++) {
                for (int n = 0; n < 13; n++) {
                        PokerType type = simple_type[t];
                        PokerNumber number = simple_number[n];
                        g.add(new PokerCard(type, number));
                }
        }

        // Add 2 Jokers
        g.add(new PokerCard(RED, JOKER));
        g.add(new PokerCard(BLACK, JOKER));
}
