#ifndef OBJ_COURIER_LOGGINGSTRATEGY_H
#define OBJ_COURIER_LOGGINGSTRATEGY_H


#include <string>
#include "Logging.h"

/**
 * Klasa decydujaca o typie logowania
 */
class LoggingStrategy {
private:
    /**
     * Pole sluzace do przechowywania konkretnej instancji obiektu typu logowania
     */
    Logging *logging;
public:
    /**
     * Konstruktor obiektu typu logowania
     * @param logging Przekazywany obiekt
     */
    LoggingStrategy(Logging *logging);

    /**
     * Metoda ustawiajaca typ logowania
     */
    void changeLoggingStrategy();

    /**
     * Ogolna metoda logowania
     * @param str Przekazana informacja
     */
    virtual void log(std::string str);

    /**
     * Metoda logowania z informacja o klasie, metodzie oraz stanie
     * @param classId Nazwa klasy
     * @param methodId Nazwa metody
     * @param level Poziom logowania
     * @param str Przekazana informacja, w tym przypadku o czasie
     */
    virtual void log(std::string classId, std::string methodId, LOG_LEVEL level, std::string str);

    virtual ~LoggingStrategy();
};


#endif //OBJ_COURIER_LOGGINGSTRATEGY_H
