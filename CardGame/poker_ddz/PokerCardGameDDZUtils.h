#ifndef CARD_GAME_POKER_CARD_GAME_DDZ_UTILS
#define CARD_GAME_POKER_CARD_GAME_DDZ_UTILS
#include "EventQueue.h"
#include "Player.h"

bool handCardComparator(Card* & c1, Card* & c2);
void sortCards(Player* p, void * data=0);
void gameOver(EventQueue * q);

#endif /* end of include guard: CARD_GAME_POKER_CARD_GAME_DDZ_UTILS */
