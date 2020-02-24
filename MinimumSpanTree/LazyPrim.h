//
// Created by yao on 19-12-24.
//

#ifndef MINIMUMSPANTREE_LAZYPRIM_H
#define MINIMUMSPANTREE_LAZYPRIM_H

#include "Edge.h"
#include <vector>
#include <queue>
#include <functional>

template<typename Graph, typename Weight>
class LazyPrim {
private:
    struct compare {
        bool operator()(Edge<Weight> *e1, Edge<Weight> *e2) {
            return (*e1) > (*e2);
        }
    };
    void look(int v) {
        assert(!visited[v]);
        visited[v] = true;
        typename Graph::iterator iter(G, v);
        for (Edge<Weight> *i = iter.begin(); !iter.end(); i = iter.next()) {
            if (!visited[i->other(v)])
                this->pq.push(i);
        }
    }

public:
    LazyPrim(Graph &graph) : G(graph) {
        visited = new bool[graph.V()];
        for (int i = 0; i < graph.V(); ++i) {
            visited[i] = false;
        }
        mst.clear();
        look(0);
        while (!pq.empty()) {
            Edge<Weight> *e = pq.top();
            pq.pop();
            if (visited[e->v()] == visited[e->w()])
                continue;
            else
                mst.push_back(e);
            if (!visited[e->v()])
                look(e->v());
            else
                look(e->w());
        }
        mst_weight = mst[0]->wt();
        for (int j = 1; j < mst.size(); ++j) {
            mst_weight += mst[j]->wt();
        }
    }
    ~LazyPrim() {
        delete[]visited;
    }
    std::vector<Edge<Weight> *> mstEdges() {
        return mst;
    }
    Weight minWeight() {
        return mst_weight;
    }

private:
    Graph &G;
    bool *visited;
    std::priority_queue<Edge<Weight> *, std::vector<Edge<Weight> *>, compare> pq;
    std::vector<Edge<Weight> *> mst;
    Weight mst_weight;
};

#endif //MINIMUMSPANTREE_LAZYPRIM_H
