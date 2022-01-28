#ifndef Sort_h
#define Sort_h

#include <iostream>
#include <random>
#include <chrono>
#include <string>
#include <vector>
#include "BST.h"
#include "MinHeap.h"

enum TimeUnits
{
  microseconds = 0,
  milliseconds
};

class Sort
{
private:
  int randomNumber(int start, int end);
  int numbers_length;
  std::vector<int> merge(std::vector<int> const &vec1, std::vector<int> const &vec2);
  long partition(std::vector<int> &numbers, long startIndex, long endIndex);
  void quickSortMain(std::vector<int> &numbers, long startIndex, long endIndex);
  std::vector<int> mergeSortMain(std::vector<int> numbers);

  // Our initialized vector
  std::vector<int> initialized_numbers;

  // Vectors that hold sorted numbers of each sorting algorithm
  std::vector<int> selection_sort_sorted_numbers;
  std::vector<int> insertion_sort_sorted_numbers;
  std::vector<int> merge_sort_sorted_numbers;
  std::vector<int> quick_sort_sorted_numbers;
  std::vector<int> heap_sort_sorted_numbers;
  std::vector<int> BST_sort_sorted_numbers;
  std::vector<int> shell_sort_sorted_numbers;

  // Durations
  int selection_sort_sorted_numbers_duration = 0;
  int insertion_sort_sorted_numbers_duration = 0;
  int merge_sort_sorted_numbers_duration = 0;
  int quick_sort_sorted_numbers_duration = 0;
  int heap_sort_sorted_numbers_duration = 0;
  int BST_sort_sorted_numbers_duration = 0;
  int shell_sort_sorted_numbers_duration = 0;

public:
  Sort();
  Sort(int numbers_length, int rangeStart, int rangeEnd);

  // Getters
  std::vector<int> getInitializedNumbers() const;
  std::vector<int> getSelectionSortSortedNumbers() const;
  std::vector<int> getMergeSortSortedNumbers() const;
  std::vector<int> getQuickSortSortedNumbers() const;
  std::vector<int> getHeapSortSortedNumbers() const;
  std::vector<int> getBSTSortSortedNumbers() const;
  std::vector<int> getShellSortSortedNumbers() const;

  void selectionSort();
  void insertionSort();
  void mergeSort();
  void quickSort();
  void heapSort();
  void BSTSort();
  void shellSort();

  void printDurations(TimeUnits u);
};

#endif /* Sort_h */
