//
// Created by djnic on 27.03.2021.
//

#include <fstream>
#include <iostream>
#include "Params.h"
#include "Constants.h"
#include <filesystem>
#include <string>
#include <regex>

namespace fs = std::filesystem;

std::map<std::string, std::string> Params::cfgMap;

void Params::loadParameters() {
    std::ofstream paramFileCreate;
    std::string cfgFileDirectory = fs::temp_directory_path().string();
    std::ifstream paramFile((cfgFileDirectory + PROPERTIES_FILE_NAME).c_str());
    std::string outfileLeft = "", outfileRight = "", appenderLeft = "", appenderRight = "", outpathLeft = "", outpathRight = "";
    //if - when there is no cfg file yet
    if (!paramFile.good()) {
        paramFileCreate.open(cfgFileDirectory + PROPERTIES_FILE_NAME, std::ios_base::app);
        paramFileCreate << DEFAULT_CONFIG;
        paramFileCreate.close();
//        int i = 0, j = 0, k=0, l=0, m=0, n=0;
//        while (DEFAULT_CONFIG[i] != '=') {
//            outfileLeft += DEFAULT_CONFIG[i];
//            i++;
//        }
//        j = i + 1;
//        while (DEFAULT_CONFIG[j] != '\n') {//j != DEFAULT_CONFIG.size()) {
//            outfileRight += DEFAULT_CONFIG[j];
//            j++;
//        }
//        while (DEFAULT_CONFIG[k] != '=') {
//            appenderLeft += DEFAULT_CONFIG[k];
//            k++;
//        }
//        l = k + 1;
//        while (DEFAULT_CONFIG[l] != '\n') {//j != DEFAULT_CONFIG.size()) {
//            appenderRight += DEFAULT_CONFIG[l];
//            l++;
//        }
//        while (DEFAULT_CONFIG[m] != '=') {
//            outpathLeft += DEFAULT_CONFIG[m];
//            m++;
//        }
//        n = m + 1;
//        while (n != DEFAULT_CONFIG.size()) {
//            outpathRight += DEFAULT_CONFIG[n];
//            n++;
//        }
        Params::cfgMap.insert(std::pair<std::string, std::string>(TSTAMP_PROPERTY, TSTAMP_PROPERTY_VAL));
        Params::cfgMap.insert(std::pair<std::string, std::string>(APPENDER_PROPERTY, APPENDER_PROPERTY_VAL));
        Params::cfgMap.insert(std::pair<std::string, std::string>(FILE_OUTPUT_PROPERTY, FILE_OUTPUT_PROPERTY_VAL));

    } else {
        //if the cfg file already exists
        std::ifstream paramFile((cfgFileDirectory + PROPERTIES_FILE_NAME));
        std::string propFileString;

        while (!paramFile.eof()) {
            std::string prop = "";
            getline(paramFile, outfileLeft, '=');
            prop += (outfileLeft + "=");
            getline(paramFile, outfileRight);
            prop += outfileRight;

            std::regex propertiesFilePattern(".+[=].+");
            if (!(std::regex_match(prop, propertiesFilePattern))) throw -4;

            Params::cfgMap.insert(std::pair<std::string, std::string>(outfileLeft, outfileRight));
        }
        paramFile.close();
    }
}

