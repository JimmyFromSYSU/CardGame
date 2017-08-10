#ifndef CARD_GAME_PLAYER
#define CARD_GAME_PLAYER

#include "CardGroup.h"
#include <string>

class Player {
public:
Player(int id, std::string name);
~Player();

// void init();
// void clear();

void addCard(Card * card);
void printCards() const;

template <typename Comparator>
void sortCards(const Comparator c) {
        this->cards.sort(c);
}

std::string getName() const;
int getID() const;

protected:
// 玩家的所有手牌
CardGroup cards;
int id;
std::string name;

};

#endif /* end of include guard: CARD_GAME_PLAYER */
