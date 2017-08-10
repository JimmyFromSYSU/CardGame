#ifndef CARD_GAME_POKER_CARD_GAME_DDZ_DEALER
#define CARD_GAME_POKER_CARD_GAME_DDZ_DEALER

#include "Dealer.h"
#include "CardGroup.h"
#include "PokerCardGameDDZInfo.h"

class PokerCardGameDDZDealer : public Dealer,  public EventQueueListener {
protected:
CardGroup ddzCards;
DZInfo dzInfo;

public:
virtual void setup(CardGroup& card_deck, bool showInfo=true);
virtual void deal(CardGroup g, PlayerRing& players, bool showInfo=true);
virtual void process(Event* e, EventQueue* q);
};

#endif /* end of include guard: CARD_GAME_POKER_CARD_GAME_DDZ_DEALER */
