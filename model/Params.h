#ifndef OBJ_COURIER_PARAMS_H
#define OBJ_COURIER_PARAMS_H


#include <string>
#include <vector>
#include <map>

class Params {
public:
    static std::map<std::string, std::string> cfgMap;

    static void Params::loadParameters();
};


#endif //OBJ_COURIER_PARAMS_H
