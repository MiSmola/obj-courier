#ifndef OBJ_COURIER_EDGE_H
#define OBJ_COURIER_EDGE_H


class Edge {
private:
    int clientA;
    int clientB;
    double weight;
    int direction;

public:
    Edge(int clientA, int clientB, double weight, int direction);

    int getClientA() const;

    void setClientA(int clientA);

    int getClientB() const;

    void setClientB(int clientB);

    double getWeight() const;

    void setWeight(double weight);

    int getDirection() const;

    void setDirection(int direction);

    Edge();
};


#endif //OBJ_COURIER_EDGE_H
