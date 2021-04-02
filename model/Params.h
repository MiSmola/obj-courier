//
// Created by djnic on 27.03.2021.
//

#ifndef OBJ_COURIER_PARAMS_H
#define OBJ_COURIER_PARAMS_H


#include <string>
#include <vector>
#include <map>

class Params {

public:
    static std::map<std::string, std::string> MAP;

    static void Params::loadParameters();

    static void feedShit();

    // const std::map<std::string, std::string> myMap;
};


#endif //OBJ_COURIER_PARAMS_H
