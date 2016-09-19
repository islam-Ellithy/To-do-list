#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include "HashTable.h"

using namespace std;

HashTable::HashTable()
{
    LF=0.0;
    for(int i=0; i<211; i++)
        arr[i].priority=-1;
}

HashTable::HashTable(double LF)
{
    this->LF=LF;
    for(int i=0; i<211; i++)
        arr[i].priority=-1;
}

ostream& operator<<(ostream& out, TaskA &T)
{
    out << T.name << " ";
    out << T.desc << " ";
    out << T.Date << " ";
    out << T.priority << " ";
    out << T.NumOfDays << endl;
    return out;
}

istream& operator>>(istream& in, TaskA &T)
{
    in >> T.name;
    in >> T.desc;
    in >> T.Date;
    in >> T.priority;
    in >> T.NumOfDays;
    return in;
}

int HashTable::HashFn(string str)
{
    int x;
    unsigned long long sum=0;
    for (int i=0; i<str.size(); i++){
        x=int(str[i]);
        sum+=pow(37, i)*x;}
    return sum%211;
}

void HashTable::InsertLP()
{
    TaskA t;
    int counter, j=1, Sum=0;
    double Avg;
    fstream file;
    file.open("T.txt", ios::in|ios::binary);
    for (int i=0; i<211*LF; i++)
    {
        j=1;
        file >> t;
        //cout << t << endl;
        int ThePosition=HashFn(t.name);
        counter=ThePosition;
        do
        {
            if (arr[counter].priority==-1)
            {
                arr[counter].name=t.name;
                arr[counter].desc=t.desc;
                arr[counter].Date=t.Date;
                arr[counter].priority=t.priority;
                arr[counter].NumOfDays=t.NumOfDays;
                break;
            }
            if (i>=((211*LF) - 10))
                j++;

            counter++;
        }while(counter%211!=ThePosition);
        if (i>=((211*LF) - 10)){
            //cout << j << endl;
            Sum+=j;
        }
    }
    Avg=Sum/10;
        cout << "Insertion Average in Linear Probing= " << Avg << " probs.\n";
    file.close();      file.clear();
}

void HashTable::InsertQP()
{
    TaskA t;
    int counter, j=1, Sum=0, m=1;
    double Avg;
    fstream file;
    file.open("T.txt", ios::in|ios::binary);
    for (int i=0; i<211*LF; i++)
    {
        m=1;
        j=1;
        file >> t;
        //cout << t << endl;
        int ThePosition=HashFn(t.name);
        counter=ThePosition;
        do
        {
            if (arr[counter].priority==-1)
            {
                arr[counter].name=t.name;
                arr[counter].desc=t.desc;
                arr[counter].Date=t.Date;
                arr[counter].priority=t.priority;
                arr[counter].NumOfDays=t.NumOfDays;
                break;
            }
            if (i>=((211*LF) - 10))
                j++;

            counter=(counter+m*m)%211;
            m++;
        }while(counter%211!=ThePosition);
        if (i>=((211*LF) - 10)){
            //cout << j << endl;
            Sum+=j;
        }
    }
    Avg=Sum/10;
        cout << "Insertion Average in Quadratic Probing=" << Avg << " probs.\n";
    file.close();      file.clear();
}

void HashTable::ScSearchLP()
{
    TaskA t;
    int counter, j=1, Sum=0;
    double Avg;
    fstream file;
    file.open("T.txt", ios::in|ios::binary);
    for (int i=0; i<10; i++)
    {
        j=1;
        file >> t;
        //cout << t << endl;
        int ThePosition=HashFn(t.name);
        counter=ThePosition;
        do
        {
            if (arr[counter].priority==-1)
            {
                cout << "Not Found.\n";
                break;
            }
            else if (arr[counter].name==t.name)
            {
                cout << t << endl;
                break;
            }
            j++;
            counter++;
        }while(counter%211!=ThePosition);
            //cout << j << endl;
            Sum+=j;
    }
    Avg=Sum/10;
        cout << "Successful Search Average in Linear Probing= " << Avg << " probs.\n";
    file.close();      file.clear();
}

