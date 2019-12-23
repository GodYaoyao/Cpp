//
// Created by yao on 19-12-23.
//

#ifndef GRAPH_READGRAPH_H
#define GRAPH_READGRAPH_H

#include <iostream>
#include <fstream>
#include <cassert>

template<typename Graph>
class ReadGraph {
public:
    ReadGraph(Graph &graph, const std::string &file_name) {
        std::ifstream file1("../" + file_name);
        int x = 0, y = 0;
        int line = -1;
        assert(file1.is_open());
        while (file1 >> x >> y) {
            line++;
            if (line == 0) {
                assert(x == graph.V());
            } else {
                graph.addEdge(x, y);
            }
        }
    }
};

#endif //GRAPH_READGRAPH_H
