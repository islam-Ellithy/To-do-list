#include "AdjacencyList.h"
#include <iostream>
#include <fstream>

using namespace std;

AdjacencyList::AdjacencyList()
{
//   List.resize(5);
}


void AdjacencyList::Load()
{
    fstream file1,file2;
    file1.open("goals.txt",ios::in|ios::out);
    file2.open("maps.txt",ios::in|ios::out);

    file1.seekg(0,ios::beg);
    while(!file1.eof())
    {
        Goal G;
        file1>>G;
        vec.push_back(G);
    }
    List.resize(vec.size());
    file2.seekg(0,ios::beg);
    int n,n1,n2;
    file2>>n;
    file2>>n1;
    for(int i=0;i<n;i++)
    {
        file2>>n1;
        file2>>n2;
        List[n1-1].push_back(vec[n2-1]);
    }

//    cout << "List is : \n";
//    cout << "list.size() = "<<List.size()<<endl;
//    for(int i=0;i<List.size();i++)
//    {
//        cout << "list["<<i<<"] :\n";
//        for(int j=0;j<List[i].size();j++)
//        {
//            cout << List[i][j]<<" ";
//        }
//        cout <<endl;
//    }

    file1.close();
    file2.close();
}


void AdjacencyList::getPrerequisite(Goal &G)
{
    for(int i=0;i<List.size();i++)
    {
        for(int j=0;j<List[i].size();j++)
        {
            if(List[i][j].getGoalNumber() == G.getGoalNumber())
            {
                cout << i+1 << endl;
                break;
            }
        }
    }

}
