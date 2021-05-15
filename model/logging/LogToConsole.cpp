#include <iostream>
#include "LogToConsole.h"
#include "../Utils.h"

void LogToConsole::log(std::string str) {
    std::cout << "[" << Utils::getCurrentTime() << "]" << str << std::endl;
}

void LogToConsole::log(std::string classId, std::string methodId, LOG_LEVEL level, std::string str) {
    showInConsole(classId + "." + methodId + " " + str, level);
}

void LogToConsole::showInConsole(std::string str, LOG_LEVEL level) {
    std::cout << "[" + Utils::getCurrentTime() + "] " << fetchLogLevel(level) << str << std::endl;
}

std::string LogToConsole::fetchLogLevel(LOG_LEVEL level) {
    return (level == NULL || level == INFO ? "INFO " : (level == WARNING ? "WARNING " : "SEVERE "));
}
