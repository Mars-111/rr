#include "Head.h"
#include "Company.h"
#include "Teams.h"
#include "Manager.h"
#include "Worker.h"

#include <cassert>
#include <iostream>

Team::Team(std::string nameManager, std::vector<std::string> nameWorkers)
{
    manager = new Manager(nameManager, this);
    this->workers.resize(nameWorkers.size());
    for (size_t i = 0; i < nameWorkers.size(); i++)
    {
        workers[i] = new Worker(this, nameWorkers[i]);
    }
    
}

Team::~Team()
{
    delete manager;
    for (size_t i = 0; i < workers.size(); i++)
    {
        delete workers[i];
        workers[i] = nullptr;
    }
    
}

void Team::task_distribution()
{
    std::srand(this->currentCompany->get_headId() + workers.size());
    int tasksCount = rand() % (this->workers.size() + 1);
    size_t i = 0;
    for (size_t i = 0; i < workers.size() && tasksCount; i++)
    {
        if (workers[i]->working == Worker::Working::NO)
        {
            tasksCount--;
            std::cout<<"Workers "<<workers[i]->name<<" busy\n";
            workers[i]->working = Worker::Working((rand()%3)+1);
            assert(workers[i]->working == Worker::Working::A || workers[i]->working == Worker::Working::B || workers[i]->working == Worker::Working::C);
        }
    }
}

bool Team::all_workers_busy()
{
    for (size_t i = 0; i < workers.size(); i++)
    {
        if (workers[i]->working == Worker::Working::NO) return false;
    }
    return true;
}
