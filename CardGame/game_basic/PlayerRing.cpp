#include "PlayerRing.h"
#include <stdio.h>

void printPlayerInfo(Player * p) {
        printf("Player %d: %s\n", p->getID(), p->getName().c_str());
}

PlayerRing::PlayerRing(){
        clear();
}

PlayerRing::~PlayerRing(){

}

void PlayerRing::clear() {
        this->players.clear();
        this->next.clear();
        this->prev.clear();
        this->curr_player = NULL;
        this->first_player= NULL;
}

void PlayerRing::deepClear() {
        std::set<Player*>::iterator it;
        for (it = players.begin(); it!= players.end(); ++it) {
                if (*it) delete (*it);
        }
        clear();
}

unsigned PlayerRing::size() const {
        return this->players.size();
}

void PlayerRing::resetCurrPlayer(){
        curr_player = first_player;
}

// curr_player is the first player at the very beginning.
bool PlayerRing::add(Player * player) {
        if(player == NULL) return false;
        if(players.count(player)>0) return false;
        players.insert(player);
        if(players.size() == 1) {
                curr_player = player;
                first_player = player;
                next[player] = player;
                prev[player] = player;
        } else {
                Player* last_player=prev[first_player];
                prev[player] = last_player;
                next[player] = first_player;

                next[last_player] = player;
                prev[first_player] = player;
        }
        return true;
}

Player* PlayerRing::getCurrPlayer() const {
        return this->curr_player;
}


Player* PlayerRing::getNextPlayer(const Player * player) const {
        return next.at(player);
}

Player* PlayerRing::getPrevPlayer(const Player * player) const {
        return prev.at(player);
}

void PlayerRing::setCurrPlayer(Player* p) {
        this->curr_player = p;
}

Player* PlayerRing::getFirstPlayer() const {
        return this->first_player;
}

Player* PlayerRing::toNext() {
        curr_player = this->next[curr_player];
        return curr_player;
}

void PlayerRing::forEachPlayerRun(PlayerFunc f, void * data) {
        Player * curr_player = this->first_player;
        do {
                f(curr_player, data);
                curr_player = this->next[curr_player];
        } while(curr_player != this->first_player);
}
