//
// Created by yao on 20-6-2.
//

#ifndef UNIONFIND_UNIONFIND_H
#define UNIONFIND_UNIONFIND_H

#include <cassert>

namespace UF1 {
    // Quick Find
    class UnionFind {

    private:
        int *id;
        int count;

    public:
        UnionFind(int n) {
            count = n;
            id = new int[n];
            for (int i = 0; i < n; ++i) {
                id[i] = i;
            }
        }
        ~UnionFind() {
            delete[]id;
        }
        int find(int p) {
            assert(0 <= p && p < count);
            return id[p];
        }
        bool isConnected(int p, int q) {
            return find(p) == find(q);
        }
        void unionElements(int p, int q) {
            int pID = find(p);
            int qID = find(q);
            if (pID == qID)
                return;
            // O(n)
            for (int i = 0; i < count; i++) {
                if (id[i] == pID)
                    id[i] = qID;
            }
        }
    };
}

namespace UF2 {
    //Quick Union
    class UnionFind {

    private:
        int *parent;
        int count;

    public:
        UnionFind(int n) {
            count = n;
            parent = new int[n];
            for (int i = 0; i < n; ++i) {
                parent[i] = i;
            }
        }
        ~UnionFind() {
            delete[]parent;
        }
        int find(int p) {
            assert(0 <= p && p < count);
            while (p != parent[p])
                p = parent[p];
            return p;
        }
        bool isConnected(int p, int q) {
            return find(p) == find(q);
        }
        void unionElements(int p, int q) {
            int p_root = find(p);
            int q_root = find(q);
            if (p_root == q_root)
                return;
            parent[p_root] = q_root;
        }
    };
}

namespace UF3 {
    //Quick Union 基于size的优化
    class UnionFind {

    private:
        int *parent;
        int *size;
        int count;

    public:
        UnionFind(int n) {
            count = n;
            parent = new int[n];
            size = new int[n]; //size[i]表示以i为根节点的树元素个数
            for (int i = 0; i < n; ++i) {
                parent[i] = i;
                size[i] = 1;
            }
        }
        ~UnionFind() {
            delete[]parent;
            delete[]size;
        }
        int find(int p) {
            assert(0 <= p && p < count);
            while (p != parent[p])
                p = parent[p];
            return p;
        }
        bool isConnected(int p, int q) {
            return find(p) == find(q);
        }
        void unionElements(int p, int q) {
            int p_root = find(p);
            int q_root = find(q);
            if (p_root == q_root)
                return;
            if (size[p_root] < size[q_root]) {
                parent[p_root] = q_root;
                size[q_root] += size[p_root];
            } else {
                parent[q_root] = p_root;
                size[p_root] += size[q_root];
            }
        }
    };
}

namespace UF4 {
    //Quick Union 基于rank的优化
    class UnionFind {

    private:
        int *parent;
        int *rank;
        int count;

    public:
        UnionFind(int n) {
            count = n;
            parent = new int[n];
            rank = new int[n]; //rank[i]表示以i为根节点的树元素个数
            for (int i = 0; i < n; ++i) {
                parent[i] = i;
                rank[i] = 1;
            }
        }
        ~UnionFind() {
            delete[]parent;
            delete[]rank;
        }
        int find(int p) {
            assert(0 <= p && p < count);
            while (p != parent[p])
                p = parent[p];
            return p;
        }
        bool isConnected(int p, int q) {
            return find(p) == find(q);
        }
        void unionElements(int p, int q) {
            int p_root = find(p);
            int q_root = find(q);
            if (p_root == q_root)
                return;
            if (rank[p_root] < rank[q_root]) {
                parent[p_root] = q_root;
            } else if (rank[p_root] > rank[q_root]) {
                parent[q_root] = p_root;
            } else {
                parent[p_root] = q_root;
                rank[q_root]++;
            }
        }
    };
}

namespace UF5 {
    //Quick Union 基于rank的优化
    class UnionFind {

    private:
        int *parent;
        int *rank;
        int count;

    public:
        UnionFind(int n) {
            count = n;
            parent = new int[n];
            rank = new int[n]; //rank[i]表示以i为根节点的树元素个数
            for (int i = 0; i < n; ++i) {
                parent[i] = i;
                rank[i] = 1;
            }
        }
        ~UnionFind() {
            delete[]parent;
            delete[]rank;
        }
        //路径压缩，似乎改变了根的rank
        int find(int p) {
            assert(0 <= p && p < count);
//            while (p != parent[p]){
//                parent[p]=parent[parent[p]];
//                p=parent[p];
//            }
//            return p;

            if (p != parent[p])
                parent[p] = find(p);
            return parent[p];
        }
        bool isConnected(int p, int q) {
            return find(p) == find(q);
        }
        void unionElements(int p, int q) {
            int p_root = find(p);
            int q_root = find(q);
            if (p_root == q_root)
                return;
            if (rank[p_root] < rank[q_root]) {
                parent[p_root] = q_root;
            } else if (rank[p_root] > rank[q_root]) {
                parent[q_root] = p_root;
            } else {
                parent[p_root] = q_root;
                rank[q_root]++;
            }
        }
    };
}

#endif //UNIONFIND_UNIONFIND_H
