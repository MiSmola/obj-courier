//
// Created by djnic on 08.03.2021.
//

#ifndef OBJ_COURIER_ROUTES_H
#define OBJ_COURIER_ROUTES_H


#include "Graph.h"
#include <set>

class Routes {
private:
    std::set<int> clients;
    int size;
    Graph map;

public:

    void addClient(int client);

    const std::set<int> &getClients() const;

    void setClients(const std::set<int> &clients);

    int getSize() const;

    void setSize(int size);

    const Graph &getMap() const;

    void setMap(const Graph &map);
};


#endif //OBJ_COURIER_ROUTES_H
