#include "Edge.h"

Edge::Edge(int clientA, int clientB, double weight, int direction) : clientA(clientA), clientB(clientB), weight(weight),
                                                                     direction(direction) {}

int Edge::getClientA() const {
    return clientA;
}

void Edge::setClientA(int clientA) {
    Edge::clientA = clientA;
}

int Edge::getClientB() const {
    return clientB;
}

void Edge::setClientB(int clientB) {
    Edge::clientB = clientB;
}

double Edge::getWeight() const {
    return weight;
}

void Edge::setWeight(double weight) {
    Edge::weight = weight;
}

int Edge::getDirection() const {
    return direction;
}

void Edge::setDirection(int direction) {
    Edge::direction = direction;
}

Edge::Edge() {}


