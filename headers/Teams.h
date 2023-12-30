#pragma once

#include <vector>
#include <string>

class Team
{
    class Manager* manager;
    std::vector<class Worker*> workers;
    class Company* currentCompany; 
public:
    Team() {}
    Team(std::string nameManager, std::vector<std::string> nameWorkers);
    ~Team();
    void task_distribution();
    bool all_workers_busy();
};