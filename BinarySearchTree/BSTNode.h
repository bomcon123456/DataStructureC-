#ifndef BSTNODE_H
#define BSTNODE_H

#include <iostream>
#define oo 1e9

using namespace std;

class BSTNode
{
private:
  int key;
  BSTNode *parent;
  BSTNode *left;
  BSTNode *right;

public:
  BSTNode() : key(-oo), parent(nullptr), left(nullptr), right(nullptr) {}
  BSTNode(int k) : key(k), parent(nullptr), left(nullptr), right(nullptr) {}

public:
  BSTNode *Find(int k);
  BSTNode *Find_min();
  BSTNode *Find_max();
  BSTNode *Next_larger();
  BSTNode *Next_smaller();

  bool isLeaf();

public:
  void SetLeft(BSTNode *input) { this->left = input; };
  void SetParent(BSTNode *input) { this->parent = input; };
  void SetRight(BSTNode *input) { this->right = input; };
  void SetKey(int k) { this->key = k; };
  BSTNode *GetLeft() { return this->left; };
  BSTNode *GetParent() { return this->parent; };
  BSTNode *GetRight() { return this->right; };
  int GetKey() { return this->key; };

public:
  bool Insert(BSTNode *input);
  BSTNode *Delete();
};

#endif