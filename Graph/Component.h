//
// Created by yao on 19-12-23.
//

#ifndef GRAPH_COMPONENT_H
#define GRAPH_COMPONENT_H

#include <iostream>
#include <stack>
template<typename Graph>
class Component {
private:
    Graph &G;
    bool *visited;
    int *id;
    int ccount;

    void dfs1(int v) {
        visited[v] = true;
        id[v] = ccount;
        typename Graph::iterator iter(G, v);
        for (int i = iter.begin(); !iter.end(); i = iter.next()) {
            if (!visited[i]) {
                dfs1(i);
            }
        }
    }

    void dfs2(int v) {
        std::stack<int> st;
        st.push(v);
        visited[v] = true;
        while (!st.empty()){
            int current = st.top();
            st.pop();
            typename Graph::iterator iter(G, current);
            for (int i = iter.begin(); !iter.end(); i = iter.next()) {
                if(!visited[i]){
                    st.push(i);
                    visited[i] = true;
                }
            }
        }
    }
public:
    Component(Graph &graph) : G(graph) {
        this->visited = new bool[graph.V()];
        this->id = new int[graph.V()];
        this->ccount = 0;
        for (int i = 0; i < graph.V(); ++i) {
            visited[i] = false;
            id[i] = -1;
        }
        for (int i = 0; i < graph.V(); ++i) {
            if (!visited[i]) {
                dfs2(i);
                ccount++;
            }
        }
    }
    ~Component() {
        delete[]visited;
        delete[]id;
    }
    int count() {
        return ccount;
    }
    bool isConnected(int v, int w) {
        assert(v >= 0 && v < G.V());
        assert(w >= 0 && w < G.V());
        return id[v] == id[w];
    }
};

#endif //GRAPH_COMPONENT_H
