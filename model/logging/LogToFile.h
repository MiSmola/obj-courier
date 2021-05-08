//
// Created by djnic on 19.04.2021.
//

#ifndef OBJ_COURIER_LOGTOFILE_H
#define OBJ_COURIER_LOGTOFILE_H


#include <string>
#include <fstream>
#include "Logging.h"

class LogToFile : public Logging {
private:
    std::ofstream logFile;

    void writeLog(std::string str, LOG_LEVEL level, bool withCheck, bool withClose);

    std::string fetchLogLevel(LOG_LEVEL level);

public:
    LogToFile();

    virtual void log(std::string str);

    void log(std::string classId, std::string methodId, LOG_LEVEL level, std::string str);

    void saveToFile();

};


#endif //OBJ_COURIER_LOGTOFILE_H
