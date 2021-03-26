//
// Created by djnic on 08.03.2021.
//

#ifndef OBJ_COURIER_TRIP_H
#define OBJ_COURIER_TRIP_H


#include <vector>
#include "Edge.h"

class Trip {
private:
    std::vector<Edge> edges;
    double summaryCost;

public:
    const std::vector<Edge> &getEdges() const;

    void setEdges(const std::vector<Edge> &edges);

    double getSummaryCost() const;

    void setSummaryCost(double summaryCost);

    Trip(std::vector<Edge> vector, double d);
};


#endif //OBJ_COURIER_TRIP_H
