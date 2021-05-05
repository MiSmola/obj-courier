//
// Created by djnic on 19.04.2021.
//

#ifndef OBJ_COURIER_TASK_H
#define OBJ_COURIER_TASK_H


#include <string>
#include <chrono>
#include <ostream>
#include "../Constants.h"

class Task {
private:
    int id = -1;
    TASK_STATUS status = NEW;
    std::chrono::duration<double, std::milli> time = std::chrono::milliseconds(0);
    std::string className;
    std::string methodName;
    std::chrono::time_point<std::chrono::steady_clock> timeStart;
    std::chrono::time_point<std::chrono::steady_clock> timeFinish;

public:
    int getId();

    void setId(int id);

    const TASK_STATUS &getStatus() const;

    void setStatus(const TASK_STATUS &status);

    const std::chrono::duration<double, std::milli> &getTime() const;

    void setTime(const std::chrono::duration<double, std::milli> &time);

    std::chrono::time_point<std::chrono::steady_clock> getTimeStart();

    void setTimeStart(std::chrono::time_point<std::chrono::steady_clock> point);

    void setTimeFinish(std::chrono::time_point<std::chrono::steady_clock> point);

    const std::string &getClassName() const;

    void setClassName(const std::string &className);

    const std::string &getMethodName() const;

    void setMethodName(const std::string &methodName);

    void build(int id, TASK_STATUS status, std::string className, std::string methodName);

    friend std::ostream &operator<<(std::ostream &os, const Task &task);
};


#endif //OBJ_COURIER_TASK_H
