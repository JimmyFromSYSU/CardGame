#ifndef POKER_CARD_GAME_DDZ
#define POKER_CARD_GAME_DDZ

#include "PokerCardGame.h"
#include "CardGroup.h"
#include "PokerCard.h"
#include "DDZDecideDZRule.h"
#include <map>

class PokerCardGameDDZ : public PokerCardGame {
protected:
CardGroup ddzCards;
DDZDecideDZRule * decideDZRule;

public:
PokerCardGameDDZ();
~PokerCardGameDDZ();

virtual bool init();
virtual void run();

};

#endif /* end of include guard: POKER_CARD_GAME_DDZ */
