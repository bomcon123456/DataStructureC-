#ifndef AVLNODE_H
#define AVLNODE_H
#include <iostream>
#define oo 1e9
using namespace std;

class AVLNode
{
  private:
    int key;
    AVLNode *left;
    AVLNode *right;
    AVLNode *parent;
    int height;

  public:
    AVLNode() : key(-oo), left(nullptr), right(nullptr), height(0){};
    AVLNode(int k) : key(k), left(nullptr), right(nullptr), height(0){};

  public:
    AVLNode *Find(AVLNode *input);
    AVLNode *Find_min();
    AVLNode *Find_max();
    AVLNode *Next_larger();
    AVLNode *Next_smaller();

  public:
    void Insert(AVLNode *input);
    AVLNode *Delete();
};
#endif