//
// Created by yao on 20-1-4.
//

#ifndef SORTALGORITHM_QUICKSORT_H
#define SORTALGORITHM_QUICKSORT_H

#include <algorithm>
#include <iostream>
template<typename T>
void quickSort_1(T *arr, int l, int r) {
    if (l >= r)
        return;
    int j = l, i = l + 1;
    while (i <= r) {
        if (arr[i] < arr[l]) {
            std::swap(arr[++j], arr[i]);
        }
        i++;
    }
    std::swap(arr[l], arr[j]);
    quickSort_1(arr, l, j - 1);
    quickSort_1(arr, j + 1, r);
}

template<typename T>
void quickSort(T *arr, int n) {
    clock_t start = clock();
    quickSort_1(arr, 0, n - 1);
    std::cout << "QuickSort Time : " << double(clock() - start) / CLOCKS_PER_SEC << "s" << std::endl;
}

#endif //SORTALGORITHM_QUICKSORT_H
