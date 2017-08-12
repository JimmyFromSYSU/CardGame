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
        this->dz_info.cards = g.draw(3);
        if(showInfo) printf("地主牌：");
        if(showInfo) this->dz_info.cards.print();
        if(showInfo) puts("");
        Dealer::deal(g, players, false);
        players.forEachPlayerRun(sortCards);
}

void printfCards(Player* p, void * data) {
        printf("player %s: ", p->getName().c_str()); p->printCards(); puts("");
}

void askToBeDZ(AskDZInfo * info, EventQueue * q) {
        Event * e = new Event(EVENT_ASK_TO_BE_DZ);
        e->addTag(EVENT_TAG_GAME_PROCESS);
        info->ask_time++;
        e->setData(info);
        std::ostringstream str;
        str << "Dealer asked " << info->curr_player->getName() << " to be DZ";
        e->setExplanation(str.str());
        q->push(e);
}

void game_over(EventQueue * q) {
        Event * e = new Event(EVENT_GAME_OVER);
        e->addTag(EVENT_TAG_GAME_PROCESS);
        e->setData(NULL);
        q->push(e);
}



void PokerCardGameDDZDealer::askToPlay(Player * p, EventQueue * q) {
        Event * e = new Event(EVENT_ASK_TO_PLAY);
        e->addTag(EVENT_TAG_GAME_PROCESS);
        this->play_card_info.curr_player = p;
        this->play_card_info.stack = &(this->stack);
        e->setData(&(this->play_card_info));
        std::ostringstream str;
        str << "Dealer asked " << p->getName()
            << " to play cards";
        e->setExplanation(str.str());
        q->push(e);
}

// 声明地主
void PokerCardGameDDZDealer::claimDZ(EventQueue * q) {
        Event * e = new Event(EVENT_CLAIM_DZ_AND_CARDS);
        e->addTag(EVENT_TAG_GAME_PROCESS);
        e->setData(&(this->dz_info));
        std::ostringstream str;
        str << "Dealer claim " << dz_info.player->getName()
            << " to be DZ and show the 3 cards";
        e->setExplanation(str.str());
        q->push(e);
}

void PokerCardGameDDZDealer::setDZ(Player * p, EventQueue * q) {
        printf(PRINT_GREEN "Dealer: Set DZ to %s\n" PRINT_END, p->getName().c_str());
        this->dz_info.player = p;
        this->claimDZ(q);
        askToPlay(p, q);
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
                this->cards = this->shuffle(this->cards);
                this->deal(this->cards, *players);
                players->forEachPlayerRun(printfCards);

                players->resetCurrPlayer();
                this->ask_dz_info.curr_player = players->getCurrPlayer();
                this->ask_dz_info.curr_ans = false;
                this->ask_dz_info.ask_time = 0;
                this->ask_dz_info.dz_players.clear();
                this->ask_dz_info.no_dz_players.clear();

                askToBeDZ(&(this->ask_dz_info), q);
        } else if (name == EVENT_TO_BE_OR_NOT_TO_BE_DZ) {  // 判断抢地主结果
                AskDZInfo * info = (AskDZInfo *)(e->getData());
                Player *  curr_player = info->curr_player;

                // game over or find the dz.
                if(info->curr_ans == false && info->no_dz_players.size() >= 2) {
                        game_over(q);
                        return;
                } else if(info->curr_ans == true && info->dz_players.count(curr_player) > 0) {
                        this->setDZ(curr_player, q);
                        return;
                } else if(
                        info->ask_time >= 3 &&
                        info->curr_ans == false &&
                        info->dz_players.size() == 1
                        ) {
                        this->setDZ(*(info->dz_players.begin()), q);
                        return;
                } else if (
                        info->ask_time >= 3 &&
                        info->curr_ans == true &&
                        info->dz_players.size() == 0) {
                        this->setDZ(curr_player, q);
                        return;
                }

                // update info for next ask
                if (info->curr_ans == true) {
                        info->dz_players.insert(curr_player);
                } else {
                        info->no_dz_players.insert(curr_player);
                }

                // Find next player who might want to be dz
                curr_player = this->players.toNext();
                while(info->no_dz_players.count(curr_player)>0) {
                        curr_player = this->players.toNext();
                }
                info->curr_ans = false;
                info->curr_player = curr_player;
                askToBeDZ(info, q);
        } else if (name == EVENT_READY_TO_PLAY_CARDS) {

        }
}
