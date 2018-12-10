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
  AVLNode() : key(-oo), parent(nullptr), left(nullptr), right(nullptr), height(0){};
  AVLNode(int k) : key(k), parent(nullptr), left(nullptr), right(nullptr), height(0){};

public:
  AVLNode *Find(int k);
  AVLNode *Find_min();
  AVLNode *Find_max();
  AVLNode *Next_larger();
  AVLNode *Next_smaller();
  AVLNode *Get_left() { return this->left; }
  AVLNode *Get_parent() { return this->parent; }
  AVLNode *Get_right() { return this->right; }

  int Get_key() { return this->key; }
  int Get_height() { return this->height; }

  void Set_left(AVLNode *input);
  void Set_parent(AVLNode *input);
  void Set_right(AVLNode *input);
  void Set_key(int k) { this->key = k; }
  void Set_height(int k) { this->height = k; }


public:
  void Insert(AVLNode *input);
  AVLNode *Delete();
};
#endif