//
// Created by djnic on 16.03.2021.
//

#ifndef OBJ_COURIER_MAPPER_H
#define OBJ_COURIER_MAPPER_H


#include <iostream>
#include "datastructures/Routes.h"
#include "datastructures/Trip.h"
#include "datastructures/Graph.h"

class Mapper {
public:
    Routes mapFileToRoutes(std::string fileName);

    std::string mapTripToFile(Trip trip, std::string resultFilePath);
};


#endif //OBJ_COURIER_MAPPER_H
