#ifndef UBST_H
#define UBST_H

#include "BSTNode.h"

class UnbalancedBST
{
  private:
    BSTNode *root;

  public:
    UnbalancedBST() : root(nullptr) {}
    UnbalancedBST(BSTNode *input) : root(input) {}
    BSTNode *GetRoot() { return root; }

  public:
    BSTNode *Find(int k);
    BSTNode *Find_min();
    BSTNode *Find_max();

    BSTNode *Next_larger(int k);
    BSTNode *Next_smaller(int k);

  public:
    void Insert(int k);
    BSTNode *Delete(int k);

  public:
    void InOrderTraverse(BSTNode *next);
    void InOrder();
};

#endif