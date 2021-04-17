#include <iostream>
#include <string>
#include "model/Mapper.h"
#include "model/Algorithm.h"
#include "controller/Controller.h"
#include "model/Params.h"

#include <iostream>
#include <filesystem>


int main(int argc, char *argv[]) {
    //Params::myMap.empty();
    //Params *params = new Params();
    //params->loadParameters();
    Controller *controller = new Controller();
    controller->execute(argc, argv);
    return 0;
}
