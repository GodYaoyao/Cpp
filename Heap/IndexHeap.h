//
// Created by yao on 19-12-27.
//

#ifndef HEAP_INDEXHEAP_H
#define HEAP_INDEXHEAP_H

#include <algorithm>
template<typename T>
class IndexHeap {
private:
    T *data;
    int *index;
    int *reverse;
    int capacity;
    int count;
private:
    void shiftUp(int k) {
        int cur_index = index[k];
        while (k > 0 && data[cur_index] > data[index[(k - 1) / 2]]) {
            index[k] = index[(k - 1) / 2];
            reverse[index[k]] = k;
            k = (k - 1) / 2;
        }
        index[k] = cur_index;
        reverse[cur_index] = k;
    }
    void shiftDown(int k) {
        int cur_index = index[k];
        while (2 * k + 1 <= count) {
            int j = 2 * k + 1;
            if (j + 1 <= count && data[index[j + 1]] > data[index[j]])
                j += 1;
            if (data[cur_index] >= data[index[j]])
                break;
            index[k] = index[j];
            reverse[index[k]] = k;
            k = j;
        }
        index[k] = cur_index;
        reverse[cur_index] = k;
    }
public:
    IndexHeap(int capacity) {
        this->capacity = capacity;
        this->count = 0;
        data = new T[capacity];
        index = new int[capacity];
        reverse = new int[capacity];
    }
    IndexHeap() {
        this->capacity = 10;
        this->count = 0;
        data = new T[capacity];
        index = new int[capacity];
        reverse = new int[capacity];
        for (int i = 0; i < capacity; ++i) {
            reverse[i] = -1;
        }
    }
    ~IndexHeap() {
        delete[]data;
        delete[]index;
        delete[]reverse;
    }
    void insert(T t) {
        if (count >= capacity) {
            capacity *= 2;
            T *data_n = new T[capacity];
            int *index_n = new int[capacity];
            int *reverse_n = new int[capacity];
            for (int i = 0; i < count; ++i) {
                data_n[i] = data[i];
                index_n[i] = index[i];
                reverse_n[i] = reverse[i];
            }
            delete[]data;
            delete[]index;
            delete[]reverse;
            data = data_n;
            index = index_n;
            reverse = reverse_n;
        }
        data[count] = t;
        index[count] = count;
        reverse[count] = count;
        shiftUp(count);
        ++count;
    }
    T extractMax() {
        T ret = data[index[0]];
        data[index[0]] = data[index[count - 1]];
        index[0] = index[count - 1];
        reverse[index[0]] = 0;
        --count;
        shiftDown(0);
        return ret;
    }
    int size() {
        return count;
    }
    bool empty() {
        return count == 0;
    }
    bool contain(int i) {
        assert(i >= 0 && i < capacity);
        return reverse[i] != -1;
    }
    void change(int i, T t) {
        assert(contain(i));
        data[i] = t;
        int j = reverse[i];
        shiftUp(j);
        shiftDown(j);
    }
    friend std::ostream &operator<<(std::ostream &out, const IndexHeap &indexHeap) {
        out << "Index : ";
        for (int i = 0; i < indexHeap.count; ++i)
            out << indexHeap.index[i] << " ";
        out << std::endl;
        out << "Data : ";
        for (int i = 0; i < indexHeap.count; ++i)
            out << "(" << i << "," << indexHeap.data[i] << ") ";
        out << std::endl;
        return out;
    }
};

#endif //HEAP_INDEXHEAP_H
