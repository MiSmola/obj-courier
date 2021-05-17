#ifndef OBJ_COURIER_LOGGING_H
#define OBJ_COURIER_LOGGING_H


#include <string>
#include "../Constants.h"

/**
 * Ogolna klasa logowania
 */
class Logging {

public:
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

};


#endif //OBJ_COURIER_LOGGING_H
