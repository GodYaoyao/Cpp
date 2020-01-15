//
// Created by yao on 19-12-27.
//

#ifndef HEAP_HEAPSORT_H
#define HEAP_HEAPSORT_H

#include <iostream>
template<typename T>
void shiftDown(T *arr, int i, int n) {
    T cur = arr[i];
    while (2 * i + 1 < n) {
        int j = 2 * i + 1;
        if (j + 1 < n && arr[j + 1] > arr[j])
            j += 1;
        if (cur > arr[j])
            break;
        arr[i] = arr[j];
        i = j;
    }
    arr[i] = cur;
}

template<typename T>
void heapSort(T *arr, int n) {
    for (int i = (n - 1) / 2; i >= 0; --i) {
        shiftDown(arr, i, n);
    }
    for (int j = n - 1; j > 0; --j) {
        std::swap(arr[0], arr[j]);
        shiftDown(arr, 0, j);
    }
}

#endif //HEAP_HEAPSORT_H
