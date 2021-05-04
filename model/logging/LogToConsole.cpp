//
// Created by djnic on 19.04.2021.
//

#include <iostream>
#include "LogToConsole.h"
#include "../Utils.h"

void LogToConsole::log(std::string str) {
    std::cout << "[" << Utils::getCurrentTime() << "]" << str << std::endl;
}

void LogToConsole::showInConsole() {

}

void LogToConsole::getTasksList() {

}
