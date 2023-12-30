#pragma once
#include <vector>
#include <cstddef>
#include <string>

class Company
{
    std::vector<class Team*> teams;
    class Head* head;
public:
    Company(std::string nameHead);
    ~Company();
    inline size_t get_countTeam() {return teams.size();}
    void add_team(std::string nameManager, std::vector<std::string> nameWorkers);
    void start_team_work(size_t indexTeam);
    void set_headId(int id);
    int get_headId();
    bool all_teams_busy();
};