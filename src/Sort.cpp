#include "Sort.h"

// These 2 will be used to generate random numbers
static std::random_device random_device;
static std::mt19937 generate(random_device());

Sort::Sort()
{
}

Sort::Sort(int numbersLength, int rangeStart, int rangeEnd)
{
  this->numbers_length = numbersLength;
  // Fills the array with random numbers
  for (int i = 0; i < this->numbers_length; i++)
  {
    initialized_numbers.push_back(randomNumber(1, 1000));
  }
}

// Genererates a random number between a given range
int Sort::randomNumber(int start, int end)
{
  std::uniform_int_distribution<> distribution(start, end);
  int random_number = distribution(generate);
  return random_number;
}

void Sort::printNumbers(std::vector<int> numbers, std::string message) const
{
  std::cout << std::endl;
  std::cout << "Vector of size " << numbers.size() << " " << message << " is:" << std::endl;
  std::cout << "[";

  for (int i = 0; i < numbers.size(); i++)
  {
    std::cout << numbers[i];
    if (i != numbers.size() - 1)
      std::cout << ", ";
  }

  std::cout << "]";
  std::cout << std::endl;
}

void Sort::printNumbers(std::vector<int> numbers) const
{
  std::cout << std::endl;
  std::cout << "Vector of size " << numbers.size() << " is:" << std::endl;
  std::cout << "[";

  for (int i = 0; i < numbers.size(); i++)
  {
    std::cout << numbers[i];
    if (i != numbers.size() - 1)
      std::cout << ", ";
  }

  std::cout << "]";
  std::cout << std::endl;
}

// Merge function for mergeSort, both vectors should be already sorted
std::vector<int> Sort::merge(std::vector<int> const &vec1, std::vector<int> const &vec2)
{
  std::vector<int> mergedVec;
  int i = 0, j = 0;

  while (i < vec1.size() && j < vec2.size())
  {
    if (vec1[i] < vec2[j])
    {
      mergedVec.push_back(vec1[i]);
      i++;
    }
    else
    {
      mergedVec.push_back(vec2[j]);
      j++;
    }
  }

  // If we still have items in vector 1
  while (i < vec1.size())
  {
    mergedVec.push_back(vec1[i]);
    i++;
  }

  // If we still have items in vector 2
  while (j < vec2.size())
  {
    mergedVec.push_back(vec2[j]);
    j++;
  }

  return mergedVec;
}

// Will be used in the quickSort function, it moves the startIndex to the correct spot,
// meaning all the left side and all the right side should be less than and greater than itself respectively
int Sort::partition(std::vector<int> &numbers, int startIndex, int endIndex)
{
  int pivot = numbers[startIndex];
  int swapIndex = startIndex;

  for (int i = startIndex + 1; i <= endIndex; i++)
  {
    if (pivot > numbers[i])
    {
      swapIndex++;
      std::swap(numbers[swapIndex], numbers[i]);
    }
  }

  // Finally move the pivot to the correct position
  std::swap(numbers[startIndex], numbers[swapIndex]);
  return swapIndex;
}

void Sort::quickSortMain(std::vector<int> &numbers, int startIndex, int endIndex)
{
  if (startIndex < endIndex)
  {
    long pivotIndex = partition(numbers, startIndex, endIndex);
    quickSortMain(numbers, startIndex, pivotIndex - 1);
    quickSortMain(numbers, pivotIndex + 1, endIndex);
  }
}

// Selection sort function, returns a new vector with the sorted numbers
void Sort::selectionSort()
{
  selection_sort_sorted_numbers = initialized_numbers;

  auto start = std::chrono::high_resolution_clock::now();

  for (int i = 0; i < selection_sort_sorted_numbers.size(); i++)
  {
    int min_index = i; // minimum index of the vector

    for (int j = i + 1; j < selection_sort_sorted_numbers.size(); j++)
    {
      if (selection_sort_sorted_numbers[min_index] > selection_sort_sorted_numbers[j])
      {
        min_index = j;
      }
    }

    // only swap if the min_index has changed in the previous loop
    // meaning that we have found an element that is less than the min_index
    if (i != min_index)
    {
      std::swap(selection_sort_sorted_numbers[min_index], selection_sort_sorted_numbers[i]);
    }
  }

  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  selection_sort_sorted_numbers_duration = duration.count();
}

