// Program: FCISLL is a generic single linked list
//          Developed for CS214 Data Structures
//          at FCI, Cairo University
// Author:  Mohammad El-Ramly, 8 Mar. 2013
// Link: http://www.mathcs.duq.edu/drozdek/DSinCpp/
#include <iostream>

#include "FCISLL.h"
#include <ctime>
using namespace std;

template <class T>
ostream& operator<< (ostream& out, Node<T> &node)
{
    out << node.getData() ;
    return out;
}

template <class T>
void FCISLL<T>::Clear()
{
    Node<T> *ptr ;
    int c =  0 ;
    while(head)
    {
        ptr = head ;
        head = ptr->getNext() ;
        delete ptr ;
    }
}

////////////////////////////////
template <class T>
void FCISLL<T>::addToTail(T item)
{
    Node<T>* ptr = new Node<T>(item, NULL, tail);
    if (head == NULL)
        head = tail = ptr;
    else
    {
        tail->setNext(ptr);
        tail = ptr;
    }
}

template <class T>
void FCISLL<T>::addToHead(T item)
{
    Node<T>* ptr = new Node<T>(item, head, NULL);
    if (head==NULL)
        head=tail=ptr;
    else
    {
        head->setPrev(ptr);
        head=ptr;
    }
    if (tail == NULL)
        tail = ptr;
}


template <class T>
FCISLL<T>::~FCISLL () {}

template <class T>
void FCISLL<T>::addToIndex(T item, int index)
{
    if (index==0)
    {
        addToHead(item);
        return;
    }


    Node<T>* nPtr = new Node<T>(item, NULL);
    Node<T>* pPtr = head;
    for (int i = 0; pPtr!= 0 && i < index-1; i++)
        pPtr = pPtr->getNext();

    if (pPtr->getNext() != 0 && index > 0)
    {
        nPtr->setNext(pPtr->getNext());
        nPtr->setPrev(pPtr);
        pPtr->setNext(nPtr);
        nPtr->getNext()->setPrev(nPtr);
    }
    else if (pPtr->getNext()==NULL)
        addToTail(item);
    else if (pPtr==NULL)
        cout << "Invalid position.\n";
}

template <class T>
bool FCISLL<T>::search(T item)
{
    Node<T>* ptr = head;
    while (! (ptr == NULL) && item != ptr->getData())
        ptr = ptr -> getNext();
    if (ptr != NULL)
        return true;
    else
        return false;
}

template <class T>
T FCISLL<T>::removeHead()
{

//    Task t;
    if(head==NULL)
    {
        cout << "Linked List is empty.\n";
        T t;
        return t;
    }
    Node<T> *ptr= head;
    head=head->getNext();
    T l=ptr->getData();
    delete  ptr;
    return l;
}
template <class T>
T FCISLL<T>::removeTail()
{
    if(tail==NULL)//{
        cout << "Linked List is empty.\n";
    // return ;}
    if (tail->getPrev()!=NULL)
    {
        Node<T> *ptr=tail;
        ptr=ptr->getPrev();
        tail=ptr;
        return ptr->getData();
    }
    else
        removeHead();
}

template <class T>
T FCISLL<T>::removeItem(T Item)
{
    Node<T> *ptr=head;
    Node<T> *ptr1=tail;

    if(ptr==NULL)
    {
        cout << "Linked List is empty.\n";
        //    return ;
    }

    if (head->getNext()==NULL && head==tail)
        removeTail();
    while (ptr!=NULL && ptr->getData()!=Item)
        ptr=ptr->getNext();

    if (ptr==ptr1)
        removeTail();
    else if (ptr==head)
        removeHead();
    else if (ptr==NULL)
        cout << "Invalid item.\n";
    else
    {
        ptr->getNext()->setPrev(ptr->getPrev());
        ptr->getPrev()->setNext(ptr->getNext());
        return ptr->getData();
    }
}

template <class T>
T FCISLL<T>::removeFromIndex(int i)
{
    int index=0;
    Node<T> *ptr=head;
    Node<T> *ptr1=tail;
    if(ptr==NULL)
        cout << "Linked List is empty.\n";
    while (ptr!=NULL && index<i)
    {
        ptr=ptr->getNext();
        index++;
    }

    if (ptr==ptr1)
        removeTail();
    else if (ptr==head)
        removeHead();
    else if (ptr==NULL)
        cout << "Invalid index.\n";
    else
    {
        ptr->getNext()->setPrev(ptr->getPrev());
        ptr->getPrev()->setNext(ptr->getNext());
        return ptr->getData();
    }
}

template <class T>
void FCISLL<T>::removePredicate(bool (*predicate)(T &Item))
{
    Node<T> *ptr=head;
    while (ptr!=NULL)
    {
        T x=ptr->getData();
        if (predicate(x))
            removeItem(x);
        ptr=ptr->getNext();
    }
}



template<class T>
void FCISLL<T>::InsertOrdered(T item)
{
    Node<T> * newnode = new Node<T>(item,nullptr);
    Node<T> *ptr  = head ;
    int i = 0 ;
    if(head==nullptr)
    {
        addToHead(item);
    }
    else
    {
        while(ptr && item < ptr->getData())
        {
            i++ ;
            ptr = ptr->getNext();
        }
        addToIndex(item,i);
    }
}


template <class T>
ostream& operator<<
(ostream& stream, FCISLL<T> &list)
{
    if (list.head != 0)
    {
        Node<T>* ptr = list.head;
        stream << *ptr;
        while (ptr != list.tail)
        {
            ptr = ptr->getNext();
            stream << *ptr;
        }
        //stream << "\n" ;
    }
    return stream;
}

////////////////////////////////////////////////////// Abdalla

template <class T>
void FCISLL<T>::Swap(Node<T>* task1,Node<T>* task2)
{
    if(task1==task2)
        return;
    if(task1==NULL || task2==NULL)
    {
        cout<<"this task is not exist here !! \n";
        return;
    }
    Node<T>* temp;
    temp->setPrev(task1->getPrev());
    temp->setNext(task1->getNext());

    task1->setPrev(task2->getPrev());
    task1->setNext(task2->getNext());

    task2->setPrev(temp->getPrev());
    task2->setNext(task2->getNext());

    delete temp;
}

template <class T>
void FCISLL<T>::BubbleSort(bool(Task::*fun)(Node<T>* task1,Node<T>* task2),int order)
{
    Node<T>*first;
    Node<T>*second;
    if(order==1)
    {
        for(first = head,second =head->next ; first!=NULL && second!=NULL ; first=first->next,second=second->next)
        {
            for(first = head,second =head->next ; first!=NULL && second!=NULL ; first=first->next,second=second->next)
            {
                if(this->*fun(first,second)==1)
                    Swap(first,second);
            }
        }
    }
    else
    {
        for(first = head,second =head->next ; first!=NULL && second!=NULL ; first=first->next,second=second->next)
        {
            for(first = head,second =head->next ; first!=NULL && second!=NULL ; first=first->next,second=second->next)
            {
                if(this->*fun(first,second)==0)
                    Swap(first,second);
            }
        }
    }
}


template <class T>
FCISLL<T> FCISLL<T>::mergeTwoLists(FCISLL listOne,FCISLL listTwo)
{
   Node<T>* ptr=listTwo;
   while(ptr!=NULL){
      listOne.InsertOrdered(ptr->data);
      ptr = ptr->next;
   }
   return listOne;
}
