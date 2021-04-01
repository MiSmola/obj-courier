//
// Created by djnic on 27.03.2021.
//

#include "Controller.h"
#include "../model/Mapper.h"
#include "../model/Algorithm.h"
#include "../model/Utils.h"
#include "../view/View.h"
#include "../model/Params.h"

void Controller::execute(int argc, char **argv) {
    Mapper *mapper = new Mapper();
    Algorithm *algorithm = new Algorithm();
    Utils *utils = new Utils();
    View *view = new View();
    view->welcomeMessage();
    try {
        if (utils->fetchParametersAndPopulateInputFields(argc, argv)[2] == "-h")
            view->displayInstructionScreen();
        std::string fileName = utils->fetchParametersAndPopulateInputFields(argc, argv)[0],
                resultFileName = utils->fetchParametersAndPopulateInputFields(argc, argv)[1];
        if (fileName != "" && resultFileName != "") {
            //FIXME Uncomment
            //Params::loadParameters();
            Routes routes = mapper->mapFileToRoutes(fileName);
            Trip trip = algorithm->generateTrip(routes, *routes.getClients().begin(),
                                                algorithm->generateConnectionArray(routes));
            mapper->mapTripToFile(trip, resultFileName);
        }
    } catch (int e) {
        if (e == -1) view->errorMapperData();
        if (e == -2) view->errorMapperDirection();
    }
    view->endMessage();
}
