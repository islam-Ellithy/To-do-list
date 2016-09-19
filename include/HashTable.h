#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
using namespace std;

struct TaskA
{
    string name;
    string desc;
    string Date;
    int priority;
    int NumOfDays;
};

class HashTable
{
    public:
        HashTable();
        HashTable(double LF);
        int HashFn(string str);
        void InsertLP();
        void InsertQP();
        void ScSearchLP();
        void UnScSearchLP();
        void ScSearchQP();
        void UnScSearchQP();
        void DeleteLP();
        void DeleteQP();
        friend ostream& operator<<(ostream& out, TaskA& T);
        friend istream& operator>>(istream& in, TaskA&T);
    private:
        double LF;
        TaskA arr[211];
};


#endif // HASHTABLE_H
