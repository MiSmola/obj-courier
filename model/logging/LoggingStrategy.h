//
// Created by djnic on 19.04.2021.
//

#ifndef OBJ_COURIER_LOGGINGSTRATEGY_H
#define OBJ_COURIER_LOGGINGSTRATEGY_H


#include <string>
#include "Logging.h"

class LoggingStrategy {
private:
    Logging *logging;
public:
    LoggingStrategy(Logging *logging);

    void changeLoggingStrategy();

    virtual void log(std::string str);

    virtual void log(std::string classId, std::string methodId, LOG_LEVEL level, std::string str);
};


#endif //OBJ_COURIER_LOGGINGSTRATEGY_H
