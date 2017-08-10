#ifndef CARD_GAME_EVENT
#define CARD_GAME_EVENT

#include <string>
#include <vector>

class Event {

protected:
// 有些Listener只关心特定的事件
std::vector<std::string> tags;
std::string name;
std::string explanation;
void * data;

public:

Event(std::string name);
~Event();

std::string getName();
std::string getExplanation();
std::vector<std::string> getTags();
void setData(void *);
void * getData();
void setExplanation(std::string explanation);
void addTag(std::string tag);
void print();
};


#endif /* end of include guard: CARD_GAME_EVENT */
