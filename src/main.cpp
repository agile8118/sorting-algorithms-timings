#include <iostream>
#include <vector>
#include "Sort.h"

/** Gets an array of integers and sorts them out using the following algorithms:
*       - Insertion Sort
*       - Selection Sort
*       - Quick Sort
*       - Merge Sort
*       - Heap Sort
*       - BST
*       - Shell Sort
**/

void printNumbers(std::vector<int> numbers, std::string message)
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

void printNumbers(std::vector<int> numbers)
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

int main()
{
    Sort sort(10000, 0, 1000000000);

    // sort.insertionSort();
    sort.mergeSort();
    sort.quickSort();
    // sort.heapSort();
    sort.BSTSort();
    // sort.shellSort();

    sort.printDurations(milliseconds);

    // printNumbers(sort.getInitializedNumbers(), "(initial unsorted vector)");
    // printNumbers(sort.getSelectionSortSortedNumbers(), "after selection sort");
    // printNumbers(sort.getMergeSortSortedNumbers(), "after merge sort");
    // printNumbers(sort.getQuickSortSortedNumbers(), "after quick sort");
    // printNumbers(sort.getHeapSortSortedNumbers(), "after heap sort");
    // printNumbers(sort.getBSTSortSortedNumbers(), "after BST sort");
    // printNumbers(sort.getShellSortSortedNumbers(), "after shell sort");
}
