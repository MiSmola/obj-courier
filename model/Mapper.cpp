//
// Created by djnic on 16.03.2021.
//

#include <fstream>
#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include "Mapper.h"
#include "StringUtils.h"
#include "Params.h"
#include "Utils.h"


using std::chrono::system_clock;
std::time_t tt = system_clock::to_time_t(system_clock::now());
struct std::tm *ptm = std::localtime(&tt);

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
                        containsLeftArrow = strs[0].find("<-") != std::string::npos,
                        containsBidirectionalArrow = strs[0].find("-") != std::string::npos;
                if (containsRightArrow || containsLeftArrow) {
                    if (containsRightArrow) {                                                      // condition ->
                        direction = 1;
                        try {
                            clientFrom = std::stoi(StringUtils::split(strs[0], "->", size)[0]);
                            clientTo = std::stoi(StringUtils::split(strs[0], "->", size)[1]);
                        } catch (std::exception &e) {
                            throw -1;
                        }
                    }
                    if (containsLeftArrow) {                                                      // condition <-
                        direction = 2;
                        try {
                            clientFrom = std::stoi(StringUtils::split(strs[0], "<-", size)[0]);
                            clientTo = std::stoi(StringUtils::split(strs[0], "<-", size)[1]);
                        } catch (std::exception &e) {
                            throw -1;
                        }
                    }
                } else if (containsBidirectionalArrow) {
                    direction = 0;
                    try {
                        clientFrom = std::stoi(StringUtils::split(strs[0], '-', size)[0]);   // condition -
                        clientTo = std::stoi(StringUtils::split(strs[0], '-', size)[1]);
                    } catch (std::exception &e) {
                        throw -1;
                    }
                } else {
                    throw -2;
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

std::string Mapper::mapTripToFile(Trip trip, std::string resultFilePath, bool timestamp, bool numbers, int resultNumber, std::string inputPath) {
    std::string tripList;
    //Params params = Params();
    //FIXME Uncomment
    //if(!Params::ccfgMap.begin()->second == "true"){

    if (timestamp == true) {
        for (int i = 0; i < 4; i++) {
            resultFilePath.pop_back();
        }
        std::ostringstream oss;
        oss << std::put_time(ptm, "%F_%H%M%S");
        resultFilePath += oss.str() + ".txt";
    }

    if(numbers == true) resultFilePath = Utils::addNumberToFileName(resultFilePath, resultNumber);

    inputPath = Utils::extractFileNameFromPath(inputPath);
    std::ofstream file;
    file.open(resultFilePath, std::ios_base::app);
    if (file.is_open()) {
        std::ostringstream date;
        date << std::put_time(ptm, "%d/%m/%y %H:%M:%S");
        tripList += "Input file: " + inputPath + "\n" + "Date: " + date.str() + "\nTrip:\n";
        for (int i = 0; i < trip.getEdges().size(); i++) {
            tripList += (std::to_string(trip.getEdges()[i].getClientA()) + "->" +
                         std::to_string(trip.getEdges()[i].getClientB()) + "\n");
        }
        tripList += "Journey cost: " + std::to_string(trip.getSummaryCost()) + "\n";
        file << tripList;
        file.close();
    } else {
        std::cerr << "Error opening result file!" << std::endl;
    }
    return resultFilePath;
}
