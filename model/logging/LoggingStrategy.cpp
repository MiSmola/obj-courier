#include "LoggingStrategy.h"
#include "../Params.h"
#include "LogToFile.h"
#include "LogToConsole.h"

LoggingStrategy::LoggingStrategy(Logging *logging) : logging(logging) {}

void LoggingStrategy::changeLoggingStrategy() {
    auto it = Params::cfgMap.find(APPENDER_PROPERTY);
    std::string appenderProp;
    if (it != Params::cfgMap.end())
        appenderProp = it->second;
    if (appenderProp == "FILE") this->logging = new LogToFile();
    else this->logging = new LogToConsole();
}

void LoggingStrategy::log(std::string str) {
    logging->log(str);
}

void LoggingStrategy::log(std::string classId, std::string methodId, LOG_LEVEL level, std::string str) {
    logging->log(classId, methodId, level, str);
}

LoggingStrategy::~LoggingStrategy() {
    delete logging;
}
