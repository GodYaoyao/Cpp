//
// Created by yao on 19-12-21.
//

#ifndef GRAPH_SPARSEGRAPH_H
#define GRAPH_SPARSEGRAPH_H

#include <vector>
#include <cassert>
class SparseGraph {
private:
    int n, m;
    bool directed;
    std::vector<std::vector<int>> g;
public:
    SparseGraph(int n, bool directed) {
        this->n = n;
        this->m = 0;
        this->directed = directed;
        for (int i = 0; i < n; ++i) {
            this->g.push_back(std::vector<int>());
        }
    }
    int V() {
        return n;
    }
    int E() {
        return m;
    }
    void addEdge(int v, int w) {
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);
        g[v].push_back(w);
        if (v != w && !directed)
            g[w].push_back(v);
        m++;
    }
    bool hasEdge(int v, int w) {
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);
        for (int i = 0; i < g[v].size(); ++i) {
            if (g[v][i] == w)
                return true;
        }
        return false;
    }
    friend std::ostream &operator<<(std::ostream &out, SparseGraph &sparseGraph) {
        for (int i = 0; i < sparseGraph.g.size(); ++i) {
            out << i << ": ";
            for (int j = 0; j < sparseGraph.g[i].size(); ++j) {
                out << sparseGraph.g[i][j] << " ";
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
        int begin() {
            this->index = 0;
            if (G.g[v].empty())
                return -1;
            return G.g[v][index];
        }
        int next() {
            this->index++;
            if (G.g[v].empty())
                return -1;
            return G.g[v][index];
        }
        bool end() {
            return this->index >= G.g[v].size();
        }
    };
};
#endif //GRAPH_SPARSEGRAPH_H
