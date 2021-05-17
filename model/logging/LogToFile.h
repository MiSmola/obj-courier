#ifndef OBJ_COURIER_LOGTOFILE_H
#define OBJ_COURIER_LOGTOFILE_H


#include <string>
#include <fstream>
#include "Logging.h"
/**
 * Klasa logowania do pliku
 */
class LogToFile : public Logging {
private:
    /**
     * Pole strumienia zapisu do pliku
     */
    std::ofstream logFile;

    /**
     * Metoda przeprowadzajaca wpis do pliku
     * @param str Wpisywana infromacja
     * @param level Poziom logowania
     * @param withCheck Flaga istnienia pliku
     * @param withClose Flaga zezwolenia na zamkniecie pliku
     */
    void writeLog(std::string str, LOG_LEVEL level, bool withCheck, bool withClose);

    /**
     * Metoda ustawiajaca poziom logowania
     * @param level Poziom logowania
     * @return
     */
    std::string fetchLogLevel(LOG_LEVEL level);

public:
    /**
     * Konstruktor obslugujacy utworzenie lub otwarcie pliku logow
     */
    LogToFile();

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


};


#endif //OBJ_COURIER_LOGTOFILE_H
