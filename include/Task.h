#ifndef TASK_H
#define TASK_H
#include <fstream>
#include "FCISLL.h"

using namespace std ;

class Task
{
public:
    string Name ;
    string Description ;
    int Priority ;
    string Date ;
    int Duration ;

    Task();
    ~Task();
    Task(const Task& rhs);

    void ReadTaskFromFile(fstream &file,Task &t)
    {
        file >> t ;
    }
    void AddToFile(Task &T);
    void Start();
    void Initializer(Task &ts);
    void OrderedList();
    void PrintList();
    bool orderByDuration(Task task1,Task task2);
    bool orderByDate(Task task1,Task task2);
    bool operator < (const Task &rhs);
    bool operator > (const Task &rhs);
    bool operator != (Task &t)
    {
        return (Name!=t.Name && Description!=t.Description
                &&  Priority != t.Priority && Date!=t.Date
                &&   Duration!=t.Duration);
    }
    Task& operator=(const Task& rhs);
    friend istream & operator >> (istream &in ,Task &);
    friend istream & operator >> (istream &in ,Task &&);
    friend ostream & operator << (ostream &out ,Task &);
    friend ostream & operator << (ostream &out ,Task &&);

};

#endif // TASK_H
