#ifndef OBJ_COURIER_LOGTOCONSOLE_H
#define OBJ_COURIER_LOGTOCONSOLE_H


#include <string>
#include "Logging.h"
/**
 * Klasa obsulgujaca logowanie do konsoli
 */
class LogToConsole : public Logging {
private:
    /**
     * Metoda ustawiajaca poziom logowania
     * @param level Poziom logowania
     * @return
     */
    std::string fetchLogLevel(LOG_LEVEL level);

public:
    /**
     * Ogolna metoda logowania
     * @param str Informacja o logu
     */
    virtual void log(std::string str);

    /**
     * Rozszerzona metoda logowania
     * @param classId Nazwa klasy
     * @param methodId Nazwa metody
     * @param level Poziom logowania
     * @param str Przekazana informacja, w tym przypadku o czasie
     */
    virtual void log(std::string classId, std::string methodId, LOG_LEVEL level, std::string str);

    /**
     * Metoda wyswietlajaca logi na standardowym wyjsciu konsoli
     * @param str Informacja przekazana do wyswietlenia
     * @param level Poziom logowania
     */
    void showInConsole(std::string str, LOG_LEVEL level);

};


#endif //OBJ_COURIER_LOGTOCONSOLE_H
