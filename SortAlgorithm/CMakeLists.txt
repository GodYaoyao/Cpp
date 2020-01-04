cmake_minimum_required(VERSION 3.9)
project(SortAlgorithm)

set(CMAKE_CXX_STANDARD 11)

add_executable(SortAlgorithm main.cpp SelectSort.h InsertSort.h MergeSort.h QuickSort.h)