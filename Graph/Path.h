//
// Created by yao on 19-12-23.
//

#ifndef GRAPH_PATH_H
#define GRAPH_PATH_H

#include <cassert>
#include <vector>
#include <stack>
#include <ostream>
template<typename Graph>
class Path {
private:
    Graph &G;
    bool *visited;
    int *from;
    std::vector<int> pv;

    void dfs(int v) {
        visited[v] = true;
        typename Graph::iterator iter(G, v);
        for (int i = iter.begin(); !iter.end(); i = iter.next()) {
            if (!visited[i]) {
                from[i] = v;
                dfs(i);
            }
        }
    }

    void dfs2(int v) {
        std::stack<int> st;
        st.push(v);
        visited[v] = true;
        while (!st.empty()) {
            int current = st.top();
            st.pop();
            typename Graph::iterator iter(G, current);
            for (int i = iter.begin(); !iter.end(); i = iter.next()) {
                if (!visited[i]) {
                    from[i] = current;
                    st.push(i);
                    visited[i] = true;
                }
            }
        }
    }

public:
    Path(Graph &graph, int s, int e) : G(graph) {
        assert(s >= 0 && s <= G.V());
        assert(e >= 0 && e <= G.V());
        this->visited = new bool[graph.V()];
        this->from = new int[graph.V()];
        for (int i = 0; i < graph.V(); ++i) {
            visited[i] = false;
            from[i] = -1;
        }
        dfs2(s);
        std::stack<int> st;
        while (e != -1) {
            st.push(e);
            e = from[e];
        }
        this->pv.clear();
        while (!st.empty()) {
            this->pv.push_back(st.top());
            st.pop();
        }
    }
    ~Path() {
        delete[]visited;
        delete[]from;
    }
    friend std::ostream &operator<<(std::ostream &out, Path &path) {
        for (int i = 0; i < path.pv.size(); ++i) {
            out << path.pv[i] << "->";
        }
        out << "\b\b" << std::endl;
    }
};

#endif //GRAPH_PATH_H
