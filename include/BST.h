// File: FCIBST.cpp - Version 3 of a BST
// Author: Mohammad El-Ramly
// Date: 29 March 2013
// Version 3 - It has the following:
// 1- Node and BST declarations
// 2- clear, isEmpty, search and insert
// 3- Breadth first, inorder and Morris inorder traversal
// 4- Traversal algo take a fun: void visit (T&)

#include <iostream>
#include <queue>
#include <string>
#include "Task.h"
using namespace std;

#ifndef BST_H
#define BST_H

template <class T>
class BSTNode       // A generic node with 2 pointers
{
public:
    T key;
    BSTNode<T>* left;
    BSTNode<T>* right;
    void Initializer(Task &ts)
    {
        ts.Name = "Not Found";
        ts.Description = "Not Found";
        ts.Date = "Not Found";
        ts.Duration = 0 ;
        ts.Priority = 0 ;
    }

    BSTNode<T> ()
    {
        left = right = NULL;
    }
    BSTNode<T> (T& el, BSTNode* l = NULL, BSTNode* r = NULL)
    {
        key   = el;
        left  = l;
        right = r;
    }
    BSTNode<T>* getLeft()
    {
        return left;
    }
    BSTNode<T>* getRight()
    {
        return right;
    }
    void setLeft(BSTNode<T>* l)
    {
        left = l;
    }
    void setRight(BSTNode<T>* r)
    {
        right = r;
    }
    T& getKey()
    {
        return key;
    }
};


template <class T>
class BSTFCI        // Generic binary search tree
{
protected:
    BSTNode<Task>* root;
    void inorder (BSTNode<Task>* p, Task &t);
    void inorder(BSTNode<Task>* p,string el,Task &t);

public:
    int cnt = 0 ;
    BSTFCI<T> ()
    {
        root = NULL;
    }
    void clear()
    {
        root = NULL;   // Dangerous - does not avoid memory leak
    }
    bool isEmpty()
    {
        return root == NULL;
    }
    Task search (string el);
    void insert (Task el,bool SortType);//sortType 0 for name & 1 for priority
    void remove( Task &data,BSTNode<Task> *& root,bool st);
    void remove( Task &data,bool st);
    void breadthFirst (void (*visit)(T&));
    void inorder (Task &t);
    void inorderMorris (void (*visit)(T&));
    void RemoveTopPriority(bool);
    BSTNode<Task> *findMin(BSTNode<Task>* t)
    {
        if(t == NULL)
            return NULL ;
        else if(t->left == NULL)
            return t ;
        else
            return findMin(t->left);
    }

    BSTNode<Task> *findMax(BSTNode<Task>* t)
    {
        if(t != NULL)
            while(t->getRight() != NULL)
                t = t->getRight() ;
        return t ;
    }

};

///////////////////////////////////////////////////////////
template <class T>
void BSTFCI<T>::remove( Task &data , bool SortType)
{
    return remove(data,root,SortType);
}

template <class T>
void BSTFCI<T>::remove( Task &data,BSTNode<Task>  *& root,bool SortType)
{
    cnt++ ;
    if(SortType==0)
    {
        if(root==NULL)
            return ;// do nothing
        else if((data.Name).compare(root->getKey().Name)>0)
            remove(data,root->right,SortType);
        else if(data.Name.compare(root->getKey().Name)<0)
            remove(data,root->left,SortType);
        else if(root->getRight()!=NULL && root->getLeft()!=NULL) // two childs
        {
            BSTNode<Task> * f = findMin(root->right) ;
            root->key = f->getKey() ;
            remove(data,root->right,SortType);
        }
        else
        {
            BSTNode<Task> *oldNode  = root ;
            root = ( root->getLeft() != NULL) ? root->getLeft() : root->getRight() ;
            delete oldNode ;
        }
    }
    else if(SortType==1) // priority
    {
        if(root==NULL)
            return ;// do nothing
        else if(data.Priority > (root->getKey().Priority))
            remove(data,root->right,SortType);
        else if(data.Priority < (root->getKey().Priority))
            remove(data,root->left,SortType);
        else if(root->getRight()!=NULL && root->getLeft()!=NULL) // two childs
        {
            BSTNode<Task> * f = findMin(root->right) ;
            root->key = f->getKey() ;
            remove(data,root->right,SortType);
        }
        else
        {
            BSTNode<Task> *oldNode  = root ;
            root = ( root->getLeft() != NULL) ? root->getLeft() : root->getRight() ;
            delete oldNode ;
        }
    }
}

