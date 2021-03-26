//
// Created by djnic on 16.03.2021.
//

#include "StringUtils.h"

int StringUtils::findAll(std::string str, char delim) {
    int size = 0, temp = 0, pos = 0;
    while ((temp = str.find(delim, pos)) >= 1) {
        pos = 1 + temp;
        size++;
    }
    return size + 1;
}

std::vector<std::string> StringUtils::split(std::string str, char delim, int &outSize) {
    outSize = findAll(str, delim);
    if (outSize == 0)
        return {};
    std::vector<std::string> out;
    for (int index = 0, start = 0, find = 0; index < outSize; index++) {
        find = str.find(delim, start);
        if (find < 0 || find < start) {
            out.insert(out.begin() + index, str.substr(start));
            break;
        } else {
            out.insert(out.begin() + index, str.substr(start, find - start));
        }
        start = find + 1;
    }
    return out;
}

int StringUtils::findAll(std::string str, std::string delim) {
    int size = 0, temp = 0, pos = 0;
    while ((temp = str.find(delim, pos)) >= 1) {
        pos = 1 + temp;
        size++;
    }
    return size + 1;
}

std::vector<std::string> StringUtils::split(std::string str, std::string delim, int &outSize) {
    outSize = findAll(str, delim);
    std::vector<std::string> out;
    if (outSize == 0)
        return {};
    size_t pos = str.find(delim);
    std::string left, right;
    left = str.substr(0, pos);
    right = str.substr(pos + delim.length(), str.length());
    out.insert(out.begin() + 0, left);
    out.insert(out.begin() + 1, right);
    return out;
}

bool StringUtils::isUnwantedChar(unsigned char c) {
    return (c == ' ' || c == '\n' || c == '\r' ||
            c == '\t' || c == '\v' || c == '\f' ||
            c == ')' || c == '(');
}