void HashTable::UnScSearchLP()
{
    TaskA t;
    int counter, j=1, Sum=0;
    double Avg;
    fstream file;
    file.open("Ta.txt", ios::in|ios::binary);
    for (int i=0; i<10; i++)
    {
        j=0;
        file >> t;
        //cout << t << endl;
        int ThePosition=HashFn(t.name);
        counter=ThePosition;
        do
        {
            if (arr[counter].priority==-1)
            {
                //cout << "Not Found.\n";
                break;
            }
            if (arr[counter].name==t.name)
            {
                cout << "Hallo its me " << t << endl;
                break;
            }
            j++;
            counter++;
        }while(counter%211!=ThePosition);
            //cout << j << endl;
            Sum+=j;
    }
    Avg=Sum/10;
        cout << "UnSuccessful search Average in Linear Probing= " << Avg << " probs.\n";
    file.close();      file.clear();
}

void HashTable::ScSearchQP()
{
    TaskA t;
    int counter, j=1, Sum=0, m=0;
    double Avg;
    fstream file;
    file.open("T.txt", ios::in|ios::binary);
    for (int i=0; i<10; i++)
    {
        m=0;
        j=1;
        file >> t;
        //cout << t << endl;
        int ThePosition=HashFn(t.name);
        counter=ThePosition;
        do
        {
            if (arr[counter].priority==-1)
            {
                cout << "Not Found.\n";
                break;
            }
            else if (arr[counter].name==t.name)
            {
                cout << t << endl;
                break;
            }
            j++;
            counter=(counter+m*m)%211;
            m++;
        }while(counter%211!=ThePosition);
            //cout << j << endl;
            Sum+=j;
    }
    Avg=Sum/10;
        cout << "Successful Search Average in Quadratic Search= " << Avg << " probs.\n";
    file.close();      file.clear();
}

void HashTable::UnScSearchQP()
{
    TaskA t;
    int counter, j=1, Sum=0, m=0;
    double Avg;
    fstream file;
    file.open("Ta.txt", ios::in|ios::binary);
    for (int i=0; i<10; i++)
    {
        j=1;
        file >> t;
        //cout << t << endl;
        int ThePosition=HashFn(t.name);
        counter=ThePosition;
        do
        {
            if (arr[counter].priority==-1)
            {
                //cout << "Not Found.\n";
                break;
            }
            if (arr[counter].name==t.name)
            {
                cout << "Hallo its me " << t << endl;
                break;
            }
            j++;
            counter++;
        }while(counter%211!=ThePosition);
            //cout << j << endl;
            Sum+=j;
    }
    Avg=Sum/10;
        cout << "UnSuccessful search Average in Quadratic Probing= " << Avg << " probs.\n";
    file.close();      file.clear();
}

void HashTable::DeleteLP()
{
    TaskA t;
    int counter, j=1, Sum=0;
    double Avg;
    fstream file;
    file.open("T.txt", ios::in|ios::binary);
    for (int i=0; i<10; i++)
    {
        j=1;
        file >> t;
        //cout << t << endl;
        int ThePosition=HashFn(t.name);
        counter=ThePosition;
        do
        {
            if (arr[counter].priority==-1)
            {
                cout << "Not Found.\n";
                break;
            }
            else if (arr[counter].name==t.name)
            {
                cout << arr[counter] << endl;
                arr[counter].name="Empty.";
                arr[counter].priority=-2;
                break;
            }
            j++;
            counter++;
        }while(counter%211!=ThePosition);
            //cout << j << endl;
            Sum+=j;
    }
    Avg=Sum/10;
        cout << "Deletion Average in Linear probing= " << Avg << " probs.\n";
    file.close();      file.clear();
}

void HashTable::DeleteQP()
{
     TaskA t;
    int counter, j=1, Sum=0, m=0;
    double Avg;
    fstream file;
    file.open("T.txt", ios::in|ios::binary);
    for (int i=0; i<10; i++)
    {
        m=0;
        j=1;
        file >> t;
        //cout << t << endl;
        int ThePosition=HashFn(t.name);
        counter=ThePosition;
        do
        {
            if (arr[counter].priority==-1)
            {
                cout << "Not Found.\n";
                break;
            }
            else if (arr[counter].name==t.name)
            {
                cout << arr[counter] << endl;
                arr[counter].name="Empty.";
                arr[counter].priority=-2;
                break;
            }
            j++;
            counter=(counter+m*m)%211;
        }while(counter%211!=ThePosition);
            //cout << j << endl;
            Sum+=j;
    }
    Avg=Sum/10;
        cout << "Deletion Average in Quadratic probing= " << Avg << " probs.\n";
    file.close();      file.clear();
}