//////////////////////////////////////////////
template <class T>
void BSTFCI<T>::insert (Task el,bool SortType)//sortType 0 for name & 1 for priority
{
    BSTNode<Task>* p = root, *prev = NULL;

    if(SortType==0)// Sort by Name
    {
        while (p != NULL)           // Move till correct position
        {
            cnt++ ;

            prev = p ;
            if ((el.Name).compare(p->getKey().Name) > 0)  // Found it
                p = p->getRight();
            else
                p = p->getLeft();
        }
        cnt++ ;
        if (root == NULL)           // If no tree, this is first node
            root = new BSTNode<Task>(el);

        else if ((prev->getKey().Name).compare(el.Name) < 0)   // Insert right
            prev->setRight(new BSTNode<Task>(el));
        else                            // Insert left
            prev->setLeft(new BSTNode<Task>(el));
    }
    else if(SortType==1)//Sort by priority
    {
        while (p != NULL)           // Move till correct position
        {
            cnt++ ;
            prev = p;
            if ((el.Priority)  >  (p->getKey().Priority))  // Found it
                p = p->getRight();
            else
                p = p->getLeft();
        }
        cnt++ ;
        if (root == NULL)           // If no tree, this is first node
            root = new BSTNode<Task>(el);

        else if ((prev->getKey().Priority) < (el.Priority))   // Insert right
            prev->setRight(new BSTNode<Task>(el));
        else                            // Insert left
            prev->setLeft(new BSTNode<Task>(el));
    }
}

//////////////////////////////////////////////
template <class T>

void BSTFCI<T>::RemoveTopPriority(bool sortType)
{
    Task top_P ;

    cout << "**********************************************************\n";

    inorder(root , top_P);

    cout << "Top Priority\n";
    cout << "**********************************************************\n";
    cout << top_P << '\n'  ;
    cout << "**********************************************************\n";

    remove(top_P,sortType);

}


//////////////////////////////////////////////
template <class T>
Task BSTFCI<T>::search (string el)
{
    BSTNode<Task>* p = root;

    Task t ;
    inorder(p,el,t);

    if(t.Name!=el)
        t.Initializer(t);

    return t;               // NOT found
}
//////////////////////////////////////////////
template <class T>
void BSTFCI<T>::breadthFirst(void (*visit)(T&))
{
    queue<BSTNode<T>* > q ;
    BSTNode<T>* p = root;
    if (p != NULL)
    {
        q.push (p);
        while (!q.empty())
        {
            cnt++ ;
            p = q.front();
            q.pop();
            visit(p->getKey());
            if (p->getLeft() != NULL)
                q.push(p->getLeft());
            if (p->getRight() != NULL)
                q.push(p->getRight());
        }
        cout << endl;
    }
    cnt++ ;

}


//////////////////////////////////////////////

template <class T>
void BSTFCI<T>::inorder (BSTNode<Task>* p, Task &t)
{
    if (p == NULL)
        return;
    inorder (p->getLeft() , t);

    if(t.Priority < p->getKey().Priority)
    {
        t = p->getKey();
    }

    inorder (p->getRight() ,t);
}

template <class T>
void BSTFCI<T>::inorder(BSTNode<Task>* p,string el,Task &t)
{
    if (p == NULL)
        return;
    inorder(p->getLeft(),el,t);
    if((p->getKey().Name).compare(el)==0)
    {
        t = p->getKey();
    }
    inorder(p->getRight(),el,t);
}

//////////////////////////////////////////////
template <class T>
void BSTFCI<T>::inorder (Task &t)
{
    inorder (root, t);
}

//////////////////////////////////////////////
// VERY IMPORTANT: Read the details in the book
template <class T>
void BSTFCI<T>::inorderMorris (void (*visit)(T&))
{
    BSTNode<T>* p = root;
    while (p != NULL)
    {
        BSTNode<T>* tmp = p->getLeft();
        if (tmp == NULL)
        {
            visit (p->getKey());
            p = p-> getRight();
        }
        else
        {
            while (tmp->getRight() != NULL && tmp->getRight() != p)
                tmp = tmp->getRight();
            if (tmp->getRight() == NULL)
            {
                tmp->setRight(p);
                p = p->getLeft();
            }
            else
            {
                visit (p->getKey());
                tmp->setRight(NULL);
                p = p->getRight();
            }
        }
    }
}

//////////////////////////////////////////////
template <class T>
void printKey (T& key)
{
    cout << "*********************************************\n";
    cout << key << "\n" ;
    cout << "*********************************************\n";
}
template <class T>
void times2 (T& key)
{
    key *=2;
}
//////////////////////////////////////////////

#endif // BST_H
