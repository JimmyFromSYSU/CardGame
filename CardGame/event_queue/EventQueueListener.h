#ifndef CARD_GAME_EVENT_QUEUE_LISTENER
#define CARD_GAME_EVENT_QUEUE_LISTENER

#include <set>
#include <string>
#include "Event.h"
#include "EventQueue.h"

class EventQueue;
class EventQueueListener {
protected:
std::set<std::string> listen_tags;
public:
void addTags(std::string);
// TODO:
// bool interestedIn(std::vector<std::string> tags);
virtual void process(Event* e, EventQueue* q)=0;
};


#endif /* end of include guard: CARD_GAME_EVENT_QUEUE_LISTENER */
