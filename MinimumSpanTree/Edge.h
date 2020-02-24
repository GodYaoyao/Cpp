//
// Created by yao on 19-12-24.
//

#ifndef MINIMUMSPANTREE_EDGE_H
#define MINIMUMSPANTREE_EDGE_H

#include <cassert>
#include <fstream>
template<typename Weight>
class Edge {
private:
    int a, b;
    Weight weight;
public:
    Edge(int a, int b, Weight weight) {
        this->a = a;
        this->b = b;
        this->weight = weight;
    }
    int v() {
        return a;
    }
    int w() {
        return b;
    }
    Weight wt() {
        return weight;
    }
    int other(int x) {
        assert(x == a || x == b);
        return x == a ? b : a;
    }
    friend std::ostream &operator<<(std::ostream &out, const Edge &e) {
        out << "(" << e.a << "-" << e.b << ":" << e.weight << ")";
        return out;
    }
    bool operator<(Edge<Weight> &e) {
        return weight < e.wt();
    }
    bool operator<=(Edge<Weight> &e) {
        return weight <= e.wt();
    }
    bool operator>(Edge<Weight> &e) {
        return weight > e.wt();
    }
    bool operator>=(Edge<Weight> &e) {
        return weight >= e.wt();
    }
    bool operator==(Edge<Weight> &e) {
        return weight == e.wt();
    }
};

#endif //MINIMUMSPANTREE_EDGE_H
