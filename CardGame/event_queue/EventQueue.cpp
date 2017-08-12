#include "EventQueue.h"
#include "Utils.h"

EventQueue::EventQueue(std::string name) {
        this->name = name;
        event_cnt = 0;
        tot_event_cnt = 0;
}

EventQueue::~EventQueue() {
        clear();
}

void EventQueue::clear() {
        clearListener();
        while(!this->q.empty()) {
                Event * e = this->q.front();
                this->q.pop();
                //e->print(); puts("");
                if(e) delete e;
        }
}

std::string EventQueue::getName() {
        return this->name;
}

void EventQueue::addListener(EventQueueListener* l) {
        if(l == NULL) return;
        for(int i = 0; i<this->listeners.size(); i++) {
                if(this->listeners[i] == l) return;
        }
        this->listeners.push_back(l);
}

void EventQueue::clearListener() {
        this->listeners.clear();
}

void EventQueue::push(Event* e) {
        this->q.push(e);
        tot_event_cnt++;
}

void EventQueue::run() {
        while(this->pop()) ;
}

bool EventQueue::pop() {
        if(this->q.empty()) return false;
        Event * e = this->q.front();

        event_cnt++;

        printf(PRINT_BLUE "Event %d/%d: ", event_cnt, tot_event_cnt);
        e->print(); puts(PRINT_END);

        for (int i = 0; i<listeners.size(); i++) {
                EventQueueListener* l = listeners[i];
                if(l->interestedInAny( e->getTags())) {
                        l->process(e, this);
                }
        }
        this->q.pop();
        if(e) delete e;
        return true;
}
