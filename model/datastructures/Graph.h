//
// Created by djnic on 08.03.2021.
//

#ifndef OBJ_COURIER_GRAPH_H
#define OBJ_COURIER_GRAPH_H


#include "Edge.h"
#include <vector>

class Graph {
private:
    int size;


public:
    std::vector<Edge> edges = {};

    Graph();

    void addEdge(Edge edge);

    int getSize() const;

    void setSize(int size);

    std::vector<Edge> getEdges();

    void setEdges(const std::vector<Edge> &edges);
};


#endif //OBJ_COURIER_GRAPH_H
