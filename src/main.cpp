#include <iostream>
#include <vector>
#include <cassert>

#include "Company.h"

int main()
{
    Company company("Head");
    std::string nameManager;
    std::vector<std::string> nameWorkers;
    int countTeams = 0;
    std::cout<<"Enter count teams: ";
    std::cin>>countTeams;
    for (int i = 0; i < countTeams; i++)
    {
        std::cout<<"Teams #"<<i+1<<":\n";
        std::cout<<"Enter manamger name: ";
        std::cin>>nameManager;
        int countWorkers = 0;
        std::cout<<"Enter count workers: ";
        std::cin>>countWorkers;
        nameWorkers.resize(countWorkers);
        for (int j = 0; j < countWorkers; j++)
        {
            std::cout<<"Enter name worker #"<<j+1<<": ";
            std::cin>>nameWorkers[j];
        }
        company.add_team(nameManager, nameWorkers);
    }
    

    while (!company.all_teams_busy())
    {
        int id;
        std::cout<<"Id: ";
        std::cin>>id;
        company.set_headId(id);

        for (size_t i = 0; i < company.get_countTeam(); i++)
        {
            company.start_team_work(i);
        }
    }



    return 0;
}