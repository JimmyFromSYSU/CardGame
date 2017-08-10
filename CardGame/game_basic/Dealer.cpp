#include "Dealer.h"
#include "PokerCardUtils.h"

Dealer::Dealer(){
}

Dealer::~Dealer(){
}

CardGroup Dealer::shuffle(const CardGroup& card_deck, bool showInfo) {
        if(showInfo) puts("Shuffle cards");
        CardGroup g = card_deck;
        g.shuffle();
        if(showInfo) g.print();
        if(showInfo) puts("");
        return g;
}

// 发牌从top开始，top不一定为0，因为可能将牌堆顶的若干牌进行了特殊处理
// 比如升级或者斗地主，都会拿出若干张牌放在牌桌上。
void Dealer::deal(CardGroup& g, PlayerRing& players, bool showInfo) {
        if(showInfo) puts("\nDeal cards");
        Card * curr_card = g.draw();
        int num_of_player = players.size();
        while(curr_card) {
                players.getCurrPlayer()->addCard(curr_card);
                players.toNext();
                curr_card = g.draw();
        }
}
