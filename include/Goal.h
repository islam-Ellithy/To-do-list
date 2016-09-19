#ifndef GOAL_H_INCLUDED
#define GOAL_H_INCLUDED

#include <iostream>
using namespace std;

class Goal
{
    private:
       int goalNumber;
       string Name;
       string Description;
       string Date;

    public:
        Goal();
        Goal(int,string,string,string);
        int getGoalNumber();
        friend istream& operator >> (istream &in,Goal &G);
        friend ostream& operator<<(ostream& out,Goal& G);
};

#endif // GOAL_H_INCLUDED
