#include "PokerCardGameDDZ.h"
#include "PokerCardGameDDZDealer.h"
#include "PokerCardGameDDZEventList.h"
#include "PokerCardGameDDZPlayer.h"

#include "PokerCard.h"
#include "Event.h"
#include "Player.h"
#include "EventTagList.h"
#include <stdio.h>


PokerCardGameDDZ::PokerCardGameDDZ() {
}

PokerCardGameDDZ::~PokerCardGameDDZ() {
}

void PokerCardGameDDZ::init() {
        CardGame::init();

        PokerCardGameDDZDealer * dealer = new PokerCardGameDDZDealer();
        this->addDealer(dealer);
        dealer->regist(this->q);

        PokerCardGameDDZPlayer* player = new PokerCardGameDDZPlayer(0, "yyh!");
        this->addPlayer(player);
        player->regist(this->q);

        player = new PokerCardGameDDZPlayer(1, "yang");
        this->addPlayer(player);
        player->regist(this->q);


        player = new PokerCardGameDDZPlayer(2, "zhi");
        this->addPlayer(player);
        player->regist(this->q);
}

void PokerCardGameDDZ::run() {
        Event * e = new Event(EVENT_GAME_INIT);
        e->addTag(EVENT_TAG_GAME_PROCESS);
        e->setData(this);
        this->q->push(e);
        this->q->run();
}
