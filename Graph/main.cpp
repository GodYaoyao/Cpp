#include <iostream>
#include "DenseGraph.h"
#include "SparseGraph.h"
#include "ReadGraph.h"
#include "Component.h"
#include "Path.h"
#include "ShortestPath.h"
int main() {
    std::cout << "Hello, World!" << std::endl;

    DenseGraph denseGraph(7, false);
    ReadGraph<DenseGraph> readGraph(denseGraph, "graph2.txt");
    std::cout << denseGraph << std::endl;

    SparseGraph sparseGraph(7, false);
    ReadGraph<SparseGraph> readGraph1(sparseGraph, "graph2.txt");
    std::cout << sparseGraph << std::endl;

    Component<DenseGraph> component(denseGraph);
    std::cout << component.count() << std::endl;
    std::cout << component.isConnected(0, 2) << std::endl;

    Component<SparseGraph> component1(sparseGraph);
    std::cout << component1.count() << std::endl;
    std::cout << component1.isConnected(1, 3) << std::endl;

    Path<DenseGraph> path(denseGraph, 0, 4);
    std::cout << path << std::endl;

    Path<SparseGraph> path1(sparseGraph, 0, 3);
    std::cout << path1 << std::endl;

    ShortestPath<DenseGraph> spath(denseGraph, 0);
    spath.shortestPath(4);

    ShortestPath<SparseGraph> spath1(sparseGraph, 0);
    spath1.shortestPath(3);

//    int N = 20;
//    int M = 100;
//    srand(time(NULL));
//
//    DenseGraph denseGraph(N, false);
//    for (int i = 0; i < M; ++i) {
//        int v = rand() % N;
//        int w = rand() % N;
//        denseGraph.addEdge(v, w);
//    }
//    std::cout << denseGraph << std::endl;
//    for (int k = 0; k < N; ++k) {
//        DenseGraph::iterator iter1(denseGraph, k);
//        for (int j = iter1.begin(); !iter1.end(); j = iter1.next()) {
//            std::cout << j << " ";
//        }
//        std::cout << std::endl;
//    }
//
//    std::cout << std::endl;
//
//    SparseGraph sparseGraph(N, false);
//    for (int i = 0; i < M; ++i) {
//        int v = rand() % N;
//        int w = rand() % N;
//        sparseGraph.addEdge(v, w);
//    }
//    std::cout << sparseGraph << std::endl;
//    for (int k = 0; k < N; ++k) {
//        SparseGraph::iterator iter2(sparseGraph, k);
//        for (int j = iter2.begin(); !iter2.end(); j = iter2.next()) {
//            std::cout << j << " ";
//        }
//        std::cout << std::endl;
//    }
    return 0;
}