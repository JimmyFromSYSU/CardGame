#ifndef CARD_GAME_APP
#define CARD_GAME_APP

#include "CardGroup.h"
#include "Player.h"
#include "PlayerRing.h"
#include "Dealer.h"

#include <vector>

#include "EventQueue.h"

// 负责组装游戏，选择什么dealer，什么player，什么rule，什么state
class CardGame {

protected:
CardGroup cards;
PlayerRing players;
Dealer * dealer;
EventQueue * q;
bool isInit;

// addPlayer when setupPlayer
// void addPlayer(Player*);
// void addDealer(Dealer*);

public:
CardGame();
~CardGame();

// a game only init once, but could run serveral times.
virtual bool init();
virtual void run()=0;

virtual CardGroup * getCardDeck();
virtual PlayerRing * getPlayers();



};

#endif /* end of include guard: CARD_GAME_APP */
