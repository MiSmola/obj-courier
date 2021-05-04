//
// Created by djnic on 19.04.2021.
//

#include "LoggingStrategy.h"

LoggingStrategy::LoggingStrategy(Logging *logging) : logging(logging) {}

void LoggingStrategy::changeLoggingStrategy(Logging *logging) {
    this->logging = logging;
}

void LoggingStrategy::log(std::string str) {
    logging->log(str);
}

void LoggingStrategy::log(std::string classId, std::string methodId, LOG_LEVEL level, std::string str) {
    logging->log(classId, methodId, level, str);
}
