#ifndef CARD_GAME_POKER_CARD_GAME_DDZ_INFO
#define CARD_GAME_POKER_CARD_GAME_DDZ_INFO

#include "HistoricalStack.h"
#include "Player.h"
#include "CardGroup.h"
#include <set>

struct AskDZInfo {
        Player * curr_player;
        // true: curr_player抢地主
        bool curr_ans;
        // 询问地主的次数
        int ask_time;
        // 抢过地主的玩家
        std::set<Player*> dz_players;
        // 放弃抢地主的玩家
        std::set<Player*> no_dz_players;
};

struct DZInfo {
        Player * player;
        // 地主三张牌
        CardGroup cards;
};

struct PlayCardInfo {
        Player * curr_player;
        //CardGroup curr_cards;
        HistoricalStack * stack;
};

#endif /* end of include guard: CARD_GAME_POKER_CARD_GAME_DDZ_INFO */
