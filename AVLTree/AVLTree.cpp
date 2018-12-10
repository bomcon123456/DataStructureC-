#include "AVLTree.h"

AVLNode *AVLTree::Find(int k)
{
    if (root)
        return root->Find(k);
    else
    {
        cout << "This tree doesn't have any member." << endl;
        return nullptr;
    }
}

AVLNode *AVLTree::Find_max()
{
    if (root)
        return root->Find_max();
    else
    {
        cout << "This tree doesn't have any member." << endl;
        return nullptr;
    }
}

AVLNode *AVLTree::Find_min()
{
    if (root)
        return root->Find_min();
    else
    {
        cout << "This tree doesn't have any member." << endl;
        return nullptr;
    }
}

AVLNode *AVLTree::Next_larger(int k)
{
    AVLNode *findee = Find(k);
    if (findee)
        return findee->Next_larger();
    else
    {
        cout << "This tree doesn't have any member." << endl;
        return nullptr;
    }
}

AVLNode *AVLTree::Next_smaller(int k)
{
    AVLNode *findee = Find(k);
    if (findee)
        return findee->Next_smaller();
    else
    {
        cout << "This tree doesn't have any member." << endl;
        return nullptr;
    }
}

int AVLTree::Get_height(AVLNode *input)
{
    if (!input)
    {
        return -1;
    }
    else
    {
        return input->Get_height();
    }
}

void AVLTree::Update_height(AVLNode *input)
{
    int HL = -1, HR = -1;
    HL = Get_height(input->Get_left());
    HR = Get_height(input->Get_right());
    input->Set_height(max(HL, HR) + 1);
}

void AVLTree::Right_rotate(AVLNode *input)
{
    if (!input)
    {
        cout << "Input is NULL." << endl;
        return;
    }
    AVLNode *B = input->Get_left();
    AVLNode *e = input->Get_parent();
    AVLNode *c = B->Get_right();

    B->Set_parent(e);
    if (e)
    {
        if (e->Get_right() == input)
        {
            e->Set_right(B);
        }
        else if (e->Get_left() == input)
        {
            e->Set_left(B);
        }
    }

    input->Set_parent(B);
    B->Set_right(input);

    if (c)
    {
        c->Set_parent(input);
    }
    input->Set_left(c);
    AVLNode* cur = input;
    while(cur->Get_parent() != nullptr)
    {
        Update_height(cur);
        cur = cur->Get_parent();
    }
    Update_height(cur);
}

void AVLTree::Left_rotate(AVLNode *input)
{
    if (!input)
    {
        cout << "Input is NULL." << endl;
        return;
    }
    AVLNode *e = input->Get_parent();
    AVLNode *y = input->Get_right();
    AVLNode *B = y->Get_left();

    y->Set_parent(e);
    if (e)
    {
        if (e->Get_left() == input)
        {
            e->Set_left(y);
        }
        else if (e->Get_right() == input)
        {
            e->Set_right(y);
        }
    }

    y->Set_left(input);
    input->Set_parent(y);

    input->Set_right(B);
    if (B)
        B->Set_parent(input);

    AVLNode* cur = input;
    while(cur->Get_parent() != nullptr)
    {
        Update_height(cur);
        cur = cur->Get_parent();
    }
    Update_height(cur);
}

void AVLTree::Insert(int k)
{
    AVLNode *insertee = new AVLNode(k);
    if (!root)
    {
        root = insertee;
        insertee->Set_height(0);
    }
    else
    {
        root->Insert(insertee);
        AVLNode *cur = insertee;
        while (cur)
        {
            Update_height(cur);
            cur = cur->Get_parent();
        }
    }
    Rebalance(insertee);
    reTrack();
    insertee = nullptr;
    delete insertee;
}

AVLNode *AVLTree::Delete()
{
}

void AVLTree::Rebalance(AVLNode *node)
{
    int i = 1;
    while (node != nullptr)
    {
        if (Get_height(node->Get_left()) >= 2 + Get_height(node->Get_right()))
        {
            if (Get_height(node->Get_left()->Get_left()) >= Get_height(node->Get_left()->Get_right()))
            {
                Right_rotate(node);
            }
            else
            {
                Left_rotate(node->Get_left());
                Right_rotate(node);
                if (node->Get_key() == 10)
                {
                    cout << node->Get_parent()->Get_key()<< " ";
                    cout << node->Get_parent()->Get_height()<<endl; 
                    cout << Get_height(node->Get_parent()->Get_parent()) << endl;
                }
            }
        }
        else if (Get_height(node->Get_right()) >= 2 + Get_height(node->Get_left()))
        {
            if (Get_height(node->Get_right()->Get_right()) >= Get_height(node->Get_right()->Get_left()))
            {
                Left_rotate(node);
            }
            else
            {
                Right_rotate(node->Get_right());
                Left_rotate(node);
            }
        }
        node = node->Get_parent();
    }
    cout << "DONE" << endl;
    return;
}

void AVLTree::InOrder()
{
    InOrderTraverse(root);
    cout << endl;
}
void AVLTree::InOrderTraverse(AVLNode *input)
{
    if (input)
    {
        cout << "Currently at:" << input->Get_key() << endl
             << "\t";
        if (input->Get_left())
            InOrderTraverse(input->Get_left());
        cout << input->Get_key() << " ";
        if (input->Get_right())
            InOrderTraverse(input->Get_right());
    }
}