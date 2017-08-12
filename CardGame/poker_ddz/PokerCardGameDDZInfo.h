#ifndef CARD_GAME_POKER_CARD_GAME_DDZ_INFO
#define CARD_GAME_POKER_CARD_GAME_DDZ_INFO

#include "HistoricalStack.h"
#include "Player.h"
#include "CardGroup.h"
#include <set>

struct PlayCardInfo {
        Player * player;
        CardGroup cards;
};

#endif /* end of include guard: CARD_GAME_POKER_CARD_GAME_DDZ_INFO */
