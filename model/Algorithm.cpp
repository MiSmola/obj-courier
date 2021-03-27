//
// Created by djnic on 17.03.2021.
//

#include "Algorithm.h"
#include "Utils.h"

std::vector<std::vector<bool>> Algorithm::generateConnectionArray(Routes routes) {
    std::vector<int> clients = Utils::convertIntSetToVector(routes.getClients());

    std::vector<std::vector<bool>> connections;
    for (int i = 0; i < clients.size(); i++) {
        std::vector<bool> row;
        row.clear();
        for (int j = 0; j < clients.size(); j++) {
            row.insert(row.begin() + j,
                       searchForConnectionBetweenClients(clients[i], clients[j], routes.getMap().getEdges()));
        }
        connections.insert(connections.begin() + i, row);
    }
    return connections;
}

Trip Algorithm::generateTrip(Routes routes, int from, std::vector<std::vector<bool>> connections) {
    int n = routes.getSize() - 1;
    std::vector<int> clientsVector = Utils::convertIntSetToVector(routes.getClients());
    std::vector<int> clients = Utils::convertIntSetToVectorWithBeginValue(clientsVector, 0);
    std::vector<int> pathArray;

    for (int i = 0; i <= n; i++)
        pathArray.insert(pathArray.begin() + i, 0);

    bool backward = false, starting = true;
    int clientsIndex = from, pathArrayIndex = 0;
    std::vector<std::vector<Edge>> edgesOfEdges;

    while (pathArrayIndex >= 0) {
        if (!alreadyContainsClient(pathArray, clients[clientsIndex], pathArrayIndex) && (starting ||
                                                                                         (pathArrayIndex != 0 &&
                                                                                          (clients[clientsIndex] - 1 >=
                                                                                           0 &&
                                                                                           pathArray[pathArrayIndex -
                                                                                                     1] - 1 >= 0)
                                                                                          && connections[
                                                                                                     findClientIndex(
                                                                                                             clients,
                                                                                                             pathArray[
                                                                                                                     pathArrayIndex -
                                                                                                                     1],
                                                                                                             clients.size()) -
                                                                                                     1][
                                                                                                     findClientIndex(
                                                                                                             clients,
                                                                                                             clients[clientsIndex],
                                                                                                             clients.size()) -
                                                                                                     1] == 1))) {
            starting = false;
            pathArray[pathArrayIndex] = clients[clientsIndex];

            if (clientsIndex == 0) backward = true;
            else backward = false;

            if (pathArrayIndex == n &&
                connections[findClientIndex(clients, pathArray[pathArrayIndex], clients.size()) - 1][0] == 1) {
                std::vector<Edge> edges;
                for (int j = 0; j < (n + 1); j++) {
                    if (j != 0) {
                        edges.push_back(findEdgeInGraphByClientsAAndB(routes.getMap().getEdges(), pathArray[j - 1],
                                                                      pathArray[j]));
                    }
                }
                edges.push_back(findEdgeInGraphByClientsAAndB(routes.getMap().getEdges(),
                                                              edges.at(edges.size() - 1).getClientB(),
                                                              edges.at(0).getClientA()));
                edgesOfEdges.push_back(edges);
                backward = true;
            }

            if (clients[clientsIndex] == 0) backward = true;

            if (!backward) {
                pathArrayIndex++;
                clientsIndex = 1;
            }

            if (backward && pathArrayIndex == n || backward && clients[clientsIndex] == 0) {
                pathArrayIndex--;
                clientsIndex = findClientIndex(clients, pathArray[pathArrayIndex], n + 1);
                clientsIndex++;
            }
        } else {
            if (clientsIndex == n + 1) clientsIndex = 0;

            if (clientsIndex == 0) {
                pathArrayIndex--;
                if (pathArrayIndex >= 0) {
                    clientsIndex = findClientIndex(clients, pathArray[pathArrayIndex], n + 1);
                    clientsIndex++;
                }
            } else
                clientsIndex++;
        }
    }
    return findTheCheapestTrip(edgesOfEdges);
}

bool Algorithm::searchForConnectionBetweenClients(int clientFrom, int clientTo, std::vector<Edge> edges) {
    for (Edge edge : edges) {
        if (((edge.getClientA() == clientFrom && edge.getClientB() == clientTo ||
              edge.getClientA() == clientTo && edge.getClientB() == clientFrom) && edge.getDirection() == 0) ||
            (edge.getClientA() == clientFrom && edge.getClientB() == clientTo && edge.getDirection() == 1) ||
            (edge.getClientA() == clientTo && edge.getClientB() == clientFrom && edge.getDirection() == 2))
            return true;
    }
    return false;
}

bool Algorithm::alreadyContainsClient(std::vector<int> pathArray, int client, int pathArrayIndex) {
    int count = 0;
    for (int i = 0; i < pathArrayIndex; i++) {
        if (pathArray[i] == client)
            count++;
    }
    return count >= 1;
}

int Algorithm::findClientIndex(std::vector<int> clients, int clientValue, int size) {
    for (int i = 0; i < size; i++) {
        if (clients[i] == clientValue)
            return i;
    }
    return -1;
}

Edge Algorithm::findEdgeInGraphByClientsAAndB(std::vector<Edge> searchEdges, int clientA, int clientB) {
    Edge result{};
    for (Edge searchEdge : searchEdges) {
        if (searchEdge.getClientA() == clientA && searchEdge.getClientB() == clientB)
            return searchEdge;
        else if (searchEdge.getClientA() == clientB && searchEdge.getClientB() == clientA) {
            result = searchEdge;
            result.setClientA(clientA);
            result.setClientB(clientB);
            return result;
        }
    }
    return result;
}

Trip Algorithm::findTheCheapestTrip(std::vector<std::vector<Edge>> trips) {
    double theCheapestTripSummaryCost = -1;
    std::vector<Edge> theCheapestTrip;
    for (int tripNo = 0; tripNo < trips.size(); tripNo++) {
        double summaryCost = 0;
        for (int edgeNo = 0; edgeNo < trips.at(tripNo).size(); edgeNo++) {
            summaryCost += trips.at(tripNo).at(edgeNo).getWeight();
        }
        if (summaryCost < theCheapestTripSummaryCost || tripNo == 0) {
            theCheapestTripSummaryCost = summaryCost;
            theCheapestTrip = trips.at(tripNo);
        }
    }
    Trip t(theCheapestTrip, theCheapestTripSummaryCost);
    return t;
}
