#include <iostream>
#include <string>
#include "model/Mapper.h"
#include "model/Algorithm.h"
#include "controller/Controller.h"
#include "model/Params.h"
#include "model/logging/AuditEntity.h"
#include "model/logging/LoggingStrategy.h"
#include "model/logging/LogToFile.h"
#include "model/logging/LogToConsole.h"
#include "test/TestActivity.h"

#include <iostream>
#include <filesystem>
#include <regex>
#include <thread>


int main(int argc, char *argv[]) {
//    LoggingStrategy *loggingStrategy = new LoggingStrategy();
//    loggingStrategy->changeLoggingStrategy(dynamic_cast<Logging *>(new LogToFile()));
//    loggingStrategy->log("DO PLIKU");
//    loggingStrategy->changeLoggingStrategy(dynamic_cast<Logging *>(new LogToConsole()));
//    loggingStrategy->log("DO KONSOLI");
//
//    Controller *controller = new Controller();
//    controller->execute(argc, argv);
    TestActivity *t = new TestActivity();
    t->perform();
    t->perform();
    t->perform();
    t->perform();

    List<Task> list = t->getFinishedTasks();
    for (int i = 0; i < list.getSize(); i++)
        std::cout << list.get(i);
    return 0;
}
