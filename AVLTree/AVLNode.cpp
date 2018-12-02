#include "AVLNode.h"

AVLNode *AVLNode::Find(AVLNode *input)
{
    if (input->key == this->key)
    {
        return this;
    }
    else if (input->key > this->key)
    {
        if (!this->right)
        {
            cout << "This key is not exist." << endl;
            return nullptr;
        }
        else
        {
            return this->right->Find(input);
        }
    }
    else
    {
        if (!this->left)
        {
            cout << "This key is not exist." << endl;
            return nullptr;
        }
        else
        {
            return this->left->Find(input);
        }
    }
}

AVLNode *AVLNode::Find_min()
{
    AVLNode *cur = this;
    while (cur->left)
    {
        cur = cur->left;
    }
    return cur;
}

AVLNode *AVLNode::Find_max()
{
    AVLNode *cur = this;
    while (cur->right)
    {
        cur = cur->right;
    }
    return cur;
}

AVLNode *AVLNode::Next_larger()
{
    if (this->right)
    {
        return this->right->Find_min();
    }
    else
    {
        AVLNode *cur = this;
        while (cur->parent != nullptr && cur == cur->parent->right)
        {
            cur = cur->parent;
        }
        return cur;
    }
}

AVLNode *AVLNode::Next_smaller()
{
    if (this->left)
    {
        return this->left->Find_min();
    }
    else
    {
        AVLNode *cur = this;
        while (cur->parent != nullptr && cur == cur->parent->left)
        {
            cur = cur->parent;
        }
        return cur;
    }
}

void AVLNode::Insert(AVLNode *input)
{
    if (!input)
    {
        cout << "Input is not valid." << endl;
        return;
    }
    else if (input->key == this->key)
    {
        cout << "Input has already been in." << endl;
        return;
    }
    else
    {
        if (input->key > this->key)
        {
            if (!this->right)
            {
                input->parent = this;
                this->right = input;
            }
            else
            {
                this->right->Insert(input);
            }
        }
        if (input->key < this->key)
        {
            if (!this->left)
            {
                input->parent = this;
                this->left = input;
            }
            else
            {
                this->left->Insert(input);
            }
        }
    }
}

AVLNode *AVLNode::Delete()
{
    if(this->left == nullptr || this->right == nullptr)
    {
        AVLNode* child = (this->left!=nullptr) ? this->left : this->right;
        if(this == this->parent->left)
        {
            this->parent->left = child;
            if(this->parent->left)
                this->parent->left->parent = this->parent;
        }
        else if (this == this->parent->right)
        {
            this->parent->right = child;
            if(this->parent->right)
                this->parent->right->parent = this->parent;
        }
        return this;
    }
    else
    {
        AVLNode* mid = this->Next_larger();
        this->key = mid->key;
        return mid->Delete();
    }
}