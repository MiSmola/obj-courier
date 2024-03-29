#ifndef OBJ_COURIER_CONTROLLER_H
#define OBJ_COURIER_CONTROLLER_H


#include <string>
#include "../model/Mapper.h"
#include "../model/Algorithm.h"

class Controller : public AuditEntity {
public:
    void execute(int argc, char *argv[]);

    void generateResult(Mapper mapper, Algorithm algorithm, std::string inputPath, std::string resultFilePath,
                        bool timestamp, bool numbers, int resultNumber);

};


#endif //OBJ_COURIER_CONTROLLER_H
