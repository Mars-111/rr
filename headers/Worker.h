#pragma once
#include "Human.h"

class Worker: public Human
{
    class Team* currentTeam = nullptr;
public:
    Worker(class Team* inCurrentTeam, std::string name) : currentTeam(inCurrentTeam) {this->name = name;}
    enum Working {NO = 0, A = 1, B = 2, C = 3};
    Working working = NO;
};