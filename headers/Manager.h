#pragma once
#include "Human.h"
#include <vector>
#include <string>


class Manager: public Human
{
    class Team* currentTeam = nullptr;
public:
    Manager(std::string name, class Team* team) : currentTeam(team) {this->name = name;}

};