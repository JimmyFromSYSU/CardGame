#ifndef CARD_GAME_PLAYER
#define CARD_GAME_PLAYER

#include "CardGroup.h"
#include <string>

class Player {

public:
Player(int id, std::string name);
Player();
virtual ~Player();

// void init();
// void clear();

void addCard(Card * card);
void addCards(CardGroup g);
void eraseCard(Card * card);
void eraseCards(CardGroup g);

void printCards() const;

template <typename Comparator>
void sortCards(const Comparator c) {
        this->cards.sort(c);
}

std::string getName() const;
int getID() const;

bool existCards(CardGroup g) const;
bool existCard(Card * card) const;

protected:
// 玩家的所有手牌
CardGroup cards;
int id;
std::string name;

};

#endif /* end of include guard: CARD_GAME_PLAYER */
