#include "PokerCardGameDDZDealer.h"
#include "PokerCardUtils.h"
#include "CardGame.h"
#include "EventTagList.h"
#include <stdio.h>
#include "PokerCardGameDDZEventList.h"
#include <sstream>
#include "PokerCardGameDDZUtils.h"
#include "Utils.h"
void PokerCardGameDDZDealer::setup(CardGroup& card_deck, bool showInfo) {
        if(showInfo) puts(PRINT_GREEN "Dealer: Set up card deck" PRINT_END);
        add54CardsTo(card_deck);
        if(showInfo) card_deck.print();
        if(showInfo) puts("");
}

void PokerCardGameDDZDealer::deal(CardGroup g, PlayerRing& players, bool showInfo) {
        if(showInfo) puts(PRINT_GREEN "Dealer: Deal cards" PRINT_END);
        this->dz_cards = g.draw(3);
        if(showInfo) printf("地主牌：");
        if(showInfo) this->dz_cards.print();
        if(showInfo) puts("");
        Dealer::deal(g, players, false);
        players.forEachPlayerRun(sortCards);
}

void printfCards(Player* p, void * data) {
        printf("player %s: ", p->getName().c_str()); p->printCards(); puts("");
}

void PokerCardGameDDZDealer::askToPlay(Player * p, EventQueue * q) {
        Event * e = new Event(EVENT_ASK_TO_PLAY);
        e->addTag(EVENT_TAG_GAME_PROCESS);
        e->setData(p);
        std::ostringstream str;
        str << "Dealer asked " << p->getName()
            << " to play cards";
        e->setExplanation(str.str());
        q->push(e);
}

void PokerCardGameDDZDealer::regist(EventQueue * q) {
        this->addTag(EVENT_TAG_GAME_PROCESS);
        this->addTag(EVENT_TAG_PLAYER_ACTION);
        q->addListener(this);
}

void PokerCardGameDDZDealer::process(Event* e, EventQueue* q) {
        std::string name=e->getName();
        if (name == EVENT_GAME_INIT) {
                CardGame * game = (CardGame *) e->getData();
                CardGroup * g = game->getCardDeck();
                PlayerRing * p = game->getPlayers();

                this->setup(*g);

                this->cards = *g;
                this->players = *p;
                this->stack.regist(q);

                Event * e = new Event(EVENT_SHUFFLE_AND_DEAL);
                e->addTag(EVENT_TAG_GAME_PROCESS);
                e->setData(game);
                q->push(e);
        } else if (name == EVENT_SHUFFLE_AND_DEAL) {
                CardGame * game = (CardGame *) e->getData();
                PlayerRing * players = game->getPlayers();

                puts(PRINT_GREEN "Dealer: Shuffle cards" PRINT_END);
                this->cards = this->shuffle(this->cards, false);
                this->cards.print(); puts("");
                this->deal(this->cards, *players);
                players->forEachPlayerRun(printfCards);

                players->resetCurrPlayer();

                Event * e = new Event(EVENT_DZ_START);
                e->addTag(EVENT_TAG_GAME_PROCESS);
                e->setData(players->getCurrPlayer());
                q->push(e);

        } else if (name == EVENT_DZ_CLAIM) {
                Player * player = (Player *) (e->getData());
                this->dz_player = player;
                this->players.setCurrPlayer(player);
                Event * e = new Event(EVENT_DZ_SHOW_3_CARDS);
                e->addTag(EVENT_TAG_GAME_PROCESS);
                e->setData(&(dz_cards));
                q->push(e);
        } else if(name == EVENT_DZ_SHOW_3_CARDS) {
                this->askToPlay(this->dz_player, q);
        } else if (name == EVENT_PLAY_CARDS_DONE) {
                Player * p = this->players.toNext();
                askToPlay(p, q);
        } else if (name == EVENT_FINISH_ALL_CARD) {
                gameOver(q);
        }
}
