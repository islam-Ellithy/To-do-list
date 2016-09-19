#ifndef TREAP_H_INCLUDED
#define TREAP_H_INCLUDED
#include <iostream>
#include "Task.h"
using namespace std;


class Treap
{
   private:
       struct TreapNode
       {
           TreapNode* right;
           TreapNode* left;
           TreapNode* Parent;
           Task data;
       };
       TreapNode* root;
       int counter;


       void inOrder(TreapNode *root);
       void preOrder(TreapNode *root);
       void postOrder(TreapNode *root);

   public:
       Treap();
       bool isEmpty();
       void Insert(string value);
       bool Search(string n);
       void Remove(string n);
       int Hieght(TreapNode* &root);
       int getHieght();
       int getBalance(TreapNode* &root);
       void RotateRight(TreapNode* &root);
       void RotateLeft(TreapNode* &root);
       void DoubleRotationToRight(TreapNode* &root);
       void DoubleRotationToLeft(TreapNode* &root);
       void balance(TreapNode* &root);
       void Balance();
       void printInOrder();
       void printPreOrder();
       void printPostOrder();
       int generateRandomNumber();


};

#endif // TREAP_H_INCLUDED
