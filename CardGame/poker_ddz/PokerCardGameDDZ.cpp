#include "PokerCardGameDDZ.h"
#include "PokerCardGameDDZDealer.h"
#include "PokerCardGameDDZEventList.h"
#include "PokerCardGameDDZPlayer.h"

#include "PokerCard.h"
#include "Event.h"
#include "Player.h"
#include "EventTagList.h"
#include "DDZDecideDZRule.h"
#include <stdio.h>


PokerCardGameDDZ::PokerCardGameDDZ() {
        decideDZRule = NULL;
}

PokerCardGameDDZ::~PokerCardGameDDZ() {
        if(decideDZRule) delete decideDZRule;
}

bool PokerCardGameDDZ::init() {
        if(CardGame::init() == false) return false;

        PokerCardGameDDZDealer * dealer = new PokerCardGameDDZDealer();
        // this->addDealer(dealer);
        this->dealer = dealer;
        dealer->regist(this->q);

        PokerCardGameDDZPlayer* player = new PokerCardGameDDZPlayer(0, "yyh!");
        this->players.add(player);
        // this->addPlayer(player);
        player->regist(this->q);

        player = new PokerCardGameDDZPlayer(1, "yang");
        this->players.add(player);
        // this->addPlayer(player);
        player->regist(this->q);


        player = new PokerCardGameDDZPlayer(2, "zhi");
        this->players.add(player);
        // this->addPlayer(player);
        player->regist(this->q);

        this->decideDZRule = new DDZDecideDZRule(&this->players);
        this->decideDZRule->regist(this->q);
        return true;
}

void PokerCardGameDDZ::run() {
        Event * e = new Event(EVENT_GAME_INIT);
        e->addTag(EVENT_TAG_GAME_PROCESS);
        e->setData(this);
        this->q->push(e);
        this->q->run();
}
