#ifndef CARD_GAME_CARDGROUP
#define CARD_GAME_CARDGROUP

#include <vector>
#include <algorithm>

#include "Card.h"

// CardGroup has an abstract set of cards.
// CardDeck has a concrete set of cards.
class CardGroup {
protected:
// cards可能有NULL元素，但是这些元素对外界不可见
// draw会跳过NULL，top和size也不把NULL计算在内
std::vector<Card*> cards;

// top只增不减
int top;
int _size;

// TODO: add and substract another CardGroup. +=, -=.
// TODO: reverse CardGroup
public:
CardGroup();
~CardGroup();
void add(Card * card);
void add(CardGroup g);

void erase(Card * card);
void erase(CardGroup g);

// 判断card是否在牌堆中，比较指针位置而不是牌型
// 如果card为NULL，返回false
bool exist(Card * card) const;

// 判断是否g中所有的卡牌都存在
bool exist(CardGroup g) const;

// 判断是否g中某张卡牌都存在
// bool existAny(CardGroup g);

int size() const;

template <typename Comparator>
void sort(const Comparator c) {
        std::sort(this->cards.begin() + top, cards.end(), c);
}
void shuffle();
void print() const;
void clear();
void deepClear();
Card * draw();
CardGroup draw(int n);
Card * first() const;
Card * last() const;
CardGroup first(int n) const;
CardGroup last(int n) const;
std::vector<const Card*> getVector() const;
};

#endif /* end of include guard: CARD_GAME_CARDGROUP */
