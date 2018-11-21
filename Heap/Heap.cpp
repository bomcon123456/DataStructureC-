#include "Heap.h"

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

size_t Heap::parent(size_t i)
{
    return (i / 2) - 1;
}
size_t Heap::left(size_t i)
{
    return 2 * i + 1;
}

size_t Heap::right(size_t i)
{
    return 2 * (i + 1);
}

//@@TODO: Change heapSize -> length ?!
bool Heap::isLeaf(size_t i)
{
    if (i >= heapSize / 2)
        return true;
    return false;
}

void Heap::Max_Heapify(size_t i)
{
    size_t l = left(i);
    size_t r = right(i);
    int largest = i;
    if (l < heapSize && arr[l] > arr[i])
    {
        largest = l;
    }
    if (r < heapSize && arr[r] > arr[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        Max_Heapify(largest);
    }

    /*
        // Loop version
        // size_t current = i;
        // while (!isLeaf(current))
        // {
        //     size_t l = left(current);
        //     size_t r = right(current);
        //     int largest = current;
        //     if (l < heapSize && arr[l] > arr[current])
        //     {
        //         largest = l;
        //     }
        //     if (r < heapSize && arr[r] > arr[largest])
        //     {
        //         largest = r;
        //     }
        //     if (largest != current)
        //     {
        //         swap(arr[i], arr[largest]);
        //     }
        //     else
        //     {
        //         break;
        //     }
        //     current = largest;
        // }
    */
}

void Heap::BuildMaxHeap()
{
    heapSize = length;
    for (int i = (length / 2) - 1; i > -1; i--)
    {
        Max_Heapify(i);
    }
}

// Traverse
void Heap::InOrderTraverse(size_t cur)
{
    if (cur >= heapSize)
    {
        return;
    }
    if (isLeaf(cur))
    {
        std::cout << arr[cur] << " ";
        return;
    }
    InOrderTraverse(left(cur));
    std::cout << arr[cur] << " ";
    InOrderTraverse(right(cur));
}

void Heap::PreOrderTraverse(size_t cur)
{
    if (cur >= heapSize)
    {
        return;
    }
    std::cout << arr[cur] << " ";
    PreOrderTraverse(left(cur));
    PreOrderTraverse(right(cur));
}

void Heap::PostOrderTraverse(size_t cur)
{
    if (cur >= heapSize)
    {
        return;
    }
    PostOrderTraverse(left(cur));
    PostOrderTraverse(right(cur));
    std::cout << arr[cur] << " ";
}

void Heap::InOrder()
{
    std::cout << "In-Order Traverse: " << std::endl;
    InOrderTraverse(0);
    std::cout << std::endl;
}

void Heap::PreOrder()
{
    std::cout << "Pre-Order Traverse: " << std::endl;
    PreOrderTraverse(0);
    std::cout << std::endl;
}

void Heap::PostOrder()
{
    std::cout << "Post-Order Traverse: " << std::endl;
    PostOrderTraverse(0);
    std::cout << std::endl;
}
void Heap::PrintArr()
{
    std::cout << "Array size: " << length << std::endl;
    for (int i = 0; i < length; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void Heap::HeapSort()
{
    for (int i = length - 1; i >= 1; i--)
    {
        swap(arr[0], arr[i]);
        heapSize -= 1;
        Max_Heapify(0);
    }
}

void Heap::Insert(int key)
{
    arr.push_back(key);
    length = arr.size();
    heapSize = length;
    size_t cur = heapSize - 1;
    size_t par = parent(cur);
    arr[cur] = key;
    while (cur != 0 && arr[par] < arr[cur])
    {
        swap(arr[cur], arr[par]);
        cur = par;
    }
}

int Heap::ExtractMax()
{
    if (heapSize < 0)
    {
        std::cout << "Doesn't have anything in heap." << std::endl;
        return 0;
    }
    if (heapSize == 1)
    {
        heapSize--;
        return arr[0];
    }
    int res = arr[0];
    swap(arr[0], arr[heapSize - 1]);
    heapSize--;
    Max_Heapify(0);
    return res;
}

int Heap::GetMax()
{
    return arr[0];
}

void Heap::IncreaseKey(size_t pos, int key)
{
    if(pos >= heapSize)
    {
        std::cout << "This position is not in heap." << std::endl;
    }
    arr[pos] = key;
    size_t par = parent(pos);
    while(pos != 0 && arr[pos] > arr[par])
    {
        swap(arr[pos],arr[par]);
        pos = par;
    }
}

void Heap::DeleteKey(size_t pos)
{
    IncreaseKey(pos, 1e9);
    ExtractMax();
}
