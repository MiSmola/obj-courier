//
// Created by djnic on 16.03.2021.
//

#include <fstream>
#include <iostream>
#include <string>
#include "Mapper.h"
#include "StringUtils.h"

Routes Mapper::mapFileToRoutes(std::string fileName) {
    std::ifstream file(fileName);
    std::string line, result, content;
    Routes routes;
    std::set<int> clients;
    if (file.is_open()) {
        Graph graph;
        int numberOfLines = 0;
        while (!file.eof()) {
            getline(file, line, ',');
            if (line.size() > 1) {
                //Phase I
                line.erase(std::remove_if(line.begin(), line.end(), StringUtils::isUnwantedChar), line.end());
                //Phase II
                int size;
                std::vector<std::string> strs = StringUtils::split(line, ':', size); //tab after first split "1-2 4.5"
                int direction, clientFrom, clientTo; // temporary direction variable
                bool containsRightArrow = strs[0].find("->") != std::string::npos,
                        containsLeftArrow = strs[0].find("<-") != std::string::npos;
                if (containsRightArrow || containsLeftArrow) {
                    if (containsRightArrow) {                                                      // condition ->
                        direction = 1;
                        clientFrom = std::stoi(StringUtils::split(strs[0], "->", size)[0]);
                        clientTo = std::stoi(StringUtils::split(strs[0], "->", size)[1]);
                    }
                    if (containsLeftArrow) {                                                      // condition <-
                        direction = 2;
                        clientFrom = std::stoi(StringUtils::split(strs[0], "<-", size)[0]);
                        clientTo = std::stoi(StringUtils::split(strs[0], "<-", size)[1]);
                    }
                } else {
                    direction = 0;
                    clientFrom = std::stoi(StringUtils::split(strs[0], '-', size)[0]);   // condition -
                    clientTo = std::stoi(StringUtils::split(strs[0], '-', size)[1]);
                }

                double weight = std::stod(strs[1]);
                Edge edge{clientFrom, clientTo, weight, direction};
                // Clients set population - all duplicates are reduced
                clients.insert(clientFrom);
                clients.insert(clientTo);
                //FIXME: graph.getEdges().push_back(edge);
                graph.edges.push_back(edge);
                numberOfLines++;
            }

        }
        if (numberOfLines == 0) {
            throw -1;
        }
        routes.setMap(graph);
        routes.setClients(clients);
        routes.setSize(clients.size());
    } else {
        throw -2;
    }
    file.close();
    return routes;
}

std::string Mapper::mapTripToFile(Trip trip, std::string resultFilePath) {
    return " ";
}
