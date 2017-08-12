#ifndef CARD_GAME_POKER_CARD_GAME_DDZ_PLAYER
#define CARD_GAME_POKER_CARD_GAME_DDZ_PLAYER

#include "Player.h"
#include "EventQueueListener.h"

class PokerCardGameDDZPlayer : public Player,  public EventQueueListener {
protected:
Player * dz_player;
Player * curr_player;
public:
PokerCardGameDDZPlayer(int id, std::string name);
~PokerCardGameDDZPlayer();
virtual void process(Event* e, EventQueue* q);
virtual void regist(EventQueue * q);
};

#endif /* end of include guard: CARD_GAME_POKER_CARD_GAME_DDZ_PLAYER */
