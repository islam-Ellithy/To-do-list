// Program: FCISLL is a generic single linked list
//          Developed for CS214 Data Structures
//          at FCI, Cairo University
// Author:  Mohammad El-Ramly, 8 Mar. 2013

#ifndef FCISLL_H_
#define FCISLL_H_
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

template <class T>
class Node
{
protected:
    Node<T>* next;     // to hold pointer to next item
    Node<T>* prev;     // to hold pointer for previous item
    int   count;
public:
    T     data;        // to hold generic data of type T
    Node ()
    {
        next = prev = NULL;
        count = 0;
    }

    Node (T dataItem, Node<T>* nextPtr = NULL, Node<T>* prevPtr = NULL)
    {
        data = dataItem;
        next = nextPtr;
        prev = prevPtr;
    }
    Node<T>* getNext ()
    {
        return next;
    }
    void setNext(Node<T>* ptr)
    {
        next = ptr;
    }
    Node<T>* getPrev ()
    {
        return prev;
    }
    void setPrev(Node<T>* ptr)
    {
        prev = ptr;
    }
    T  getData ()
    {
        return data;
    }
    void setData (T dataItem)
    {
        data = dataItem;
    }
    template <class TT>
    friend ostream& operator<< (ostream& out, Node<TT> &n);
};

/////////////////////////////
template <class T>
class FCISLL
{
private:
public:
    Node<T> *head, *tail;

    class Task ;
    FCISLL()
    {
        head = NULL;
        tail = NULL;
    }
    void setTail(Node<T>*last)
    {
        tail->setNext(nullptr);
    }
    ~FCISLL ();
    bool IsEmpty()
    {
        return ((head==nullptr)?1:0);
    }
    Node<T> *GetHead()
    {
        return head ;
    }
    Node<T> *GetTail()
    {
        return tail ;
    }
    void Clear();
    T  removeHead();
    T  removeTail();
    T  removeItem(T Item);
    T  removeFromIndex(int i);
    bool isPassed(Task &t);
    void removePredicate(bool (*predicate)(T &Item));
    void StrToint(string str, int &day, int &month, int &year);

    void addToHead(T item);
    void addToTail(T item);
    void addToIndex(T item, int index);
    void InsertOrdered(T item);
    bool search (T item);
    template <class TT>
    friend ostream& operator<<(ostream&, FCISLL<TT>&);

    //////////////////////////////////////
    void Swap(Node<T>* task1,Node<T>* task2);
    void BubbleSort(bool(Task::*fun)(Node<T>* task1,Node<T>* task2),int order);
    FCISLL<T> mergeTwoLists(FCISLL listOne,FCISLL listTwo);
};
//////////////////////////////
#endif
