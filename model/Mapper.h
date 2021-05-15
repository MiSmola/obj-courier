#ifndef OBJ_COURIER_MAPPER_H
#define OBJ_COURIER_MAPPER_H


#include <iostream>
#include "datastructures/Routes.h"
#include "datastructures/Trip.h"
#include "datastructures/Graph.h"
#include "logging/AuditEntity.h"

class Mapper : public AuditEntity {
public:
    Routes mapFileToRoutes(std::string fileName);

    std::string mapTripToFile(Trip trip, std::string resultFilePath, bool timestamp, bool numbers, int resultNumber,
                              std::string inputPath);
};


#endif //OBJ_COURIER_MAPPER_H
