
#include "PokerCard.h"
#include <stdio.h>
#include "Utils.h"

std::string PokerCard::PokerTypeToStr[6] = {"♠", "♥", "♣","♦", "大", "小"};
std::string PokerCard::PokerNumberToStr[14] = {
        "王","A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"
};

PokerCard::PokerCard(PokerType type, PokerNumber number){
        this->type = type;
        this->number = number;
}

PokerCard::~PokerCard(){
}

PokerType PokerCard::getType() const {
        return type;
}
PokerNumber PokerCard::getNumber() const {
        return number;
}

bool PokerCard::isRed() const {
        if (type == HEART ||
            type == DIAMOND ||
            type == RED
            ) return true;
        else return false;
}

void PokerCard::print() const {
        if(isRed()) printf(PRINT_RED);
        printf("%s%s",
               PokerTypeToStr[type].c_str(),
               PokerNumberToStr[number].c_str()
               );
        if(isRed()) printf(PRINT_END);
}