// Insertion sort function, returns a new vector with the sorted numbers
void Sort::insertionSort()
{
  insertion_sort_sorted_numbers = initialized_numbers;

  auto start = std::chrono::high_resolution_clock::now();

  int currentValue; // the number that we're going to compare to the left side (sorted portion)

  for (int i = 1; i < insertion_sort_sorted_numbers.size(); i++)
  {
    currentValue = insertion_sort_sorted_numbers[i];
    int j;

    for (j = i - 1; j > -1; j--)
    {
      // if currentValue is greater than the number to its left side, we are done
      if (insertion_sort_sorted_numbers[j] < currentValue)
        break;
      insertion_sort_sorted_numbers[j + 1] = insertion_sort_sorted_numbers[j];
    }

    insertion_sort_sorted_numbers[j + 1] = currentValue;
  }

  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  insertion_sort_sorted_numbers_duration = duration.count();
}

// Merge sort function, return a new vector with the sorted numbers
std::vector<int> Sort::mergeSortMain(std::vector<int> numbers)
{
  if (numbers.size() <= 1)
    return numbers;

  int midpoint = std::floor(numbers.size() / 2);
  std::vector<int> leftSide = mergeSortMain(std::vector<int>(numbers.begin(), numbers.begin() + midpoint));
  std::vector<int> rightSide = mergeSortMain(std::vector<int>(numbers.begin() + midpoint, numbers.end()));

  return merge(leftSide, rightSide);
}

void Sort::mergeSort()
{
  auto start = std::chrono::high_resolution_clock::now();

  merge_sort_sorted_numbers = mergeSortMain(initialized_numbers);

  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  merge_sort_sorted_numbers_duration = duration.count();
}

// The wrapper function for the main quickSort
void Sort::quickSort()
{
  auto start = std::chrono::high_resolution_clock::now();

  quick_sort_sorted_numbers = initialized_numbers;
  long startIndex = 0;
  long endIndex = quick_sort_sorted_numbers.size() - 1;
  quickSortMain(quick_sort_sorted_numbers, startIndex, endIndex);

  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  quick_sort_sorted_numbers_duration = duration.count();
}

void Sort::heapSort()
{
  auto start = std::chrono::high_resolution_clock::now();

  MinHeap heap;

  for (int x : initialized_numbers)
  {
    heap.insert(x);
  }

  while (!heap.isEmpty())
  {
    heap_sort_sorted_numbers.push_back(heap.removeMin());
  }

  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  heap_sort_sorted_numbers_duration = duration.count();
}

void Sort::BSTSort()
{
  auto start = std::chrono::high_resolution_clock::now();

  BST tree;

  for (int x : initialized_numbers)
  {
    tree.insert(x);
  }

  BST_sort_sorted_numbers = tree.inOrder();

  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  BST_sort_sorted_numbers_duration = duration.count();
}

// Shell sort algorithm (based on Bubble Sort)
void Sort::shellSort()
{
  shell_sort_sorted_numbers = initialized_numbers;

  auto start = std::chrono::high_resolution_clock::now();

  int gap = std::floor(shell_sort_sorted_numbers.size() / 2);

  while (gap > 0)
  {
    for (int j = gap; j < shell_sort_sorted_numbers.size(); j++)
    {
      int temp = shell_sort_sorted_numbers[j]; // the right element
      int i = 0;

      for (i = j; (i >= gap) && (shell_sort_sorted_numbers[i - gap]) > temp; i -= gap)
      {
        shell_sort_sorted_numbers[i] = shell_sort_sorted_numbers[i - gap];
      }

      shell_sort_sorted_numbers[i] = temp;
    }

    gap = std::floor(gap / 2);
  }

  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  shell_sort_sorted_numbers_duration = duration.count();
}

