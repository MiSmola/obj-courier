#include <iostream>
#include <string>
#include "model/Mapper.h"
#include "model/Algorithm.h"
#include "controller/Controller.h"
#include "model/Params.h"

#include <iostream>
#include <filesystem>
#include <regex>


int main(int argc, char *argv[]) {
    Controller *controller = new Controller();
    controller->execute(argc, argv);
    return 0;
}
