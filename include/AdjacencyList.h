#ifndef ADJACENCYLIST_H_INCLUDED
#define ADJACENCYLIST_H_INCLUDED

#include <vector>
#include "Goal.h"
using namespace std;

class AdjacencyList
{
    private:
       int numOfVerticies;
       vector<vector<Goal> >List;
       vector<Goal>vec;
    public:
       AdjacencyList();
       void Load();
       void getPrerequisite(Goal &G);

};

#endif // ADJACENCYLIST_H_INCLUDED
