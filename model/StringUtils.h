//
// Created by djnic on 16.03.2021.
//

#ifndef OBJ_COURIER_STRINGUTILS_H
#define OBJ_COURIER_STRINGUTILS_H


#include <string>
#include <vector>

class StringUtils {
public:
    static int findAll(std::string str, char delim);

    static std::vector<std::string> split(std::string str, char delim, int &outSize);

    static int findAll(std::string str, std::string delim);

    static std::vector<std::string> split(std::string str, std::string delim, int &outSize);

    static bool isUnwantedChar(unsigned char c);
};


#endif //OBJ_COURIER_STRINGUTILS_H
