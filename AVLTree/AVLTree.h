#ifndef AVLTREE_H
#define AVLTREE_H

#include "AVLNode.h"

class AVLTree
{
private:
  AVLNode *root;

public:
  AVLTree() : root(nullptr){};
  AVLTree(AVLNode *input) : root(input){};

public:
  AVLNode *Find(int k);
  AVLNode *Find_max();
  AVLNode *Find_min();
  AVLNode *Next_larger(int k);
  AVLNode *Next_smaller(int k);

  int Get_height(AVLNode *input);
  AVLNode* Get_root(){return root;}
  void reTrack(){if(root->Get_parent()) root = root->Get_parent();}

public:
  void Update_height(AVLNode *input);
  void Right_rotate(AVLNode *input);
  void Left_rotate(AVLNode *input);

public:
  void Insert(int k);
  AVLNode *Delete();
  void Rebalance(AVLNode *node);

public:
  void InOrder();
  void InOrderTraverse(AVLNode* input);
};

#endif