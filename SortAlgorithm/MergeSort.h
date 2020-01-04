//
// Created by yao on 20-1-4.
//

#ifndef SORTALGORITHM_MERGESORT_H
#define SORTALGORITHM_MERGESORT_H

#include "InsertSort.h"

template<typename T>
void mergeSort_(T *arr, int n) {
    if (n <= 32) {
        insertSort2(arr, n);
        return;
    }
    T *arr_1 = new T[n / 2];
    T *arr_2 = new T[n - n / 2];
    for (int i = 0; i < n / 2; ++i) {
        arr_1[i] = arr[i];
    }
    for (int j = 0; j < n - n / 2; ++j) {
        arr_2[j] = arr[j + n / 2];
    }
    mergeSort_(arr_1, n / 2);
    mergeSort_(arr_2, n - n / 2);
    int i = 0, j = 0, k = 0;
    while (i < n / 2 || j < n - n / 2) {
        if (i == n / 2) {
            arr[k] = arr_2[j];
            j++;
        } else if (j == n - n / 2) {
            arr[k] = arr_1[i];
            i++;
        } else if (arr_1[i] <= arr_2[j]) {
            arr[k] = arr_1[i];
            i++;
        } else {
            arr[k] = arr_2[j];
            j++;
        }
        k++;
    }
    delete[]arr_1;
    delete[]arr_2;
}

template<typename T>
void mergeSort(T *arr, int n) {
    clock_t start = clock();
    mergeSort_(arr, n);
    std::cout << "MergeSort Time : " << double(clock() - start) / CLOCKS_PER_SEC << "s" << std::endl;
}

#endif //SORTALGORITHM_MERGESORT_H
