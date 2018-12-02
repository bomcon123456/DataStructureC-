#ifndef HEAP_H
#define HEAP_H
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Heap
{
  private:
    std::vector<int> arr;
    size_t length;
    size_t heapSize;

  public:
    Heap() : length(0), heapSize(0){};
    Heap(std::vector<int> copy) : arr(copy)
    {
        length = copy.size();
        BuildMaxHeap();
    } //this->BuildMaxHeap();

  public:
    size_t parent(size_t i);
    size_t left(size_t i);
    size_t right(size_t i);
    bool isLeaf(size_t i);

  private:
    void InOrderTraverse(size_t cur);
    void PreOrderTraverse(size_t cur);
    void PostOrderTraverse(size_t cur);

  public:
    void InOrder();
    void PreOrder();
    void PostOrder();
    void PrintArr();

  public:
    void Max_Heapify(size_t i);
    void BuildMaxHeap();

  public:
    int ExtractMax();
    int GetMax();
    void IncreaseKey(size_t pos, int key);
    void DeleteKey(size_t pos);
    void Insert(int value);

  public:
    void HeapSort();
};

#endif