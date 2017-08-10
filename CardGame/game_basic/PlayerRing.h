#ifndef CARD_GAME_PLAYER_RING
#define CARD_GAME_PLAYER_RING

#include "Player.h"
#include <set>
#include <map>

typedef void (PlayerFunc)(Player *, void * data);

class PlayerRing {

public:
PlayerRing();
~PlayerRing();
bool add(Player * player);
Player* toNext();
void clear();
void deepClear();
unsigned size() const;

void setCurrPlayer(Player *);
Player* getCurrPlayer() const;

Player* getFirstPlayer() const;

void resetCurrPlayer();

void forEachPlayerRun(PlayerFunc f, void * data = 0);

protected:
std::set<Player*> players;
std::map<Player*, Player*> next;
std::map<Player*, Player*> prev;
Player* curr_player;
Player* first_player;
};

#endif /* end of include guard: CARD_GAME_PLAYER_RING */
