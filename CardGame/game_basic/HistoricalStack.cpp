#include "HistoricalStack.h"

HistoricalStack::HistoricalStack() {
        curr_player = NULL;
        curr_action = NULL;
}

HistoricalStack::~HistoricalStack() {
        this->deepClear();
}

void HistoricalStack::deepClear() {
        while(this->stack.size()>0) this->pop();
        this->clear();
}

void HistoricalStack::clear() {
        this->stack.clear();
}

void HistoricalStack::push(Player * p, Action * action) {
        puts("HistoricalStack: push action");
        PlayerAction player_action(p, action);
        this->stack.push_back(player_action);
}

void HistoricalStack::pop() {
        puts("HistoricalStack: pop");
        if(this->stack.size() > 0) {
                Action * action = this->stack.back().action;
                if(action) delete action;
                this->stack.pop_back();
        }
}

Player * HistoricalStack::topPlayer() const {
        return this->stack.back().player;
}

Action * HistoricalStack::topAction() const {
        return this->stack.back().action;
}

void HistoricalStack::process(Event* e, EventQueue* q) {
        std::string name=e->getName();
        if (name == EVENT_READY_TO_PLAY_CARDS) {
                curr_player = (Player*) (e->getData());
        } else if(name == EVENT_PLAY_CARDS) {
                curr_action = (Action*) (e->getData());
                this->push(curr_player, curr_action);
        }
}

void HistoricalStack::regist(EventQueue * q) {
        this->addTag(EVENT_TAG_PLAYER_ACTION);
        q->addListener(this);
}
