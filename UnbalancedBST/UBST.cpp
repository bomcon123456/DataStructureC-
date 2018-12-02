#include "UBST.h"

BSTNode *UnbalancedBST::Find(int k)
{
    return root->Find(k);
}

BSTNode *UnbalancedBST::Find_min()
{
    return root->Find_min();
}

BSTNode *UnbalancedBST::Find_max()
{
    return root->Find_max();
}

BSTNode *UnbalancedBST::Next_larger(int k)
{
    BSTNode *finded = Find(k);
    return finded->Next_larger();
}

BSTNode *UnbalancedBST::Next_smaller(int k)
{
    BSTNode *finded = Find(k);
    return finded->Next_smaller();
}

void UnbalancedBST::Insert(int k)
{
    BSTNode *insertee = new BSTNode(k);
    if (!root)
    {
        //cout << insertee->GetKey() << endl;
        root = insertee;
        //cout << root->GetKey() << endl;
    }
    else
    {
        root->Insert(insertee);
    }
    insertee = nullptr;
    delete insertee;
    return;
}

BSTNode *UnbalancedBST::Delete(int k)
{
    BSTNode *deletee = Find(k);
    if (!deletee)
    {
        cout << "This key is not exist." << endl;
        return nullptr;
    }
    // If we're going to delete the root.
    if (deletee == root)
    {
        // Create a fake root having root as its left child, so that the Node's delete function works (which re-direct parent, child ptr)
        BSTNode *pseudoroot = new BSTNode(0);
        pseudoroot->SetLeft(root);
        root->SetParent(pseudoroot);
        BSTNode *deleted = root->Delete();
        root = pseudoroot->GetLeft();
        if (root)
        {
            root->SetParent(nullptr);
        }
        pseudoroot = nullptr;
        delete pseudoroot;
        return deleted;
    }
    else
    {
        return deletee->Delete();
    }
}

void UnbalancedBST::InOrderTraverse(BSTNode *next)
{
    if (next->GetLeft())
        InOrderTraverse(next->GetLeft());
    cout << next->GetKey() << " ";
    if (next->GetRight())
        InOrderTraverse(next->GetRight());
}

void UnbalancedBST::InOrder()
{
    InOrderTraverse(root);
    cout << endl;
}