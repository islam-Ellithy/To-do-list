#include "Task.h"
#include <fstream>
#include <algorithm>
#include "FCISLL.cpp"

using namespace std;

Task::Task()
{
}

Task::~Task()
{

}


void Task::Initializer(Task &ts)
{
    ts.Name = "Not Found";
    ts.Description = "Not Found";
    ts.Date = "Not Found";
    ts.Duration = 0 ;
    ts.Priority = 0 ;
}

Task::Task(const Task& rhs)
{
    Name = rhs.Name ;
    Date = rhs.Date ;
    Description = rhs.Description ;
    Duration = rhs.Duration ;
    Priority = rhs.Priority ;
}

void Task::AddToFile(Task &T)
{
    ofstream file("MyTasks.txt",ios::out|ios::app);
    file << T ;
    file.close() ;
}


void Task::OrderedList()
{
    string path = "MyTasks.txt";

    fstream file(path,ios::in|ios::out|ios::app);
    FCISLL<Task> List ;
    file.seekg(0,ios::beg);
    while(true)
    {
        Task ts ;
        file >> ts ;
        if(file.fail())
            break ;
        if(!(List.GetHead()))//if head = null
        {
            cout << "Head\n";
            List.addToHead(ts);
            Task hd = List.head->data;
            cout << hd.Name << '\n';
        }
        else
        {
            Node<Task> *ptr  =  List.head ;
            Task Data = ptr->getData();
            int index = 0 ;
            while(ptr->getNext() != NULL)
            {
                cout << "File : " << ts.Name  << '\n';
                if(ts.Priority <= Data.Priority)
                {
                    cout << ts.Name << "\t\t" << Data.Name << '\n';
                    cout << ts.Priority << " <= "  << Data.Priority << '\n';
                    ++index ;
                    Data = ptr->getData() ;
                    ptr  = ptr->getNext() ;
                }
                break ;
            }
            cout << "index = " << index << '\n';
            if(index==0)
                List.addToHead(ts);
            else if(ptr->getNext()==NULL)
                List.addToTail(ts);
            else
                List.addToIndex(ts,index);
        }
    }
    file.close();

    file.open("MyTasks.txt",ios::out|ios::trunc);
    cout << List ;
    file << List ;
    List.Clear() ;
    cout << "After Remove\n";
    cout << List ;
    file.close();
}


Task& Task::operator = (const Task& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    Name = rhs.Name ;
    Date = rhs.Date ;
    Description = rhs.Description ;
    Duration = rhs.Duration ;
    Priority = rhs.Priority ;
    return *this ;
}

bool Task::operator < (const Task& rhs)
{
 /*
    cout<<"Enter the Criteria you want to compare with : \n";
    string s;
    cin>>s;
    if(s=="Duration")
        return Duration < rhs.Duration;
    else if(s=="Name")
        return Name < rhs.Name;
    else if(s=="Description")
        return Description < rhs.Description;
    else if(s=="Date")
        return Date < rhs.Date;
    else if(s=="Priority")
   */     return Priority < rhs.Priority;
}

bool Task::operator > (const Task& rhs)
{
/*    cout<<"Enter the Criteria you want to compare with : \n";
    string s;
    cin>>s;
    if(s=="Duration")
        return Duration > rhs.Duration;
    else if(s=="Name")
        return Name > rhs.Name;
    else if(s=="Description")
        return Description > rhs.Description;
    else if(s=="Date")
        return Date > rhs.Date;
    else if(s=="Priority")
  */
    return Priority > rhs.Priority;
}



istream & operator >> (istream &in ,Task &ts)
{
    if(in==cin)
    {
        cout << "Enter task name : ";
        getline(in,ts.Name,'\n') ;
        cout << "Enter task Description  : " ;
        getline(in,ts.Description,'\n') ;
        cout << "Enter task Priority : " ;
        in >> ts.Priority ;
        in.ignore();
        cout << "Enter task Date : " ;
        getline(in,ts.Date,'\n') ;
        cout << "Enter task duration : ";
        in >> ts.Duration ;
    }
    else
    {
        getline(in,ts.Name,'\n') ;
        getline(in,ts.Description,'\n');
        in >> ts.Priority ;
        in.ignore();
        getline(in ,ts.Date,'\n') ;
        in >> ts.Duration ;
        in.ignore();
    }
    return in;
}

