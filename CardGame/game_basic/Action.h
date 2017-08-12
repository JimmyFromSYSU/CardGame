#ifndef CARD_GAME_ACTION
#define CARD_GAME_ACTION

#include <string>
#include "Player.h"

// 一个玩家动作，包括玩家执行该动作所需要的所有数据
// action->playBy(p)，将会使玩家执行该动作。
// 每个动作都有反动作：允许玩家反悔
class Action {

public:
virtual void playBy(Player* p) const=0;
// 反动作
virtual void inversePlayBy(Player* p) const=0;
Action();
virtual ~Action();
};

#endif /* end of include guard: CARD_GAME_ACTION */
