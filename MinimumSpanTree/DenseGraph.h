//
// Created by yao on 19-12-24.
//

#ifndef MINIMUMSPANTREE_DENSEGRAPH_H
#define MINIMUMSPANTREE_DENSEGRAPH_H

#include <vector>
#include <fstream>
#include <iomanip>
#include "Edge.h"
template<typename Weight>
class DenseGraph {
private:
    int n;
    int m;
    bool directed;
    std::vector<std::vector<Edge<Weight> *>> g;
public:
    DenseGraph(int n, bool directed) {
        this->n = n;
        this->m = 0;
        this->directed = directed;
        this->g = std::vector<std::vector<Edge<Weight> *>>(n, std::vector<Edge<Weight> *>(n, NULL));
    }
    ~DenseGraph() {
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
        return g[v][w];
    }
    void addEdge(int v, int w, Weight weight) {

        if (hasEdge(v, w)) {
            delete g[v][w];
            if (!directed)
                delete g[w][v];
            m--;
        }
        g[v][w] = new Edge<Weight>(v, w, weight);
        if (!directed)
            g[w][v] = new Edge<Weight>(w, v, weight);
        m++;
    }
    friend std::ostream &operator<<(std::ostream &out, const DenseGraph<Weight> &denseGraph) {
        for (int i = 0; i < denseGraph.g.size(); ++i) {
            for (int j = 0; j < denseGraph.g[i].size(); ++j) {
                if (denseGraph.g[i][j])
                    out << denseGraph.g[i][j]->wt() << " ";
                else
                    out << "NULL ";
            }
            out << std::endl;
        }
        return out;
    }
    class iterator {
    private:
        DenseGraph &G;
        int v;
        int index;
    public:
        iterator(DenseGraph &denseGraph, int v) : G(denseGraph) {
            this->v = v;
            this->index = -1;
        }
        Edge<Weight> *begin() {
            this->index = -1;
            return next();
        }
        Edge<Weight> *next() {
            while (G.g[v][++index] == NULL)
                ;
            return G.g[v][index];
        }
        bool end() {
            return this->index >= G.V();
        }
    };
};

#endif //MINIMUMSPANTREE_DENSEGRAPH_H
