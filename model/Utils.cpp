//
// Created by djnic on 20.03.2021.
//

#include <iterator>
#include "Utils.h"

std::vector<int> Utils::convertIntSetToVector(std::set<int> set) {
    std::vector<int> v;
    v.reserve(set.size());
    std::copy(set.begin(), set.end(), std::back_inserter(v));
    return v;
}

std::vector<int> Utils::convertIntSetToVectorWithBeginValue(std::vector<int> intVector, int value) {
    std::vector<int> intVectorWithBeginValue;
    for (int i = 0; i < intVector.size() + 1; i++) {
        if (i == 0) intVectorWithBeginValue.insert(intVectorWithBeginValue.begin() + i, value);
        else intVectorWithBeginValue.insert(intVectorWithBeginValue.begin() + i, intVector[i - 1]);

    }
    return intVectorWithBeginValue;
}

std::vector<std::string> Utils::fetchParametersAndPopulateInputFields(int argc, char **argv) {
    std::vector<std::string> result(3);
    if (argc == 5 || argc == 2 || argc == 6) {
        for (int i = 1; i < argc; i++) {
            std::string arg = argv[i];
            if (arg == "-i") result[0] = argv[i + 1];
            else if (arg == "-o") result[1] = argv[i + 1];
            else if (arg == "-h") result[2] = argv[i];
        }
    } else {
        throw -2;
    }
    return result;
}


