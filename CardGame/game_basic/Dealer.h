#ifndef CARD_GAME_DEALER
#define CARD_GAME_DEALER

#include "PlayerRing.h"
#include "CardGroup.h"
#include "EventQueueListener.h"

// who knows the process of the game
class Dealer {
protected:
CardGroup cards;
PlayerRing players;

public:
Dealer();
virtual ~Dealer();
virtual void setup(CardGroup& card_deck, bool showInfo=true) = 0;
virtual CardGroup shuffle(const CardGroup& card_deck, bool showInfo=true);
virtual void deal(CardGroup& g, PlayerRing& players, bool showInfo=true);
};

#endif /* end of include guard: CARD_GAME_DEALER */
