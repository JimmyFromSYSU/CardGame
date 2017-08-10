#include "Event.h"

Event::Event(std::string name) {
        this->name = name;
}

Event::~Event() {
}

void Event::setData(void * data) {
        this->data = data;
}

void * Event::getData() {
        return this->data;
}

std::string Event::getName() {
        return this->name;
}

std::string Event::getExplanation() {
        return this->explanation;
}

std::vector<std::string> Event::getTags(){
        return this->tags;
}

void Event::setExplanation(std::string explanation) {
        this->explanation = explanation;
}

void Event::addTag(std::string tag) {
        this->tags.push_back(tag);
}

void Event::print() {
        printf("%s (", this->name.c_str());
        for(int i = 0; i < tags.size(); i++) {
                printf("[%s]", this->tags[i].c_str());
        }
        printf(") - %s", this->explanation.c_str());
}
