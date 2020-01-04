#include <iostream>
#include "SelectSort.h"
#include "InsertSort.h"
#include "MergeSort.h"
#include "QuickSort.h"

template<typename T>
bool checkSort(T *arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        if (arr[i + 1] < arr[i])
            return false;
    }
    return true;
}

template<typename T>
void copyArray(T *arr1, T *arr2, int n) {
    for (int j = 0; j < n; ++j) {
        arr2[j] = arr1[j];
    }
}

template<typename T>
void printArray(T *arr, int n) {
    for (int j = 0; j < n; ++j) {
        std::cout << arr[j] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int n = 1000000;
    int *arr = new int[n];
    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % n;
    }

    int *arr1 = new int[n];
    int *arr2_1 = new int[n];
    int *arr2_2 = new int[n];
    int *arr3 = new int[n];
    int *arr4 = new int[n];
    copyArray(arr, arr1, n);
    copyArray(arr, arr2_1, n);
    copyArray(arr, arr2_2, n);
    copyArray(arr, arr3, n);
    copyArray(arr, arr4, n);

//    printArray(arr, n);

//    selectSort(arr1, n);
//    insertSort1(arr2_1, n);
//    insertSort2(arr2_2, n);
    mergeSort(arr3, n);
    quickSort(arr4, n);

//    printArray(arr2, n);

    std::cout << checkSort(arr1, n) << std::endl;
    std::cout << checkSort(arr2_1, n) << std::endl;
    std::cout << checkSort(arr2_2, n) << std::endl;
    std::cout << checkSort(arr3, n) << std::endl;
    std::cout << checkSort(arr4, n) << std::endl;

    delete[]arr;
    delete[]arr1;
    delete[]arr2_1;
    delete[]arr2_2;
    delete[]arr3;
    delete[]arr4;

    return 0;
}