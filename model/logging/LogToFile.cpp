#include <iostream>
#include <filesystem>
#include "LogToFile.h"
#include "../Utils.h"
#include "../Params.h"

LogToFile::LogToFile() {
    auto it = Params::cfgMap.find(FILE_OUTPUT_PROPERTY);
    std::string logFilePath;
    if (it != Params::cfgMap.end())
        logFilePath = it->second;
    logFilePath.erase(logFilePath.begin());
    logFilePath.erase(logFilePath.size() - 1);
    std::string logFileName;
    if (logFilePath.size() == 0) logFileName = logFilePath + "log-" + Utils::getCurrentTimeAsddMMYYYY() + ".log";
    else
        logFileName = logFilePath + "\\log-" + Utils::getCurrentTimeAsddMMYYYY() + ".log";

    bool isNewFile = std::filesystem::exists(logFileName);
    logFile.open(logFileName, std::ios_base::app);
    writeLog(isNewFile ? "Log file opened" : "Log file created",
             static_cast<LOG_LEVEL>(NULL), true, false);
}

void LogToFile::log(std::string str) {
    writeLog(str, static_cast<LOG_LEVEL>(NULL), true, false);
}

void LogToFile::log(std::string classId, std::string methodId, LOG_LEVEL level, std::string str) {
    writeLog(classId + "." + methodId + " " + str, level, true, false);
}


void LogToFile::writeLog(std::string str, LOG_LEVEL level, bool withCheck, bool withClose) {
    if (withCheck && logFile.is_open()) {
        logFile << "[" + Utils::getCurrentTime() + "] " << fetchLogLevel(level) << str << std::endl;
        if (withClose) logFile.close();
    } else if (withCheck && !logFile.is_open())
        std::cerr << fetchLogLevel(level) << "LogToFile.writeLog() - cannot open log file" << std::endl;
    else {
        logFile << "[" + Utils::getCurrentTime() + "] " << fetchLogLevel(level) << str << std::endl;
        if (withClose) logFile.close();
    }
}

std::string LogToFile::fetchLogLevel(LOG_LEVEL level) {
    return (level == NULL || level == INFO ? "INFO " : (level == WARNING ? "WARNING " : "SEVERE "));
}


