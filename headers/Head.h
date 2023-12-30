#pragma once
#include "Human.h"

class Head: public Human
{
    class Company* currentCompany = nullptr;
public:
    int identifier = 0;
};