#include "EventQueueListener.h"

void EventQueueListener::addTags(std::string tag) {
        this->listen_tags.insert(tag);
}
