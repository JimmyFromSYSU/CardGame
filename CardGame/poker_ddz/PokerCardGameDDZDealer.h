#ifndef CARD_GAME_POKER_CARD_GAME_DDZ_DEALER
#define CARD_GAME_POKER_CARD_GAME_DDZ_DEALER

#include "Dealer.h"
#include "CardGroup.h"
#include "PokerCardGameDDZInfo.h"
#include "HistoricalStack.h"

class PokerCardGameDDZDealer : public Dealer,  public EventQueueListener {
protected:
//轮询叫地主时的信息
AskDZInfo ask_dz_info;

// 公布地主时的信息
DZInfo dz_info;

// 轮询出牌时的信息
PlayCardInfo play_card_info;

void askToPlay(Player * p, EventQueue * q);
void claimDZ(EventQueue * q);
void setDZ(Player * p, EventQueue * q);

public:
virtual void setup(CardGroup& card_deck, bool showInfo=true);
virtual void deal(CardGroup g, PlayerRing& players, bool showInfo=true);
virtual void process(Event* e, EventQueue* q);
virtual void regist(EventQueue * q);
};

#endif /* end of include guard: CARD_GAME_POKER_CARD_GAME_DDZ_DEALER */
