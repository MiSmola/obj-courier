//
// Created by djnic on 19.04.2021.
//

#ifndef OBJ_COURIER_LOGGING_H
#define OBJ_COURIER_LOGGING_H


#include <string>
#include "../Constants.h"

class Logging {

public:
    virtual void log(std::string str);

    virtual void log(std::string classId, std::string methodId, LOG_LEVEL level, std::string str);
};


#endif //OBJ_COURIER_LOGGING_H
