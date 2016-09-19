#include <iostream>
#include <fstream>
#include "Task.h"
#include "FCISLL.h"
#include "BST.h"
#include "AVL.h"
#include "Heap.h"
#include "Treap.h"
#include "Goal.h"
#include "AdjacencyList.h"
using namespace std;

int main()
{
    ///Abd-Allah
    Goal G(3,"Doing the phase","it's very nessesary","17/5/2016");
//  Goal G(4,"Discussiong of the project","very important","20/5/2016");
//  Goal G(5,"Final Exam","fulfil the success","23/5/2016");
    AdjacencyList L;
    L.Load();
    L.getPrerequisite(G);
    ///

///Islam Part
//
//#define oo 1e6
//
//struct Task
//{
//    int from ;
//    int to ;
//    string Taskname ;
//    double weight ;
//    friend istream& operator >> (istream &in,Task &t)
//    {
//        string str ;
//        getline(in,str);
//        t.from = atoi(str.c_str());
//        getline(in,str);
//        t.to = atoi(str.c_str());
//        getline(in,str);
//        t.Taskname = str ;
//        getline(in,str);
//        t.weight = atof(str.c_str());
//    }
//    friend ostream &operator << (ostream &out,Task &t)
//    {
//        out << t.Taskname << '\n';
//        out << t.from << '\t' << t.to << '\n';
//        out << t.weight << '\n';
//    }
//};
//
//Task Matrix[50][50];
//int path[50][50];
//
//void build_path(int src, int dest)
//{
//
//    if( path[src][dest] == -1 )//So this is the last way
//    {
//        cout << src << "->" << dest << "->";
//        return;
//    }
//    build_path( src, path[src][dest]);
//    build_path( path[src][dest], dest);
//}
//
//vector<int> p ;
//int main()
//{
//    Task t ;
//    ifstream f ;
//    f.open("p2.txt",ios::in);
//
//    memset(path,-1,sizeof(path));
//
//
//    cout << fixed ;
//    int n = 6 ;
//
//    for(int i =0; i<n; i++)
//    {
//        for(int j =0; j<n; j++)
//        {
//            Matrix[i][j].weight = oo ;
//        }
//    }
//
//    for(int j =0; j<n; j++)
//    {
//        Matrix[j][j].weight = 0 ;
//    }
//
//
//
//    while(true)
//    {
//        f >> t ;
//        if(f.fail())
//            break ;
//        Matrix[t.from-1][t.to-1].weight = -1*t.weight ;
//    }
//
//
//    cout << "Before\n";
//    for(int i = 0; i<n; i++)
//    {
//        for(int j= 0; j<n; j++)
//        {
//            cout << Matrix[i][j].weight << ' ';
//        }
//        cout << '\n';
//    }
//
//    cout << "After Floyed\n\n";
//    for(int k= 0 ; k<n ; k++)
//    {
//        for(int i =0; i<n; i++)
//        {
//            for(int j =0; j<n; j++)
//            {
//                if(Matrix[i][k].weight < oo && Matrix[k][j].weight <oo )
//                {
//                    if(Matrix[i][j].weight > Matrix[i][k].weight+Matrix[k][j].weight)
//                    {
//                        Matrix[i][j].weight = Matrix[i][k].weight + Matrix[k][j].weight ;
//                    }
//                    path[i][j] = k ;
//                }
//
//            }
//        }
//    }
//
//    build_path(0,6);
//
//    for(int i = 0; i<n; i++)
//    {
//        for(int j= 0; j<n; j++)
//        {
//            cout << Matrix[i][j].weight << ' ';
//        }
//        cout << '\n';
//    }
//
//    cout << "Critical path = "<< -1*Matrix[0][5].weight << '\n';
//
//    cout << "Path Matrix\n\n" ;
//    for(int i = 0; i<p.size(); i++)
//    {
//        cout << p[i] << ' ' ;
//    }
//
//    f.close();
//
//    return 0;
//}
///End Of Eslam Part


 /*   //Task TASKO ; //Phase1
    // TASKO.start(); //Phase1

    int choice ;
    fstream file("MyTasks.txt");

    /////////////////// Task 1(heap)

    cout << "Enter your choice :\n";
    cout << "1-Create a heap\n";
    cout << "2-Create BST\n";
    cout << "3-Create AVL\n";

    cin >> choice ;


    if(choice==1)
    {

        Heap<Task> hp ;
        file.seekg(0);
        Task t ;

        while(true)
        {
            file >> t ;
            if(file.fail())
                break;
            hp.add(t);
        }

        cout << hp ;
Hell:
        cout << "************************************************************\n";
        cout << "Enter your choice :\n";
        cout << "1-List tasks sorted by priority\n";
        cout << "2-search for task\n\n";
        cout << "************************************************************\n";
        cin >>choice ;
        if(1==choice)
        {
            vector<Task> v = hp.heapSort();// sorted tasks
            for(int i = 0 ; i<(int)v.size(); i++)
            {
                cout << v[i] << '\n' ;
            }
        }
        else if(2==choice)
        {
            cin.ignore();
            string key = "Data Structure" ;
            cout << "Enter task name : \n";
            getline(cin,key);
            cout << "*******************************************\n";
            cout << "Search function\n";
            cout << "*******************************************\n";
            Task t = hp.search(key) ;
            if(t.Name=="Not Found")
            {
                cout << "Mafesh task y3m\n";
            }
            else
            {
                cout << hp.search(key);
            }
            cout << "*******************************************\n";
            getchar();
        }
        else
        {
            goto Hell ;
        }
    }

    else if(choice==2)
    {
agin:

        cout << "Enter your choice\n\n";
        cout << "1-Sort by Name\n";
        cout << "2-Sort by Priority\n";

        cin >> choice ;

        if(choice!=1 && choice!=2)
            goto agin ;
        BSTFCI <Task> * bst = new BSTFCI<Task>();


        Task t1 ;
        file.seekg(0);
        Task t ;
        while(true)
        {
            t1.ReadTaskFromFile(file,t); // read task from a file
            if(file.fail())
                break;
            bst->insert (t,choice-1);
        }

        cout << "BST by Breadth First traverse\n";

        cout << "*************************************************\n";
        bst->breadthFirst(printKey);
        cout << "*************************************************\n";

        string taskName ;

        cin.ignore();

        cout << "search for task Name : \n";
        getline(cin,taskName);

        Task s = bst->search(taskName) ;
        if(s.Name=="Not Found")
        {
            cout << "*************************************************\n";
            cout << "Not Found\n";
            cout << "*************************************************\n";
        }
        else
        {
            cout << "*************************************************\n";
            cout << s ;
            cout << "*************************************************\n";

        }
        cout << "Are you want to remove top priority(y or n):\n";
        char c ;
        cin.get(c);
        if(c=='y' || c=='Y')
        {
            bst->RemoveTopPriority(choice-1);
            cout << "After remove top Priority\n";
        }
        bst->breadthFirst(printKey);

    }
    else if(choice==3)
    {
        cout << "Enter your choice\n\n";
        cout << "1-Sort by Name\n";
        cout << "2-Sort by Priority\n";
        cin >> choice ;
        AVLTree<Task> AVL ;
        file.seekg(0);
        Task t ,t1 ;
        while(true)
        {
            t1.ReadTaskFromFile(file,t); // read task from a file
            if(file.fail())
                break;

            AVL.insert(t,choice-1);
        }
        AVL.breadthFirst(printKey);
    }

*/
//Treap T;
//T.Insert("M");
//T.Insert("U");
//T.Insert("R");
//
//T.printInOrder();
//
//T.Remove("M");
//T.printInOrder();
    return 0 ;
}
