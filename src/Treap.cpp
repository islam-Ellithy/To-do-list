#include "Treap.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;


Treap::Treap()
{
    root = NULL;
    counter = 0;
}

bool Treap::isEmpty()
{
    return root == NULL ;
}

int Treap::generateRandomNumber()
{
    srand(time(0));
    return rand()%10;
}

void Treap::Insert(string n)
{
    TreapNode* T=new TreapNode;
    T->data.Name=n;
    T->data.Priority = generateRandomNumber();
    T->right=NULL;
    T->left=NULL;
    T->Parent=NULL;

    if(isEmpty())
    {
        root = T;
        T->Parent = NULL;
        counter++;
    }
    else
    {
        TreapNode* curr=root;
        TreapNode* parent=NULL;
        while(curr!=NULL)
        {
            parent = curr;
            if(n>curr->data.Name)
                curr=curr->right;
            else if(n<curr->data.Name)
                curr=curr->left;
            else
                return ;
        }
        if(n>parent->data.Name)
        {
            parent->right=T;
            T->Parent = parent;
            counter++;
        }
        else
        {
            parent->left=T;
            T->Parent = parent;
            counter++;
        }
    }

    if(T->Parent != NULL)
    {
        while(T->data.Priority > T->Parent->data.Priority)
        {

            if(T->Parent->right == T)
            {
                RotateLeft(T->Parent);
            }
            else if(T->Parent->left == T)
            {
                RotateRight(T->Parent);
            }
            T = T->Parent;
        }
    }
}


bool Treap::Search(string n)
{
    if(isEmpty())
    {
        cout<<"The BST is empty!!"<<endl;
        return false;
    }
    else
    {
        TreapNode* parent=NULL;            /** to search the value exist or no **/
        TreapNode*curr=root;
        while(curr!=NULL)
        {
            if(curr->data.Name==n)
            {
                return true;
            }
            else
            {
                parent=curr;
                if(n>curr->data.Name)
                    curr=curr->right;
                else
                    curr=curr->left;
            }
        }
        return false;
    }
}

void Treap::Remove(string n)
{
    if(isEmpty())
    {
        cout<<"The BST is empty!!"<<endl;
        return;
    }
    else
    {
        TreapNode* parent=NULL;            /** to search the value exist or no **/
        TreapNode*curr=root;
        bool found=false;
        while(curr!=NULL)
        {
            if(curr->data.Name==n)
            {
                found=true;
                break;
            }
            else
            {
                parent=curr;
                if(n>curr->data.Name)
                    curr=curr->right;
                else
                    curr=curr->left;
            }
        }
        if(!found)
        {
            cout<<"This Name is not in the BST!!"<<endl;
            return;
        }
        else
        {
            while(curr->right != NULL && curr->left != NULL)
            {
                if(curr->right->data.Priority > curr->left->data.Priority)
                {
                    cout << "the balance of this node is "<<getBalance(curr)<<endl;
                    if(getBalance(curr->right) < 2)
                    {
                        cout << "the balance of this node->right "<<getBalance(curr->right)<<endl;
                        RotateLeft(curr);
                        cout <<"single rotation done! \n";
                    }
                    else
                    {
                        DoubleRotationToLeft(curr);
                        cout << "double rotation done! \n";
                    }
                }
                else
                {
                    cout << "the balance of this node is "<<getBalance(curr)<<endl;
                    if(getBalance(curr->left) < -2)
                    {
                        cout << "the balance of this node->left "<<getBalance(curr->left)<<endl;
                        RotateRight(curr);
                        cout <<"single rotation done! \n";
                    }
                    else
                    {
                        cout << "the balance of this node->right "<<getBalance(curr->right)<<endl;
                        DoubleRotationToRight(curr);
                        cout << "double rotation done! \n";
                    }
                }
            }
            if((curr->right == NULL && curr->left != NULL) || (curr->right != NULL && curr->left == NULL))
            {
                if(curr->right == NULL && curr->left != NULL)
                {
                    cout << "node->right == NULL && node->left != NULL \n";
                    cout << "balance of this node->left = " << getBalance(curr->left)<<endl;
                    if(getBalance(curr->left) > -2)
                    {
                        RotateRight(curr);
                        cout <<"single rotation done! \n";
                    }
                    else
                    {
                        DoubleRotationToRight(curr);
                        cout << "double rotation done! \n";
                    }
                    curr->Parent->right = NULL;
                    delete curr;
                    counter--;
                }
                else
                {
                    cout << "node->right != NULL && node->left == NULL \n";
                    cout << "balance of this node->right = " << getBalance(curr->right)<<endl;
                    if(getBalance(curr->right) < 2)
                    {
                        RotateLeft(curr);
                        cout << "single roatation done! \n";
                    }
                    else
                    {

                        DoubleRotationToLeft(curr);
                        cout <<"double rotation done! \n";
                    }
                    curr->Parent->left = NULL;
                    delete curr;
                    counter--;
                }
            }
            else if(curr->right == NULL && curr->left == NULL)
            {
                if(curr->Parent->right == curr)
                {
                    curr->Parent->right = NULL;
                }
                else if(curr->Parent->left == curr)
                {
                    curr->Parent->left = NULL;
                }
                delete curr;
                counter--;
            }
        }
    }
}


