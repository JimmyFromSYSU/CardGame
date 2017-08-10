#ifndef CARD_GAME_CARD
#define CARD_GAME_CARD

// NO POINTER
class Card {
public:
virtual void print() const = 0;
virtual ~Card(){
};
};

#endif /* end of include guard: CARD_GAME_CARD */
