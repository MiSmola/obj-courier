#ifndef OBJ_COURIER_ALGORITHM_H
#define OBJ_COURIER_ALGORITHM_H


#include <vector>
#include "datastructures/Routes.h"
#include "datastructures/Trip.h"
#include "logging/AuditEntity.h"

class Algorithm : public AuditEntity {
public:
    std::vector<std::vector<bool>> generateConnectionArray(Routes routes);

    Trip generateTrip(Routes routes, int from, std::vector<std::vector<bool>> connections);

    bool searchForConnectionBetweenClients(int clientFrom, int clientTo, std::vector<Edge> edges);

    bool alreadyContainsClient(std::vector<int> pathArray, int client, int pathArrayIndex);

    int findClientIndex(std::vector<int> clients, int clientValue, int size);

    Edge findEdgeInGraphByClientsAAndB(std::vector<Edge> searchEdges, int clientA, int clientB);

    Trip findTheCheapestTrip(std::vector<std::vector<Edge>> trips);

};


#endif //OBJ_COURIER_ALGORITHM_H
