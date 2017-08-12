#ifndef CARD_GAME_PLAY_CARDS_ACTION
#define CARD_GAME_PLAY_CARDS_ACTION

#include <string>
#include "Player.h"
#include "CardGroup.h"
#include "Action.h"

// 一个玩家动作，包括玩家执行
class PlayCardsAction : public Action {
protected:
CardGroup cards;
public:
PlayCardsAction(CardGroup cards);
~PlayCardsAction();
virtual std::string getName();
CardGroup getCards();
virtual void playBy(Player* p) const;
// 反动作
virtual void inversePlayBy(Player* p) const;
};

#endif /* end of include guard: CARD_GAME_PLAY_CARDS_ACTION */
