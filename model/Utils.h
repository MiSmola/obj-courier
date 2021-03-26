//
// Created by djnic on 20.03.2021.
//

#ifndef OBJ_COURIER_UTILS_H
#define OBJ_COURIER_UTILS_H


#include <set>
#include <vector>

class Utils {
public:
    static std::vector<int> convertIntSetToVector(std::set<int> set);

    static std::vector<int> convertIntSetToVectorWithBeginValue(std::vector<int> intVector, int value);
};


#endif //OBJ_COURIER_UTILS_H
