cmake_minimum_required(VERSION 3.7)

set(CMAKE_CXX_STANDARD 14)

project(SortingAlgorithmsTimings)

add_executable(SortingAlgorithmsTimings src/main.cpp src/Sort.cpp src/BST.cpp src/MinHeap.cpp)
