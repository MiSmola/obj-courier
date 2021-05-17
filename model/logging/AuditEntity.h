#ifndef OBJ_COURIER_AUDITENTITY_H
#define OBJ_COURIER_AUDITENTITY_H


#include <vector>
#include "LoggingStrategy.h"
#include "LogToFile.h"
#include "../datastructures/List.h"
#include "Task.h"
#include "LogToConsole.h"

/**
 * Klasa zarzadzajaca logowaniem przebiegu dzialania programu
 */
class AuditEntity {
private:
    /**
     * lista zdarzen zachodzacych podczas dzialania programu
     */
    List<Task> list;

    /**
     * Logowanie ustawione domyslnie do konsoli.
     */
    LoggingStrategy *log = new LoggingStrategy(new LogToConsole());

    /**
     * Metoda przetwarzajaca dane o rozpoczeciu i zakonczeniu zadania
     * @param taskIndex indeks danego zadania
     * @param task obiekt przechowujacy informacje o zadaniu
     * @param classId id nazwa logowanej klasy
     * @param methodId nazwa logowanej metody
     * @param status status obslugiwanej metody
     * @return
     */
    Task handleTask(int taskIndex, Task &task, std::string classId, std::string methodId, TASK_STATUS status);

    /**
     * Metoda znajdująca obiekt task o zadanym indeksie
     * @param id
     * @return
     */
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

    ~AuditEntity();
};


#endif //OBJ_COURIER_AUDITENTITY_H
