//
// Created by yao on 19-12-29.
//

#ifndef SORTALGORITHM_INSERTSORT_H
#define SORTALGORITHM_INSERTSORT_H

template<typename T>
void insertSort1(T *arr, int n) {
    clock_t start = clock();
    for (int i = 1; i < n; ++i) {
        for (int j = i - 1; j >= 0; --j) {
            if (arr[j] <= arr[j + 1])
                break;
            std::swap(arr[j], arr[j + 1]);
        }
    }
    std::cout << "InsertSort1 Time : " << double(clock() - start) / CLOCKS_PER_SEC << "s" << std::endl;
}

template<typename T>
void insertSort2(T *arr, int n) {
//    clock_t start = clock();
    for (int i = 1; i < n; ++i) {
        T cur = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > cur) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = cur;
    }
//    std::cout << "InsertSort2 Time : " << double(clock() - start) / CLOCKS_PER_SEC << "s" << std::endl;
}

#endif //SORTALGORITHM_INSERTSORT_H