void Sort::printDuration(TimeUnits u) const
{
  std::cout << std::endl;
  std::cout << "---------------------- " << std::endl;
  std::cout << std::endl;

  int division;
  std::string unit;

  if (u == microseconds)
  {
    division = 1;
    unit = " microseconds";
  }
  else if (u == milliseconds)
  {
    division = 1000;
    unit = "ms";
  }

  std::cout << "Duration of the functions is as follows: " << std::endl;
  if (selection_sort_sorted_numbers_duration)
    std::cout << "Selection Sort: " << std::floor(selection_sort_sorted_numbers_duration / division) << unit << std::endl;

  if (insertion_sort_sorted_numbers_duration)
    std::cout << "Insertion Sort: " << std::floor(insertion_sort_sorted_numbers_duration / division) << unit << std::endl;

  if (merge_sort_sorted_numbers_duration)
    std::cout << "Merge Sort: " << std::floor(merge_sort_sorted_numbers_duration / division) << unit << std::endl;

  if (quick_sort_sorted_numbers_duration)
    std::cout << "Quick Sort: " << std::floor(quick_sort_sorted_numbers_duration / division) << unit << std::endl;

  if (heap_sort_sorted_numbers_duration)
    std::cout << "Heap Sort: " << std::floor(heap_sort_sorted_numbers_duration / division) << unit << std::endl;

  if (BST_sort_sorted_numbers_duration)
    std::cout << "BST Sort: " << std::floor(BST_sort_sorted_numbers_duration / division) << unit << std::endl;

  if (shell_sort_sorted_numbers_duration)
    std::cout << "Shell Sort: " << std::floor(shell_sort_sorted_numbers_duration / division) << unit << std::endl;
}

void Sort::printAllNumbers() const
{
  printNumbers(initialized_numbers, "(initial unsorted vector)");

  if (insertion_sort_sorted_numbers.size())
    printNumbers(insertion_sort_sorted_numbers, "after insertion sort");

  if (selection_sort_sorted_numbers.size())
    printNumbers(selection_sort_sorted_numbers, "after selection sort");

  if (merge_sort_sorted_numbers.size())
    printNumbers(merge_sort_sorted_numbers, "after merge sort");

  if (quick_sort_sorted_numbers.size())
    printNumbers(quick_sort_sorted_numbers, "after quick sort");

  if (heap_sort_sorted_numbers.size())
    printNumbers(heap_sort_sorted_numbers, "after heap sort");

  if (BST_sort_sorted_numbers.size())
    printNumbers(BST_sort_sorted_numbers, "after BST sort");

  if (shell_sort_sorted_numbers.size())
    printNumbers(shell_sort_sorted_numbers, "after shell sort");
}

std::vector<int> Sort::getInitializedNumbers() const
{
  return initialized_numbers;
}

std::vector<int> Sort::getInsertionSortSortedNumbers() const
{
  return insertion_sort_sorted_numbers;
}

std::vector<int> Sort::getSelectionSortSortedNumbers() const
{
  return selection_sort_sorted_numbers;
}

std::vector<int> Sort::getMergeSortSortedNumbers() const
{
  return merge_sort_sorted_numbers;
}

std::vector<int> Sort::getQuickSortSortedNumbers() const
{
  return quick_sort_sorted_numbers;
}

std::vector<int> Sort::getHeapSortSortedNumbers() const
{
  return heap_sort_sorted_numbers;
}

std::vector<int> Sort::getBSTSortSortedNumbers() const
{
  return BST_sort_sorted_numbers;
}

std::vector<int> Sort::getShellSortSortedNumbers() const
{
  return shell_sort_sorted_numbers;
}
