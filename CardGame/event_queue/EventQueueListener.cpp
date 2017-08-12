#include "EventQueueListener.h"

void EventQueueListener::addTag(std::string tag) {
        this->listen_tags.insert(tag);
}

bool EventQueueListener::interestedIn(std::string tag) const {
        if(this->listen_tags.size() == 0) return true;
        return this->listen_tags.count(tag) > 0;
}

bool EventQueueListener::interestedInAny(std::vector<std::string> tags) const {
        for(int i = 0; i < tags.size(); i++) {
                if(this->interestedIn(tags[i])) return true;
        }
        return false;
}

bool EventQueueListener::interestedIn(std::vector<std::string> tags) const {
        for(int i = 0; i < tags.size(); i++) {
                if(this->interestedIn(tags[i]) == false) return false;
        }
        return true;
}
