//
// Created by djnic on 20.03.2021.
//

#ifndef OBJ_COURIER_UTILS_H
#define OBJ_COURIER_UTILS_H


#include <set>
#include <vector>
#include <string>

class Utils {
public:

    std::vector<std::string> fetchParametersAndPopulateInputFields(int argc, char *argv[]);

    static std::vector<int> convertIntSetToVector(std::set<int> set);

    static std::vector<int> convertIntSetToVectorWithBeginValue(std::vector<int> intVector, int value);

    static std::string addNumberToFileName(std::string resultFilePath, int resultNumber);

    static std::string extractFileNameFromPath(std::string inputPath);

    static std::string getCurrentTime();

    static std::string Utils::getCurrentTimeAsddMMYYYY();
};


#endif //OBJ_COURIER_UTILS_H
