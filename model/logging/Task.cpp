//
// Created by djnic on 19.04.2021.
//

#include "Task.h"

int Task::getId() {
    return id;
}

void Task::setId(int id) {
    Task::id = id;
}

const TASK_STATUS &Task::getStatus() const {
    return status;
}

void Task::setStatus(const TASK_STATUS &status) {
    Task::status = status;
}

std::chrono::time_point<std::chrono::steady_clock> Task::getTimeStart() {
    return timeStart;
}

void Task::setTimeStart(std::chrono::time_point<std::chrono::steady_clock> timeStart) {
    Task::timeStart = timeStart;
}

void Task::setTimeFinish(std::chrono::time_point<std::chrono::steady_clock> timeFinish) {
    Task::timeFinish = timeFinish;
}

const std::string &Task::getClassName() const {
    return className;
}

void Task::setClassName(const std::string &className) {
    Task::className = className;
}

const std::string &Task::getMethodName() const {
    return methodName;
}

void Task::setMethodName(const std::string &methodName) {
    Task::methodName = methodName;
}

const std::chrono::duration<double, std::milli> &Task::getTime() const {
    return time;
}

void Task::setTime(const std::chrono::duration<double, std::milli> &time) {
    Task::time = time;
}

void Task::
build(int id, TASK_STATUS status, std::string className, std::string methodName) {
    Task::id = id;
    Task::status = status;
    Task::className = className;
    Task::methodName = methodName;
}

std::ostream &operator<<(std::ostream &os, const Task &task) {
    typedef std::chrono::milliseconds ms;
    ms millis = std::chrono::duration_cast<ms>(task.time);
    os << "{ id: " << task.id << ", status: " << task.status << ", time: " << millis.count() << ", className: "
       << task.className
       << ", methodName: " << task.methodName << "}" << std::endl;
    return os;
}
