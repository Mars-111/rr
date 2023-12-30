#include <string>
#include "Company.h"
#include "Teams.h"
#include "Head.h"

Company::Company(std::string nameHead)
{
    head->name = nameHead;
}

Company::~Company()
{
    delete head;
    for (size_t i = 0; i < teams.size(); i++)
    {
        delete teams[i];
        teams[i] = nullptr;
    }
}

void Company::add_team(std::string nameManager, std::vector<std::string> nameWorkers)
{
    teams.push_back(new Team(nameManager, nameWorkers));
}

void Company::start_team_work(size_t indexTeam)
{
    for (size_t i = 0; i < teams.size(); i++)
    {
        teams[i]->task_distribution();
    }
}

void Company::set_headId(int id)
{
    this->head->identifier = id;
}

int Company::get_headId()
{
    return this->head->identifier;
}

bool Company::all_teams_busy()
{
    for (size_t i = 0; i < teams.size(); i++)
    {
        if (!teams[i]->all_workers_busy()) return false;
    }
    
    return true;
}
