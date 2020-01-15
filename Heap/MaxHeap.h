//
// Created by yao on 19-12-26.
//

#ifndef HEAP_MAXHEAP_H
#define HEAP_MAXHEAP_H

#include <cassert>
#include <algorithm>
template<typename Item>
class MaxHeap {
private:
    int capacity;
    int size;
    Item *item;
private:
    void shiftUp(int k) {
        Item cur = item[k];
        while (k > 1 && item[k / 2] < cur) {
            item[k] = item[k / 2];
            k /= 2;
        }
        item[k] = cur;
    }
    void shiftDown(int k) {
        Item cur = item[k];
        while (2 * k <= size) {
            int j = 2 * k;
            if (j + 1 <= size && item[j + 1] > item[j])
                j += 1;
            if (cur >= item[j])
                break;
            item[k] = item[j];
            k = j;
        }
        item[k] = cur;
    }
public:
    MaxHeap(int n) {
        this->capacity = n;
        this->size = 0;
        this->item = new Item[n + 1];
    }
    MaxHeap() {
        this->capacity = 10;
        this->size = 0;
        this->item = new Item[10 + 1];
    }
    ~MaxHeap() {
        delete[]item;
    }
    int getSize() {
        return size;
    }
    bool isEmpty() {
        return size == 0;
    }
    void insert(Item i) {
        if (size >= capacity) {
            capacity *= 2;
            Item *temp = new Item[capacity + 1];
            for (int j = 1; j <= size; ++j) {
                temp[j] = item[j];
            }
            delete[]item;
            item = temp;
        }
        item[++size] = i;
        shiftUp(size);
    }
    Item extractMax() {
        assert(size > 0);
        if (size <= capacity / 4) {
            capacity /= 2;
            Item *temp = new Item[capacity + 1];
            for (int j = 1; j <= size; ++j) {
                temp[j] = item[j];
            }
            delete[]item;
            item = temp;
        }
        Item ret = item[1];
        item[1] = item[size--];
        shiftDown(1);
        return ret;
    }
    Item at(int n) {
        assert(n >= 1 && n <= size);
        return item[n];
    }
    Item operator[](int n) {
        assert(n >= 1 && n <= size);
        return item[n];
    }
    friend std::ostream &operator<<(std::ostream &out, const MaxHeap &maxHeap) {
        for (int i = 0; i < maxHeap.size; ++i) {
            out << maxHeap.item[i + 1] << " ";
        }
        return out;
    }
};

#endif //HEAP_MAXHEAP_H
