#include <bits/stdc++.h>
#include "Heap.h"

int main()
{
    Heap test({4,1,3,2,16,9,10,14,8,7});
    
    test.PrintArr();
    test.Insert(20);
    test.Insert(6);
    test.InOrder();
    test.PrintArr();
    //test.PreOrder();
    //test.PostOrder();

    //test.HeapSort();
    //test.PrintArr();
    return 0;
}