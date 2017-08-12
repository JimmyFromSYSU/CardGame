#ifndef CARD_GAME_DECIDE_DZ_RULE
#define CARD_GAME_DECIDE_DZ_RULE

#include "GameRule.h"
#include "EventQueueListener.h"
#include "Player.h"
#include "PlayerRing.h"

class DDZDecideDZRule : public GameRule, public EventQueueListener {

protected:
PlayerRing * players;
Player * player1;
Player * player2;
Player * player3;

int curr_state;
Player * curr_player;

public:
DDZDecideDZRule(PlayerRing *);
~DDZDecideDZRule();
virtual void clear();
virtual void deal(EventQueue* q);
// virtual void build();

virtual void process(Event* e, EventQueue* q);
virtual void regist(EventQueue * q);
};

#endif /* end of include guard: CARD_GAME_DECIDE_DZ_RULE */
