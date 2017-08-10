#include "EventQueue.h"
#include "Utils.h"

EventQueue::EventQueue(std::string name) {
        this->name = name;
        event_cnt = 0;
        tot_event_cnt = 0;
}

EventQueue::~EventQueue() {
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
        this->listeners.push_back(l);
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

        printf(PRINT_BLUE "Event %d/%d: ", event_cnt, tot_event_cnt);
        e->print(); puts(PRINT_END);

        event_cnt++;
        for (int i = 0; i<listeners.size(); i++) {
                EventQueueListener* l = listeners[i];
                l->process(e, this);
        }
        this->q.pop();
        if(e) delete e;
        return true;
}
