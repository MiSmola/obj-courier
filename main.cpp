#include <iostream>
#include <string>
#include "model/Mapper.h"
#include "model/Algorithm.h"
#include "controller/Controller.h"
#include "model/Params.h"

int main(int argc, char *argv[]) {
    Params::loadParameters();
    Controller *controller = new Controller();
    controller->execute(argc, argv);
    return 0;
}
