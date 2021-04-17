//
// Created by djnic on 27.03.2021.
//

#include <fstream>

#include <iostream>
#include "Params.h"
#include "Constants.h"
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

std::map<std::string, std::string> Params::cfgMap;

void Params::loadParameters() {
    std::ofstream paramFileCreate;
    std::string cfgFileDirectory = fs::temp_directory_path().string();
    std::ifstream paramFile((cfgFileDirectory + PROPERTIES_FILE_NAME).c_str());
    std::string left = "", right = "";
    //if - when there is no cfg file yet
    if (!paramFile.good()) {
        paramFileCreate.open(cfgFileDirectory + PROPERTIES_FILE_NAME, std::ios_base::app);
        paramFileCreate << DEFAULT_CONFIG;
        paramFileCreate.close();
        int i = 0, j = 0;
        while (DEFAULT_CONFIG[i] != '=') {
            left += DEFAULT_CONFIG[i];
            i++;
        }
        j = i + 1;
        while (j != DEFAULT_CONFIG.size()) {
            right += DEFAULT_CONFIG[j];
            j++;
        }
        Params::cfgMap.insert(std::pair<std::string, std::string>(left, right));
    } else {
        //if the cfg file already exists
        std::ifstream paramFile((cfgFileDirectory + PROPERTIES_FILE_NAME));
        while (!paramFile.eof()) {
            getline(paramFile, left, '=');
            getline(paramFile, right);
            Params::cfgMap.insert(std::pair<std::string, std::string>(left, right));
        }
        paramFile.close();
    }
}

