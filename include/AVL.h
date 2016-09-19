#include "BST.h"
#include <bits/stdc++.h>
using namespace std;

#ifndef AVL_H
#define AVL_H

template<class T>
class AVLNode
{
public:
    AVLNode *left ;
    AVLNode *right ;
    int height ;
    T data ;
    AVLNode()
    {
        right = left = NULL ;
        height = 1;
    }
    AVLNode(AVLNode* l , AVLNode* r , T data)
    {
        this->left  = l ;
        this->right = r ;
        this->data = data ;
        height = 1 ;
    }
    AVLNode(T data)
    {
        this->data = data ;
        this->right = this->left = NULL ;
        height = 1;
    }
};

template<class T>
class AVLTree
{
private :
    AVLNode<T> *root;
public :
    AVLTree()
    {
        root =nullptr ;
    }
    int height(AVLNode<T> *p)
    {
        if(p==nullptr)
        {
            return -1 ;
        }
        int hl = height(p->left);
        int hr = height(p->right);
        return 1 + max(hl,hr);
    }

    int bfactor(AVLNode<T> *p)
    {
        return height(p->left)-height(p->right);
    }


    void Balance(AVLNode<Task>* p)
    {
        p->height = height(p);

        if(bfactor(p)==2)
        {

            if(bfactor(p->left)<0)
                doubleWithLeft(p);
            else
                RightRotation(p);
        }
        else if (bfactor(p)==-2)
        {
            if(bfactor(p->right)>0)
                doubleWithRight(p);
            else
                LeftRotation(p);
        }

    }

    void insert (Task el,bool SortType)//sortType 0 for name & 1 for priority
    {
        AVLNode<Task>* p ;
        p = root ;//*
        AVLNode<Task> *prev = NULL;

        if(SortType==0)// Sort by Name
        {
            while (p != NULL)           // Move till correct position
            {
                prev = p;
                if ((el.Name).compare(p->data.Name) > 0 )  // Found it
                    p = p->right;
                else
                    p = p->left;
            }

            if (root == NULL)           // If no tree, this is first node
                root = new AVLNode<Task>(el);

            else if ((prev->data.Name).compare(el.Name) < 0)   // Insert right
            {

                prev->right = new AVLNode<Task>(el);
                Balance(prev->right);
            }
            else                            // Insert left
            {

                prev->left = new AVLNode<Task>(el);
                Balance(prev->left);
            }
        }
        else if(SortType==1)//Sort by priority
        {
            while (p != NULL)           // Move till correct position
            {
                prev = p;
                if ((el.Priority)  >  (p->data.Priority))  // Found it
                    p = p->right;
                else
                    p = p->left;
            }
            if (root == NULL)           // If no tree, this is first node
                root = new AVLNode<Task>(el);

            else if ((prev->data.Priority) < (el.Priority))   // Insert right
                prev->right = new AVLNode<Task>(el);
            else                            // Insert left
                prev->left = new AVLNode<Task>(el);
        }
    }

    AVLNode<T> *findMin(AVLNode<T>* t)
    {
        if(t == NULL)
            return NULL ;
        else if(t->left == NULL)
            return t ;
        else
            return findMin(t->left);
    }

    AVLNode<T> *findMax(AVLNode<T>* t)
    {
        if(t != NULL)
            while(t->right != NULL)
                t = t->right ;
        return t ;
    }

    void remove(const Task &data)
    {
        return remove(data,root);
    }

    void remove(const Task &data,AVLNode<Task>  *& root,bool SortType)
    {
        if(SortType==0)     //remove by name
        {
            if(root==NULL)
                return ;// do nothing
            else if(data.Name.compare(root->data.Name)>0)
                remove(data,root->right,SortType);
            else if((data.Name).compare(root->data.Name)<0)
                remove(data,root->left,SortType);
            else if(root->right!=NULL && root->left!=NULL) // two childs
            {
                root->data = findMin(root->right).data ;
                remove(data,root->right,SortType);
            }
            else
            {
                AVLNode<T> *oldNode  = root ;
                root = ( root->left != NULL) ? root->left : root->right ;
                delete oldNode ;
            }
        }
        else if(SortType==1)
        {
            if(root==NULL)
                return ;// do nothing
            else if(data.Priority > root->data.Priority)
                remove(data,root->right,SortType);
            else if(data.Priority < root->data.Priority )
                remove(data,root->left,SortType);
            else if(root->right!=NULL && root->left!=NULL) // two childs
            {
                root->data = findMin(root->right).data ;
                remove(data,root->right,SortType);
            }
            else
            {
                AVLNode<Task> *oldNode  = root ;
                root = ( root->left != NULL) ? root->left : root->right ;
                delete oldNode ;
            }
        }
    }
    void printKey (T& key)
    {
        cout << "*********************************************\n";
        cout << key << "\n" ;
        cout << "*********************************************\n";
    }

    void breadthFirst(void (*visit)(T&))
    {
        queue<AVLNode<T>* > q ;
        AVLNode<T>* p = root;
        if (p != NULL)
        {
            q.push (p);
            while (!q.empty())
            {
                p = q.front();
                q.pop();
                visit(p->data);
                if (p->left != NULL)
                    q.push(p->left);
                if (p->right != NULL)
                    q.push(p->right);
            }
            cout << endl;
        }
    }

    void clear(AVLNode<T> *& t)
    {
        if(t!=NULL)
        {
            clear(t->left);
            clear(t->right);
            delete t ;
        }
        t = NULL ;
    }

    ~AVLTree()
    {
        clear(root);
    }

    void LeftRotation(AVLNode<T> *& p) // single
    {
        AVLNode<T> * q = p->right ;
        q->left = p ;
        p->right = q->left ;
        p->height = height(p);
        q->height = height(q);
    }
    void RightRotation(AVLNode<T> *& p) // single
    {
        AVLNode<T> *q = p->left ;
        q->right = p ;
        p->left = q->right ;
        p->height = height(p);
        q->height = height(q);
    }


    void doubleWithLeft(AVLNode<T> *& p)// left right
    {
        LeftRotation(p->left);
        RightRotation(p);
    }

    void doubleWithRight(AVLNode<T> *& p)// right left
    {
        RightRotation(p->right);
        LeftRotation(p);
    }

    void inorder (BSTNode<T>* p, void (*visit)(T&))
    {
        if (p == NULL)
            return;
        inorder (p->getLeft(), visit);
        visit (p->getKey());
        inorder (p->getRight(), visit);
    }

//////////////////////////////////////////////
    void inorder (void (*visit)(T&))
    {
        inorder (root, visit);
    }

//////////////////////////////////////////////
// VERY IMPORTANT: Read the details in the book
    void inorderMorris (void (*visit)(T&))
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
};

#endif // AVL_H
