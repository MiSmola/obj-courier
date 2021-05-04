//
// Created by djnic on 19.04.2021.
//

#include "AuditEntity.h"
#include "../Constants.h"
#include <chrono>
#include <iostream>
#include <sstream>

int AuditEntity::registerTask() {
    Task task;
    handleTask(NULL, task, "AuditEntity", "registerTask", IN_PROGRESS);
    return CURRENT_TASK_ID;
}

int AuditEntity::registerTask(std::string className, std::string methodName) {
    Task task;
    handleTask(NULL, task, className, methodName, IN_PROGRESS);
    return CURRENT_TASK_ID;
}

Task AuditEntity::closeTask(int id) {
    Task task = getTask(id);
    handleTask(getTaskIndex(id), task, "AuditEntity", "closeTask", FINISHED);
    return task;
}

Task AuditEntity::getTask(int id) {
    Task task = list.get(0);
    for (int i = 0; i < list.getSize(); i++)
        if (list.get(i).getId() == id) {
            return list.get(i);
        }
    return task;
}

List<Task> AuditEntity::getFinishedTasks() {
    List<Task> result;
    for (int i = 0; i < list.getSize(); i++)
        if (list.get(i).getStatus() == FINISHED)
            result.add(list.get(i));
    return result;
}

//TODO: Handle logging in the task using given strategy
Task AuditEntity::handleTask(int taskIndex, Task &task, std::string classId, std::string methodId, TASK_STATUS status) {
    std::chrono::time_point<std::chrono::steady_clock> timeFinish = std::chrono::high_resolution_clock::now(),
            timeStart;
    std::ostringstream logMessage;
    std::string strLogMessage;
    switch (status) {
        case IN_PROGRESS:
            CURRENT_TASK_ID++;
            task.setTimeStart(std::chrono::high_resolution_clock::now());
            task.build(CURRENT_TASK_ID, status, classId, methodId);
            list.add(task);

            logMessage << "Process task: " << task << " started";
            strLogMessage = logMessage.str();
            strLogMessage.erase(std::remove(strLogMessage.begin(), strLogMessage.end(), '\n'), strLogMessage.end());
            log->log(classId, methodId, INFO, strLogMessage);
            break;
        case FINISHED:
            task.setTimeFinish(std::chrono::high_resolution_clock::now());
            std::chrono::duration<double, std::milli> elapsed = timeFinish - timeStart;
            task.setTime(elapsed);
            task.setStatus(status);
            list.set(taskIndex, task);

            logMessage << "Process task: " << task << " finished";
            strLogMessage = logMessage.str();
            strLogMessage.erase(std::remove(strLogMessage.begin(), strLogMessage.end(), '\n'), strLogMessage.end());
            log->log(classId, "closeTask", INFO, strLogMessage);
            break;
    }
    return task;
}

int AuditEntity::getTaskIndex(int id) {
    Task task = list.get(0);
    for (int i = 0; i < list.getSize(); i++)
        if (list.get(i).getId() == id)
            return i;
    return -1;
}
