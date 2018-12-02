#include "BSTNode.h"

BSTNode *BSTNode::Find(int k)
{
    if (this->key == k)
    {
        return this;
    }
    else if (this->key > k)
    {
        if (!this->left)
        {
            cout << "Doesn't have node containing this key." << endl;
            return nullptr;
        }
        else
        {
            return this->left->Find(k);
        }
    }
    else if (this->key < k)
    {
        if (!this->right)
        {
            cout << "Doesn't have node containing this key." << endl;
            return nullptr;
        }
        else
        {
            return this->right->Find(k);
        }
    }
    return nullptr;
}

BSTNode *BSTNode::Find_min()
{
    BSTNode *cur = this;
    while (cur->left)
    {
        cur = cur->left;
    }
    return cur;
}

BSTNode *BSTNode::Find_max()
{
    BSTNode *cur = this;
    while (cur->right)
    {
        cur = cur->right;
    }
    return cur;
}

BSTNode *BSTNode::Next_larger()
{
    if (this->right)
    {
        return this->right->Find_min();
    }
    BSTNode *cur = this;
    // This node has a parent and this node is at the right of that node
    while (cur->parent != nullptr && cur == cur->parent->right)
    {
        cur = cur->parent;
    }
    return cur;
}

BSTNode *BSTNode::Next_smaller()
{
    if (this->left)
    {
        return this->right->Find_max();
    }
    BSTNode *cur = this;
    // This node has a parent and this node is at the right of that node
    while (cur->parent != nullptr && cur == cur->parent->left)
    {
        cur = cur->parent;
    }
    return cur;
}

bool BSTNode::Insert(BSTNode *input)
{
    if (!input)
    {
        cout << "Input is NULL." << endl;
        return 0;
    }
    else
    {
        if (input->key > this->key)
        {
            if (!this->right)
            {
                this->right = input;
                input->parent = this;
                return 1;
            }
            else
            {
                return this->right->Insert(input);
            }
        }
        else if (input->key < this->key)
        {
            if (!this->left)
            {
                this->left = input;
                input->parent = this;
                cout << input->parent->GetKey() << endl;
                return 1;
            }
            else
            {
                return this->left->Insert(input);
            }
        }
    }
    return 0;
}

bool BSTNode::isLeaf()
{
    if ((!this->left) && (!this->right))
    {
        return 1;
    }
    return 0;
}

BSTNode *BSTNode::Delete()
{
    if (this->left == nullptr || this->right == nullptr)
    {
        cout << "LOL" << endl;
        BSTNode *child = (this->left != nullptr) ? (this->left) : (this->right);
        if (this == this->parent->left)
        {
            this->parent->left = child;
            if (this->parent->left)
            {
                this->parent->left->parent = this->parent;
            }
        }
        else
        {
            this->parent->right = child;
            if (this->parent->right)
            {
                this->parent->right->parent = this->parent;
            }
        }
        return this;
    }
    else
    {
        BSTNode *s = this->Next_larger();
        this->key = s->key;
        return s->Delete();
    }
}