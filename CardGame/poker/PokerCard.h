#ifndef CARD_GAME_POKER_CARD
#define CARD_GAME_POKER_CARD

#include "Card.h"
#include <string>

// 扑克牌花色，RED为大王，BLACK为小王
enum PokerType {
        SPADE, HEART, CLUB, DIAMOND, RED, BLACK
};

// 扑克牌点数，大王为JOKER
enum PokerNumber {
        JOKER, A, _2, _3, _4, _5, _6, _7, _8, _9, _10, J, Q, K
};

// NO POINTER
class PokerCard : public Card {
protected:

// 用于在控制台输出扑克牌
static std::string PokerTypeToStr[6];
static std::string PokerNumberToStr[14];

PokerType type;
PokerNumber number;

public:

PokerCard(PokerType type, PokerNumber number);
~PokerCard();

PokerType getType() const;
PokerNumber getNumber() const;
virtual void print() const;
bool isRed() const;

};

#endif /* end of include guard: CARD_GAME_POKER_CARD */