int Treap::Hieght(TreapNode* &root)
{
    if(root == NULL)
        return 0;

    return max(Hieght(root->left),Hieght(root->right)) + 1;

}



int Treap::getHieght()
{
    return Hieght(root);
}

int Treap::getBalance(TreapNode* &root)
{
    if(root->right == NULL && root->left == NULL)
        return 0;

    else if(root->right == NULL && root->left != NULL)
        return Hieght(root->left);

    else if(root->right != NULL && root->left == NULL)
        return -1 * Hieght(root->right);

    else
        return Hieght(root->left) - Hieght(root->right);
}


void Treap::RotateRight(TreapNode * &root)
{
    if(root == NULL || root->left == NULL)
    {
        cout << "ERROR OCCURED IN THE TREE \n";
        return;
    }
    TreapNode *p = root->left;
    root->left = p->right;
    p->right = root;
    p->Parent = root->Parent;
    if(root->Parent->right == root)
        root->Parent->right = p;
    else
        root->Parent->left = p;
    root->Parent = p;
}


void Treap::RotateLeft(TreapNode* &root)
{
    if(root == NULL || root->right == NULL)
    {
        cout << "ERROR OCCURED IN THE TREE \n";
        return;
    }
    TreapNode *p = root->right;
    root->right = p->left;
    p->left = root;
    p->Parent = root->Parent;
    if(root->Parent->right == root)
        root->Parent->right = p;
    else
        root->Parent->left = p;
    root->Parent = p;
}


void Treap::DoubleRotationToRight(TreapNode* &root)
{
    RotateLeft(root->left);
    RotateRight(root);
}



void Treap::DoubleRotationToLeft(TreapNode* &root)
{
    RotateRight(root->right);
    RotateLeft(root);
}



void Treap::balance(TreapNode* &root)
{
    if(root != NULL)
    {
        if(root->left)
        {
            balance(root->left);
            if(getBalance(root->left) > 1 && getBalance((root->left)->left) < -1)
            {
                DoubleRotationToRight(root->left);
            }
            else if(getBalance(root->left) < -1 && getBalance((root->left)->left) > 1)
            {
                DoubleRotationToLeft(root->left);
            }
            else if(getBalance(root->left) > 1)
            {
                RotateRight(root->left);
            }
            else if(getBalance(root->left) < -1)
            {
                RotateLeft(root->left);
            }

        }
        if(root->right)
        {
            balance(root->right);
            if(getBalance(root->right) > 1 && getBalance((root->right)->left) < -1)
            {
                DoubleRotationToLeft(root->right);
            }
            else if(getBalance(root->right) < -1 && getBalance((root->right)->right) > 1)
            {
                DoubleRotationToRight(root->right);
            }
            else if(getBalance(root->right) > 1)
            {
                RotateRight(root->right);
            }
            else if(getBalance(root->right) < -1)
            {
                RotateLeft(root->right);
            }
        }
    }
}


void Treap::Balance()
{
    balance(root);
}


void Treap::inOrder(TreapNode* root)
{
    if(root != NULL)
    {
        if(root->left)
            inOrder(root->left);
        cout << root->data <<endl;
        if(root->right)
            inOrder(root->right);
    }
}


void Treap::printInOrder()
{
    inOrder(root);
}


void Treap::preOrder(TreapNode* root)
{
    if(root != NULL)
    {
        cout << root->data <<endl;
        if(root->left)
            preOrder(root->left);
        if(root->right)
            preOrder(root->right);
    }
}

void Treap::printPreOrder()
{
    preOrder(root);
}



void Treap::postOrder(TreapNode* root)
{
    if(root != NULL)
    {
        if(root->left)
            postOrder(root->left);
        if(root->right)
            postOrder(root->right);
        cout << root->data <<endl;
    }
}

void Treap::printPostOrder()
{
    postOrder(root);
}


