#include "PokerCardGameDDZ.h"
#include "PokerCardGameDDZDealer.h"
#include "PokerCardGameDDZEventName.h"

#include "PokerCard.h"
#include "Event.h"
#include "Player.h"
#include "EventTags.h"
#include <stdio.h>

std::map<PokerNumber,int> create_poker_number_map()
{
        std::map<PokerNumber,int> m;
        m[JOKER]  = 13;
        m[_2]     = 12;
        m[A]      = 11;
        m[K]      = 10;
        m[Q]      = 9;
        m[J]      = 8;
        m[_10]    = 7;
        m[_9]     = 6;
        m[_8]     = 5;
        m[_7]     = 4;
        m[_6]     = 3;
        m[_5]     = 2;
        m[_4]     = 1;
        m[_3]     = 0;
        return m;
}

std::map<PokerType,int> create_poker_type_map()
{
        std::map<PokerType,int> m;
        m[RED]      = 5;
        m[BLACK]    = 4;
        m[SPADE]    = 3;
        m[HEART]    = 2;
        m[CLUB]     = 1;
        m[DIAMOND]  = 0;
        return m;
}

std::map<PokerNumber,int> PokerCardGameDDZ::numberOrder = create_poker_number_map();

std::map<PokerType,int> PokerCardGameDDZ::typeOrder = create_poker_type_map();

// TODO: use const in the input parameter
bool PokerCardGameDDZ::DDZHandCardComparator(Card* & c1, Card* & c2)
{
        int n1 = numberOrder[((const PokerCard*)c1)->getNumber()];
        int n2 = numberOrder[((const PokerCard*)c2)->getNumber()];

        if (n1 == n2) {
                int t1 = typeOrder[((const PokerCard*)c1)->getType()];
                int t2 = typeOrder[((const PokerCard*)c2)->getType()];
                return t1 < t2;
        } else return n1 < n2;
}


PokerCardGameDDZ::PokerCardGameDDZ() {
}

PokerCardGameDDZ::~PokerCardGameDDZ() {
}

void sortCards(Player* p, void * data) {
        p->sortCards(PokerCardGameDDZ::DDZHandCardComparator);
}

void PokerCardGameDDZ::init() {
        CardGame::init();

        PokerCardGameDDZDealer * dealer = new PokerCardGameDDZDealer();
        this->addDealer(dealer);
        this->q->addListener(dealer);

        this->addPlayer(new Player(0, "Kevin"));
        this->addPlayer(new Player(1, "Bill"));
        this->addPlayer(new Player(2, "Zhi"));
}

void PokerCardGameDDZ::run() {
        Event * e = new Event(GAME_INIT);
        e->addTag(GAME_PROCESS);
        e->setData(this);
        this->q->push(e);
        this->q->run();
}
