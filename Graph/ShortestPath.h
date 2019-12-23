//
// Created by yao on 19-12-23.
//

#ifndef GRAPH_SHORTESTPATH_H
#define GRAPH_SHORTESTPATH_H

#include <cassert>
#include <queue>
#include <iostream>
template<typename Graph>
class ShortestPath {
private:
    bool *visited;
    int *from;
    int *ord;
    std::vector<int> pv;
public:
    ShortestPath(Graph &graph, int s) {
        assert(s >= 0 && s < graph.V());
        visited = new bool[graph.V()];
        from = new int[graph.V()];
        ord = new int[graph.V()];
        for (int i = 0; i < graph.V(); ++i) {
            visited[i] = false;
            from[i] = -1;
            ord[i] = -1;
        }
        std::queue<int> qu;
        qu.push(s);
        visited[s] = true;
        ord[s] = 0;
        while (!qu.empty()) {
            int current = qu.front();
            qu.pop();
            typename Graph::iterator iter(graph, current);
            for (int i = iter.begin(); !iter.end(); i = iter.next()) {
                if (!visited[i]) {
                    qu.push(i);
                    visited[i] = true;
                    from[i] = current;
                    ord[i] = ord[current] + 1;
                }
            }
        }
    }
    ~ShortestPath() {
        delete[]visited;
        delete[]from;
        delete[]ord;
    }
    void shortestPath(int e) {
        pv.clear();
        while (e != -1) {
            pv.push_back(e);
            e = from[e];
        }
        for (int i = pv.size() - 1; i >= 0; --i) {
            std::cout << pv[i] << "->";
        }
        std::cout << "\b\b" << std::endl;
    }
};

#endif //GRAPH_SHORTESTPATH_H
