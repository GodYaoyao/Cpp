//
// Created by yao on 19-12-24.
//

#ifndef MINIMUMSPANTREE_SPARSEGRAPH_H
#define MINIMUMSPANTREE_SPARSEGRAPH_H

#include <vector>
#include "Edge.h"

template<typename Weight>
class SparseGraph {
private:
    int n;
    int m;
    bool directed;
    std::vector<std::vector<Edge<Weight> *>> g;
public:
    SparseGraph(int n, bool directed) {
        this->n = n;
        this->m = 0;
        this->directed = directed;
        g = std::vector<std::vector<Edge<Weight> *>>(n, std::vector<Edge<Weight> *>());
    }
    ~SparseGraph() {
        for (int i = 0; i < g.size(); ++i) {
            for (int j = 0; j < g[i].size(); ++j) {
                delete g[i][j];
            }
        }
    }
    int V() {
        return n;
    }
    int E() {
        return m;
    }
    bool hasEdge(int v, int w) {
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);
        for (int i = 0; i < g[v].size(); ++i) {
            if (g[v][i]->other(v) == w)
                return true;
        }
        return false;
    }
    void addEdge(int v, int w, Weight weight) {
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);
        g[v].push_back(new Edge<Weight>(v, w, weight));
        if (!directed)
            g[w].push_back(new Edge<Weight>(w, v, weight));
        m++;
    }
    friend std::ostream &operator<<(std::ostream &out, const SparseGraph &sparseGraph) {
        for (int i = 0; i < sparseGraph.g.size(); ++i) {
            out << i << ":";
            for (int j = 0; j < sparseGraph.g[i].size(); ++j) {
                out << (*sparseGraph.g[i][j]) << ",";
            }
            out << std::endl;
        }
        return out;
    }
    class iterator {
    private:
        SparseGraph &G;
        int v;
        int index;
    public:
        iterator(SparseGraph &sparseGraph, int v) : G(sparseGraph) {
            this->v = v;
            this->index = 0;
        }
        Edge<Weight> *begin() {
            this->index = 0;
            if (G.g[v].empty())
                return NULL;
            return G.g[v][index];
        }
        Edge<Weight> *next() {
            return G.g[v][++index];
        }
        bool end() {
            return this->index >= G.g[v].size();
        }
    };
};

#endif //MINIMUMSPANTREE_SPARSEGRAPH_H
