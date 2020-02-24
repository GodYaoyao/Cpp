#include <iostream>
#include "ReadGraph.h"
#include "DenseGraph.h"
#include "SparseGraph.h"
#include "LazyPrim.h"
#include "Prim.h"
int main() {

    DenseGraph<double> denseGraph(8, false);
    ReadGraph<DenseGraph<double>, double> readGraph(denseGraph, "graph1.txt");
    std::cout << denseGraph << std::endl;
    for (int v = 0; v < 8; ++v) {
        DenseGraph<double>::iterator iter(denseGraph, v);
        for (Edge<double> *i = iter.begin(); !iter.end(); i = iter.next()) {
            std::cout << (*i) << " ";
        }
        std::cout << std::endl;
    }

    LazyPrim<DenseGraph<double>, double> lazyPrim(denseGraph);
    std::vector<Edge<double> *> mst = lazyPrim.mstEdges();
    for (int j = 0; j < mst.size(); ++j) {
        std::cout << *(mst[j]) << " ";
    }
    std::cout << lazyPrim.minWeight() << std::endl;
    std::cout << std::endl;

    SparseGraph<double> sparseGraph(8, false);
    ReadGraph<SparseGraph<double>, double> readGraph1(sparseGraph, "graph1.txt");
    std::cout << sparseGraph << std::endl;
    for (int v = 0; v < 8; ++v) {
        SparseGraph<double>::iterator iter(sparseGraph, v);
        for (Edge<double> *i = iter.begin(); !iter.end(); i = iter.next()) {
            std::cout << (*i) << " ";
        }
        std::cout << std::endl;
    }

    Prim<SparseGraph<double>, double> prim(sparseGraph);
    std::vector<double> mst_2 = prim.mstEdges();
    for (int j = 0; j < mst_2.size(); ++j) {
        std::cout << mst[j] << " ";
    }
    std::cout << prim.minWeight() << std::endl;
    std::cout << std::endl;

    return 0;
}