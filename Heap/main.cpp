#include <iostream>
#include "MaxHeap.h"
#include "HeapSort.h"
#include "IndexHeap.h"

int main() {
    srand(time(NULL));

    // 最大堆
    MaxHeap<int> maxHeap;
    for (int i = 0; i < 30; ++i) {
        int j = rand() % 50;
        maxHeap.insert(j);
//        std::cout << maxHeap << std::endl;
    }
    while (!maxHeap.isEmpty()) {
        std::cout << maxHeap.extractMax() << " ";
    }
    std::cout << std::endl;

    // 堆排序
    int n = 50;
    int arr[n];
    for (int k = 0; k < n; ++k) {
        arr[k] = rand() % n;
    }
    heapSort(arr, n);
    for (int k = 0; k < n; ++k) {
        std::cout << arr[k] << " ";
    }
    std::cout << std::endl;

    // 最大索引堆
    IndexHeap<int> indexHeap;
    for (int l = 0; l < 10; ++l) {
        indexHeap.insert(rand() % 50);
    }
    std::cout << indexHeap << std::endl;
    indexHeap.change(1, 50);
    indexHeap.change(3, 51);
    indexHeap.change(6, 52);
    std::cout << indexHeap << std::endl;
    while (!indexHeap.empty()) {
        std::cout << indexHeap.extractMax() << " ";
    }
    std::cout << std::endl;

    return 0;
}