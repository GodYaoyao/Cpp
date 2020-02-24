//
// Created by yao on 19-12-24.
//

#ifndef MINIMUMSPANTREE_READGRAPH_H
#define MINIMUMSPANTREE_READGRAPH_H

#include <iostream>
#include <fstream>
#include <cassert>
template<typename Graph, typename Weight>
class ReadGraph {
public:
    ReadGraph(Graph &graph, const std::string &filename) {
        std::ifstream file("../" + filename);
        int x=0, y=0;
        Weight weight=0.;
        int line = 0;
        assert(file.is_open());
        while (file >> x >> y >> weight) {
            if (++line == 1) {
                assert(x == graph.V());
            } else {
                graph.addEdge(x, y, weight);
            }
        }
    }
};

#endif //MINIMUMSPANTREE_READGRAPH_H
