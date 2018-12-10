#include "AVLTree.h"

using namespace std;

int main()
{
    AVLTree test;
    test.Insert(5);
    test.Insert(4);
    test.Insert(3);
    test.Insert(2);
    test.Insert(1);
    test.Insert(6);
    test.Insert(10);
    test.Insert(7);
    test.Insert(9);
    test.Insert(8);
    //test.Rebalance(test.Get_root()->Get_left()->Get_left());
    //cout << "LOL" << endl;
    //test.reTrack();
    cout << "Root: "<<test.Get_root()->Get_key()<< " has height: "<<test.Get_height(test.Get_root())<<endl;
    cout << "First Level Left: "<<test.Get_root()->Get_left()->Get_key()<< " has height: "<<test.Get_height(test.Get_root()->Get_left())<<endl;
    cout << "First Level Right: "<<test.Get_root()->Get_right()->Get_key()<< " has height: "<<test.Get_height(test.Get_root()->Get_right())<<endl;
    cout << "Second Level Right: "<<test.Get_root()->Get_left()->Get_left()->Get_key()<< " has height: "<<test.Get_height(test.Get_root()->Get_left()->Get_left())<<endl;
    cout << "Second Level Right: "<<test.Get_root()->Get_left()->Get_right()->Get_key()<< " has height: "<<test.Get_height(test.Get_root()->Get_left()->Get_right())<<endl;
    cout << "Second Level Right: "<<test.Get_root()->Get_right()->Get_left()->Get_key()<< " has height: "<<test.Get_height(test.Get_root()->Get_right()->Get_left())<<endl;
    cout << "Second Level Right: "<<test.Get_root()->Get_right()->Get_right()->Get_key()<< " has height: "<<test.Get_height(test.Get_root()->Get_right()->Get_right())<<endl;
    cout << "Third Level Right: "<<test.Get_root()->Get_right()->Get_right()->Get_left()->Get_key()<< " has height: "<<test.Get_height(test.Get_root()->Get_right()->Get_right()->Get_left())<<endl;
    cout << "Third Level Right: "<<test.Get_root()->Get_right()->Get_right()->Get_right()->Get_key()<< " has height: "<<test.Get_height(test.Get_root()->Get_right()->Get_right()->Get_right())<<endl;

}