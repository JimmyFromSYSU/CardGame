#include "PokerCardGameDDZDealer.h"
#include "PokerCardUtils.h"
#include "CardGame.h"
#include "EventTags.h"
#include <stdio.h>
#include "PokerCardGameDDZEventName.h"

void PokerCardGameDDZDealer::setup(CardGroup& card_deck, bool showInfo) {
        if(showInfo) puts("Set up card deck");
        add54CardsTo(card_deck);
        if(showInfo) card_deck.print();
        if(showInfo) puts("");
}

void PokerCardGameDDZDealer::deal(CardGroup g, PlayerRing& players, bool showInfo) {
        if(showInfo) puts("Deal cards");
        if(showInfo) printf("地主牌：");
        // 准备地主牌
        for( int i =0; i<3; i++) {
                Card* curr_card = g.draw();
                ddzCards.add(curr_card);
                if(showInfo) {
                        curr_card->print(); printf(" ");
                }
        }

        if(showInfo) puts("");
        Dealer::deal(g, players, false);
}

void printfCards(Player* p, void * data) {
        printf("player %s: ", p->getName().c_str()); p->printCards(); puts("");
}

void askToBeDZ(Player* p, EventQueue * q) {
        Event * e = new Event(ASK_TO_BE_DZ);
        e->addTag(GAME_PROCESS);
        e->setData(p);
        q->push(e);
}

void PokerCardGameDDZDealer::process(Event* e, EventQueue* q) {
        std::string name=e->getName();
        if (name == GAME_INIT) {
                CardGame * game = (CardGame *) e->getData();
                CardGroup * g = game->getCardDeck();
                PlayerRing * p = game->getPlayers();

                this->setup(*g);

                this->cards = *g;
                this->players = *p;

                Event * e = new Event(SHUFFLE_AND_DEAL);
                e->addTag(GAME_PROCESS);
                e->setData(game);
                q->push(e);
        } else if (name == SHUFFLE_AND_DEAL) {
                CardGame * game = (CardGame *) e->getData();
                PlayerRing * players = game->getPlayers();
                this->shuffle(this->cards);
                this->deal(this->cards, *players);
                players->forEachPlayerRun(printfCards);
                askToBeDZ(players->getFirstPlayer(), q);
        }
}
