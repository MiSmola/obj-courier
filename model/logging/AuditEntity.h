#ifndef OBJ_COURIER_AUDITENTITY_H
#define OBJ_COURIER_AUDITENTITY_H


#include <vector>
#include "LoggingStrategy.h"
#include "LogToFile.h"
#include "../datastructures/List.h"
#include "Task.h"
#include "LogToConsole.h"

class AuditEntity {
private:
    List<Task> list;

    LoggingStrategy *log = new LoggingStrategy(new LogToConsole());

    Task handleTask(int taskIndex, Task &task, std::string classId, std::string methodId, TASK_STATUS status);

    int getTaskIndex(int id);

public:
    AuditEntity();

    //courier.properties: logging.appender=FILE/STDOUT
    //courier.properties: logging.fileoutpath=<directory>

    Task getTask(int id);

    List<Task> getFinishedTasks();

    int registerTask(std::string className, std::string methodName);

    int registerTask();

    Task closeTask(int id);
};


#endif //OBJ_COURIER_AUDITENTITY_H
