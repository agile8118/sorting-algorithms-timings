#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <cmath>

/** Gets an array of integers and sorts them out using the following algorithms:
*       - Insertion Sort
*       - Selection Sort
*       - Quick Sort
*       - Merge Sort
*       - Heap Sort
*       - BST
*       - Shell Sort
**/

// These 2 will be used to generate random numbers
static std::random_device random_device;
static std::mt19937 generate(random_device());


// Genererates a random number between a given range
int randomNumber(int start, int end) {
    std::uniform_int_distribution<> distribution(start, end);
    int random_number = distribution(generate);
    return random_number;
}

// Selection sort function, returns a new vector with the sorted numbers
std::vector<int> selectionSort(std::vector<int> numbers) {
    for (int i = 0; i < numbers.size(); i++) {
        int min_index = i; // minimum index of the vector

        for (int j = i + 1; j < numbers.size(); j++) {
            if (numbers[min_index] > numbers[j]) {
                min_index = j;
            }
        }
        
        // only swap if the min_index has changed in the previous loop
        // meaning that we have found an element that is less than the min_index
        if (i != min_index) {
            std::swap(numbers[min_index], numbers[i]);
        }
    }
    
    return numbers;
}

// Insertion sort function, returns a new vector with the sorted numbers
std::vector<int> insertionSort(std::vector<int> numbers) {
    int currentValue; // the number that we're going to compare to the left side (sorted portion)
    
    for (int i = 1; i < numbers.size(); i++) {
        currentValue = numbers[i];
        int j;

        for (j = i - 1; j > -1; j--) {
            // if currentValue is greater than the number to its left side, we are done
            if (numbers[j] < currentValue) break;
            numbers[j + 1] = numbers[j];
        }
        
        numbers[j + 1] = currentValue;
    }
    
    return numbers;
}

// Merge function for mergeSort, both vectors should be already sorted
std::vector<int> merge(std::vector<int> const &vec1, std::vector<int> const &vec2) {
    std::vector<int> mergedVec;
    int i = 0, j = 0;
        
    while (i < vec1.size() && j < vec2.size()) {
        if (vec1[i] < vec2[j]) {
            mergedVec.push_back(vec1[i]);
            i++;
        } else {
            mergedVec.push_back(vec2[j]);
            j++;
        }
    }
    
    // If we still have items in vector 1
    while (i < vec1.size()) {
        mergedVec.push_back(vec1[i]);
        i++;
    }
    
    // If we still have items in vector 2
    while (j < vec2.size()) {
        mergedVec.push_back(vec2[j]);
        j++;
    }
    
    return mergedVec;
}

// Merge sort function, return a new vector with the sorted numbers
std::vector<int> mergeSort(std::vector<int> numbers) {
    if (numbers.size() <= 1) return numbers;

    int midpoint = std::floor(numbers.size() / 2);
    std::vector<int> leftSide = mergeSort(std::vector<int>(numbers.begin(), numbers.end() - midpoint));
    std::vector<int> rightSide = mergeSort(std::vector<int>(numbers.begin() + midpoint, numbers.end()));

    return merge(leftSide, rightSide);
}

// Will be used in the quickSort function, it moves the startIndex to the correct spot,
// meaning all the left side and all the right side should be less than and greater than itself respectively
long partition(std::vector<int> &numbers, long startIndex, long endIndex) {
    long pivot = numbers[startIndex];
    long swapIndex = startIndex;
    
    for (long i = startIndex + 1; i <= endIndex; i++) {
        if (pivot > numbers[i]) {
            swapIndex++;
            std::swap(numbers[swapIndex], numbers[i]);
        }
    }
    
    // Finally move the pivot to the correct position
    std::swap(numbers[startIndex], numbers[swapIndex]);
    return swapIndex;
}

void quickSortMain(std::vector<int> &numbers, long startIndex, long endIndex) {
    if (startIndex < endIndex) {
        long pivotIndex = partition(numbers, startIndex, endIndex);
        quickSortMain(numbers, startIndex, pivotIndex - 1);
        quickSortMain(numbers, pivotIndex + 1, endIndex);
    }
}

// The wrapper function for the main quickSort
std::vector<int> quickSort(std::vector<int> numbers) {
    long startIndex = 0;
    long endIndex = numbers.size() - 1;
    quickSortMain(numbers, startIndex, endIndex);
    return numbers;
}


void printNumbers(std::vector<int> numbers, std::string message) {
    std::cout << std::endl;
    std::cout << "Vector of size " << numbers.size() << " " << message << " is:" << std::endl;
    std::cout << "[";

    for (int i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i];
        if (i != numbers.size() - 1) std::cout << ", ";
    }
    
    std::cout << "]";
    std::cout << std::endl;
}

void printNumbers(std::vector<int> numbers) {
    std::cout << std::endl;
    std::cout << "Vector of size " << numbers.size() << " is:" << std::endl;
    std::cout << "[";

    for (int i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i];
        if (i != numbers.size() - 1) std::cout << ", ";
    }
    
    std::cout << "]";
    std::cout << std::endl;
}

int main()
{
//    int vector_size = 20;
//    std::vector<int> numbers;
//
//    // Fills the array with random numbers
//    for (int i = 0; i < vector_size; i++) {
//        numbers.push_back(randomNumber(1, 1000));
//    }
//
//    printNumbers(numbers);
//
//    std::vector<int> test1 = insertionSort(numbers);
//    printNumbers(test1, "after insertion sort");
//
//
//    std::vector<int> test2 = insertionSort(numbers);
//    printNumbers(test2, "after selection sort");
    
    
    
//    auto start2 = std::chrono::high_resolution_clock::now();
//    int insertion_sorted_arr[array_size] = &insertionSort(numbers);
//    auto stop2 = std::chrono::high_resolution_clock::now();
//    auto duration2 = duration_cast<std::chrono::milliseconds>(stop2 - start2);
//    std::cout << "Insertion Sort: " << duration2.count() << " ms" << std::endl;


//    auto start = std::chrono::high_resolution_clock::now();
//    int heap_sorted_arr[array_size] = heapSort(numbers, array_size);
//    auto stop = std::chrono::high_resolution_clock::now();
//    auto duration = duration_cast<std::chrono::milliseconds>(stop - start);
//    std::cout << "Heap Sort: " << duration.count() << " ms" << std::endl;


    
//     std::vector<int> vec1 = {1, 5, 6, 7, 10, 14, 19};
//     std::vector<int> vec2 = {2, 6, 100, 1000};
    
//     std::vector<int> vec3 = merge(vec1, vec2);
    
    
//     printNumbers(vec1);
//     printNumbers(vec2);

//     printNumbers(vec3);        
    std::vector<int> vec1 = {4,  3, 2, 1 , 32, 14, 9000, 34, 56, 73, 12};

    std::vector<int> vec2 = quickSort(vec1);
    printNumbers(vec2);

}

