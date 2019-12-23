//
// Created by yao on 19-12-21.
//

#ifndef GRAPH_DENSEGRAPH_H
#define GRAPH_DENSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>

class DenseGraph {
private:
    int n, m;
    bool directed;
    std::vector<std::vector<bool>> g;
public:
    DenseGraph(int n, bool directed) {
        this->n = n;
        this->m = 0;
        this->directed = directed;
        for (int i = 0; i < n; ++i) {
            this->g.push_back(std::vector<bool>(n, false));
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
        if (hasEdge(v, w))
            return;
        g[v][w] = true;
        if (!directed)
            g[w][v] = true;
        m++;
    }
    bool hasEdge(int v, int w) {
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);
        return g[v][w];
    }
    friend std::ostream &operator<<(std::ostream &out, DenseGraph &denseGraph) {
        for (int i = 0; i < denseGraph.g.size(); ++i) {
            for (int j = 0; j < denseGraph.g[i].size(); ++j) {
                out << denseGraph.g[i][j] << " ";
            }
            out << std::endl;
        }
        return out;
    }
    class iterator {
    public:
        DenseGraph &G;
        int v;
        int index;
    public:
        iterator(DenseGraph &denseGraph, int v) : G(denseGraph) {
            this->v = v;
            this->index = -1;
        }
        int begin() {
            this->index = -1;
            return next();
        }
        int next() {
            while (!G.g[v][++index])
                ;
            return index;
        }
        bool end() {
            return this->index >= G.g[v].size();
        }
    };
};

#endif //GRAPH_DENSEGRAPH_H
