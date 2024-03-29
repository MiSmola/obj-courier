#include "Trip.h"

const std::vector<Edge> &Trip::getEdges() const {
    return edges;
}

void Trip::setEdges(const std::vector<Edge> &edges) {
    Trip::edges = edges;
}

double Trip::getSummaryCost() const {
    return summaryCost;
}

void Trip::setSummaryCost(double summaryCost) {
    Trip::summaryCost = summaryCost;
}

Trip::Trip(std::vector<Edge> vector, double d) {
    this->edges = vector;
    this->summaryCost = d;
}


