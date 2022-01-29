#include <iostream>
#include "Sort.h"

// This project is hosted on GitHub at https://github.com/agile8118/sorting-algorithms-timings

/** Gets an array of integers and sorts them out using the following algorithms:
*       - Insertion Sort
*       - Selection Sort
*       - Quick Sort
*       - Merge Sort
*       - Heap Sort
*       - BST
*       - Shell Sort
**/

int main()
{

    /*
    * ------------------------------ EXAMPLE 1 -----------------------------      
    * The initial array is of size 80 and the numbers start from 0 up to 100.
    * This example will sort the numbers using all available seven algorithms 
    * and then prints the numbers (both the initial unsorted numbers and then the sorted ones).
    * It also prints the time that took each one of the functions to run.
    * Change the first value of the constructor to experiment with various lengths.
    * 
    * --- Uncomment the following lines in order to be able to run and see the resutls of this example:
    */

    // Sort sort(80, 0, 1000000, Random);
    // sort.selectionSort();
    // sort.insertionSort();
    // sort.mergeSort();
    // sort.quickSort();
    // sort.heapSort();
    // sort.BSTSort();
    // sort.shellSort();
    // sort.printAllNumbers();
    // sort.printDuration(Microseconds);

    /*
    * ------------------------------ EXAMPLE 2 -----------------------------      
    * The initial array is of size ten million and the numbers are in the range of zero to one hunder million.
    * This example will sort the numbers using only Merge and Quick Sort, note that if you want to sort using other
    * algorithms it will probably take a long time for the application to finish.
    * What it demonstrates is that for small array sizes, quick sort is generally faster but for longer array sizes,
    * merge sort is usually the winner.
    * 
    * It's not advisable to run the printAllNumbers method here due to the fact that it will try to print
    * thirty million numbers. 
    * This example will probably take a few minutes to run, depending upon how fast your CPU is (around 2.5 minutes on Apple M1).
    * It took quick sort approximately 113 seconds to complete the task, and only 20 seconds for merge sort to do the same.
    * 
    * --- Uncomment the following lines in order to be able to run and see the resutls of this example: ---
    */

    Sort sort(10000000, 0, 100000000, Random);
    sort.mergeSort();
    sort.shellSort();
    sort.printDuration(Milliseconds);

    /*
    * ------------------------------ EPILOGUE -----------------------------      
    * -- All tests conducted on Apple M1. --
    * For length of a hundred million it took Merge Sort 230 seconds.
    * For length of a hundred million it took Heap Sort 118 seconds (faster than merge sort).
    * 
    * 
    * @TODO: set up multi-threading on Merge Sort to reduce the time it takes to sort very large array of numbers
    * @TODO: Try to optimize the algorithms to see how much we could reduce the computation times.
    * @TODO: Try to change the variable types of merge sort to long or unassigned long long to be able to run the test
    *        for a vector with more than billions of numbers (it might take hours for the sorting to get done).
    * @TODO: Try to optimize the BST algorithm's memory management, right now for insertion, new memory for each node 
    *        is being allocated on the heap and it's not getting deleted once done.  
    */
}
