#ifndef CARD_GAME_EVENT_QUEUE
#define CARD_GAME_EVENT_QUEUE

#include <queue>
#include <vector>
#include "EventQueueListener.h"
#include "Event.h"

class EventQueueListener;
class EventQueue {
protected:
int event_cnt;
int tot_event_cnt;

std::string name;
std::queue<Event *> q;
std::vector<EventQueueListener*> listeners;

bool pop();

public:
EventQueue(std::string);
~EventQueue();
std::string getName();
void addListener(EventQueueListener* l);
void push(Event* e);
void run();
};

#endif /* end of include guard: CARD_GAME_EVENT_QUEUE */
