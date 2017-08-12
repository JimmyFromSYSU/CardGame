#include "PokerCardGameDDZPlayer.h"
#include "PokerCardGameDDZInfo.h"
#include "PokerCardGameDDZEventList.h"
#include "EventTagList.h"
#include "PokerCardGameDDZUtils.h"
#include <sstream>
#include "PlayCardsAction.h"

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

void PokerCardGameDDZPlayer::process(Event* e, EventQueue* q) {
        std::string name=e->getName();
        if (name == EVENT_ASK_TO_BE_DZ) {
                AskDZInfo * info = (AskDZInfo *)(e->getData());
                if(info->curr_player == this) {
                        std::ostringstream str;
                        Event * e = new Event(EVENT_TO_BE_OR_NOT_TO_BE_DZ);
                        // TODO: Decide if to be dz
                        if(info->ask_time != 2) {
                                info->curr_ans = true;
                                str << info->curr_player->getName() << " answered YES";
                        } else {
                                info->curr_ans = false;
                                str << info->curr_player->getName() << " answered NO";
                        }

                        e->setExplanation(str.str());
                        e->addTag(EVENT_TAG_PLAYER_ACTION);
                        e->setData(info);
                        q->push(e);
                }
        } else if(name == EVENT_CLAIM_DZ_AND_CARDS) {
                DZInfo * info = (DZInfo*) (e->getData());
                this->dz_player = info->player;
                if(info->player == this) {
                        this->cards.add(info->cards);
                        this->cards.sort(handCardComparator);
                        this->cards.print(); puts("");
                }
        } else if(name == EVENT_ASK_TO_PLAY) {
                PlayCardInfo * info = (PlayCardInfo*) (e->getData());
                if(info->curr_player == this) {

                        std::ostringstream str;
                        str << this->name << " is going to play some cards";
                        Event * e = new Event(EVENT_READY_TO_PLAY_CARDS);
                        e->setExplanation(str.str());
                        e->addTag(EVENT_TAG_PLAYER_ACTION);
                        e->setData(this);
                        q->push(e);


                        CardGroup g = this->cards.first(1);
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
                if(this->curr_player == this) {
                        PlayCardsAction * action = (PlayCardsAction*) (e->getData());
                        action->playBy(this);
                        printf("%s: now ", this->name.c_str());
                        this->cards.print(); puts("");
                }
        }
}
