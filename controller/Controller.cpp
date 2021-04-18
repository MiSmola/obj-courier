//
// Created by djnic on 27.03.2021.
//

#include "Controller.h"
#include "../model/Mapper.h"
#include "../model/Algorithm.h"
#include "../model/Utils.h"
#include "../view/View.h"
#include "../model/Params.h"
#include "../model/Constants.h"
#include <filesystem>
#include <iostream>
#include <regex>

namespace fs = std::filesystem;

void Controller::execute(int argc, char **argv) {
    Utils *utils = new Utils();
    View *view = new View();
    Mapper *mapper = new Mapper();
    Algorithm *algorithm = new Algorithm();


    view->welcomeMessage();

    std::regex textFileExtensionPattern(".+[.txt|.TXT]$");
    try {
        if (utils->fetchParametersAndPopulateInputFields(argc, argv)[2] == "-h")
            view->displayInstructionScreen();

        std::string inputPath = utils->fetchParametersAndPopulateInputFields(argc, argv)[0],
                resultFileName = utils->fetchParametersAndPopulateInputFields(argc, argv)[1];

        bool regexMatch = std::regex_match(inputPath, textFileExtensionPattern);
        bool multiMode = utils->fetchParametersAndPopulateInputFields(argc, argv)[3] == "-m";

        if ((regexMatch && !multiMode) || (!regexMatch && multiMode)) {
            Params::loadParameters();
            bool timestamp, numbers;
            auto it = Params::cfgMap.find(TSTAMP_PROPERTY);
            std::string paramOutfileNameTimestamp;
            if (it != Params::cfgMap.end())
                paramOutfileNameTimestamp = it->second;
            if (paramOutfileNameTimestamp == "true") timestamp = true;
            else timestamp = false;

            if (utils->fetchParametersAndPopulateInputFields(argc, argv)[3] == "-m") {
                int resultNumber = 0;
                numbers = true;
                for (const auto &entry : fs::directory_iterator(inputPath)) {
                    fs::path path{entry.path()};
                    std::string pathString{path.string()};
                    if (std::regex_match(pathString, textFileExtensionPattern)) {
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
        } else
            throw -3;
    } catch (int e) {
        if (e == -1) view->errorMapperData();
        if (e == -2) view->errorMapperDirection();
        if (e == -3) view->errorFileExtension();
        if (e == -4) view->errorPropFileForm();
    }
    view->endMessage();
}

void
Controller::generateResult(Mapper mapper, Algorithm algorithm, std::string inputPath, std::string resultFilePath,
                           bool timestamp, bool numbers, int resultNumber) {

    Routes routes = mapper.mapFileToRoutes(inputPath);
    Trip trip = algorithm.generateTrip(routes, *routes.getClients().begin(),
                                       algorithm.generateConnectionArray(routes));
    mapper.mapTripToFile(trip, resultFilePath, timestamp, numbers, resultNumber, inputPath);
}
