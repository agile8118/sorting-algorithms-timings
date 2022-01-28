#ifndef MinHeap_h
#define MinHeap_h

#include <vector>
#include <cmath>

class MinHeap
{
private:
  int _size = 0;
  std::vector<int> numbers = {-1};

  int parent(int index) { return std::floor(index / 2); };
  int left(int index) { return index * 2; };
  int right(int index) { return index * 2 + 1; };

public:
  bool isEmpty() const { return _size == 0; };
  int getMin() const { return numbers[1]; };
  void insert(int value);
  void shiftUp(int index);
  void shiftDown(int index);
  int removeMin();
};

#endif /* Minheap_h */
