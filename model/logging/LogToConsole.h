//
// Created by djnic on 19.04.2021.
//

#ifndef OBJ_COURIER_LOGTOCONSOLE_H
#define OBJ_COURIER_LOGTOCONSOLE_H


#include <string>
#include "Logging.h"

class LogToConsole : public Logging {
private:
    std::string fetchLogLevel(LOG_LEVEL level);

public:
    virtual void log(std::string str);

    void log(std::string classId, std::string methodId, LOG_LEVEL level, std::string str);

    void showInConsole(std::string str, LOG_LEVEL level);

};


#endif //OBJ_COURIER_LOGTOCONSOLE_H