ostream & operator << (ostream &out ,Task &ts)
{
    if(out==cout)
    {
        out << "Task Name : " << ts.Name << "\n";
        out << "Description : " << ts.Description << "\n";
        out << "Priority : " << ts.Priority << "\n" ;
        out <<  "Date : " << ts.Date << "\n";
        out << "Number of days : " << ts.Duration << "\n" ;
    }
    else
    {
        out << ts.Name << '\n';
        out << ts.Description << '\n';
        out << ts.Priority << '\n' ;
        out << ts.Date << '\n';
        out << ts.Duration << '\n';
    }
    return out;
}


istream & operator >> (istream &in ,Task &&obj)
{
    if(in==cin)
    {
        cout << "Enter task name : ";
        getline(in,obj.Name,'\n') ;
        cout << "Enter task Description  : " ;
        getline(in,obj.Description,'\n') ;
        cout << "Enter task Priority : " ;
        in >> obj.Priority ;
        cin.ignore();
        cout << "Enter task Date : " ;
        getline(in,obj.Date,'\n') ;
        cout << "Enter task duration : ";
        in >> obj.Duration ;
    }
    else
    {
        getline(in,obj.Name,'\n') ;
        getline(in,obj.Description,'\n') ;
        in >> obj.Priority ;
        cin.ignore();
        getline(in,obj.Date,'\n') ;
        in >> obj.Duration ;
    }
    return in;
}

ostream & operator << (ostream &out ,Task &&obj)
{
    if(out==cout)
    {
        out << "Task Name : " << obj.Name << "\n";
        out << "Description : " << obj.Description << "\n";
        out << "Priority : " << obj.Priority << "\n" ;
        out <<  "Date : " << obj.Date << "\n";
        out << "Number of days : " << obj.Duration << "\n\n" ;
        return out;
    }
    else
    {
        out << obj.Name << "\n";
        out << obj.Description << "\n";
        out << obj.Priority << "\n" ;
        out << obj.Date << "\n";
        out << obj.Duration << "\n" ;
        return out;
    }
}

void StrToint(string str,int &day,int &month,int &year)
{
    day = atoi((str.substr(0,2)).c_str());
    month = atoi((str.substr(3,2)).c_str());
    year = atoi((str.substr(6,4)).c_str()) ;
}

bool isPassed(Task &t)
{
    time_t now = time(0);
    tm *Itm=localtime(&now);
    int day , month , year ;
    int year1=1900+Itm->tm_year, month1=1+Itm->tm_mon, day1=Itm->tm_mday;
    StrToint(t.Date ,day , month , year);
    if (year1>year)
        return true;
    else if (year1<year)
        return false;
    else if(month1>month)
        return true;
    else if(month1<month)
        return false;
    else if (day1>day)
        return true;
    else if (day1<day)
        return false;
    else
        return true;
}

void Task::Start()
{
    Task NewTask , task ;
    char c ;
    printf("If you want to continue Enter 'y' else 'n' : ");
    while(cin >> c && c!='n')
    {
        cout << "Load (1) , Add(2) , Remove(3): " ;
        cin >> c ;
        cin.ignore();
        if(c=='1')
        {
            task.OrderedList();
        }
        else if(c=='2')
        {
            Task T ;
            cin >> T ;
            task.AddToFile(T);
            system("CLS");
        }
        else if(c=='3')
        {
            FCISLL<Task> *List = new FCISLL<Task>();
            int choice ;
            fstream file("MyTasks.txt",ios::in|ios::out);

            file.seekg(0,ios::beg);

            cout << *List ;

            while(true)
            {
                Task ts ;
                file >> ts ;// read a task from the file
                if(file.fail())
                    break ;
                file.ignore();
                List->addToTail(ts);
            }
            file.close();
            cout << *List ;
            cout << "if you want to Remove head(1) , tail(2) , index(3) , item(4) , predicate(5): ";
            cin >> choice ;
            switch(choice)
            {
            case 1 :
                List->removeHead();
                break;
            case 2 :
                List->removeTail();
                break ;
            case 3 :
                cout << "Enter index that you want to delete it : ";
                int ind ;
                cin >> ind ;
                List->removeFromIndex(ind);
                break ;
            case 4 :
                cout << "Enter item that you want to delete it : ";
                Task item ;

                cin.ignore();

                cout << "\n";
                cin >> item ;

                cin.ignore();

                List->removeItem(item);

                break ;
            }
            if(choice==5)
            {
                //cin.ignore();
                //Task t ;
                //cin >> t ;
                List->removePredicate(isPassed);
            }
            cout << "After remove\n";
            cout << *List ;
        }
        printf("If you want to continue Enter 'y' else 'n' : ");
    }
}


bool Task::orderByDuration(Task task1,Task task2)
{
    return task1.Duration < task2.Duration;
}

bool Task::orderByDate(Task task1,Task task2)
{
    return task1.Date < task2.Date;
}
