//
// Created by yao on 19-12-29.
//

#ifndef SORTALGORITHM_SELECTSORT_H
#define SORTALGORITHM_SELECTSORT_H

#include <algorithm>
template<typename T>
void selectSort(T *arr, int n) {
    clock_t start = clock();
    for (int i = 0; i < n; ++i) {
        int min_index = i;
        for (int j = i; j < n; ++j) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        std::swap(arr[i], arr[min_index]);
    }
    std::cout << "SelectSort Time : " << double(clock() - start) / CLOCKS_PER_SEC << "s" << std::endl;
}

#endif //SORTALGORITHM_SELECTSORT_H
