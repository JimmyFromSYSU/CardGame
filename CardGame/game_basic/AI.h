#ifndef CARD_GAME_AI
#define CARD_GAME_AI

#include <string>

class AI {

public:
AI();
~AI();
virtual std::string getName() const = 0;
virtual std::string getExplanation() const = 0;
};

#endif /* end of include guard: CARD_GAME_AI */
