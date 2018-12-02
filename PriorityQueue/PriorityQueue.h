#include "Heap/Heap.h"

class PriorityQueue
{
  private:
    Heap queue;

  public:
    PriorityQueue(){};

    int GetMax() { return queue.GetMax(); }
    int ExtractMax() { return queue.ExtractMax(); }

  public:
    void IncreaseKey(int pos, int key) { queue.IncreaseKey(pos,key); };
    void Insert(int key) { queue.Insert(key); }
};