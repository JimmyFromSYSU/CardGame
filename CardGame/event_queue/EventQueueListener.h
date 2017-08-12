#ifndef CARD_GAME_EVENT_QUEUE_LISTENER
#define CARD_GAME_EVENT_QUEUE_LISTENER

#include <set>
#include <string>
#include "Event.h"
#include "EventQueue.h"
#include "EventTagList.h"
#include "EventList.h"

class EventQueue;
// 需要对EventQueue进行监听，处理其pop出来的Event的所有对象都应当继承EventQueueListener
class EventQueueListener {
protected:
// 只关心特定Tag的事件，如果为空则关心所有事件
std::set<std::string> listen_tags;
public:

bool interestedIn(std::string) const;
bool interestedInAny(std::vector<std::string>) const;
bool interestedIn(std::vector<std::string>) const;
void addTag(std::string);
virtual void process(Event* e, EventQueue* q)=0;
virtual void regist(EventQueue * q)=0;
};


#endif /* end of include guard: CARD_GAME_EVENT_QUEUE_LISTENER */
