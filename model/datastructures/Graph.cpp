#include "Graph.h"

void Graph::addEdge(Edge edge) {
    this->edges.push_back(edge);
}

std::vector<Edge> Graph::getEdges() {
    return edges;
}

void Graph::setEdges(const std::vector<Edge> &edges) {
    Graph::edges = edges;
}

Graph::Graph() {

}

