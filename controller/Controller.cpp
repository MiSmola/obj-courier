//
// Created by djnic on 27.03.2021.
//

#include "Controller.h"
#include "../model/Mapper.h"
#include "../model/Algorithm.h"
#include "../model/Utils.h"
#include "../view/View.h"
#include "../model/Params.h"
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

void Controller::execute(int argc, char **argv) {
    Utils *utils = new Utils();
    View *view = new View();
    Mapper *mapper = new Mapper();
    Algorithm *algorithm = new Algorithm();
    view->welcomeMessage();
    try {
        if (utils->fetchParametersAndPopulateInputFields(argc, argv)[2] == "-h")
            view->displayInstructionScreen();

        std::string inputPath = utils->fetchParametersAndPopulateInputFields(argc, argv)[0],
                resultFileName = utils->fetchParametersAndPopulateInputFields(argc, argv)[1];
        bool timestamp = true, numbers;     //FIXME Timestamp hardcode

        if (utils->fetchParametersAndPopulateInputFields(argc, argv)[3] == "-m") {
            int resultNumber = 0;
            numbers = true;
            for (const auto &entry : fs::directory_iterator(inputPath)) {
                fs::path path{entry.path()};
                std::string pathString{path.string()};
                std::string txtCheck = pathString.substr(pathString.size() - 4, 4);
                if (txtCheck == ".txt") {
                    if (inputPath != "" && resultFileName != "")
                        resultNumber++;
                    generateResult(*mapper, *algorithm, pathString, resultFileName, timestamp, numbers, resultNumber);
                }
            }
        } else {
            int resultNumber = 0;
            numbers = false;
            generateResult(*mapper, *algorithm, inputPath, resultFileName, timestamp, numbers, resultNumber);
        }

    } catch (int e) {
        if (e == -1) view->errorMapperData();
        if (e == -2) view->errorMapperDirection();
    }
    view->endMessage();
}

void
Controller::generateResult(Mapper mapper, Algorithm algorithm, std::string inputFilePath, std::string resultFilePath,
                           bool timestamp, bool numbers, int resultNumber) {

    Routes routes = mapper.mapFileToRoutes(inputFilePath);
    Trip trip = algorithm.generateTrip(routes, *routes.getClients().begin(),
                                       algorithm.generateConnectionArray(routes));
    mapper.mapTripToFile(trip, resultFilePath, timestamp, numbers, resultNumber);
}
