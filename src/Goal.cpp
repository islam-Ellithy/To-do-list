#include "Goal.h"
#include <iostream>

using namespace std;


Goal::Goal()
{
   goalNumber = 0;
   Name = Description = Date = "\0";
}

Goal::Goal(int goalNumber,string Name,string Description,string Date)
{
    this->goalNumber = goalNumber;
    this->Name = Name;
    this->Description = Description;
    this->Date = Date;
}

int Goal::getGoalNumber()
{
    return goalNumber;
}

istream& operator >> (istream &in,Goal &G)
{
    in>>G.goalNumber;
    in.ignore();
    getline(in,G.Name);
    getline(in,G.Description);
    getline(in,G.Date);
    return in;
}


ostream& operator<<(ostream& out,Goal& G)
{
    out<<G.goalNumber<<endl;
    out<<G.Name<<endl;
    out<<G.Description<<endl;
    out<<G.Date<<endl;
    return out;
}

