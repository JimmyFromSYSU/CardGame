#include "PokerCardGameDDZ.h"

int main(){
        PokerCardGameDDZ * game = new PokerCardGameDDZ();
        game->init();
        game->run();
        delete game;
        return 0;
}
