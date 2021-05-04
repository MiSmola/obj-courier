//
// Created by djnic on 19.04.2021.
//

#ifndef OBJ_COURIER_LOGTOCONSOLE_H
#define OBJ_COURIER_LOGTOCONSOLE_H


#include <string>
#include "Logging.h"

class LogToConsole : public Logging {
public:
    virtual void log(std::string str);

    void showInConsole();

    void getTasksList();
};


#endif //OBJ_COURIER_LOGTOCONSOLE_H
