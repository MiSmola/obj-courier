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

