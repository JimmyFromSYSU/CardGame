#ifndef CARD_GAME_HISTORICAL_STACK
#define CARD_GAME_HISTORICAL_STACK

#include <vector>
#include "Player.h"
#include "Action.h"
#include "EventQueueListener.h"

struct PlayerAction {
        Player * player;
        Action * action;
        PlayerAction(Player * p, Action * a) {
                this->player = p;
                this->action = a;
        }
};

class HistoricalStack : public EventQueueListener {
protected:
std::vector <PlayerAction> stack;
Player * curr_player;
Action * curr_action;
void clear();

public:

HistoricalStack();
~HistoricalStack();
void deepClear();

void push(Player *, Action *);
void pop();
Player * topPlayer() const;
Action * topAction() const;

virtual void process(Event* e, EventQueue* q);
virtual void regist(EventQueue * q);
};

#endif /* end of include guard: CARD_GAME_HISTORICAL_STACK */
