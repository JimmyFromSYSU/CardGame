#ifndef CARD_GAME_APP
#define CARD_GAME_APP

#include "CardGroup.h"
#include "Player.h"
#include "PlayerRing.h"
#include "Dealer.h"

#include <vector>

#include "EventQueue.h"

class CardGame {

protected:
CardGroup card_deck;
PlayerRing players;
Dealer * dealer;
EventQueue * q;

// addPlayer when setupPlayer
void addPlayer(Player*);
void addDealer(Dealer*);

public:
CardGame();
~CardGame();

// a game only init once, but could run serveral times.
virtual void init();
virtual void run()=0;

virtual CardGroup * getCardDeck();
virtual PlayerRing * getPlayers();



};

#endif /* end of include guard: CARD_GAME_APP */
