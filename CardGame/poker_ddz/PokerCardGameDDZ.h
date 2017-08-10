#ifndef POKER_CARD_GAME_DDZ
#define POKER_CARD_GAME_DDZ

#include "PokerCardGame.h"
#include "CardGroup.h"
#include "PokerCard.h"
#include <map>

class PokerCardGameDDZ : public PokerCardGame {
protected:
CardGroup ddzCards;

public:
static std::map<PokerNumber,int> numberOrder;
static std::map<PokerType,int> typeOrder;
static bool DDZHandCardComparator(Card* &c1, Card* &c2);

PokerCardGameDDZ();
~PokerCardGameDDZ();

virtual void init();
virtual void run();

};

#endif /* end of include guard: POKER_CARD_GAME_DDZ */
