//
// Created by djnic on 27.03.2021.
//

#ifndef OBJ_COURIER_CONTROLLER_H
#define OBJ_COURIER_CONTROLLER_H


#include <string>
#include "../model/Mapper.h"
#include "../model/Algorithm.h"

class Controller {
public:
    void execute(int argc, char *argv[]);

    void generateResult(Mapper mapper, Algorithm algorithm, std::string inputFilePath, std::string resultFilePath,
                        bool timestamp, bool numbers, int resultNumber);

};


#endif //OBJ_COURIER_CONTROLLER_H
