#include "DDZDecideDZRule.h"
#include "PokerCardGameDDZUtils.h"
#include "PokerCardGameDDZEventList.h"
#include <sstream>

int next[][2] = {
        {0, 0},         // 0
        {10, 2},        // 1
        {9, 3},         // 2
        {7, 4},         // 3
        {6, 5},         // 4
        {0, 0},         // 5
        {0, 0},         // 6
        {8, 5},         // 7
        {0, 0},         // 8
        {5, 4},         // 9
        {13, 11},       // 10
        {8, 12},        // 11
        {6, 8},         // 12
        {14, 6},        // 13
        {0, 0},         // 14
};

DDZDecideDZRule::DDZDecideDZRule(PlayerRing * players) {
        this->players = players;
        this->player1 = players->getCurrPlayer();
        this->player2 = players->getNextPlayer(this->player1);
        this->player3 = players->getNextPlayer(this->player2);
        this->clear();
}

DDZDecideDZRule::~DDZDecideDZRule() {

}

void DDZDecideDZRule::clear() {
        this->curr_state = 0;
}


void DDZDecideDZRule::regist(EventQueue * q) {
        this->addTag(EVENT_TAG_PLAYER_ACTION);
        this->addTag(EVENT_TAG_GAME_PROCESS);
        q->addListener(this);
}

void DDZDecideDZRule::deal(EventQueue * q) {
        std::string event_name = "";
        std::string explanation = "";
        std::ostringstream str;
        Player * player = NULL;

        switch (this->curr_state) {
        case 1:
        case 4:
        case 7:
                event_name = EVENT_DZ_ASK_TO_BE;
                player = player1;
                str << "ask " << player->getName() << " to be dz";
                explanation = str.str();
                break;
        case 2:
        case 10:
        case 12:
                event_name = EVENT_DZ_ASK_TO_BE;
                player = player2;
                str << "ask " << player->getName() << " to be dz";
                explanation = str.str();
                break;
        case 3:
        case 9:
        case 11:
        case 13:
                event_name = EVENT_DZ_ASK_TO_BE;
                player = player3;
                str << "ask " << player->getName() << " to be dz";
                explanation = str.str();
                break;
        case 5:
                event_name = EVENT_DZ_CLAIM;
                player = player1;
                str << "claim " << player->getName() << " to be dz";
                explanation = str.str();
                break;
        case 8:
                event_name = EVENT_DZ_CLAIM;
                player = player2;
                str << "claim " << player->getName() << " to be dz";
                explanation = str.str();
                break;
        case 6:
                event_name = EVENT_DZ_CLAIM;
                player = player3;
                str << "claim " << player->getName() << " to be dz";
                explanation = str.str();
                break;
        case 14:
                event_name = EVENT_GAME_OVER;
                explanation = "Game Over";
                break;
        default:
                break;
        }

        if(event_name!= "") {
                Event * e = new Event(event_name);
                e->addTag(EVENT_TAG_GAME_PROCESS);
                e->setData(player);
                e->setExplanation(explanation);
                q->push(e);
        }
}

void DDZDecideDZRule::process(Event* e, EventQueue* q) {
        std::string name=e->getName();
        // printf("DDZDecideDZRule: %s\n", name.c_str());
        if (name == EVENT_DZ_TO_BE) {  // 判断抢地主结果
                this->curr_state = next[this->curr_state][1];
                this->deal(q);
        } else if(name == EVENT_DZ_NOT_TO_BE) {
                this->curr_state = next[this->curr_state][0];
                this->deal(q);
        } else if(name == EVENT_DZ_START) {
                this->curr_state = 1;
                this->deal(q);
        }
}
