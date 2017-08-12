#ifndef CARD_GAME_EVENT_QUEUE
#define CARD_GAME_EVENT_QUEUE

#include <queue>
#include <vector>
#include "EventQueueListener.h"
#include "Event.h"

class EventQueueListener;
// EventQueue不断取出队列头元素，对Listener进行轮询调用，并负责Event的销毁。
// 1. 通过在EventQueue中打印Log会清楚地展示整个系统的流程
// 2. EventQueue解耦了对象之间的依赖关系和顺序逻辑。
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
void clear();
void clearListener();
// 添加一个监听者，去重，去NULL
void addListener(EventQueueListener* l);
void push(Event* e);
void run();
};

#endif /* end of include guard: CARD_GAME_EVENT_QUEUE */
