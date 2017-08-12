#ifndef CARD_GAME_EVENT
#define CARD_GAME_EVENT

#include <string>
#include <vector>

// 一个事件，该卡牌游戏系统由事件进行驱动
// 一个对象，比如Dealer，Player或者UI等，都将维护一个自己的状态机，
// 并根据接受到的事件进行处理和更新状态。这些事件将会放入到EventQueue当中
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
