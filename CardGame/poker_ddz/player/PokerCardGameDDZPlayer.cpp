#include "PokerCardGameDDZPlayer.h"
#include "PokerCardGameDDZInfo.h"
#include "PokerCardGameDDZEventList.h"
#include "EventTagList.h"
#include "PokerCardGameDDZUtils.h"
#include <sstream>
#include "PlayCardsAction.h"
#include "PokerCard.h"

PokerCardGameDDZPlayer::PokerCardGameDDZPlayer(int id, std::string name) {
        this->id =id;
        this->name = name;
        this->dz_player = NULL;
}

PokerCardGameDDZPlayer::~PokerCardGameDDZPlayer() {
}

void PokerCardGameDDZPlayer::regist(EventQueue * q) {
        this->addTag(EVENT_TAG_GAME_PROCESS);
        this->addTag(EVENT_TAG_PLAYER_ACTION);
        q->addListener(this);
}

CardGroup PokerCardGameDDZPlayer::think() {
        //if(last_useful_play_card_info.player == this) {
        //std::vector<const Card*> c = this->cards.getVector();

        //}
        return this->cards.first(1);
}

void PokerCardGameDDZPlayer::process(Event* e, EventQueue* q) {
        std::string name=e->getName();
        if (name == EVENT_DZ_ASK_TO_BE) {
                Player * player = (Player *)(e->getData());
                if(player == this) {
                        std::ostringstream str;
                        Event * e;
                        // TODO: Decide if to be dz
                        if(rand()%2 == 0) {
                                e = new Event(EVENT_DZ_TO_BE);
                                str << player->getName() << " answered YES";
                        } else {
                                e = new Event(EVENT_DZ_NOT_TO_BE);
                                str << player->getName() << " answered NO";
                        }

                        e->setExplanation(str.str());
                        e->addTag(EVENT_TAG_PLAYER_ACTION);
                        e->setData(player);
                        q->push(e);
                }
        } else if(name == EVENT_DZ_CLAIM) {
                Player * player = (Player *)(e->getData());
                this->dz_player = player;
                this->last_useful_play_card_info.player = NULL;
        } else if(name == EVENT_DZ_SHOW_3_CARDS) {
                CardGroup * cards = (CardGroup*) (e->getData());
                if(this->dz_player == this) {
                        this->cards.add(*cards);
                        this->cards.sort(handCardComparator);
                        printf("Player %s: ", this->name.c_str());
                        this->cards.print(); puts("");
                }
        } else if(name == EVENT_ASK_TO_PLAY) {
                Player * player = (Player*) (e->getData());
                if(player == this) {
                        std::ostringstream str;
                        str << this->name << " is going to play some cards";
                        Event * e = new Event(EVENT_READY_TO_PLAY_CARDS);
                        e->setExplanation(str.str());
                        e->addTag(EVENT_TAG_PLAYER_ACTION);
                        e->setData(this);
                        q->push(e);

                        CardGroup g = this->think();

                        PlayCardsAction * action = new PlayCardsAction(g);
                        e = new Event(EVENT_PLAY_CARDS);
                        e->setExplanation("Playing cards");
                        e->addTag(EVENT_TAG_PLAYER_ACTION);
                        e->setData(action);
                        q->push(e);
                }
        } else if (name == EVENT_READY_TO_PLAY_CARDS) {
                Player * curr_player = (Player*) (e->getData());
                this->curr_player = curr_player;
        } else if (name == EVENT_PLAY_CARDS) {
                PlayCardsAction * action = (PlayCardsAction*) (e->getData());
                if(this->curr_player == this) {
                        action->playBy(this);
                        // printf("%s: now ", this->name.c_str());
                        // this->cards.print(); puts("");
                        if(this->cards.size() == 0) {
                                Event * e = new Event(EVENT_FINISH_ALL_CARD);
                                e->addTag(EVENT_TAG_PLAYER_ACTION);
                                q->push(e);
                        } else {
                                Event * e = new Event(EVENT_PLAY_CARDS_DONE);
                                e->addTag(EVENT_TAG_PLAYER_ACTION);
                                q->push(e);
                        }
                }
                if (action->getCards().size()) {
                        this->last_useful_play_card_info.player = this->curr_player;
                        this->last_useful_play_card_info.cards = action->getCards();
                }
        }
}
