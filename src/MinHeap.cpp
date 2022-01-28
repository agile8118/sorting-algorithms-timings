#include "MinHeap.h"

void MinHeap::insert(int value)
{
  if (_size + 1 >= numbers.size())
  {
    numbers.push_back(0);
  }

  numbers[++_size] = value;
  shiftUp(_size);
}

void MinHeap::shiftUp(int index)
{
  if (_size < index)
    return;
  if (index == 1)
    return;

  if (numbers[index] < numbers[parent(index)])
  {
    std::swap(numbers[parent(index)], numbers[index]);
  }

  shiftUp(parent(index));
}

void MinHeap::shiftDown(int index)
{
  if (index > _size)
    return;

  int swapId = index;
  if (left(index) <= _size && numbers[index] > numbers[left(index)])
  {
    swapId = left(index);
  }

  if (right(index) <= _size && numbers[swapId] > numbers[right(index)])
  {
    swapId = right(index);
  }

  if (swapId != index)
  {
    std::swap(numbers[index], numbers[swapId]);
    shiftDown(swapId);
  }
}

int MinHeap::removeMin()
{

  int minValue = numbers[1];
  std::swap(numbers[1], numbers[_size]);
  --_size;
  shiftDown(1);
  return minValue;
}