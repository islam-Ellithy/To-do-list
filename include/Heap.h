#include<Task.h>
#include <vector>
#ifndef HEAP_H
#define HEAP_H

template <class T>
class Heap
{
private:
    vector<T> heapElements ; 	// Pointer to array of heap items
public:
//    class Task ;
    Heap	();			// Create empty heap
    Heap(vector<T>heapElements, int size) ; // done
    Heap(const Heap<T> &hp);
    Task Initializer(Task ts);
    void  Print();
    int left(int node);
    int right(int node);
    int parent(int node);
    void ShiftDown(int i);
    void ShiftUp(int i);
    int size()
    {
        return heapElements.size();
    }
    void add(T elem);	// Add item at end & sift-up
    T 	removeRoot();	// Return top item & reheap
    Task search (string taskName);	// find task by name
    vector<T> heapSort();	// Return items sorted by priority
    friend ostream &operator << (ostream &out,Heap &hp)
    {
        out << "Elements of heap\n\n";
        for(int i = 0 ; i< hp.size(); i++)
        {
            out << hp.heapElements[i] << '\n';
            out << "****************************************************\n";
        }
        return out ;
    }
    T operator [](int i)
    {
        return heapElements[i] ;
    }
};

#endif // HEAP_H

template<class T>
Heap<T>::Heap() // done
{

}

template<class T>
Heap<T>::Heap(const Heap<T> &hp)
{
    heapElements = hp.heapElements ;
}

template<class T>
int Heap<T>::left(int node)
{
    int lf = 2*node+1 ;
    return lf> size() ?-1:lf;
}

template<class T>
int Heap<T>::right(int node)
{
    int rt = 2*node+2 ;
    return rt>  size()  ?-1:rt;
}

template<class T>
int Heap<T>::parent(int node)
{
    return node==0 ? -1 : (node-1)/2 ;
}

template<class T>
Heap<T>::Heap(vector<T> v , int size) // done
{
    for(int i = 0 ; i< v.size(); i++)
    {
        heapElements[i] = v[i];
    }
}


template<class T>
void Heap<T>::add(T elem)	// Add item at end & shift-up
{
    heapElements.push_back(elem);
    ShiftUp(size()-1);
}

template<class T>
void Heap<T>::ShiftUp(int i)
{
    if(i==0 || heapElements[parent(i)] > heapElements[i])
    {
        return ;
    }

    swap(heapElements[i],heapElements[parent(i)]);

    ShiftUp(parent(i));
}

template<class T>
void Heap<T>::ShiftDown(int i)
{
    int selChild = left(i);

    if(selChild==-1)// left not found then no childs for this node
        return ;

    int rightChild = right(i);

    if(rightChild !=-1 && heapElements[rightChild] > heapElements[selChild])// right greater
    {
        selChild = right(i);// max child
    }

    if(heapElements[i]  <  heapElements[selChild])
    {
        swap(heapElements[i],heapElements[selChild]);
        ShiftDown(selChild);
    }
}


template<class T>
T Heap<T>::removeRoot()// Return top item & reheap
{

    if(size())
    {
        T top = heapElements.front();

        heapElements[0]= heapElements.back();

        heapElements.pop_back();

        ShiftDown(0);

        return  top ;
    }
}

template<class T>
void Heap<T>::Print()
{
    cout << "*******************************************\n";
    cout << "Size of Heap Data = " << size() << "\n";
    cout << "*******************************************\n";

    for(int i = 0 ; i< size(); i++)
    {
        cout << heapElements[i] << '\n' ;
        cout << "*******************************************\n";
    }
    cout << '\n';
}


template<class T>
Task Heap<T>::search(string taskName)// find task by name
{
    Task ts ;

    for(int i = 0 ; i<size(); i++)
    {
        ts = heapElements[i];
        if(taskName==ts.Name)
        {
            return ts ;
        }
    }
    ts.Initializer(ts);
    return ts;

}


template<class T>
vector<T> Heap<T>::heapSort()// Return items sorted by priority
{
    int heapSize = size() ;
    vector<T> temp = heapElements ,  hp = heapElements ;
    for (int i=0; i<heapSize; i++)
    {
        // Move current root to end
        temp[i]=removeRoot();
    }

    heapElements = hp ;

    return temp ;
}
